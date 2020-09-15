#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cara;
    int cont;
    cont=0;
    printf("\n Ingrese caracter:");
    fflush(stdin);
    scanf("%c",&cara);
    while(cara!='*')
    {
        cont++;
        printf("\n Ingrese caracteres:");
        fflush(stdin);
        scanf("%c",&cara);
    }
    printf("\n Se cargaron %d letras",cont);
    return 0;
}
