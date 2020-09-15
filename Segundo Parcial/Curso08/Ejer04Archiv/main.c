#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//4) tomar los datos del archivo DATOSPERSONAS.dat y Agregar mas registros y luego grabar
typedef struct {int leg;char apy[15];char nom[15];float alt;char sex;}persona;
int leer_archivo(persona []);
void mostrar(persona [],int);
int validae(int,int);
char validac(char,char);
void graba_archivo(persona [],int);

int main()
{
    persona p[10];
    int cant,x;
    cant=leer_archivo(p);
    x=cant;
    p[x].leg=validae(0,1000);
    while(p[x].leg!=0)
    {
     printf("\n Ingrese Apellido :");
     fflush(stdin);
     gets(p[x].apy);
     printf(" Ingrese Nombre   :");
     fflush(stdin);
     gets(p[x].nom);
     do{
        printf("Ingrese Altura :");
        scanf("%f",&p[x].alt);
       }while(p[x].alt<0);
     p[x].sex=validac('M','F');
     x++;
     p[x].leg=validae(0,1000);
    }
    graba_archivo(p,x);
    mostrar(p,x);
    return 0;
}

int leer_archivo(persona a[10])
 {
     int x=0;
     FILE * AR;
     if((AR=fopen("DATOSPERSONAS.dat","rb"))==NULL){puts("error archivo");exit(0);};
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
int validae(int i,int f)
{
  system("cls");
  int num;
  do{
     printf("Ingrese Numero de Legajo:");
     scanf("%d",&num);
    }while(num<i||num>f);
  return num;
};
char validac(char a,char b)
{
   char s;
  do{
     printf("Ingrese Sexo [M o F]:");
     fflush(stdin);
     scanf("%c",&s);
    }while(s!=a&&s!=b);
  return s;
};
void graba_archivo(persona a[10],int n)

 {
       int x=0;
     FILE * AR;
     if((AR=fopen("DATOSPERSONAS.dat","wb"))==NULL)
         {
          puts("error archivo");
          exit(0);
         };
    for(x=0;x<n;x++)
     {
     fwrite(&a[x],sizeof(persona),1,AR);
     }
     fclose(AR);
 };

