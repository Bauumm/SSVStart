// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#pragma once

#include "SSVStart/GameSystem/GameTimer.hpp"
#include "SSVStart/GameSystem/GameState.hpp"

#include "SSVStart/Input/InputState.hpp"

#include <SFML/Window/Event.hpp>

namespace ssvs
{

class GameWindow;

class GameEngine
{
    friend GameWindow;
    friend class TimerBase;
    friend class TimerStatic;
    friend class TimerDynamic;

private:
    GameTimer timer;
    GameState* gameState{nullptr};
    Input::InputState* inputState{nullptr};
    bool running{true};

    void refreshTimer()
    {
        timer.refresh();
    }

    // These methods are called from the timer
    void updateFromTimer(FT mFT)
    {
        SSVU_ASSERT(isValid());
        if(inputState != nullptr) gameState->updateInput(*inputState, mFT);
        gameState->update(mFT);
    }
    void drawFromTimer()
    {
        SSVU_ASSERT(isValid());
        gameState->draw();
    }

    void handleEvent(const sf::Event& mEvent) const noexcept
    {
        SSVU_ASSERT(isValid());
        gameState->handleEvent(mEvent);
    }

    bool isValid() const noexcept
    {
        return gameState != nullptr;
    }

public:
    GameEngine() = default;

    GameEngine(const GameEngine&) = delete;
    GameEngine& operator=(const GameEngine&) = delete;

    void stop() noexcept
    {
        running = false;
    }

    void runUpdate()
    {
        SSVU_ASSERT(isValid());

        if(inputState != nullptr) gameState->refreshInput(*inputState);
        timer->runUpdate();
        gameState->onPostUpdate();
    }

    void runDraw()
    {
        SSVU_ASSERT(isValid());

        timer->runDraw();
    }

    void runFPS()
    {
        SSVU_ASSERT(isValid());

        timer->runFrameTime();
        timer->runFPS();
    }

    float getFPS() const noexcept
    {
        return timer->getFPS();
    }

    void setGameState(GameState& mGameState) noexcept
    {
        gameState = &mGameState;
    }
    void setInputState(Input::InputState& mInputState) noexcept
    {
        inputState = &mInputState;
    }

    bool isRunning() const noexcept
    {
        return running;
    }

    template <typename T>
    T& getTimer()
    {
        return timer.getImpl<T>();
    }
    template <typename T, typename... TArgs>
    void setTimer(TArgs&&... mArgs)
    {
        timer.setImpl<T>(*this, FWD(mArgs)...);
    }
};

} // namespace ssvs
