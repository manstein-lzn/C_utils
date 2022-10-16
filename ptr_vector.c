#include "ptr_vector.h"

//utils
void _PtrVector_ExpandCheck(PTRVECTOR* vec){
    if (vec->size == vec->capacity) {
		PTR* newSpace = (PTR*)malloc(sizeof(PTR) * vec->capacity * 2);
		memcpy(newSpace, vec->pData, vec->size * sizeof(int)); 
		free(vec->pData);
		vec->capacity *= 2;
		vec->pData = newSpace;
	}
}

//implementation
PTRVECTOR* PtrVector_Init(const char* ptr_type){
	PTRVECTOR* newvector = (PTRVECTOR*)malloc(sizeof(PTRVECTOR));

	newvector->size = 0;
	newvector->capacity = PTRVEC_initCAPACITY;
	newvector->pData =(PTR*) malloc(sizeof(PTR) * PTRVEC_initCAPACITY);
	newvector->dType = ptr_type;
	return newvector;
}

void PtrVector_PushBack(PTRVECTOR* vec, PTR val){
    if(vec == NULL){
        param_exception("PTRVECTOR* is NULL", "PtrVector_PushBack");
    }
    if(val == NULL){
        param_exception("PTR is NULL", "PtrVector_PushBack");
    }

    _PtrVector_ExpandCheck(vec);
    vec->pData[vec->size] = val;
	vec->size ++;
}

void PtrVector_Insert(PTRVECTOR* vec, PTR val, int pos){
    if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_Insert");
    if(pos > vec->size - 1) param_exception("pos out of vector range", "PtrVector_Insert");

    _PtrVector_ExpandCheck(vec);
    for(int i = vec->size; i > pos; i--){
		vec->pData[i] = vec->pData[i-1];
	}
	vec->pData[pos] = val;
	vec->size ++;
}

void PtrVector_RemoveByPos(PTRVECTOR* vec, int pos){
    if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_RemoveByPos");
    if(pos > vec->size - 1 ) param_exception("pos out of vector range", "PtrVector_RemoveByPos");

    for (int i = pos; i < vec->size-1; i++) {
		vec->pData[i] = vec->pData[i + 1];
	}
	vec->size--;
}

int PtrVector_FindValue(PTRVECTOR* vec, PTR val){
    if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_FindValue");

	for (int i = 0; i < vec->size; i++) {
		if (vec->pData[i] == val) {
			return i;
		}
	}
	return -1;
}

void PtrVector_UpdateValue(PTRVECTOR* vec, int pos, PTR val){
    if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_UpdateValue");
    if(pos > vec->size - 1 ) param_exception("pos out of vector range", "PtrVector_UpdateValue");

	vec->pData[pos] = val;
}

int PtrVector_GetSize(PTRVECTOR* vec){
    if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_GetSize");
	return vec->size;
}

int PtrVector_GetCapacity(PTRVECTOR* vec){
    if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_GetSize");
	return vec->capacity;
}

const char* PtrVector_GetType(PTRVECTOR* vec){
	if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_GetSize");
	return vec->dType;
}

void PtrVector_Clear(PTRVECTOR* vec){
    if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_Clear");
	vec->size = 0;
}

void PtrVector_Free(PTRVECTOR* vec){
    if(vec == NULL) param_exception("PTRVECTOR* is NULL", "PtrVector_Free");
	if(vec->pData == NULL) normal_exception("vec->pData is NULL", "PtrVector_Free");
	free(vec->pData);
	free((char*)vec->dType);
	free(vec);
}