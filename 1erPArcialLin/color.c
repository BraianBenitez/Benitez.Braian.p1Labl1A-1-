#include <stdio.h>
#include <stdlib.h>

#include "color.h"

void listarColores(eColor colores[], int tam)
{
    if(colores != NULL && tam > 0)
    {
        printf("   *** LISTADO DE COLORES ***   \n");
        printf("----------------------------------\n");
        printf("ID                     COLOR\n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d    %20s\n",
                   colores[i].id,
                   colores[i].nombreColor);
        }
    }
}
