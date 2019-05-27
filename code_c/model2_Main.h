#ifndef NO_MODEL2_MAIN_H
#define NO_MODEL2_MAIN_H
#include "model2.h"
static int iterationCount;
void preinitialize();
void initialize(void);
boolean iterate();
void wrapup(void);
#endif
