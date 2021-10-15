#include <stdio.h>

#define N 25

#define Usuarios 2

void leerDatos(int C[N], char nom[Usuarios][N],float ES[N][2]);
int masAlto(float estatura[N][2],int *col);


int main()
{
    int clave [N];
    char nombre[Usuarios][N];
    float EstaturaSueldo [N][2];
    int pos,col;


    leerDatos( clave, nombre, EstaturaSueldo);
    
    pos = masAlto(EstaturaSueldo, &col);
    
    return 0;
}

void leerDatos(int C[N], char nom[Usuarios][N],float ES[N][2])
{
    int i,j;
    
    for ( i = 0; i < Usuarios; i++)
    {
        printf("Dame clave %d: ",i);
        scanf("%d", &C[i]);
        printf("Dame nombre: ");
        scanf("%s", nom[i]);

        for (j = 0;j < 1; j++)
        {
            printf("Dame estatura : ");
            scanf("%f", &ES[i][0]);
            printf("Dame sueldo: ");
            scanf("%f", &ES[i][1]);
        }
    }   
}


int masAlto(float estatura[N][2],int *col)
{
    int pos ;
    int j,i;
    float ma = estatura [0][0];


    for ( j= 0; j < Usuarios; j++)
    {
        for (i = 0; i < 1 ; i++)
        {
            if (estatura[j][i] > ma)
            {
                ma = estatura[j][i];
                *col = i;
               pos = i;
            } 
        }
    }
 return pos; 
}
