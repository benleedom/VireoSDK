#include "TypeDefiner.h"

namespace Vireo {

VIREO_FUNCTION_SIGNATURE2(MakeRefInt32, Int32, Int32*)
{
    _Param(1) = _ParamPointer(0);
    return _NextInstruction();
}

//------------------------------------------------------------
VIREO_FUNCTION_SIGNATURE3(DerefAddInt32, Int32*, Int32*, Int32)
{
    _Param(2) = *_Param(0) + *_Param(1);
    return _NextInstruction();
}

DEFINE_VIREO_BEGIN(RustGPrims)
    DEFINE_VIREO_FUNCTION_CUSTOM(MakeRefInt32, MakeRefInt32, "p(i(Int32) o(ptr(Int32)))")
    DEFINE_VIREO_FUNCTION_CUSTOM(DerefAddInt32, DerefAddInt32, "p(i(ptr(Int32)) i(ptr(Int32)) o(Int32))")
DEFINE_VIREO_END()

}