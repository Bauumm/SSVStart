// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_UTILS_SFML
#define SSVS_UTILS_SFML

#include <SFML/Graphics.hpp>
#include "SSVStart/Global/Typedefs.hpp"

namespace ssvs
{
	// TODO: docs
	template<typename T> float getGlobalLeft(const T& mElement)	noexcept		{ return mElement.getGlobalBounds().left; }
	template<typename T> float getGlobalRight(const T& mElement) noexcept		{ return mElement.getGlobalBounds().left + mElement.getGlobalBounds().width; }
	template<typename T> float getGlobalTop(const T& mElement) noexcept			{ return mElement.getGlobalBounds().top; }
	template<typename T> float getGlobalBottom(const T& mElement) noexcept		{ return mElement.getGlobalBounds().top + mElement.getGlobalBounds().height; }
	template<typename T> float getGlobalWidth(const T& mElement) noexcept		{ return mElement.getGlobalBounds().width; }
	template<typename T> float getGlobalHeight(const T& mElement) noexcept		{ return mElement.getGlobalBounds().height; }
	template<typename T> Vec2f getGlobalSize(const T& mElement) noexcept		{ return {getGlobalWidth(mElement), getGlobalHeight(mElement)}; }
	template<typename T> Vec2f getGlobalHalfSize(const T& mElement) noexcept	{ return getGlobalSize(mElement) / 2.f; }

	template<typename T> float getLocalLeft(const T& mElement) noexcept			{ return mElement.getLocalBounds().left; }
	template<typename T> float getLocalRight(const T& mElement) noexcept		{ return mElement.getLocalBounds().left + mElement.getLocalBounds().width; }
	template<typename T> float getLocalTop(const T& mElement) noexcept			{ return mElement.getLocalBounds().top; }
	template<typename T> float getLocalBottom(const T& mElement) noexcept		{ return mElement.getLocalBounds().top + mElement.getLocalBounds().height; }
	template<typename T> float getLocalWidth(const T& mElement) noexcept		{ return mElement.getLocalBounds().width; }
	template<typename T> float getLocalHeight(const T& mElement) noexcept		{ return mElement.getLocalBounds().height; }
	template<typename T> Vec2f getLocalSize(const T& mElement) noexcept			{ return {getLocalWidth(mElement), getLocalHeight(mElement)}; }
	template<typename T> Vec2f getLocalHalfSize(const T& mElement) noexcept		{ return getLocalSize(mElement) / 2.f; }
}

#endif
