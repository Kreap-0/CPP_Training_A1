#include "ExecutorImpl.hpp"

#include <memory>
#include <new>

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
    std::unique_ptr<ICommand> cmder;
    for (const auto cmd : commands) {
        if (cmd == 'M') {
            cmder = std::make_unique<MoveCommand>();
        } else if (cmd == 'L') {
            cmder = std::make_unique<TurnLeftCommand>();
        } else if (cmd == 'R') {
            cmder = std::make_unique<TurnRightCommand>();
        } else if (cmd == 'F') {
            cmder = std::make_unique<FastCommand>();
        }

        if (cmder) {
            cmder->DoOperate(poseHandler);
        }
    }
}

Pose ExecutorImpl::Query() const noexcept
{
    return poseHandler.Query();
}
}  // namespace adas