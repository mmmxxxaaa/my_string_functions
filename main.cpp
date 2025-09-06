#include <stdio.h>
#include <stddef.h>

#include "string_functions.h"

int main()
{
    /*
    size_t check = 0;
    check = my_strlen("penis");
    printf("%zu", check);
    */

    /*
    char str_to[] = "Cat";
    char str_from[] = "Dog";  //через char *str_from не сработало (после сема знаю, почему)))
    char* saved_ptr = my_strcpy(str_to, str_from);
    printf("%s", saved_ptr);
    */

    /*
    char str_to[] = "Dog";
    char str_from[] = "Saved";  //через char *str_from не сработало
    char* saved_ptr = my_strncpy(str_to, str_from, 5);
    printf("%s", saved_ptr);
    */

    /*
    char str_1[] = "Dog";
    char str_2[] = "Dog";
    int result = my_strcmp(str_1, str_2);
    printf("%d\n", result);
    return 0;
    */

    /*
    char str_1[] = "Dor";
    char str_2[] = "Dog";
    int result = my_strncmp(str_1, str_2, 2);
    printf("%d\n", result);
    */

    /*
    char str_1[7] = "Dor";
    char str_2[] = "Dog";
    char* result = my_strcat(str_1, str_2);
    printf("%s\n", result);
    */

    /*
    char str_1[7] = "Dor";
    char str_2[] = "Dog";
    char* result = my_strncat(str_1, str_2, 2);
    printf("%s\n", result);
    */

    /*
    char string[] = "dog";
    int result = my_puts(string);
    printf("%d\n", result);
    */

    /*
    char string[] = "Poltorashka";
    const char* result = my_strchr(string, 'o');
    printf("%s\n", result);
    */

    /*
    char string[] = "-333";
    int result = my_atoi(string);
    printf("%d\n", result);
    */

    /*
    char string[15];
    int n;
    char* ptr;

    ptr = my_fgets(string, sizeof(string), stdin);

    printf("%s\n", string);
    printf("%s\n", ptr);
    */

    /*
    const char *original = "Poltorashka is a cat";
    char *copy = strdup(original);

    printf("%s\n", copy);

    free(copy); //обязательно почистить память
    */

    /*
    const char string[25] = "Poltorashka is a cat";
    char* result = my_strstr(string, "iвгдд");
    printf("%s", result);
    */

    /*
    char* string = NULL;
    size_t size = 10;
    my_getline(string, size, stdin);
    printf("%s\n", string);
    */


//========================================================================================
//Задание от Деда
//========================================================================================

    char example_string[] = "Poltorashka";
    char changing_string[] = "Obshaga";

    char* string1 = example_string;        //1 если нет инициализации, то ошибки не будет, но лучше делать
    printf("string1: %s\n", string1);

    const char* string2 = "Cat";           //2 обязательна инициализация
    printf("string2: %s\n", string2);

    char* const string3 = example_string;  //3 обязательна инициализация, НО не строковой константой
    printf("string3: %s\n", string3);

    const char* const string4 = "Dog";     //4 обязательна инициализация
    printf("string4: %s\n", string4);

// 1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
    string1 = changing_string; // можно менять сам указатель
    printf("%s\n", string1);

    string1[5] = 'v';
    printf("%s\n", string1);  // можно менять значения по указателю


    //string1 = "Ded"; нельзя
// 1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1

// 2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2

    string2 = changing_string; // можно менять сам указатель
    printf("%s\n", string1);

    //string1[5] = 'v';
    //printf("%s\n", string1);  // нельзя менять значения по указателю
// 2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2-2

// 3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3

    //string3 = changing_string; // нельзя менять сам указатель
    //printf("%s\n", string1);

    string1[5] = 'v';           // можно менять значения по указателю
    printf("%s\n", string1);

// 3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3-3

// 4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4
    //string2 = changing_string; // нельзя менять сам указатель
    //printf("%s\n", string1);

    //string1[5] = 'v';
    //printf("%s\n", string1);   // нельзя менять значения по указателю
// 4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4-4

    return 0;
}
