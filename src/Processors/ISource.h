#pragma once

#include <Processors/IProcessor.h>


namespace DB
{

class ISource : public IProcessor
{
private:
    ReadProgressCounters read_progress;
    bool read_progress_was_set = false;
    bool auto_progress;

protected:
    OutputPort & output;
    OutputPort * output_totals = nullptr;
    OutputPort * output_extremes = nullptr;
    bool has_input = false;
    bool finished = false;
    bool got_exception = false;
    Port::Data current_chunk;

    std::shared_ptr<const StorageLimitsList> storage_limits;

    virtual Chunk generate();
    virtual std::optional<Chunk> tryGenerate();

    virtual void progress(size_t read_rows, size_t read_bytes);

public:

    explicit ISource(Block header, bool enable_auto_progress = true);

    struct WithTotalsOutputTag {};
    struct WithExtremesOutputTag {};
    struct WithTotalsAndExtremesOutputTag {};

    /// Use these constructors if the derived source also needs to produce totals and/or extremes.
    /// All output ports will have the same column structure given by 'header'.
    ISource(Block header, WithTotalsOutputTag tag, bool enable_auto_progress = true);
    ISource(Block header, WithExtremesOutputTag tag, bool enable_auto_progress = true);
    ISource(Block header, WithTotalsAndExtremesOutputTag tag, bool enable_auto_progress = true);

    ~ISource() override;

    Status prepare() override;
    void work() override;

    OutputPort & getPort() { return output; }
    const OutputPort & getPort() const { return output; }

    OutputPort * getTotalsPort() { return output_totals; }
    const OutputPort * getTotalsPort() const { return output_totals; }

    OutputPort * getExtremesPort() { return output_extremes; }
    const OutputPort * getExtremesPort() const { return output_extremes; }

    void setStorageLimits(const std::shared_ptr<const StorageLimitsList> & storage_limits_) override;

    /// Default implementation for all the sources.
    std::optional<ReadProgress> getReadProgress() final;

    void addTotalRowsApprox(size_t value) { read_progress.total_rows_approx += value; }
};

using SourcePtr = std::shared_ptr<ISource>;

}
