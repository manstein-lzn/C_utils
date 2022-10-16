#include "exception.h"
#include <stdlib.h>
#include <stdio.h>

void normal_exception(char* info, char* func_name){
    printf("Error, function: %s, info: %s. \r\n", func_name, info);
    exit(1);
}

void param_exception(char* info, char* func_name){
    printf("Parameter error, function: %s, info: %s. \r\n", func_name, info);
    exit(1);
}

void normal_warning(char* info, char* func_name){
    printf("Warning, function: %s, info: %s. \r\n", func_name, info);
}

void param_warning(char* info, char* func_name){
    printf("Parameter warning, function: %s, info: %s. \r\n", func_name, info);
}