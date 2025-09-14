#include "string_functions.h"

#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "logic_functions.h"

const int first_buffer_size = 256;
const int grow_buffer_coefficient = 2;


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

    while ((*copy_from != '\0') && counter < size - 1)
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

    while (*string_1 != '\0' && *string_1 == *string_2)
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

    while (*string_1 != '\0' && *string_1 == *string_2 && counter < size - 1)
    {
        string_1++;
        string_2++;
        counter++;
    }
    if (*string_1 > *string_2) //разность str2 - str1 //FIXME
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

    my_strcpy(concat_to, concat_what);

    return saved_pointer;
}

// +
char* my_strncat(char* concat_to, const char* concat_what, size_t size) //FIXME спросить у Деда про const
{
    assert(concat_to != NULL);
    assert(concat_what != NULL);

    char* saved_pointer = concat_to;
    //size_t counter = 0;

    size_t length = my_strlen(concat_to);

    if (length >= size)     //FIXME еще такую проверку добавил
        return saved_pointer;

    concat_to += length;
    my_strncpy(concat_to, concat_what, size - length);

    return saved_pointer;
}

int my_puts(const char* string)
{
    int result = my_fputs(string, stdout);

    fputc('\n', stdout);
    result++;

    return result;
}

int my_fputs(const char* string, FILE* stream)
{
    assert(string != NULL);
    assert(stream != NULL);

    size_t counter = my_strlen(string);

    while (*string != '\0')
    {
        if (fputc(*string, stream) == EOF)
            return EOF;
        string++;
    }

    return counter;
}

char* my_fgets(char* string, int size, FILE* stream)
{
    assert(string != NULL);
    assert(stream != NULL);

    int symbol = 0;
    int i = 0;

    if (size <= 0)
        return string;

    while (i < size - 1 && ((symbol = getc(stream)) != EOF))
    {
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
char* my_strchr(const char* string, int symbol) // FIXME is_symbol + const cast ptr
{
    assert(string != NULL);
    assert(is_symbol(symbol));

    while(*string != symbol && *string != '\0')
        string++;

    if (symbol == '\0')
        return const_kostyl_suka(string);

    if (*string == '\0')
        return NULL;

    char* saved_string = const_kostyl_suka(string);

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

    for (; is_digit(string[i]); ++i)
        result = 10 * result + (string[i] - '0');

    return sign * result;
}


char* my_strdup(const char* src)
{
    assert(src != NULL);

    size_t len = my_strlen(src) + 1;
    char* s = (char *) calloc(len, sizeof(*src));
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
        return const_kostyl_suka(search_in);

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
                return const_kostyl_suka(search_in); //без явного приведения ошибка
        }
        search_in++;
    }

    return NULL;
}

ssize_t my_getline(char** ptr_string, size_t* ptr_size, FILE* stream)
{
    if (ptr_string == NULL || ptr_size == NULL || stream == NULL)
        return -1;

    char* buffer = *ptr_string;
    size_t size = *ptr_size;

    if  (buffer == NULL)
    {
        size = first_buffer_size;
        buffer = (char*) calloc(size, sizeof(char));
        if (buffer == NULL)
            return -1;
    }
    else
    {
        if (size == 0)
            return -1;
    }


    size_t length = 0;
    int symbol = '\0';

    while ((symbol = fgetc(stream)) != EOF)
    {
        if (length == size - 1)
        {
            size_t new_size = size * grow_buffer_coefficient;
            // buffer = realloc(*ptr_string, size); //ptr_string = realloc(///)
            char* check_buf = (char*) realloc(buffer, new_size);
            if (check_buf == NULL)
            {
                *ptr_size = size;
                *ptr_string = buffer;

                return -1;
            }

            buffer = check_buf;
            size = new_size;
        }

        buffer[length++] = symbol;

        if (symbol == '\n')
            break;
    }

// Обработка случая, когда ничего не прочитано
    if (length == 0 && symbol == EOF)
        return -1;

    if (length == size)
    {
        size_t new_size = length + 1;
        char* check_buf = (char*) realloc(buffer, new_size);
        if (check_buf == NULL)
        {
            *ptr_size = size;
            *ptr_string = buffer;

            return -1;
        }
        buffer = check_buf;
        size = new_size;
    }

    // Завершаем строку нулем
    buffer[length] = '\0';

    // Обновляем указатели
    *ptr_string = buffer;
    *ptr_size = size;
    return length;
}

char* const_kostyl_suka(const char* source) //Вова гений
{
    assert(source != NULL);

    char* destination = (char*) calloc(1, 8);
    memcpy(destination, source, sizeof(char*));

    return destination;
}
