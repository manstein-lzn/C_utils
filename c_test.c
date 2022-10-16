#include <stdio.h>
#include "vector_int.h"
#include "vector_float.h"
#include "vector_string.h"
#include "ptr_vector.h"
int main(){
    /**************************************************/
    /*         FloatVector test (passed)              */
    /**************************************************/
    // FLOATVECTOR* floatv = FloatVector_Init();
    // //test pushback
    // for(int i = 0; i < 10; i++){
    //     FloatVector_PushBack(floatv, i + 0.1);
    // }
    // printf("Vector after pushback: \n");
    // for(int i = 0; i < floatv->size; i++){
    //     printf("index: %d, value: %f\n", i, floatv->pData[i]);
    // }
    // //test insert
    // printf("Vector after insert: \n");
    // FloatVector_Insert(floatv, (float)9.99, 0);
    // FloatVector_Insert(floatv, (float)8.88, floatv->size);
    // FloatVector_Insert(floatv, (float)9.99, 5);
    // FloatVector_Insert(floatv, (float)6666.0, floatv->size);
    // for(int i = 0; i < floatv->size; i++){
    //     printf("index: %d, value: %f\n", i, floatv->pData[i]);
    // }
    // //test remove bypos
    // printf("Vector after remove bypos: \n");
    // FloatVector_RemoveByPos(floatv, 13);
    // FloatVector_RemoveByPos(floatv, 3);
    // for(int i = 0; i < floatv->size; i++){
    //     printf("index: %d, value: %f\n", i, floatv->pData[i]);
    // }
    // //test remove byval
    // printf("Vector after remove byval: \n");
    // FloatVector_RemoveByVal(floatv, (float)9.99);
    // FloatVector_RemoveByVal(floatv, (float)8.88);
    // for(int i = 0; i < floatv->size; i++){
    //     printf("index: %d, value: %f\n", i, floatv->pData[i]);
    // }
    // //find value
    // printf("find value: \n");
    // int pos = FloatVector_FindValue(floatv, (float)0.10);
    // printf("0.10 pos: %d \n", pos);
    // pos = FloatVector_FindValue(floatv, (float)4.10);
    // printf("4.10 pos: %d \n", pos);
    // //update value
    // printf("update value at 8 as 100.0: \n");
    // FloatVector_UpdateValue(floatv, 8, (float)100.0);
    // for(int i = 0; i < floatv->size; i++){
    //     printf("index: %d, value: %f\n", i, floatv->pData[i]);
    // }
    // //size and capacity check
    // printf("FVector size: %d \n", FloatVector_GetSize(floatv));
    // printf("FVector capacity: %d \n", FloatVector_GetCapacity(floatv));
    // //vector free check
    // FloatVector_Free(floatv);

    /**************************************************/
    /*       StringVector test (passed)               */
    /**************************************************/
    STRINGVECTOR* sv = StringVector_Init();
    StringVector_PushBack(sv, "value0");
    StringVector_PushBack(sv, "value1");
    StringVector_PushBack(sv, "value2");
    StringVector_PushBack(sv, "value4");
    StringVector_PushBack(sv, "value5");
    StringVector_PushBack(sv, "value6");
    StringVector_PushBack(sv, "value7");
    StringVector_PushBack(sv, "value8");
    StringVector_PushBack(sv, "value9");

    StringVector_Insert(sv, "value3", 3);

    StringVector_RemoveByPos(sv, 8);

    StringVector_RemoveByVal(sv, "value9");

    StringVector_UpdateValue(sv, 7, "value_update7");

    StringVector_PushBack(sv, "value_todel");

    StringVector_PushBack(sv, "value_todel");

    StringVector_PushBack(sv, "value_nottodel");

    StringVector_RemoveByVal(sv, "value_todel");

    for(int i = 0; i < sv->size; ++i){
        printf("%s\n", sv->pData[i]);
    }
    printf("StringVector size: %d\n", sv->size);
    printf("StringVector capacity: %d\n", sv->capacity);

    StringVector_Free(sv);

    /**************************************************/
    /*                 Vector test                    */
    /**************************************************/
    //create vector<floatvector>
    PTRVECTOR* ptrv = PtrVector_Init("float");
    for(int i = 0; i < 10; ++i){
        FLOATVECTOR* floatv = FloatVector_Init();
        for(int j = 0; j < 10; ++j){
            FloatVector_PushBack(floatv, i + 0.1);
        }
        PtrVector_PushBack(ptrv, (PTR)floatv);        
    }
    //check
    for(int i = 0; i < 10; ++i){
        FLOATVECTOR* floatv = (FLOATVECTOR*)ptrv->pData[i];
        printf("ptrvector[%d]->pdata[%d] = %f \r\n", i, i, floatv->pData[i]);
        FloatVector_Free(floatv);
    }
    printf("Ptr vector data type: %s\r\n", ptrv->dType);
    PtrVector_Free(ptrv);
}