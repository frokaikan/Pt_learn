#ifdef __cplusplus
extern "C" {
    #endif
    #include "model2_Display.h"
    #ifdef __cplusplus
}
#endif
#ifdef __cplusplus
extern "C" {
    #endif
    static struct TypedIOPort* input;
    void model2_Display_preinitialize(struct AtomicActor* actor);
    void model2_Display_initialize(struct AtomicActor* actor);
    bool model2_Display_prefire(struct AtomicActor* actor);
    void model2_Display_fire(struct AtomicActor* actor);
    bool model2_Display_postfire(struct AtomicActor* actor);
    void model2_Display_wrapup(struct AtomicActor* actor);
    struct AtomicActor* model2_Display_New() {
        struct AtomicActor* model2_Display = AtomicActor_New();
        #ifdef _debugging
        ((struct AtomicActor*)model2_Display)->setName((struct AtomicActor *)model2_Display, "Display");
        #endif
        model2_Display->container = model2;
        model2_Display->preinitialize = model2_Display_preinitialize;
        model2_Display->initialize = model2_Display_initialize;
        model2_Display->prefire = model2_Display_prefire;
        model2_Display->fire = model2_Display_fire;
        model2_Display->postfire = model2_Display_postfire;
        model2_Display->wrapup = model2_Display_wrapup;
        input = (struct TypedIOPort*)TypedIOPort_New();
        #ifdef _debugging
        input->setName((struct IOPort*)input, "input");
        #endif
        input->container = (struct Actor*)model2_Display;
        input->_isInsideConnected = false;
        input->_isOutsideConnected = true;
        input->_isInput = true;
        input->_isOutput = false;
        input->_isMultiport = true;
        input->_width = 1;
        input->_insideWidth = 0;
        input->_numberOfSinks = 0;
        input->_numberOfSources = 1;
        input->_type = TYPE_Int;
        pblListAdd(model2_Display->_inputPorts, input);
        PblList* input_0 = pblListNewArrayList();
        struct SDFReceiver* input_0_0 = SDFReceiver_New();
        input_0_0->container = (struct IOPort*)input;
        pblListAdd(input_0, input_0_0);
        pblListAdd(input->_localReceivers , input_0);
        return model2_Display;
    }
    struct IOPort* model2_Display_get_input() {
        return (struct IOPort*) input;
    }
    void model2_Display_preinitialize(struct AtomicActor* actor) {
    }
    void model2_Display_initialize(struct AtomicActor* actor) {
    }
    bool model2_Display_prefire(struct AtomicActor* actor) {
        return true;
    }
    #ifdef __cplusplus
}
#endif
void model2_Display_fire(struct AtomicActor* actor) {
    if ((*(input->hasToken))((struct IOPort*) input, 0)) {
        printf("%d\n", (*(input->get))((struct IOPort*) input, 0)->payload.Int);
    }
}
#ifdef __cplusplus
extern "C" {
    #endif
    bool model2_Display_postfire(struct AtomicActor* actor) {
        return true;
    }
    void model2_Display_wrapup(struct AtomicActor* actor) {
    }
    #ifdef __cplusplus
}
#endif
