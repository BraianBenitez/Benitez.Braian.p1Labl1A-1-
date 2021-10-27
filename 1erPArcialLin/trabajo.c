#include <stdio.h>
#include <stdlib.h>

#include "trabajo.h"
#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "funciones.h"


int altaTrabajo(eTrabajo trabajos[], int tamTra, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eFecha fechas[], int* pId)
{
        int retorno = 0;
        int indice;

    if(trabajos != NULL && tamTra > 0 && bicicletas != NULL && tamBic > 0 && servicios != NULL && tamServ > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol && pId != NULL)
    {
        system("clear");
        printf("     *** Alta Trabajo ***      \n");
        printf("--------------------------------\n");
        eTrabajo auxTrabajo;
        indice = buscarLibreTrabajo(trabajos, tamTra);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxTrabajo.id = *pId;
            (*pId)++;

            if(!listarBicicletas(bicicletas, tamBic, tipos, tamTip, colores, tamCol))
            {
                printf("No se puede realizar el alta del trabajo\n");
            }
            else
            {
                printf("Ingrese el Id de la bicicleta: ");
                scanf("%d", &auxTrabajo.id);
                while(!validarIdBicicleta(bicicletas, tamBic, auxTrabajo.id))
                {
                    printf("El ID ingresado no es valido. Intente nuevamente\n");
                    printf("Ingrese el Id de la bicicleta: ");
                    scanf("%d", &auxTrabajo.id);
                }

                printf("Ingrese el ID del servicio: ");
                scanf("%d", &auxTrabajo.idServicio);
                while(!validarIdservicio(servicios, tamServ, auxTrabajo.idServicio))
                {
                    printf("El ID ingresado no es valido. Intente nuevamente\n");
                    printf("Ingrese el ID del servicio: ");
                    scanf("%d", &auxTrabajo.idServicio);
                }

                printf("Ingrese el dia, mes y año: ");
                scanf("%d %d %d",
                      &auxTrabajo.fechas.dia,
                      &auxTrabajo.fechas.mes,
                      &auxTrabajo.fechas.anio
                      );

                trabajos[indice].isEmpty = 0;

                trabajos[indice] = auxTrabajo;

                retorno = 1;
            }
        }
    }
    return retorno;
}

