#include <Processors/Sources/SourceFromChunks.h>

namespace DB
{

SourceFromChunks::SourceFromChunks(Block header, Chunks && chunks_)
    : ISource(std::move(header))
    , chunks(std::move(chunks_))
    , it(chunks.begin())
{
}

SourceFromChunks::SourceFromChunks(Block header, Chunks && chunks_, Chunk && other,  WithTotalsOutputTag tag)
    : ISource(std::move(header), tag)
    , chunks(std::move(chunks_))
    , it(chunks.begin())
    , chunk_totals(std::move(other))
{
    chassert(!chunk_totals.empty());
}

SourceFromChunks::SourceFromChunks(Block header, Chunks && chunks_, Chunk && other,  WithExtremesOutputTag tag)
    : ISource(std::move(header), tag)
    , chunks(std::move(chunks_))
    , it(chunks.begin())
    , chunk_extremes(std::move(other))
{
    chassert(!chunk_extremes.empty());
}

SourceFromChunks::SourceFromChunks(Block header, Chunks && chunks_, Chunk && totals_, Chunk && extremes_)
    : ISource(std::move(header), WithTotalsAndExtremesOutputTag())
    , chunks(std::move(chunks_))
    , it(chunks.begin())
    , chunk_totals(std::move(totals_))
    , chunk_extremes(std::move(extremes_))
{
    chassert(!chunk_totals.empty());
    chassert(!chunk_extremes.empty());
}

SourceFromChunks::Status SourceFromChunks::prepare()
{
    if (!finished_chunks)
    {
        Status status = ISource::prepare();

        if (status != Status::Finished)
            return status;

        finished_chunks = true;
    }

    if (!chunk_totals.empty())
    {
        chassert(getTotalsPort());

        if (getTotalsPort()->isFinished())
            return Status::Finished;

        if (!getTotalsPort()->canPush())
            return Status::PortFull;

        /// chassert(!getTotalsPort()->isFinished());
        /// chassert(getTotalsPort()->canPush());

        getTotalsPort()->push(std::move(chunk_totals));
        getTotalsPort()->finish();
    }

    if (!chunk_extremes.empty())
    {
        chassert(getExtremesPort());

        if (getExtremesPort()->isFinished())
            return Status::Finished;

        if (!getExtremesPort()->canPush())
            return Status::PortFull;

        /// chassert(!getExtremesPort()->isFinished());
        /// chassert(getExtremesPort()->canPush());

        getExtremesPort()->push(std::move(chunk_extremes));
        getExtremesPort()->finish();
    }

    return Status::Finished;
}

void SourceFromChunks::work()
{
    if (!finished_chunks)
        ISource::work();
}

String SourceFromChunks::getName() const
{
    return "SourceFromChunks";
}

Chunk SourceFromChunks::generate()
{
    if (it != chunks.end())
    {
        Chunk && chunk = std::move(*it);
        it++;
        return chunk;
    }
    else
        return {};
}

}

