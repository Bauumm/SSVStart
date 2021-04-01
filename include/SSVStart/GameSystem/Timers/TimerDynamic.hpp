// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#pragma once

#include <SSVUtils/Core/Utils/Math.hpp>

namespace ssvs
{

class TimerDynamic final : public TimerBase
{
private:
    FT frameTimeLimit{4.f};

public:
    TimerDynamic(GameEngine& mGameEngine) noexcept : TimerBase(mGameEngine)
    {
    }

    void runUpdate() override
    {
        gameEngine.updateFromTimer(frameTime);
    }
    void runFPS() override
    {
        ssvu::clampMax(frameTime, frameTimeLimit);
        TimerBase::runFPS();
    }
};

} // namespace ssvs
