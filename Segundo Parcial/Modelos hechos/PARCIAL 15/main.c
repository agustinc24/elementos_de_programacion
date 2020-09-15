#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int nroinm;
    char ubi [30];
    int lote;
    int camb;
    char cara;
    float pre;
}merca;
typedef struct
{
    char cara;
    int camb;
    float pre;
}consul;
int carga_arch (merca [],int);
int buscar (int,merca [],int);
char buscar2 (char,merca [],int);
void imprime_c(int,int,char);
int main()
{
    merca mer[3000];
    consul con;
    int pos,pos2,cant,amb,maxp,maxa,maxc,va[10]={0},x,vc[5]={0},sen,maxcant,mencant,maxcara,mencara;
    sen=x=0;
    char cara;
    cant=carga_arch(mer,3000);
    FILE * CO;
    if((fopen("consultas.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&con,sizeof(consul),1,CO);
    while(!feof(CO))
    {
        for(x=0;x<cant;x++)
        {
            if(con.cara==mer[x].cara&&con.camb==mer[x].camb&&con.pre<=mer[x].pre)
            {
                printf("\n Inmueble:%d \n Ubica:%s \n Lote:%d m2 \n Ambientes:%d \n Característica:%c \n Precio:%f",mer[x].nroinm,mer[x].ubi,mer[x].lote,mer[x].camb,mer[x].cara,mer[x].pre);
            }
        }
            amb=con.camb;
            buscar(amb,mer,cant);
            if(amb==mer[pos].camb)
                va[pos-1]++;
            cara=con.cara;
            pos2=buscar2(cara,mer,cant);
            switch(con.cara)
            {
                case 'C':vc[0]++;
                break;
                case 'D':vc[1]++;
                break;
                case 'L':vc[2]++;
                break;
                case 'T':vc[3]++;
                break;
                case 'P':vc[4]++;
                break;
            }
            if (sen==0||maxp<con.pre)
            {
                sen=1;
                maxp=con.pre;
                maxc=con.cara;
                maxa=con.camb;
            }
            fread(&con,sizeof(consul),1,CO);
    }
    fclose(CO);
    for(x=0;x<10;x++)
    {
        printf("\n Con una cantidad de %d ambientes se hicieron %d consultas",x+1,va[x]);
    }
    for (x=0;x<5;x++)
    {
        if(x==0||maxcant<vc[x])
        {
            maxcant=vc[x];
            maxcara=x;
        }
        if(x==0||vc[x]<mencant)
        {
            mencant=vc[x];
            mencara=x;
        }
    }
    if(maxcara==0)
        printf("\n La caracteristica más consultada fueron las casas");
    if(maxcara==1)
        printf("\n La caracteristica más consultada fueron los dptos");
    if(maxcara==2)
        printf("\n La caracteristica más consultada fueron los locales");
    if(maxcara==3)
        printf("\n La caracteristica más consultada fueron los terrenos");
    if(maxcara==4)
        printf("\n La caracteristica más consultada fueron los duplex");
     if(mencara==0)
        printf("\n La caracteristica menos consultada fueron las casas");
    if(mencara==1)
        printf("\n La caracteristica menos consultada fueron los dptos");
    if(mencara==2)
        printf("\n La caracteristica menos consultada fueron los locales");
    if(mencara==3)
        printf("\n La caracteristica menos consultada fueron los terrenos");
    if(mencara==4)
        printf("\n La caracteristica menos consultada fueron los duplex");
    imprime_c(maxp,maxa,maxc);

    return 0;
}
void imprime_c(int a,int b,char c)
{
    printf("La caracteristica %c con %d ambientes y un precio de %f fue el mayor precio solicitado",c,b,a);
}
int buscar(int a,merca b[],int c)
{
    int p,x;
    p==-1;x=0;
    while (p==-1&&x<c)
    {
        if(a==b[x].camb)
            p=x;
        else
            x++;
    }
    return x;
}
char buscar2(char a,merca b[],int c)
{
    int p,x;
    p==-1;x=0;
    while (p==-1&&x<c)
    {
        if(a==b[x].cara)
            p=x;
        else
            x++;
    }
    return x;
}
int carga_arch(merca a[],int b)
{
    int x=0;
    FILE * NN;
    if((NN=fopen("inmuebles.dat","rb"))==NULL)
    {
        puts("Error");
        exit(0);
    }
    fread(&a[x],sizeof(merca),1,NN);
    while(!feof(NN)&&x<b)
        {
            x++;
            fread(&a[x],sizeof(merca),1,NN);
        }
    fclose(NN);
    return x;
}
