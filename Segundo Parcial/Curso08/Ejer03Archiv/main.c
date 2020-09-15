#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 3)	Leer el archivo llamado “DATOSPERSONAS.dat”, considerando que no hay más de 1.000
//      personas. Y guardar los datos en memoria en forma ordenada.
typedef struct {int leg;char apy[15];char nom[15];float alt;char sex;}persona;
int leer_archivo(persona []);
void mostrar(persona [],int);
void ordenar(persona [],int);
int main()
{
    persona p[10];
    int cant;
    cant=leer_archivo(p);
    ordenar(p,cant);
    mostrar(p,cant);
    return 0;
}

int leer_archivo(persona a[10])
 {
     int x=0;
     FILE * AR;
     if((AR=fopen("E:\\Lopez\\Progra\\DATOSPERSONA.dat","rb"))==NULL){puts("error archivo");exit(0);};
     fread(&a[x],sizeof(persona),1,AR);
     while(!feof(AR))
     {
      x++;
      fread(&a[x],sizeof(persona),1,AR);
     }
     fclose(AR);
     return x;
 };
void mostrar(persona a[10],int n)
{
  int x;
  system("cls");
  for(x=0;x<n;x++)
  {
    printf("\n Legajo  :%d",a[x].leg);
    printf("\n Apellido:%s",a[x].apy);
    printf("\n Nombre  :%s",a[x].nom);
    printf("\n Altura  :%f",a[x].alt);
    printf("\n Sexo    :%c",a[x].sex);
  }
};
void ordenar(persona a[10],int n)
{
  int x=0,sen=0;
  persona aux;
  while(sen==0&&x<n)
  {
     sen=1;
     for(x=0;x<n-1;x++)
     {
         if(strcmp(a[x].apy,a[x+1].apy)>0)
           {
             aux=a[x];
             a[x]=a[x+1];
             a[x+1]=aux;
             sen=0;
           }
     }
            n--;
  }
};
