#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "createxml.h"

int main(){
    char str[255];
    system(clean);
    printf("Insira o nome do projeto: ");
    scanf("%s",str);
    getchar();

    createxml(str);

    return 1;
}

