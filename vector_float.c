#include "vector_float.h"
#include <stdbool.h>
#include <assert.h>
#define CAPACITY_SIZE 20

FLOATVECTOR* FloatVector_Init(){
	FLOATVECTOR* newvector = (FLOATVECTOR*)malloc(sizeof(FLOATVECTOR));

	newvector->size = 0;
	newvector->capacity = CAPACITY_SIZE;
	newvector->pData =(float*) malloc(sizeof(float) * CAPACITY_SIZE);
	return newvector;
}

FLOATVECTOR* FloatVector_InitByPtr(float* pData, int p_size){
    FLOATVECTOR* newvector = (FLOATVECTOR*)malloc(sizeof(FLOATVECTOR));
	newvector->size = p_size;

	newvector->capacity = CAPACITY_SIZE * (p_size/CAPACITY_SIZE + 1);
	newvector->pData = pData;
	return newvector;
}

void FloatVector_PushBack(FLOATVECTOR* vec, float val){
    assert(vec != NULL);
    _FloatVector_ExpandCheck(vec);
    vec->pData[vec->size] = val;
	vec->size ++;
}

void FloatVector_Insert(FLOATVECTOR* vec, float val, int pos){
    assert(vec != NULL);
    _FloatVector_ExpandCheck(vec);
    for(int i = vec->size; i > pos; i--){
		vec->pData[i] = vec->pData[i-1];
	}
	vec->pData[pos] = val;
	vec->size ++;
}

void FloatVector_RemoveByPos(FLOATVECTOR* vec, int pos){
    assert(vec != NULL);
	assert(pos >= 0 || pos <= vec->size);
	for (int i = pos; i < vec->size-1; i++) {
		vec->pData[i] = vec->pData[i + 1];
	}
	vec->size--;    
}

void FloatVector_RemoveByVal(FLOATVECTOR* vec, float val){
	assert(vec != NULL);
	int pos = FloatVector_FindValue(vec, val);
	while(pos > -1){
		FloatVector_RemoveByPos(vec, pos);
		pos = FloatVector_FindValue(vec, val);
	}    
}

int FloatVector_FindValue(FLOATVECTOR* vec, float val){
	assert(vec != NULL);
	for (int i = 0; i < vec->size; i++) {
		if (vec->pData[i] == val) {
			return i;
		}
	}
	return -1;    
}

void FloatVector_UpdateValue(FLOATVECTOR* vec, int pos, float val){
	assert(vec != NULL);
	assert(vec->size > pos);
	vec->pData[pos] = val;
}

int FloatVector_GetSize(FLOATVECTOR* vec){
	assert(vec != NULL);
	return vec->size;
}

int FloatVector_GetCapacity(FLOATVECTOR* vec){
	assert(vec != NULL);
	return vec->capacity;
}

void FloatVector_Clear(FLOATVECTOR* vec){
	assert(vec != NULL);
	vec->size = 0;
}

void FloatVector_Free(FLOATVECTOR* vec){
	assert(vec != NULL);
	assert(vec->pData != NULL);
	free(vec->pData);
	free(vec);
}

/*Utils*/
void _FloatVector_ExpandCheck(FLOATVECTOR* vec){
	if (vec->size == vec->capacity) {
		float* newSpace = (float*)malloc(sizeof(float) * vec->capacity * 2);
		memcpy(newSpace, vec->pData, vec->size * sizeof(float)); 
		free(vec->pData);
		vec->capacity *= 2;
		vec->pData = newSpace;
	}
}