#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

#include "bicicleta.h"
#include "color.h"
#include "fecha.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"
#include "funciones.h"


int altaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eRodado rodados[], int tamRod, int* pId)
{
    system("clear");
    printf("     *** Alta Bicicleta ***      \n");
    printf("--------------------------------\n");
    int retorno = 0;
    int indice;
    eBicicleta auxBicicleta;

    if(lista != NULL && tam > 0 && tipos != NULL && tamTipo > 0 && colores != NULL && tamColor > 0 && pId != NULL)
    {
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxBicicleta.id = *pId;
            (*pId)++;

            printf("Ingrese Marca: ");
            __fpurge(stdin);
            scanf("%*c%[^\n]", auxBicicleta.marca);

            listarTipos(tipos, tamTipo);
            printf("Ingrese ID tipo: ");
            scanf("%d", &auxBicicleta.idTipo);
            while(!validarIdTipo(tipos, tamTipo, auxBicicleta.idTipo))
            {
                printf("El ID ingresado no corresponde a ningun tipo. Intente nuevamente: ");
                scanf("%d", &auxBicicleta.idTipo);
            }

            listarColores(colores, tamColor);
            printf("Ingrese ID color: ");
            scanf("%d", &auxBicicleta.idColor);
            while(!validarIdColor(colores, tamColor, auxBicicleta.idColor))
            {
                printf("El ID ingresado no corresponde a ningun color. Intente nuevamente: ");
                scanf("%d", &auxBicicleta.idColor);
            }

            printf("Ingrese material ('c' Carbono, o 'a' Aluminio): ");
            __fpurge(stdin);
            scanf("%c", &auxBicicleta.material);
            auxBicicleta.material = tolower(auxBicicleta.material);
            while(auxBicicleta.material != 'c' && auxBicicleta.material != 'a')
            {
                printf("Indice de material no aceptado. Intente nuevamente\n");
                __fpurge(stdin);
                scanf("%c", &auxBicicleta.material);
                auxBicicleta.material = tolower(auxBicicleta.material);
            }
            listarRodados(rodados, tamRod);
            printf("Ingrese el rodado: ");
            scanf("%d", &auxBicicleta.rodado.numRodado);
            while(!validacionRodado(auxBicicleta.rodado.numRodado, rodados, tamRod))
            {
                printf("El rodado ingresado no es valido. Intente nuevamente\n");
                printf("Ingrese el rodado: ");
                scanf("%d", &auxBicicleta.rodado.numRodado);
            }

            auxBicicleta.isEmpty = 0;

            lista[indice] = auxBicicleta;

            retorno = 1;
        }
    }
    return retorno;
}


int modificarTipoBicicleta(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip, int idBicicleta)
{
    int retorno = 0;
    int opcion;

    if(bicicletas != NULL && tam > 0 && tipos != NULL && tamTip > 0)
    {
        if(validarIdBicicleta(bicicletas, tam, idBicicleta))
        {
            listarTipos(tipos, tamTip);
            printf("Seleccione el codigo correspondiente al tipo que desea aplicar: ");
            scanf("%d", &opcion);
            if(validarIdTipo(tipos, tamTip, opcion))
            {
                for(int i = 0; i < tam; i++)
                {
                    if(idBicicleta == bicicletas[i].id)
                    {
                        bicicletas[i].idTipo = opcion;
                        retorno = 1;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

int modificarRodadoBicicleta(eBicicleta bicicletas[], int tam, eRodado rodados[], int tamRod, int idBicicleta)
{
    int retorno = 0;
    int opcion;

    if(bicicletas != NULL && tam > 0 && rodados != NULL && tamRod > 0)
    {
        if(validarIdBicicleta(bicicletas, tam, idBicicleta))
        {
            listarRodados(rodados, tamRod);
            printf("Seleccione el numero de rodado que desea aplicar a la bicicleta: ");
            scanf("%d", &opcion);
            if(validacionRodado(opcion, rodados, tamRod))
            {
                for(int i = 0; i < tam; i++)
                {
                    if(idBicicleta == bicicletas[i].id)
                    {
                        bicicletas[i].rodado.numRodado = opcion;
                        retorno = 1;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

/*
int bajaBicicleta()
{

}

*/
























