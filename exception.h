#ifndef EXCEPTION_H
#define EXCEPTION_H

void normal_exception(char* info, char* func_name);

void param_exception(char* info, char* func_name);

void normal_warning(char* info, char* func_name);

void param_warning(char* info, char* func_name);

#endif // ! EXCEPTION_H