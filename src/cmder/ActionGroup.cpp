#include "ActionGroup.hpp"

#include <algorithm>
#include <vector>

#include "CmderFactory.hpp"
#include "PoseHandler.hpp"

namespace adas
{

class ForwarAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Forward();
    }
};

class BackwarAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Backward();
    }
};

class TurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};

class ReverseTurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};

class TurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};

class ReverseTurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};

class BeFaseAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};

class BeReverseAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};

ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept : actions(actions)
{
}

void ActionGroup::PushAction(const ActionType ActionType) noexcept
{
    actions.push_back(ActionType);
}

void ActionGroup::DoOperate(PoseHandler& poseHandler) const noexcept
{
    static std::vector<std::function<void(PoseHandler&)>> actionVec = {
        ForwarAction(),    BackwarAction(),          TurnLeftAction(), ReverseTurnLeftAction(),
        TurnRightAction(), ReverseTurnRightAction(), BeFaseAction(),   BeReverseAction(),
    };

    std::for_each(actions.begin(), actions.end(), [&poseHandler](const ActionType actionType) mutable noexcept {
        actionVec[static_cast<uint16_t>(actionType)](poseHandler);
    });
}

}  // namespace adas
