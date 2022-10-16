#include "vector_string.h"
#include <stdbool.h>
#include <assert.h>
#define CAPACITY_SIZE 20

STRINGVECTOR* StringVector_Init(){
	STRINGVECTOR* newvector = (STRINGVECTOR*)malloc(sizeof(STRINGVECTOR));

	newvector->size = 0;
	newvector->capacity = CAPACITY_SIZE;
	newvector->pData =(char**) malloc(sizeof(char*) * CAPACITY_SIZE);
	return newvector;
}

STRINGVECTOR* StringVector_InitByPtr(char** pData, int p_size){
    STRINGVECTOR* newvector = (STRINGVECTOR*)malloc(sizeof(STRINGVECTOR));
	newvector->size = p_size;

	newvector->capacity = CAPACITY_SIZE * (p_size/CAPACITY_SIZE + 1);
	newvector->pData = pData;
	return newvector;
}

void StringVector_PushBack(STRINGVECTOR* vec, char* val){
	assert(vec != NULL);
    _StringVector_ExpandCheck(vec);
    vec->pData[vec->size] = val;
	vec->size ++;
}

void StringVector_Insert(STRINGVECTOR* vec, char* val, int pos){
    assert(vec != NULL);
    _StringVector_ExpandCheck(vec);
    for(int i = vec->size; i > pos; i--){
		vec->pData[i] = vec->pData[i-1];
	}
	vec->pData[pos] = val;
	vec->size ++;
}

void StringVector_RemoveByPos(STRINGVECTOR* vec, int pos){
	assert(vec != NULL);
	assert(pos >= 0 || pos <= vec->size);
	free(vec->pData[pos]);
	for (int i = pos; i < vec->size-1; i++) {
		vec->pData[i] = vec->pData[i + 1];
	}
	vec->size--;    
}

void StringVector_RemoveByVal(STRINGVECTOR* vec, char* val){
	assert(vec != NULL);
	int pos = StringVector_FindValue(vec, val);
	while(pos > -1){
		StringVector_RemoveByPos(vec, pos);
		pos = StringVector_FindValue(vec, val);
	}    
}

int StringVector_FindValue(STRINGVECTOR* vec, char* val){
	assert(vec != NULL);
	for (int i = 0; i < vec->size; i++) {
		if (strcmp(vec->pData[i],val) == 0) {
			return i;
		}
	}
	return -1;    
}

void StringVector_UpdateValue(STRINGVECTOR* vec, int pos, char* val){
	assert(vec != NULL);
	assert(vec->size > pos);
	free(vec->pData[pos]);
	vec->pData[pos] = val;
}

int StringVector_GetSize(STRINGVECTOR* vec){
	assert(vec != NULL);
	return vec->size;
}

int StringVector_GetCapacity(STRINGVECTOR* vec){
	assert(vec != NULL);
	return vec->capacity;
}

void StringVector_Clear(STRINGVECTOR* vec){
	assert(vec != NULL);
	vec->size = 0;
}

void StringVector_Free(STRINGVECTOR* vec){
	assert(vec != NULL);
	assert(vec->pData != NULL);
	for(int i = 0; i < vec->size; ++i){
		free(vec->pData[i]);
	}
	free(vec->pData);
	free(vec);
}

/*Utils*/
void _StringVector_ExpandCheck(STRINGVECTOR* vec){
	if (vec->size == vec->capacity) {
		char** newSpace = (char**)malloc(sizeof(char*) * vec->capacity * 2);
		memcpy(newSpace, vec->pData, vec->size * sizeof(char*)); 
		free(vec->pData);
		vec->capacity *= 2;
		vec->pData = newSpace;
	}
}
