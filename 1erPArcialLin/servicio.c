#include <stdio.h>
#include <stdlib.h>

#include "servicio.h"

void listarServicios(eServicio servicios[], int tam)
{
    if(servicios != NULL && tam > 0)
    {
        system("clear");
        printf("           *** LISTADO DE SERVICIOS ***   \n");
        printf("------------------------------------------------\n");
        printf("ID                      DESCRIPCION     PRECIO\n");
        for(int i = 0; i < tam; i++)
        {
        printf("%d     %25s      $%d\n",
               servicios[i].id,
               servicios[i].descripcion,
               servicios[i].precio);
        }
    }
}
