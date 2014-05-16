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
		class Trigger
		{
			private:
				std::vector<Combo> combos;

			public:
				inline Trigger() = default;
				inline Trigger(const std::initializer_list<Combo>& mCombos) noexcept : combos{mCombos} { }

				inline bool operator==(const Trigger& mRhs) const noexcept { return combos == mRhs.combos; }
				inline bool operator!=(const Trigger& mRhs) const noexcept { return !this->operator==(mRhs); }

				inline decltype(combos)& getCombos() noexcept				{ return combos; }
				inline const decltype(combos)& getCombos() const noexcept	{ return combos; }
		};
	}
}

#endif
