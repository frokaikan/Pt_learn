#ifndef NO_MODEL2_ADDSUBTRACT_H
#define NO_MODEL2_ADDSUBTRACT_H
#include "_ptTypes.h"
#include "_AtomicActor.h"
#include "_TypedIOPort.h"
#include "_SDFReceiver.h"
#include "model2.h"
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
    #endif
    struct AtomicActor* model2_AddSubtract_New();struct IOPort* model2_AddSubtract_get_plus();
    struct IOPort* model2_AddSubtract_get_minus();
    struct IOPort* model2_AddSubtract_get_output();
    struct IOPort* model2_AddSubtract_get_output();
    #ifdef __cplusplus
}
#endif
#endif /* MODEL2_ADDSUBTRACT_H */
