// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#pragma once

#include "SSVStart/GameSystem/Timers/TimerBase.hpp"

#include <SSVUtils/Core/Common/Casts.hpp>

#include <cassert>

namespace ssvs
{

class GameEngine;

class GameTimer
{
private:
    std::unique_ptr<TimerBase> impl, nextImpl;

public:
    void refresh() noexcept
    {
        if(nextImpl == nullptr) return;

        impl.swap(nextImpl);
        nextImpl = nullptr;

        assert(nextImpl == nullptr);
    }

    auto operator->()
    {
        return impl.get();
    }
    auto operator->() const
    {
        return impl.get();
    }

    template <typename T>
    T& getImpl() noexcept
    {
        assert(impl != nullptr);
        return ssvu::castUp<T>(*impl);
    }
    template <typename T, typename... TArgs>
    void setImpl(GameEngine& mGameEngine, TArgs&&... mArgs)
    {
        nextImpl = std::make_unique<T>(mGameEngine, FWD(mArgs)...);
    }
};

} // namespace ssvs
