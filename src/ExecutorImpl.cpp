#include "ExecutorImpl.hpp"

#include <algorithm>
#include <functional>
#include <memory>
#include <new>
#include <unordered_map>

#include "cmder/ActionGroup.hpp"
#include "cmder/CmderFactory.hpp"
#include "cmder/Command.hpp"
#include "core/Singleton.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose, const CarType& cartype) noexcept
{
    return new ExecutorImpl(pose, cartype);
}

ExecutorImpl::ExecutorImpl(const Pose& pose, const CarType& cartype) noexcept : poseHandler(pose), cartype(cartype)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(commands);
    std::for_each(cmders.begin(), cmders.end(),
                  [this](const Cmder& cmder) noexcept { cmder(poseHandler, cartype).DoOperate(poseHandler); });
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas