#ifndef  STRINGVECTOR_H
#define INTVECTOR_H
#include<stdlib.h>
#include <string.h>

typedef struct{
    int* pData; //data pointer
    int size; //current valid data size
    int capacity; //current data pointer size
} STRINGVECTOR;


#endif // ! STRINGVECTOR_H