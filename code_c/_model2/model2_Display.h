#ifndef NO_MODEL2_DISPLAY_H
#define NO_MODEL2_DISPLAY_H
#include "_ptTypes.h"
#include "_AtomicActor.h"
#include "_TypedIOPort.h"
#include "_SDFReceiver.h"
#include "model2.h"
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
    #endif
    struct AtomicActor* model2_Display_New();struct IOPort* model2_Display_get_input();
    #ifdef __cplusplus
}
#endif
#endif /* MODEL2_DISPLAY_H */
