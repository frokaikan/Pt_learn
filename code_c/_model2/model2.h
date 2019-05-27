#ifndef _MODEL2_H_
#define _MODEL2_H_
#include "_CompositeActor.h"
#include "_AtomicActor.h"
#include "_SDFDirector.h"
#include "model2_Display.h"
#include "model2_Ramp.h"
#include "model2_Const.h"
#include "model2_AddSubtract.h"
#ifdef __cplusplus
extern "C" {
    #endif
    extern struct CompositeActor* model2;
    extern struct CompositeActor* model2_New();
    void model2_Schedule_iterate();
    extern struct AtomicActor* model2_Display;
    extern struct AtomicActor* model2_Ramp;
    extern struct AtomicActor* model2_Const;
    extern struct AtomicActor* model2_AddSubtract;
    #ifdef __cplusplus
}
#endif
#endif /* MODEL2 */
