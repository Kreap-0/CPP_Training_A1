#include "ExecutorImpl.hpp"

#include <memory>
#include <new>
#include <unordered_map>

#include "Command.hpp"

namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new ExecutorImpl(pose);
}

ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : poseHandler(pose)
{
}

void ExecutorImpl::Execute(const std::string& commands) noexcept
{
    std::unordered_map<char, std::unique_ptr<ICommand>> cmderMap;
    cmderMap.emplace('M', std::make_unique<MoveCommand>());
    cmderMap.emplace('L', std::make_unique<TurnLeftCommand>());
    cmderMap.emplace('R', std::make_unique<TurnRightCommand>());
    cmderMap.emplace('F', std::make_unique<FastCommand>());

    std::unique_ptr<ICommand> cmder;
    for (const auto cmd : commands) {
        const auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) {
            it->second->DoOperate(poseHandler);
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas