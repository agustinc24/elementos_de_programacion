#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int loc;
    int prov;
    int zona;
}destinos;
typedef struct
{
    int loc;
    float kg;
    char tipo;
}envios;
int carga_archivo(destinos [],int);
int buscar (int, destinos [], int);
void punto_d(float [][3],int, int);
void punto_e (int,int);
int main()
{
    int x,pos,cant,ma[][3]={{0}},ant,v[300]={0},cod,max,cont,codl,contgen,contv;
    cont=contgen=contv=0;
    destinos des [300];
    envios env;
    cant=carga_archivo(des,300);
    FILE * EN;
    if((fopen("ENVIOS.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&env,1,sizeof(envios),EN);
    while (!feof(EN))
    {
        ant=env.loc;
        cont=0;
        codl=env.loc;
        pos=buscar(codl,des,cant);

        while(ant==env.loc)
        {
            contgen++;
            v[env.loc-1]++;
            if (env.kg>4)
                cont++;
            if (env.tipo=='N')
                ma[des[pos].zona][0]+=env.kg;
            if(env.tipo=='F')
                ma[des[pos].zona][1]+=env.kg;
            if(env.tipo=='V')
            {
                ma[des[pos].zona][2]+=env.kg;
                contv++;
            }
        }
        printf("\n En la localidad %d, hubo %d de encomiendas mayores a 4kg",ant,cont);

    }
    punto_d(ma,8,3);
    punto_e(contgen,contv);
    for (x=0;x<300;x++)
    {
        if (x==0||max<v[x])
        {
            max=v[x];
            cod=x+1;
        }
        if(v[x]==0)
        {
            printf("\n La localidad %d no recibio encomiendas",x+1);
        }
    }
    printf("\n La localidad %d realizo la mayor cantidad de envios que fueron %d",cod,max);

    return 0;
}
int carga_archivo(destinos a [], int n)
{
    int x;
    FILE * DE;
    if((DE=fopen("DESTINOS.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(destinos),1,DE);
    while (!feof(DE)&&x<n)
    {
        x++;
        fread(&a[x],sizeof(destinos),1,DE);
    }
    fclose(DE);
    return x;
}
void punto_d(float a[][3],int b,int c)
{
    int x,z,total;
    printf ("\n Zona: \t Total kilos: \t Total 'N': \n Total 'F': \n Total 'V':");
    for (x=0;x<b;x++)
    {
        for(z=0;z<c;x++)
        {
            total+=a[x][z];
        }
        printf("%d \t %f",x+1,total);
    }
    for (x=0;x<b;x++)
    {
        for(z=0;z<c;x++)
        {
            printf("\t %f",a[x][z]);
        }
    }
}
void punto_e(int a,int b)
{
    float por;
    por=b*100/a;
    printf("\n El porcentaje de encomiendas tipo 'V' es de %f %",por);
}
int buscar(int a, destinos b [], int c)
{
    int x,p;
    x=0;p=-1;
    while (p==-1&&x<c)
    {
        if (a==b[x].loc)
            p=x;
        else
            x++;
    }
    return p;
}
