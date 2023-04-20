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

    /// Use these constructors if SourceFromChunks owns the chunks
    SourceFromChunks(Block header, Chunks chunks_);
    SourceFromChunks(Block header, Chunks chunks_, Chunk other,  WithTotalsOutputTag tag);
    SourceFromChunks(Block header, Chunks chunks_, Chunk other,  WithExtremesOutputTag tag);
    SourceFromChunks(Block header, Chunks chunks_, Chunk totals_, Chunk extremes_);

    /// Use these constructors if the chunks are owned by someone else
    SourceFromChunks(Block header, std::shared_ptr<Chunks> chunks_);
    /// SourceFromChunks(Block header, std::shared_ptr<Chunks> chunks_, std::shared_ptr<Chunk> totals_, std::shared_ptr<Chunk> extremes_);

    String getName() const override;

    Status prepare() override;
    void work() override;

protected:
    Chunk generate() override;

private:
    const std::shared_ptr<Chunks> chunks;
    Chunks::iterator it;
    const bool move_from_chunks; /// optimization: if SourceFromChunks owns the chunks, then generate() can move from them

    Chunk chunk_totals;
    Chunk chunk_extremes;

    bool finished_chunks = false;

};

}
