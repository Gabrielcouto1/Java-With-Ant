#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "createxml.h"

int main(){
    char str[255];
    system(clean);
    printf("Insert the project name(no blank spaces): ");
    scanf("%s",str);
    getchar();

    createxml(str);

    return 1;
}

