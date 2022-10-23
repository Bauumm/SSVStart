// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_INPUT_INPUTSTATE
#define SSVS_INPUT_INPUTSTATE

#include "SSVStart/Global/Typedefs.hpp"
#include <SFML/System/Vector2.hpp>

namespace ssvs
{
class GameWindow;

namespace Input
{
class InputState
{
    friend ssvs::GameWindow;

private:
    FingerBitset fingerStates;
    FingerPositions fingerPos;
    KeyBitset keys;
    BtnBitset btns;

public:
    inline auto getFingerPos(FingerID mX) noexcept
    {
        return fingerPos[mX];
    }
    inline auto getFingerState(FingerID mX) noexcept
    {
        return getFingerBit(fingerStates, mX);
    }
    inline auto operator[](KKey mKey) noexcept
    {
        return getKeyBit(keys, mKey);
    }
    inline auto operator[](MBtn mBtn) noexcept
    {
        return getBtnBit(btns, mBtn);
    }
    inline sf::Vector2i getFingerPos(FingerID mX) const noexcept
    {
        return fingerPos[mX];
    }
    inline bool getFingerState(FingerID mX) const noexcept
    {
        return getFingerBit(fingerStates, mX);
    }
    inline bool operator[](KKey mKey) const noexcept
    {
        return getKeyBit(keys, mKey);
    }
    inline bool operator[](MBtn mBtn) const noexcept
    {
        return getBtnBit(btns, mBtn);
    }

    inline void reset() noexcept
    {
        fingerStates.reset();
        keys.reset();
        btns.reset();
    }

    inline auto& getFingerPositions() noexcept
    {
        return fingerPos;
    }
    inline auto& getFingerStates() noexcept
    {
        return fingerStates;
    }
    inline auto& getKeys() noexcept
    {
        return keys;
    }
    inline auto& getBtns() noexcept
    {
        return btns;
    }
    inline const auto& getFingerPositions() const noexcept
    {
        return fingerPos;
    }
    inline const auto& getFingerStates() const noexcept
    {
        return fingerStates;
    }
    inline const auto& getKeys() const noexcept
    {
        return keys;
    }
    inline const auto& getBtns() const noexcept
    {
        return btns;
    }
};
} // namespace Input
} // namespace ssvs

#endif
