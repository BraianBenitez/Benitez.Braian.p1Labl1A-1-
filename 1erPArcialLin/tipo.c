#include <stdio.h>
#include <stdlib.h>

#include "tipo.h"

void listarTipos(eTipo tipo[], int tam)
{
    if(tipo != NULL && tam > 0)
    {
        printf("    *** LISTADO DE TIPOS ***    \n\n");
        printf(" ID                  DESCRIPCION\n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d      %20s\n",
                   tipo[i].id,
                   tipo[i].descripcion);
        }
    }
}
