#ifdef __cplusplus
extern "C" {
    #endif
    #include "model2_Const.h"
    #ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
    #endif
    static struct TypedIOPort* output;
    void model2_Const_preinitialize(struct AtomicActor* actor);
    void model2_Const_initialize(struct AtomicActor* actor);
    bool model2_Const_prefire(struct AtomicActor* actor);
    void model2_Const_fire(struct AtomicActor* actor);
    bool model2_Const_postfire(struct AtomicActor* actor);
    void model2_Const_wrapup(struct AtomicActor* actor);
    struct AtomicActor* model2_Const_New() {
        struct AtomicActor* model2_Const = AtomicActor_New();
        #ifdef _debugging
        ((struct AtomicActor*)model2_Const)->setName((struct AtomicActor *)model2_Const, "Const");
        #endif
        model2_Const->container = model2;
        model2_Const->preinitialize = model2_Const_preinitialize;
        model2_Const->initialize = model2_Const_initialize;
        model2_Const->prefire = model2_Const_prefire;
        model2_Const->fire = model2_Const_fire;
        model2_Const->postfire = model2_Const_postfire;
        model2_Const->wrapup = model2_Const_wrapup;
        output = (struct TypedIOPort*)TypedIOPort_New();
        #ifdef _debugging
        output->setName((struct IOPort*)output, "output");
        #endif
        output->container = (struct Actor*)model2_Const;
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
        pblListAdd(model2_Const->_outputPorts, output);
        PblList* output__0 = pblListNewArrayList();
        pblListAdd(output->_farReceivers, output__0);
        return model2_Const;
    }
    struct IOPort* model2_Const_get_output() {
        return (struct IOPort*) output;
    }
    void model2_Const_preinitialize(struct AtomicActor* actor) {
    }
    void model2_Const_initialize(struct AtomicActor* actor) {
    }
    bool model2_Const_prefire(struct AtomicActor* actor) {
        return true;
    }
    #ifdef __cplusplus
}
#endif
void model2_Const_fire(struct AtomicActor* actor) {
    (*(output->send))((struct IOPort*) output, 0, Int_new(10));
}
#ifdef __cplusplus
extern "C" {
    #endif
    bool model2_Const_postfire(struct AtomicActor* actor) {
        return true;
    }
    void model2_Const_wrapup(struct AtomicActor* actor) {
    }
    #ifdef __cplusplus
}
#endif
