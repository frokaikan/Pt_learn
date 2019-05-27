#include "model2.h"
struct CompositeActor* model2;
struct CompositeActor* model2_New() {
    model2 = CompositeActor_New();
    #ifdef _debugging
    ((struct CompositeActor*)model2)->setName((struct CompositeActor *)model2, "model2");
    #endif
    struct SDFDirector* model2_SDF_Director = SDFDirector_New();
    #ifdef _debugging
    ((struct Director*)model2_SDF_Director)->setName((struct Director *)model2_SDF_Director, "SDF Director");
    #endif
    model2->_director = (struct Director*)model2_SDF_Director;
    model2_Display = model2_Display_New();
    pblListAdd(model2->_containedEntities, model2_Display);
    model2_Ramp = model2_Ramp_New();
    pblListAdd(model2->_containedEntities, model2_Ramp);
    model2_Const = model2_Const_New();
    pblListAdd(model2->_containedEntities, model2_Const);
    model2_AddSubtract = model2_AddSubtract_New();
    pblListAdd(model2->_containedEntities, model2_AddSubtract);
    model2_SDF_Director->container = model2;
    model2_SDF_Director->_startTime = 0.0;
    model2_SDF_Director->_stopTime = Infinity;
    model2_SDF_Director->iterations = -1;
    model2_SDF_Director->period = 0.0;
    model2_SDF_Director->localClock->container = (struct Director*)model2_SDF_Director;
    model2_SDF_Director->schedule = model2_Schedule_iterate;
    struct IOPort* model2_Display_input = (struct IOPort*)model2_Display_get_input();
    struct IOPort* model2_Ramp_output = (struct IOPort*)model2_Ramp_get_output();
    struct IOPort* model2_Const_output = (struct IOPort*)model2_Const_get_output();
    struct IOPort* model2_AddSubtract_plus = (struct IOPort*)model2_AddSubtract_get_plus();
    struct IOPort* model2_AddSubtract_minus = (struct IOPort*)model2_AddSubtract_get_minus();
    struct IOPort* model2_AddSubtract_output = (struct IOPort*)model2_AddSubtract_get_output();
    pblListAdd(pblListGet(model2_Ramp_output->_farReceivers, 0), pblListGet(pblListGet(model2_AddSubtract_plus->_localReceivers, 0), 0));
    pblListAdd(pblListGet(model2_Const_output->_farReceivers, 0), pblListGet(pblListGet(model2_AddSubtract_minus->_localReceivers, 0), 0));
    pblListAdd(pblListGet(model2_AddSubtract_output->_farReceivers, 0), pblListGet(pblListGet(model2_Display_input->_localReceivers, 0), 0));
    return model2;
}
struct AtomicActor* model2_Display;
struct AtomicActor* model2_Ramp;
struct AtomicActor* model2_Const;
struct AtomicActor* model2_AddSubtract;
