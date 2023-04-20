#pragma once

#include <Processors/Chunk.h>
#include <Processors/ISource.h>


namespace DB
{

/// The big brother of SourceFromSingleChunk. Supports multiple chunks and totals/extremes.
class SourceFromChunks : public ISource
{
public:
    /// Totals/extremes must be single chunks each. If there are no totals or extremes, pass in an empty chunks.
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

    Chunk chunk_totals;
    Chunk chunk_extremes;

    bool finished_chunks = false;
};

}
