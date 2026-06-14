
// #include "common/singleton.h"
#include "./server.h"
#include "share/process/main.h"

#include<stdio.h>

// auto Instance() -> Server& {
// 	return Singleton<Server>::instance();
// }

auto main(int argc, char* argv[]) -> int{
	int vStatus{ RESULT_SUCCESS };
	::Common::Result<> vResult{ ::Framework::Share::Process::Main() };
	if(!vResult) {
		vStatus = RESULT_FAILURE;
		printf("Process failed with error code: %d\n", vResult.ErrorCode());
	}
	return(vStatus);
}
