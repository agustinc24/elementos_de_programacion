#include <stdio.h>
#include <stdlib.h>
struct persona
{
    int leg;
    char ape[15];
    char nom[15];
    float altura;
    char sexo;
};
int validar(int,int,char[10]);
char validar2(char,char,char[10]);
int main()
{
    struct persona p[10];
    int x,i;
    x=0;
    FILE * pp;
    p[x].leg=validar(0,1000,"legajo");
    while(p[x].leg!=0)
    {
        printf("\n Ingrese apellido:");
        scanf("%s",&p[x].ape);
        printf("\n Ingrese nombre:");
        scanf("%s",&p[x].nom);
        do
        {
            printf("\n Ingrese altura:");
            scanf("%f",&p[x].altura);
        }while(p[x].altura<0);
        p[x].sexo=validar2('F','M',"sexo");
        x++;
        p[x].leg=validar(0,1000,"legajo");
    }
    if((pp=fopen("f:\\Datos\\DATOSPERSONA.dat","wb"))==NULL)
    {
        puts("error");
        exit(0);
    }
    for(i=0;i<x;i++)
    {
        fwrite(&p[i],sizeof(struct persona),1,pp);
    }
    fclose(p);
    return 0;
}
int validar(int a,int b,char c[10])
{
    int x;
    do
    {
        printf("\n Ingrese %s:",c);
        scanf("%d",&x);
    }while(x<a||x>b);
    return x;
}
char validar2(char a,char b,char c[10])
{
    char x;
    do
    {
        printf("\n Ingrese %s:",c);
        fflush(stdin);
        scanf("%c",&x);
    }while(x!=a&&x!=b);
    return x;
}
