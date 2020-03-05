/*
 ============================================================================
 Name        : exercicio02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int palindromoTail(char str[], int s, int e)
{
    if (s == e)
    return 1;

    if (str[s] != str[e])
    return 0;

    if (s < e + 1)
    return palindromoTail(str, s + 1, e - 1);

    return 1;
}

int isPalindromo(char str[])
{
int n = strlen(str);

if (n == 0)
    return 1;

return palindromoTail(str, 0, n - 1);
}

int main()
{
    char str[] = "reviver";

    if (isPalindromo(str))
    printf("Sim");
    else
    printf("Não");

    return 0;
}
