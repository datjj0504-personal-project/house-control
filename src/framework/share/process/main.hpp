#include "./main.h"

#include <stdio.h>

namespace Framework {
namespace Share {
	namespace Process {
		auto Main() -> ::Common::Result<> {
			::Common::Result<> vResult{ RESULT_S_SUCCESS };
			printf("Hello, World haha!\n");
			return(vResult);
		}
	} // end of namespace for Process
}// end of namespace for Share
}// end of namespace for Framework