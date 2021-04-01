// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#pragma once

#include "SSVStart/Global/Typedefs.hpp"

#include <SFML/Graphics/Rect.hpp>

#include <string>
#include <unordered_map>

namespace ssvs
{

class Tileset
{
private:
    Vec2u tileSize;
    std::unordered_map<std::string, Vec2u> labels;

public:
    Tileset() = default;
    Tileset(const Vec2u& mTileSize) noexcept : tileSize{mTileSize}
    {
    }

    void setTileSize(const Vec2u& mTileSize) noexcept
    {
        tileSize = mTileSize;
    }

    void setLabel(const std::string& mLabel, const Vec2u& mIdx)
    {
        labels[mLabel] = mIdx;
    }

    const auto& getLabels() const noexcept
    {
        return labels;
    }

    const auto& getTileSize() const noexcept
    {
        return tileSize;
    }

    const auto& getIdx(const std::string& mLabel) const
    {
        return labels.at(mLabel);
    }

    auto operator()(unsigned int mX, unsigned int mY) const noexcept
    {
        return sf::IntRect(
            mX * tileSize.x, mY * tileSize.y, tileSize.x, tileSize.y);
    }

    auto operator()(const Vec2u& mIdx) const noexcept
    {
        return (*this)(mIdx.x, mIdx.y);
    }

    auto operator()(const std::string& mLabel) const noexcept
    {
        return (*this)(getIdx(mLabel));
    }
};

} // namespace ssvs
