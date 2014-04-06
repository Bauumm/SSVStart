// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVS_INPUT_TRIGGER
#define SSVS_INPUT_TRIGGER

#include <vector>
#include "SSVStart/Input/Enums.hpp"
#include "SSVStart/Input/Combo.hpp"

namespace ssvs
{
	namespace Input
	{
		class InputState;
		class Manager;

		class Trigger
		{
			private:
				Type type{Type::Always};
				Mode mode{Mode::Overlap};
				std::vector<Combo> combos;
				bool released{true};
				std::size_t priority{0u};

				inline bool isDown(Manager& mManager, InputState& mInputState) const
				{
					for(const auto& c : combos) if(c.isDown(mManager, mInputState, mode)) return true;
					return false;
				}

				inline void recalculatePriority()
				{
					std::size_t max{0u};
					for(auto& c : combos) max = std::max(c.getKeys().count() + c.getBtns().count(), max);
					priority = max;
				}

			public:
				inline Trigger() = default;
				inline Trigger(const std::initializer_list<Combo>& mCombos) noexcept : combos{mCombos} { recalculatePriority(); }

				inline void refresh(Manager& mManager, InputState& mInputState)	{ if(!released && !isDown(mManager, mInputState)) released = true; }

				inline void setType(Type mType) noexcept		{ type = mType; }
				inline void setMode(Mode mMode) noexcept		{ mode = mMode; }
				inline void setReleased(bool mValue) noexcept	{ released = mValue; }

				inline bool isActive(Manager& mManager, InputState& mInputState)
				{
					if(type == Type::Always) return isDown(mManager, mInputState);
					if(released && isDown(mManager, mInputState)) { released = false; return true; }
					return false;
				}

				inline decltype(combos)& getCombos() noexcept				{ return combos; }
				inline const decltype(combos)& getCombos() const noexcept	{ return combos; }

				inline bool operator<(const Trigger& mRhs) const noexcept	{ return priority > mRhs.priority; }\
		};
	}
}

#endif
