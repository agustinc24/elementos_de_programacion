#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int leg;
    char edad;
    char loc;
    int cod;
}universidad;
int punto_b(universidad[]);

int main()
{
    int x,cont,num,cont2;
    universidad uni [10000];
    cont=0;cont2=0;
    num=punto_b(uni);
    for (x=0;x<num;x++)
        if(uni[x].edad=='M')
    {
        cont++;
    }
    printf("\n La cantidad de alumnos mayores a 20 anios es:%d",cont);



    float por;
    for (x=0;x<num;x++)

    {

        if (uni[x].edad=='A'&&uni[x].loc=='C')
            cont2++;
    }
    por=cont/num*100;
    printf("\n \n Porcentaje de alumnos de Capital y menores a 20 anios:%f",por);
    return 0;
}
int punto_b(universidad a[10000])
{
    int x;
    x=0;
    FILE * NN;
     if((NN=fopen("C:\\Progra\\TANDIL.dat","rb"))==NULL)
    {
        puts ("Error");
        exit(0);
    }
    fread(&a[x],sizeof(universidad),1,NN);
    while (!feof(NN))
    {
        x++;

        fread(&a[x],sizeof(universidad),1,NN);

    }
    return x;
    }

