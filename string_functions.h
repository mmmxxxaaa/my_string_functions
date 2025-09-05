#ifndef STRING_FUNCTIONS_H_
#define STRING_FUNCTIONS_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

/*getline*/

size_t my_strlen(const char* string);
size_t my_strlen_counter(const char* string);
//--------------------------------------------------------------------------
char* my_strcpy(char* copy_to, const char* copy_from);

char* my_strncpy(char* copy_to, const char* copy_from, size_t size);
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
int my_strcmp(const char* string_1, const char* string_2);

int my_strncmp(const char* string_1, const char* string_2, size_t size);
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
char* my_strcat(char* concat_to, const char* concat_what);

char* my_strncat(char* concat_to, char* concat_what, size_t size);        //FIXME (почему в ориге нет конст перед concat_what)
//--------------------------------------------------------------------------

size_t my_puts(const char* string);

size_t my_fputs(const char* string, FILE* filestream);

char* my_fgets(char* string, int size, FILE* filename);

char* my_strchr(const char* string, int symbol);

int my_atoi(const char* string);

char* my_strdup(const char* src);

char* my_strstr(const char* string1, const char* string2);

ssize_t my_getline(char *string, size_t size, FILE *stream);


#endif //STRING_FUNCTIONS_H_
