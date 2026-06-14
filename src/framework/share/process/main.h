#pragma once

#include "../../../common/define/result.h"

namespace Framework {
namespace Share {
	namespace Process {
		auto Main() -> ::Common::Result<>;
	} // end of namespace for Process
}// end of namespace for Share
}// end of namespace for Framework
#include "./main.hpp"