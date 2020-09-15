#include <stdio.h>
#include <stdlib.h>
// 2)	Leer el archivo llamado “DATOSPERSONAS.dat”, considerando que no hay más de 1.000 personas.
//      Y guardar los datos en memoria
typedef struct {int leg;char apy[15];char nom[15];float alt;char sex;}persona;
int leer_archivo(persona []);
void mostrar(persona [],int);
int main()
{
    persona p[10];
    int x,cant;
    cant=leer_archivo(p);
    mostrar(p,cant);
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
