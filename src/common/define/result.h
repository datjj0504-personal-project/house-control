#pragma once

#include "../result.h"

namespace Common {

#define RESULT_SUCCESS             (0)
#define RESULT_FAILURE             (-1)
#define MAKE_SUCCESS_RESULT(_ErrorCode)    ::Common::Result<>::Make(true, _ErrorCode)
#define MAKE_FAILURE_RESULT(_ErrorCode)    ::Common::Result<>::Make(false, _ErrorCode)

// [0x0100 - 0x01FF] : Common error codes
#define RESULT_S_SUCCESS           MAKE_SUCCESS_RESULT(0x0100)
#define RESULT_E_FAILURE           MAKE_FAILURE_RESULT(0x0100)
#define RESULT_S_FOUND             MAKE_SUCCESS_RESULT(0x0101)
#define RESULT_E_FOUND             MAKE_FAILURE_RESULT(0x0101)

}// end of namespace for Common