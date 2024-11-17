#include "ExecutorImpl.hpp"

#include <new>

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose = {0, 0, 'N'}) noexcept
{
    return new ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
}

Pose ExecutorImpl::Query() const noexcept
{
    return pose;
}
}  // namespace adas