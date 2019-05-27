#include "model2_Main.h"
int main(int argc, char *argv[]) {
    //boolean completedSuccessfully = false;
    initialize();
    while (true) {
        if (!iterate()) {
            break;
        }
        //completedSuccessfully = true;
    }
    wrapup();
    exit(0);
}
void preinitialize() {
    emptyToken.type = -1;
    iterationCount = 0;
    model2_New();
    (*(model2->preinitialize))(model2);
}
void initialize(void) {
    preinitialize();
(*(model2->initialize))(model2);}
boolean iterate() {
    boolean result = true;
    iterationCount++;
    if ((*(model2->prefire))(model2)) {
        (*(model2->fire))(model2);
        result = (*(model2->postfire))(model2);
    }
    return result;
}
void wrapup(void) {
(*(model2->wrapup))(model2);}
