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

int carga_archivo(struct persona []);

int main()
{
    struct persona p[10];
    int x,i;
    x=0;
    int cant;
    cant=carga_archivo(p);

    for (i=0;i<cant;i++)
    {
        printf("\n \n El legajo:%d",p[i].leg);
        printf("\n");
        puts(p[i].ape);
        printf("\n");
        puts(p[i].nom);
        printf("\n Altura:%f",p[i].altura);
        printf("\n Sexo:%c",p[i].sexo);
    }
    fclose(p);
    return 0;
}

int carga_archivo (struct persona a [])
{
    int x=0;
    FILE * pp;
    if((pp=fopen("f:\\Datos\\DATOSPERSONA.dat","rb"))==NULL)
    {
        puts("error");
        exit(0);
    }
    fread(&a[x],sizeof(struct persona),1,pp);
    while (!feof(pp))
    {
        x++;
        fread(&a[x],sizeof(struct persona),1,pp);
    }
    return x;
}
