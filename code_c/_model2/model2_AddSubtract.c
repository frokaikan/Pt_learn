#ifdef __cplusplus
extern "C" {
    #endif
    #include "model2_AddSubtract.h"
    #ifdef __cplusplus
}
#endif
int model2_AddSubtract__result;
#ifdef __cplusplus
extern "C" {
    #endif
    static struct TypedIOPort* plus;
    static struct TypedIOPort* minus;
    static struct TypedIOPort* output;
    void model2_AddSubtract_preinitialize(struct AtomicActor* actor);
    void model2_AddSubtract_initialize(struct AtomicActor* actor);
    bool model2_AddSubtract_prefire(struct AtomicActor* actor);
    void model2_AddSubtract_fire(struct AtomicActor* actor);
    bool model2_AddSubtract_postfire(struct AtomicActor* actor);
    void model2_AddSubtract_wrapup(struct AtomicActor* actor);
    struct AtomicActor* model2_AddSubtract_New() {
        struct AtomicActor* model2_AddSubtract = AtomicActor_New();
        #ifdef _debugging
        ((struct AtomicActor*)model2_AddSubtract)->setName((struct AtomicActor *)model2_AddSubtract, "AddSubtract");
        #endif
        model2_AddSubtract->container = model2;
        model2_AddSubtract->preinitialize = model2_AddSubtract_preinitialize;
        model2_AddSubtract->initialize = model2_AddSubtract_initialize;
        model2_AddSubtract->prefire = model2_AddSubtract_prefire;
        model2_AddSubtract->fire = model2_AddSubtract_fire;
        model2_AddSubtract->postfire = model2_AddSubtract_postfire;
        model2_AddSubtract->wrapup = model2_AddSubtract_wrapup;
        plus = (struct TypedIOPort*)TypedIOPort_New();
        #ifdef _debugging
        plus->setName((struct IOPort*)plus, "plus");
        #endif
        plus->container = (struct Actor*)model2_AddSubtract;
        plus->_isInsideConnected = false;
        plus->_isOutsideConnected = true;
        plus->_isInput = true;
        plus->_isOutput = false;
        plus->_isMultiport = true;
        plus->_width = 1;
        plus->_insideWidth = 0;
        plus->_numberOfSinks = 0;
        plus->_numberOfSources = 1;
        plus->_type = TYPE_Int;
        pblListAdd(model2_AddSubtract->_inputPorts, plus);
        PblList* plus_0 = pblListNewArrayList();
        struct SDFReceiver* plus_0_0 = SDFReceiver_New();
        plus_0_0->container = (struct IOPort*)plus;
        pblListAdd(plus_0, plus_0_0);
        pblListAdd(plus->_localReceivers , plus_0);
        minus = (struct TypedIOPort*)TypedIOPort_New();
        #ifdef _debugging
        minus->setName((struct IOPort*)minus, "minus");
        #endif
        minus->container = (struct Actor*)model2_AddSubtract;
        minus->_isInsideConnected = false;
        minus->_isOutsideConnected = true;
        minus->_isInput = true;
        minus->_isOutput = false;
        minus->_isMultiport = true;
        minus->_width = 1;
        minus->_insideWidth = 0;
        minus->_numberOfSinks = 0;
        minus->_numberOfSources = 1;
        minus->_type = TYPE_Int;
        pblListAdd(model2_AddSubtract->_inputPorts, minus);
        PblList* minus_0 = pblListNewArrayList();
        struct SDFReceiver* minus_0_0 = SDFReceiver_New();
        minus_0_0->container = (struct IOPort*)minus;
        pblListAdd(minus_0, minus_0_0);
        pblListAdd(minus->_localReceivers , minus_0);
        output = (struct TypedIOPort*)TypedIOPort_New();
        #ifdef _debugging
        output->setName((struct IOPort*)output, "output");
        #endif
        output->container = (struct Actor*)model2_AddSubtract;
        output->_isInsideConnected = false;
        output->_isOutsideConnected = true;
        output->_isInput = false;
        output->_isOutput = true;
        output->_isMultiport = false;
        output->_width = 1;
        output->_insideWidth = 0;
        output->_numberOfSinks = 1;
        output->_numberOfSources = 0;
        output->_type = TYPE_Int;
        pblListAdd(model2_AddSubtract->_outputPorts, output);
        PblList* output__0 = pblListNewArrayList();
        pblListAdd(output->_farReceivers, output__0);
        return model2_AddSubtract;
    }
    struct IOPort* model2_AddSubtract_get_plus() {
        return (struct IOPort*) plus;
    }
    struct IOPort* model2_AddSubtract_get_minus() {
        return (struct IOPort*) minus;
    }
    struct IOPort* model2_AddSubtract_get_output() {
        return (struct IOPort*) output;
    }
    void model2_AddSubtract_preinitialize(struct AtomicActor* actor) {
    }
    void model2_AddSubtract_initialize(struct AtomicActor* actor) {
    }
    bool model2_AddSubtract_prefire(struct AtomicActor* actor) {
        return true;
    }
    #ifdef __cplusplus
}
#endif
void model2_AddSubtract_fire(struct AtomicActor* actor) {
    model2_AddSubtract__result = 0;
    bool triggered = false;
    if ((*(plus->hasToken))((struct IOPort*) plus, 0)) {
        triggered = true;
        model2_AddSubtract__result = add_Int_Int(model2_AddSubtract__result, (*(plus->get))((struct IOPort*) plus, 0)->payload.Int);
    }
    if ((*(minus->hasToken))((struct IOPort*) minus, 0)) {
        triggered = true;
        model2_AddSubtract__result = subtract_Int_Int(model2_AddSubtract__result, (*(minus->get))((struct IOPort*) minus, 0)->payload.Int);
    }
    if (triggered) {
        (*(output->send))((struct IOPort*) output, 0, Int_new(model2_AddSubtract__result));
    }
}
#ifdef __cplusplus
extern "C" {
    #endif
    bool model2_AddSubtract_postfire(struct AtomicActor* actor) {
        return true;
    }
    void model2_AddSubtract_wrapup(struct AtomicActor* actor) {
    }
    #ifdef __cplusplus
}
#endif
