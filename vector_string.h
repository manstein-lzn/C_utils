#ifndef  STRINGVECTOR_H  //防止头文件被重复调用
#define STRINGVECTOR_H
#include<stdlib.h>
#include <string.h>

typedef struct{
    char** pData;
    int size;
    int capacity;
} STRINGVECTOR;

/**
* @brief String Vector initialization
* @param 
* @return STRINGVECTOR*
*/
STRINGVECTOR* StringVector_Init();

/**
* @brief String Vector initialization with existing data pointer
* @param float* pData, int p_size
* @return STRINGVECTOR*
*/
STRINGVECTOR* StringVector_InitByPtr(char** pData, int p_size);

/**************************************************/
/*               Add and Remove value             */
/**************************************************/
/**
* @brief push back string(char*) value
* @param STRINGVECTOR*, char* value
* @return 
*/
void StringVector_PushBack(STRINGVECTOR* vec, char* val);

/**
* @brief insert string(char*) value to int position
* @param STRINGVECTOR*, string(char*) value, int position
* @return 
*/
void StringVector_Insert(STRINGVECTOR* vec, char* val, int pos);

/**
* @brief delete value by position
* @param STRINGVECTOR*, int position
* @return 
*/
void StringVector_RemoveByPos(STRINGVECTOR* vec, int pos);

/**
* @brief delete all vector data by value
* @param STRINGVECTOR*, char* value
* @return 
*/
void StringVector_RemoveByVal(STRINGVECTOR* vec, char* val);

/**************************************************/
/*            Find and Update Value               */
/**************************************************/
/**
* @brief get first position of char* value
* @param STRINGVECTOR*, char* value
* @return if found return int posiiton, else -1
*/
int StringVector_FindValue(STRINGVECTOR* vec, char* val);

/**
* @brief update data by position and velue
* @param STRINGVECTOR*, int position, char* value
* @return if found return int posiiton, else -1
*/
void StringVector_UpdateValue(STRINGVECTOR* vec, int pos, char* val);

/**************************************************/
/*            Get StringVecotor params               */
/**************************************************/
/**
* @brief get vector size
* @param STRINGVECTOR*
* @return vector size
*/
int StringVector_GetSize(STRINGVECTOR* vec);

/**
* @brief get vector capacity
* @param STRINGVECTOR*
* @return vector capacity
*/
int StringVector_GetCapacity(STRINGVECTOR* vec);

/**************************************************/
/*             Clear and Free Space               */
/**************************************************/
/**
* @brief String Vector clear, reset vector size, keep capacity
* @param STRINGVECTOR* to be clear
* @return 
*/
void StringVector_Clear(STRINGVECTOR* vec);

/**
* @brief String Vector destruction, free struct&pData memory space
* @param STRINGVECTOR* to be freed
* @return 
*/
void StringVector_Free(STRINGVECTOR* vec);

/**************************************************/
/*                     Utils                      */
/**************************************************/
/**
* @brief if size=capacity, expand data ptr 
* @param STRINGVECTOR* to check
* @return
*/
void _StringVector_ExpandCheck(STRINGVECTOR* vec);

#endif // ! STRINGVECTOR_H