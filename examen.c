#include <stdio.h>
#include <string.h>

#define N 2

#define Estatu 0
#define Sueldo 1

void leerDatos(int C[N], char nom[N][20],float ES[N][2]);
int masAlto(float estatura[N][2]);
void ordenar(int c[N], char n[N][20], float ES[N][2]);
void imprimir(int c[N],char n[N][20],float es[N][2]);


int main()
{
    int clave [N];
    char nombre[N][20];
    float EstaturaSueldo [N][2];
    int pos;


    leerDatos( clave, nombre, EstaturaSueldo);
    ordenar(clave, nombre, EstaturaSueldo);
    imprimir(clave, nombre,EstaturaSueldo);
    
    pos = masAlto(EstaturaSueldo);

    printf("Empleado mas alto: %s\n", nombre[pos]);
    printf("Estatura de: %f\n",EstaturaSueldo[pos][Estatu]);
    
    return 0;
}
void imprimir(int c[N],char n[N][20],float es[N][2])
{
    int i;

    printf("Clave     Nombre     Estatura    Sueldo\n");

    for ( i = 0; i < N; i++)
    {
        printf("%d\t\t", c[i]);
        printf("%s\t", n[i]);
        printf("%f\t",es[i][Estatu]);
        printf("%f\n", es[i][Sueldo]);
    }
    
}

void ordenar(int c[N], char n[N][20], float ES[N][2])
{
    int i, j;
    float aux;
    int auxClave;
    char auxN[20];

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N -1; j++)
        {
            if (ES[j][Sueldo]< ES[j+1][Sueldo])
            {
                aux = ES[j][Sueldo];
                ES[j][Sueldo]=ES[j+1][Sueldo];
                ES[j+1][Sueldo]=aux;

                aux = ES[j][Estatu];
                ES[j][Estatu]=ES[j+1][Estatu];
                ES[j+1][Estatu]=aux;

                auxClave= c[j];
                c[j]=c[j+1];
                c[j+1]=auxClave;

                strcpy(auxN, n[j]);
                strcpy(n[j],n[j+1]);
                strcpy(n[j+1],auxN);
            }
            
        }
        
    }
    
}

void leerDatos(int C[N], char nom[N][20],float ES[N][2])
{
    int i;
    
    for ( i = 0; i < N; i++)
    {
        printf("Dame clave %d: ",i);
        scanf("%d", &C[i]);
        printf("Dame nombre: ");
        scanf("%s", nom[i]);
        printf("Dame estatura : ");
        scanf("%f", &ES[i][0]);
        printf("Dame sueldo: ");
         scanf("%f", &ES[i][1]);
        
    }   
}

int masAlto(float estatura[N][2])
{
    int pos= 0 ;
    int i;
    float ma = estatura [0][0];
    
    
    for (i = 0; i < N ; i++)
    {
        if (estatura[i][0]>ma)
        {
            ma = estatura[1][0];
            pos = i;
        } 
    }
    
 return pos; 
}
 //     <3
