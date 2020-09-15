#include <stdio.h>
#include <stdlib.h>
void cargar_matrix(int[5][3],int,int);
int mostrar_punto_c(int[5][3],int,int);
void mostrar_punto_f(int);
void mostrar_punto_h(int,int,int,int[5][3]);
int main()
{
    int m[5][3]={{0}},x,i,acum,tot,max,pf,pc,min,pmc,pmf;
    float prom;
    cargar_matrix(m,5,3);
    for(x=0;x<3;x++)
    {
        acum=0;
        for(i=0;i<5;i++)
        {
            acum+=m[i][x];
        }
        printf("\n Suma total de columna %d: %d",x+1,acum);
    }
    tot=0;
    tot=mostrar_punto_c(m,5,3);
    printf("\n Suma total de las filas %d",tot);
    prom=0;
    prom=tot/15;
    printf("\n El promedio general de la matriz es:%f",prom);
    for(x=0;x<3;x++)
    {
        acum=0;
        for(i=0;i<5;i++)
        {
            acum+=m[i][x];
        }
        mostrar_punto_f(acum);
    }
    max=m[0][0];
    for(x=0;x<5;x++)
    {
        for(i=0;i<3;i++)
        {
            if(max<m[x][i])
            {
                max=m[x][i];
                pf=x;
                pc=i;
            }
        }
    }
    printf("\n El maximo es: %d, ubicado en la fila %d y en la columna %d",max,pf+1,pc+1);
    mostrar_punto_h(max,5,3,m);
    min=m[0][0];
    for(x=0;x<5;x++)
    {
        for(i=0;i<3;i++)
        {
            if(min>m[x][i])
            {
                min=m[x][i];
                pmc=i;
                pmf=x;
            }
        }
    }
     printf("\n El minimo es: %d, ubicado en la fila %d y en la columna %d",min,pmf+1,pmc+1);
    return 0;
}
void cargar_matrix(int a[5][3],int f,int c)
{
    int r,s;
    for(r=0;r<f;r++)
    {
        for(s=0;s<c;s++)
        {
            printf("Ingrese valor:");
            scanf("%d",&a[r][s]);
        }
    }
}
int mostrar_punto_c(int a[5][3],int f,int c)
{
    int y,z,acum,gen=0;
    for(y=0;y<f;y++)
    {
        acum=0;
        for(z=0;z<c;z++)
            {
                acum+=a[y][z];
            }
        printf("\n Suma total fila %d: %d",y+1,acum);
        gen+=acum;
    }

    return gen;
}
void mostrar_punto_f(int a)
{
    float prom;
    prom=a/5;
    printf("\n El promedio de las columnas es:%f",prom);
}
void mostrar_punto_h(int a,int f,int c,int b[5][3])
{
    int z,x;
    for(x=0;x<f;x++)
    {
        for(z=0;z<c;z++)
        {
            if(a==b[x][z])
            {
                 printf("\n El maximo es: %d, ubicado en la fila %d y en la columna %d",b[x][z],x+1,z+1);
            }
        }
    }
}
