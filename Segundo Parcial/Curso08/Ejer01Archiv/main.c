#include <stdio.h>
#include <stdlib.h>
// 1)Guardar los datos ingresado por teclado (luego de ser validados)
//   hasta que se ingresa un Cero en Número de Legajo, en un archivo
//   llamado “DATOSPERSONAS.dat”
struct persona {int leg;char apy[15];char nom[15];float alt;char sex;};
int validae(int,int);
char validac(char,char);
void graba_archivo(struct persona [],int);

int main()
{
    struct persona p[10];
    int x=0;
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
    return 0;
}
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
void graba_archivo(struct persona a[10],int n)

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
     fwrite(&a[x],sizeof(struct persona),1,AR);
     }
     fclose(AR);
 };
