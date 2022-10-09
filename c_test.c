#include <stdio.h>
#include "intvector.h"
#include "floatvector.h"
int main(){
    /**************************************************/
    /*                 Vector test                    */
    /**************************************************/
    FLOATVECTOR* floatv = FloatVector_Init();
    //test pushback
    for(int i = 0; i < 10; i++){
        FloatVector_PushBack(floatv, i + 0.1);
    }
    printf("Vector after pushback: \n");
    for(int i = 0; i < floatv->size; i++){
        printf("index: %d, value: %f\n", i, floatv->pData[i]);
    }
    //test insert
    printf("Vector after insert: \n");
    FloatVector_Insert(floatv, (float)9.99, 0);
    FloatVector_Insert(floatv, (float)8.88, floatv->size);
    FloatVector_Insert(floatv, (float)9.99, 5);
    FloatVector_Insert(floatv, (float)6666.0, floatv->size);
    for(int i = 0; i < floatv->size; i++){
        printf("index: %d, value: %f\n", i, floatv->pData[i]);
    }
    //test remove bypos
    printf("Vector after remove bypos: \n");
    FloatVector_RemoveByPos(floatv, 13);
    FloatVector_RemoveByPos(floatv, 3);
    for(int i = 0; i < floatv->size; i++){
        printf("index: %d, value: %f\n", i, floatv->pData[i]);
    }
    //test remove byval
    printf("Vector after remove byval: \n");
    FloatVector_RemoveByVal(floatv, (float)9.99);
    FloatVector_RemoveByVal(floatv, (float)8.88);
    for(int i = 0; i < floatv->size; i++){
        printf("index: %d, value: %f\n", i, floatv->pData[i]);
    }
    //find value
    printf("find value: \n");
    int pos = FloatVector_FindValue(floatv, (float)0.10);
    printf("0.10 pos: %d \n", pos);
    pos = FloatVector_FindValue(floatv, (float)4.10);
    printf("4.10 pos: %d \n", pos);
    //update value
    printf("update value at 8 as 100.0: \n");
    FloatVector_UpdateValue(floatv, 8, (float)100.0);
    for(int i = 0; i < floatv->size; i++){
        printf("index: %d, value: %f\n", i, floatv->pData[i]);
    }
    //size and capacity check
    printf("FVector size: %d \n", FloatVector_GetSize(floatv));
    printf("FVector capacity: %d \n", FloatVector_GetCapacity(floatv));
    //vector free check
    FloatVector_Free(floatv);
}