#pragma once

#include "../../../common/define/result.h"
#include <string>

namespace Framework {
namespace Setting {

	template <class Value, class Functor, typename... Args>
	auto Query(Value &_Value, Functor &&_Functor, ::std::string const &_FilePath, Args &&... _Args) -> ::Common::Result<> {
		return(_Functor(_Value, _FilePath, ::std::forward<Args>(_Args)...));
	}
}// end of namespace for Framework
}// end of namespace for Setting