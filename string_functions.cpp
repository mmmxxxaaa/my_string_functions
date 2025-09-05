#include "string_functions.h"

#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// +
size_t my_strlen_counter(const char* string)
{
    assert(string != NULL);

    size_t counter = 0;

    while (*string != '\0')
    {
        string++;
        counter++;
    }
    return counter;
}

// +
size_t my_strlen(const char* string)
{
    assert(string != NULL);

    const char* saved_pointer = string;

    while (*string != '\0')
        string++;

    size_t result = (size_t) (string - saved_pointer);  //FIXME - long int ???

    return result;
}
//----------------------------------------------------
// +
char* my_strcpy(char* copy_to, const char* copy_from) // возвращаем указатель на начало строки, куда скопировали
{
    assert(copy_to != NULL);
    assert(copy_from != NULL);

    char* saved_pointer = copy_to;
    while (*copy_from != '\0')
    {
        *copy_to = *copy_from;
        copy_to++;
        copy_from++;
    }
    *copy_to = '\0';

    return saved_pointer;
}

// +
char* my_strncpy(char* copy_to, const char* copy_from, size_t size) //возвращаем указатель на начало строки, куда скопировали
{
    assert(copy_to != NULL);
    assert(copy_from != NULL);

    size_t counter = 0;
    char* saved_pointer = copy_to;

    while ((*copy_from != '\0') && (*copy_to != '\0') && counter < size - 1)
    {
        *copy_to = *copy_from;
        copy_to++;
        copy_from++;
    }
    *copy_to = '\0';

    return saved_pointer;
}
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
// +
int my_strcmp(const char* string_1, const char* string_2)
{
    assert(string_1 != NULL);
    assert(string_2 != NULL);

    while (*string_1 && *string_1 == *string_2)
    {
        string_1++;
        string_2++;
    }
    if (*string_1 > *string_2)
        return 1;
    if (*string_1 < *string_2)
        return -1;
    return 0;
}

// +
int my_strncmp(const char* string_1, const char* string_2, size_t size)
{
    assert(string_1 != NULL);
    assert(string_2 != NULL);

    size_t counter = 0;

    while (*string_1 && *string_1 == *string_2 && counter < size - 1)
    {
        string_1++;
        string_2++;
        counter++;
    }
    if (*string_1 > *string_2)
        return 1;
    if (*string_1 < *string_2)
        return -1;
    return 0;
}
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
char* my_strcat(char* concat_to, const char* concat_what)
{
    assert(concat_to != NULL);
    assert(concat_what != NULL);

    char* saved_pointer = concat_to;

    size_t length = my_strlen(concat_to);
    concat_to += length;

    while (*concat_what != '\0')
    {
        *concat_to = *concat_what;
        concat_to++;
        concat_what++;
    }
    return saved_pointer;
}

// +
char* my_strncat(char* concat_to, char* concat_what, size_t size)
{
    assert(concat_to != NULL);
    assert(concat_what != NULL);

    char* saved_pointer = concat_to;
    size_t counter = 0;

    size_t length = my_strlen(concat_to);
    concat_to += length;

    while (*concat_what != '\0' && counter < size)
    {
        *concat_to = *concat_what;
        concat_to++;
        concat_what++;
        counter++;
    }
    return saved_pointer;
}

size_t my_puts(const char* string)
{
    return my_fputs(string, stdout);
}

size_t my_fputs(const char* string, FILE* filestream)
{
    assert(string != NULL);

    size_t counter = my_strlen(string);

    while (*string != '\0')
    {
        fputc(*string, filestream);
        string++;
    }

    fputc('\n', stdout);
    counter++;

    return counter;
}

char* my_fgets(char* string, int size, FILE* fp)
{
    assert(string != NULL);

    int symbol = 0;
    int i = 0;

    if (size <= 0)
        return string;

    while (i < size - 1 && ((symbol = getc(fp)) != EOF)) {
        string[i++] = symbol;
        if (symbol == '\n')
            break;
    }
    string[i] = '\0';

    if (i > 0)
        return string;

    return NULL;
}

// +
char* my_strchr(const char* string, int symbol)
{
    assert(string != NULL);

    while(*string != symbol && *string != '\0')
        string++;

    if (*string == '\0')
        return NULL;

    char* saved_string = (char*) string;

    return saved_string; //избавиться от конст чара
}

int my_atoi(const char* string)
{
    assert(string != NULL);

    int result = 0;
    int i = 0;

    for (i = 0; isspace(string[i]); i++)     //В КиР еще пробелы перед началом пропускают
        ;

    int sign = (string[i] == '-') ? -1 : 1;
    if (string[i] == '+' || string[i] == '-')
        i++;        //пропуск знака

    for (; isdigit(string[i]); ++i)
        result = 10 * result + (string[i] - '0');

    return sign * result;
}


char* my_strdup(const char* src)
{
    assert(src != NULL);

    size_t len = strlen(src) + 1;
    char* s = (char *) calloc(len, sizeof(src));
    if (s == NULL)
        return NULL;

    //писали, что через memcpy эффективнее, чем через strcpy
    return (char *) memcpy(s, src, len); //сама по себе memcpy возвращает void*, но для удобства лучше явно приводить
}


char* my_strstr(const char* search_in, const char* search_what)
{
    assert(search_in != NULL);
    assert(search_what != NULL);

    if (*search_what == '\0')
        return (char*) search_in;

    while (*search_in)
    {
        if (*search_in == *search_what)
        {
            const char* starting_in = search_in;
            const char* starting_what = search_what;

            while (*starting_in && *starting_what && *starting_what == *starting_in)
            {
                starting_in++;
                starting_what++;
            }

            if (*starting_what == '\0')
                return (char*) search_in; //без явного приведения ошибка
        }
        search_in++;
    }

    return NULL;
}

ssize_t my_getline(char *string, size_t size, FILE *stream)  //почему в оригинале size_t *n и **string
{
    if (stream == NULL || size == 0)
        return -1;

    int symbol = '\0';
    size_t i = 0;

    while (i < size - 1)
    {
        symbol = fgetc(stream);
        if (symbol == EOF)
            return -1;

        string[i++] = symbol;

        if (symbol == '\n')
            break;
    }

    string[i] = '\0'; //FIXME - закинуть на гитхаб   fseek B1.6

    return i;
}
