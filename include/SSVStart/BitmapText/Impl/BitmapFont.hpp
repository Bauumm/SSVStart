// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#pragma once

#include "SSVStart/Global/Typedefs.hpp"

#include <SSVUtils/Core/Utils/Math.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace ssvs
{

struct BitmapFontData
{
    unsigned int cellColumns, cellWidth, cellHeight, cellStart;
};

class BitmapFont
{
private:
    const sf::Texture& texture;
    const BitmapFontData data;

public:
    BitmapFont(
        const sf::Texture& mTexture, const BitmapFontData& mData) noexcept
        : texture(mTexture), data(mData)
    {
    }

    const auto& getTexture() const noexcept
    {
        return texture;
    }

    auto getCellWidth() const noexcept
    {
        return data.cellWidth;
    }

    auto getCellHeight() const noexcept
    {
        return data.cellHeight;
    }

    auto getGlyphRect(char mX) const
    {
        mX += toNum<long>(data.cellStart) - 33;
        const auto& i(ssvu::get2DIdxFrom1D(mX, data.cellColumns));
        return sf::IntRect(std::get<0>(i) * data.cellWidth,
            std::get<1>(i) * data.cellHeight, data.cellWidth, data.cellHeight);
    }
};

} // namespace ssvs
