#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int leg;
    char ape [15];
    char nom [15];
    float alt;
    char sex;
}persona;
int carga_archivo(persona [],int );
int validar (int, int, char[10]);

int main ()
{
    persona per[10];
    cant=carga_archivo(per,10);

}
int validar (int a, int b. char c [10])
{
    int x;
    do
    {
        printf("\n Ingrese %s:",c);
        scanf("%d",&x);
    }while (x<a||x>b);
}
int carga_archivo(persona a [],int n)
{
    FILE * PE;

}
