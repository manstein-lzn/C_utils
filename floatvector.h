#ifndef  FLOATVECTOR_H  //防止头文件被重复调用
#define FLOATVECTOR_H
#include<stdlib.h>
#include <string.h>

typedef struct{
    float* pData; //data pointer
    int size; //current valid data size
    int capacity; //current data pointer size
} FLOATVECTOR;

/**
* @brief Float Vector initialization
* @param 
* @return FLOATVECTOR*
*/
FLOATVECTOR* FloatVector_Init();

/**
* @brief Float Vector initialization with exist
* @param float* pData, int p_size
* @return FLOATVECTOR*
*/
FLOATVECTOR* FloatVector_InitByPtr(float* pData, int p_size);

/**************************************************/
/*               Add and Remove value             */
/**************************************************/
/**
* @brief push back float value
* @param FLOATVECTOR*, float value
* @return 
*/
void FloatVector_PushBack(FLOATVECTOR* vec, float val);

/**
* @brief insert float value to int position
* @param FLOATVECTOR*, float value, int position
* @return 
*/
void FloatVector_Insert(FLOATVECTOR* vec, float val, int pos);

/**
* @brief delete value by position
* @param FLOATVECTOR*, int position
* @return 
*/
void FloatVector_RemoveByPos(FLOATVECTOR* vec, int pos);

/**
* @brief delete all vector data by value
* @param FLOATVECTOR*, float value
* @return 
*/
void FloatVector_RemoveByVal(FLOATVECTOR* vec, float val);

/**************************************************/
/*            Find and Update Value               */
/**************************************************/
/**
* @brief get first position of float value
* @param FLOATVECTOR*, float value
* @return if found return int posiiton, else -1
*/
int FloatVector_FindValue(FLOATVECTOR* vec, float val);

/**
* @brief update data by position and velue
* @param FLOATVECTOR*, int position, float value
* @return if found return int posiiton, else -1
*/
void FloatVector_UpdateValue(FLOATVECTOR* vec, int pos, float val);

/**************************************************/
/*            Get IntVecotor params               */
/**************************************************/
/**
* @brief get vector size
* @param FLOATVECTOR*
* @return vector size
*/
int FloatVector_GetSize(FLOATVECTOR* vec);

/**
* @brief get vector capacity
* @param FLOATVECTOR*
* @return vector capacity
*/
int FloatVector_GetCapacity(FLOATVECTOR* vec);

/**************************************************/
/*             Clear and Free Space               */
/**************************************************/
/**
* @brief Int Vector clear, reset vector size, keep capacity
* @param FLOATVECTOR* to be clear
* @return 
*/
void FloatVector_Clear(FLOATVECTOR* vec);

/**
* @brief Int Vector destruction, free struct&pData memory space
* @param FLOATVECTOR* to be freed
* @return 
*/
void FloatVector_Free(FLOATVECTOR* vec);

/**************************************************/
/*                     Utils                      */
/**************************************************/
/**
* @brief if size=capacity, expand data ptr 
* @param FLOATVECTOR* to check
* @return
*/
void _FloatVector_ExpandCheck(FLOATVECTOR* vec);

#endif // ! FLOATVECTOR_H