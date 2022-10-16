#ifndef  INTVECTOR_H
#define INTVECTOR_H
#include<stdlib.h>
#include <string.h>

typedef struct{
    int* pData; //data pointer
    int size; //current valid data size
    int capacity; //current data pointer size
} INTVECTOR;

/**
* @brief Int Vector initialization
* @param 
* @return INTVECTOR*
*/
INTVECTOR* IntVector_Init();

/**
* @brief Int Vector initialization with exist
* @param int* pData, int p_size
* @return INTVECTOR*
*/
INTVECTOR* IntVector_InitByPtr(int* pData, int p_size);

/**************************************************/
/*               Add and Remove value             */
/**************************************************/
/**
* @brief push back int value
* @param INTVECTOR*, int value
* @return 
*/
void IntVector_PushBack(INTVECTOR* vec, int val);

/**
* @brief insert int value to int position
* @param INTVECTOR*, int value, int position
* @return 
*/
void IntVector_Insert(INTVECTOR* vec, int val, int pos);

/**
* @brief delete value by position
* @param INTVECTOR*, int position
* @return 
*/
void IntVector_RemoveByPos(INTVECTOR* vec, int pos);

/**
* @brief delete all vector data by value
* @param INTVECTOR*, int value
* @return 
*/
void IntVector_RemoveByVal(INTVECTOR* vec, int val);

/**************************************************/
/*            Find and Update Value               */
/**************************************************/
/**
* @brief get first position of int value
* @param INTVECTOR*, int value
* @return if found return int posiiton, else -1
*/
int IntVector_FindValue(INTVECTOR* vec, int val);

/**
* @brief update data by position and velue
* @param INTVECTOR*, int position, int value
* @return if found return int posiiton, else -1
*/
void IntVector_UpdateValue(INTVECTOR* vec, int pos, int val);

/**************************************************/
/*            Get IntVecotor params               */
/**************************************************/
/**
* @brief get vector size
* @param INTVECTOR*
* @return vector size
*/
int IntVector_GetSize(INTVECTOR* vec);

/**
* @brief get vector capacity
* @param INTVECTOR*
* @return vector capacity
*/
int IntVector_GetCapacity(INTVECTOR* vec);

/**************************************************/
/*             Clear and Free Space               */
/**************************************************/
/**
* @brief Int Vector clear, reset vector size, keep capacity
* @param INTVECTOR* to be clear
* @return 
*/
void IntVector_Clear(INTVECTOR* vec);

/**
* @brief Int Vector destruction, free struct&pData memory space
* @param INTVECTOR* to be freed
* @return 
*/
void IntVector_Free(INTVECTOR* vec);

/**************************************************/
/*                     Utils                      */
/**************************************************/
/**
* @brief if size=capacity, expand data ptr 
* @param INTVECTOR* to check
* @return
*/
void _IntVector_ExpandCheck(INTVECTOR* vec);

#endif // ! INTVECTOR_H