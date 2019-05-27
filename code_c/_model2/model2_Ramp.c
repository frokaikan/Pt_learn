#ifdef __cplusplus
extern "C" {
    #endif
    #include "model2_Ramp.h"
    #ifdef __cplusplus
}
#endif
int model2_Ramp__state;
int model2_Ramp_step_;
#ifdef __cplusplus
extern "C" {
    #endif
    static struct TypedIOPort* output;
    void model2_Ramp_preinitialize(struct AtomicActor* actor);
    void model2_Ramp_initialize(struct AtomicActor* actor);
    bool model2_Ramp_prefire(struct AtomicActor* actor);
    void model2_Ramp_fire(struct AtomicActor* actor);
    bool model2_Ramp_postfire(struct AtomicActor* actor);
    void model2_Ramp_wrapup(struct AtomicActor* actor);
    struct AtomicActor* model2_Ramp_New() {
        struct AtomicActor* model2_Ramp = AtomicActor_New();
        #ifdef _debugging
        ((struct AtomicActor*)model2_Ramp)->setName((struct AtomicActor *)model2_Ramp, "Ramp");
        #endif
        model2_Ramp->container = model2;
        model2_Ramp->preinitialize = model2_Ramp_preinitialize;
        model2_Ramp->initialize = model2_Ramp_initialize;
        model2_Ramp->prefire = model2_Ramp_prefire;
        model2_Ramp->fire = model2_Ramp_fire;
        model2_Ramp->postfire = model2_Ramp_postfire;
        model2_Ramp->wrapup = model2_Ramp_wrapup;
        output = (struct TypedIOPort*)TypedIOPort_New();
        #ifdef _debugging
        output->setName((struct IOPort*)output, "output");
        #endif
        output->container = (struct Actor*)model2_Ramp;
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
        pblListAdd(model2_Ramp->_outputPorts, output);
        PblList* output__0 = pblListNewArrayList();
        pblListAdd(output->_farReceivers, output__0);
        return model2_Ramp;
    }
    struct IOPort* model2_Ramp_get_output() {
        return (struct IOPort*) output;
    }
    void model2_Ramp_preinitialize(struct AtomicActor* actor) {
        model2_Ramp_step_ = 10;
    }
    void model2_Ramp_initialize(struct AtomicActor* actor) {
        model2_Ramp__state = 0;
        model2_Ramp_step_ = 10;
    }
    bool model2_Ramp_prefire(struct AtomicActor* actor) {
        return true;
    }
    #ifdef __cplusplus
}
#endif
void model2_Ramp_fire(struct AtomicActor* actor) {
    (*(output->send))((struct IOPort*) output, 0, Int_new(model2_Ramp__state));
    if (false) {
        model2_Ramp_step_ = Int_new(0)->payload.Int;
    }
    model2_Ramp__state += (int)model2_Ramp_step_;
}
#ifdef __cplusplus
extern "C" {
    #endif
    bool model2_Ramp_postfire(struct AtomicActor* actor) {
        return true;
    }
    void model2_Ramp_wrapup(struct AtomicActor* actor) {
    }
    #ifdef __cplusplus
}
#endif
