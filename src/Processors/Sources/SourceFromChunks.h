#pragma once

#include <Processors/Chunk.h>
#include <Processors/ISource.h>


namespace DB
{

/// The big brother of SourceFromSingleChunk. Supports multiple chunks and totals/extremes.
class SourceFromChunks : public ISource
{
public:
    /// Totals/extremes must be single chunks each and (if specified) they are assumed to be non-empty.
    SourceFromChunks(Block header, Chunks && chunks_);
    SourceFromChunks(Block header, Chunks && chunks_, Chunk && other,  WithTotalsOutputTag tag);
    SourceFromChunks(Block header, Chunks && chunks_, Chunk && other,  WithExtremesOutputTag tag);
    SourceFromChunks(Block header, Chunks && chunks_, Chunk && totals_, Chunk && extremes_);

    String getName() const override;

    Status prepare() override;
    void work() override;

protected:
    Chunk generate() override;

private:
    Chunks chunks;
    Chunks::iterator it;

    std::optional<Chunk> chunk_totals = std::nullopt;
    std::optional<Chunk> chunk_extremes = std::nullopt;

    bool finished_chunks = false;
};

}
