#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
    
    Do not just use the `strdup` function from the standard library.
*/
// int string_length(char s[])
// {
//     //int len = sizeof(s) / sizeof(s[0]);
//     //return len;
//     int i;
//     int counter = 0;
//     for (i = 0; i < 512; i++) {
//         counter++;
//         if(s[i] == '\0') {
//             return(i);
//         }
//     }
// }

char *string_dup(char *src)
{
    int len = string_length(src);
    char *strcp = malloc(sizeof(len - 1));

    for (int i = 0; i < len; i++){
        strcp[i] = src[i];
    }
    strcp[len] = '\0';
    return strcp;

    //solution lecture code

    // int n = string_length(src);
    // char *str = malloc(n + 1);

    // for (int i = 0; i < n; i++) {
    //     *(str+i) = *(src+i);
    // }
    // *(str+n) = '\0';
    
    // return str;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    `n` is the number of bytes to copy. You may want to cast the input 
    pointers to char pointers first before performing the copying. 
    
    Do not just use the `memcpy` function from the standard library.
*/
// const is there to tell you to not manipulate src pointer
void *mem_copy(void *dest, const void *src, int n)
{
    // char *csrc = (char *)src;
    // char *cdest = (char *)dest;

    // for (int i = 0; i < n; i++){
    //     cdest[i] = csrc[i];
    //     //working strictly with pointers
            // //*(cdest+i) = *(csrc+i) same as array index syntax
    // }
    // solution lecture code
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    for (int i = 0; i < n; i++){
        *(cdest+i) = *(csrc+i);
    }
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    return 0;
}
#endif
