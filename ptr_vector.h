#ifndef PTRVECTOR_H
#define PTRVECTOR_H

#include <stdlib.h>
#include <string.h>
#include "exception.h"

//default PTRVECTOR init capacity, PTRVECTOR allocates memory space in terms of PTRVEC_initCAPACITY*2^n at n th expanding
#define PTRVEC_initCAPACITY 20

/*
Guide Warning:
1. since different data structure ptr takes up same number of bytes, PTRVECTOR use void** to save ptrs, 
   user should    CAST BACK    returned ptr manualy when visit ptr data in PTRVECTOR
2. PtrVector_Free() doesn't(can't) free PTRs in pData
*/
#define PTR void*

typedef struct{
    PTR* pData;       //ptr data ptr
    int  size;        //current valid data size
    int  capacity;    //current data pointer size
} PTRVECTOR;

/**************************************************/
/*                     Init                       */
/**************************************************/
/**
* @brief Prt Vector initialization
* @param 
* @return PTRVECTOR*
*/
PTRVECTOR* PtrVector_Init();

/**************************************************/
/*               Add and Remove value             */
/**************************************************/
/**
* @brief push back PTR value
* @param PTRVECTOR*, PTR value
* @return 
*/
void PtrVector_PushBack(PTRVECTOR* vec, PTR val);

/**
* @brief insert PTR value to int position
* @param INTVECTOR*, PTR value, int position
* @return 
*/
void PtrVector_Insert(PTRVECTOR* vec, PTR val, int pos);

/**
* @brief delete value by position
* @param PTRVECTOR*, int position
* @return 
*/
void PtrVector_RemoveByPos(PTRVECTOR* vec, int pos);

/**************************************************/
/*            Find and Update Value               */
/**************************************************/
/**
* @brief get first position of PTR value
* @param PTRVECTOR*, int value
* @return if found return int posiiton, else -1
*/
int PtrVector_FindValue(PTRVECTOR* vec, PTR val);

/**
* @brief update data by position and velue
* @param PTRVECTOR*, int position, PTR value
* @return if found return int posiiton, else -1
*/
void PtrVector_UpdateValue(PTRVECTOR* vec, int pos, PTR val);

/**************************************************/
/*            Get IntVecotor params               */
/**************************************************/
/**
* @brief get vector size
* @param PTRVECTOR*
* @return vector size
*/
int PtrVector_GetSize(PTRVECTOR* vec);

/**
* @brief get vector capacity
* @param PTRVECTOR*
* @return vector capacity
*/
int PtrVector_GetCapacity(PTRVECTOR* vec);

/**************************************************/
/*             Clear and Free Space               */
/**************************************************/
/**
* @brief Ptr Vector clear, reset vector size, keep capacity
* @param PTRVECTOR* to be clear
* @return 
*/
void PtrVector_Clear(PTRVECTOR* vec);

/**
* @brief Ptr Vector destruction, free struct&pData memory space
* @param PTRVECTOR* to be freed
* @return 
*/
void PtrVector_Free(PTRVECTOR* vec);

#endif // ! PTRVECTOR_H