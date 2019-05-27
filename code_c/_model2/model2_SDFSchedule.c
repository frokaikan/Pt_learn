#include "model2.h"
void model2_Schedule_iterate() {
#ifdef _debugging
    fprintf(stderr, "%s, line: %d:model2_Schedule_iterate(): Start\n", __FILE__, __LINE__);
#endif

(*(model2_Const->iterate))(model2_Const, 5);
(*(model2_Ramp->iterate))(model2_Ramp, 5);
(*(model2_AddSubtract->iterate))(model2_AddSubtract, 5);
(*(model2_Display->iterate))(model2_Display, 5);
#ifdef _debugging
    fprintf(stderr, "%s, line: %d:model2_Schedule_iterate(): Done!\n", __FILE__, __LINE__);
#endif
}
