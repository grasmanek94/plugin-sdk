#pragma once

#include "plbase/PluginBase.h"
#include "CTaskSimpleRunAnim.h"

class PLUGIN_API CTaskSimpleHitFromBack : public CTaskSimpleRunAnim {
protected:
    CTaskSimpleHitFromBack(plugin::dummy_func_t a) : CTaskSimpleRunAnim(a) {}
public:
    
};

//VALIDATE_SIZE(CTaskSimpleHitFromBack, 0x);