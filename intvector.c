#include "intvector.h"
#include <stdbool.h>
#include <assert.h>
#define CAPACITY_SIZE 20

INTVECTOR* IntVector_Init(){
	INTVECTOR* newvector = (INTVECTOR*)malloc(sizeof(INTVECTOR));

	newvector->size = 0;
	newvector->capacity = CAPACITY_SIZE;
	newvector->pData =(int*) malloc(sizeof(int) * CAPACITY_SIZE);
	return newvector;
}

INTVECTOR* IntVector_InitByPtr(int* pData, int p_size){
	INTVECTOR* newvector = (INTVECTOR*)malloc(sizeof(INTVECTOR));
	newvector->size = p_size;

	newvector->capacity = CAPACITY_SIZE * (p_size/CAPACITY_SIZE + 1);
	newvector->pData = pData;
	return newvector;
}

void IntVector_PushBack(INTVECTOR* vec, int val){
    assert(vec != NULL);
    _IntVector_ExpandCheck(vec);
    vec->pData[vec->size] = val;
	vec->size ++;
}

void IntVector_Insert(INTVECTOR* vec, int val, int pos){
    assert(vec != NULL);
    _IntVector_ExpandCheck(vec);
    for(int i = vec->size; i > pos; i--){
		vec->pData[i] = vec->pData[i-1];
	}
	vec->pData[pos] = val;
	vec->size ++;
}

void IntVector_RemoveByPos(INTVECTOR* vec, int pos){
    assert(vec != NULL);
	if (pos < 0 || pos >= vec->size) {
		return;
	}
	for (int i = pos; i < vec->size-1; i++) {
		vec->pData[i] = vec->pData[i + 1];
	}
	vec->size--;
}

void IntVector_RemoveByVal(INTVECTOR* vec, int val){
	assert(vec != NULL);
	int pos = IntVector_FindValue(vec, val);
	while(pos > -1){
		IntVector_RemoveByPos(vec, pos);
		pos = IntVector_FindValue(vec, val);
	}
}

int IntVector_FindValue(INTVECTOR* vec, int val){
	assert(vec != NULL);
	for (int i = 0; i < vec->size; i++) {
		if (vec->pData[i] == val) {
			return i;
		}
	}
	return -1;
}

void IntVector_UpdateValue(INTVECTOR* vec, int pos, int val){
	assert(vec != NULL);
	assert(vec->size > pos);
	vec->pData[pos] = val;
}

int IntVector_GetSize(INTVECTOR* vec){
	assert(vec != NULL);
	return vec->size;
}

int IntVector_GetCapacity(INTVECTOR* vec){
	assert(vec != NULL);
	return vec->capacity;
}

void IntVector_Clear(INTVECTOR* vec){
	assert(vec != NULL);
	vec->size = 0;
}

void IntVector_Free(INTVECTOR* vec){
	assert(vec != NULL);
	assert(vec->pData != NULL);
	free(vec->pData);
	free(vec);
}

/*Utils*/
void _IntVector_ExpandCheck(INTVECTOR* vec){
	if (vec->size == vec->capacity) {
		int* newSpace = (int*)malloc(sizeof(int) * vec->capacity * 2);
		memcpy(newSpace, vec->pData, vec->capacity * sizeof(int)); 
		free(vec->pData);
		vec->capacity *= 2;
		vec->pData = newSpace;
	}
}