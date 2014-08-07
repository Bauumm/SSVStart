// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_ASSETS_INTERNAL_LOADER
#define SSVS_ASSETS_INTERNAL_LOADER

#include "SSVStart/BitmapText/BitmapText.hpp"
#include "SSVStart/Tileset/Tileset.hpp"
#include "SSVStart/Assets/Internal/Helper.hpp"

namespace ssvs
{
	namespace Internal
	{
		template<typename T> struct Loader // Most resources can be loaded only from Path, Memory or Stream
		{
			template<typename... TArgs> inline static UPtr<T> load(TArgs&&... mArgs) { return Helper<Mode::Load, T>::load(mArgs...); }
		};
		template<> struct Loader<sf::Texture> // Texture can also be loaded from Image
		{
			using T = sf::Texture;
			inline static UPtr<T> load(const Path& mPath)						{ return Helper<Mode::Load, T>::load(mPath); }
			inline static UPtr<T> load(const void* mData, std::size_t mSize)	{ return Helper<Mode::Load, T>::load(mData, mSize); }
			inline static UPtr<T> load(sf::InputStream& mStream)				{ return Helper<Mode::Load, T>::load(mStream); }
			inline static UPtr<T> load(const sf::Image& mImage)					{ return Helper<Mode::Image, T>::load(mImage); }
		};
		template<> struct Loader<sf::SoundBuffer> // SoundBuffer can also be loaded from samples
		{
			using T = sf::SoundBuffer;
			inline static UPtr<T> load(const Path& mPath)						{ return Helper<Mode::Load, T>::load(mPath); }
			inline static UPtr<T> load(const void* mData, std::size_t mSize)	{ return Helper<Mode::Load, T>::load(mData, mSize); }
			inline static UPtr<T> load(sf::InputStream& mStream)				{ return Helper<Mode::Load, T>::load(mStream); }
			inline static UPtr<T> load(const sf::Int16* mSamples, std::size_t mSampleCount, unsigned int mChannelCount, unsigned int mSampleRate) { return Helper<Mode::Samples, T>::load(mSamples, mSampleCount, mChannelCount, mSampleRate); }
		};
		template<> struct Loader<sf::Music> // Music can be opened from Path, Memory or StreamloadFromFile
		{
			using T = sf::Music;
			template<typename... TArgs> inline static UPtr<T> load(TArgs&&... mArgs) { return Helper<Mode::Open, T>::load(mArgs...); }
		};
		template<> struct Loader<sf::Shader> // Shader has unique syntax
		{
			using T = sf::Shader;
			template<typename... TArgs> inline static UPtr<T> load(TArgs&&... mArgs) { return Helper<Mode::Shader, T>::load(mArgs...); }
		};
		template<> struct Loader<BitmapFont> // BitmapFont has unique syntax
		{
			using T = BitmapFont;
			template<typename... TArgs> inline static UPtr<T> load(TArgs&&... mArgs) { return Helper<Mode::BitmapFont, T>::load(mArgs...); }
		};
		template<> struct Loader<Tileset> // Tileset has unique syntax
		{
			using T = Tileset;
			template<typename... TArgs> inline static UPtr<T> load(TArgs&&... mArgs) { return Helper<Mode::Tileset, T>::load(mArgs...); }
		};
	}
}

#endif
