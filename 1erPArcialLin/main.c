#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio_ext.h>

#include "bicicleta.h"
#include "color.h"
#include "fecha.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"
#include "funciones.h"
#include "fecha.h"

#define TAM 1000
#define TAM_TRAB 1000
#define TAM_FECH 1000
#define TAM_TIP 4
#define TAM_COL 5
#define TAM_SERV 4
#define TAM_ROD 3

int main()
{
    int seguir = 's';
    //int inputOutputId;
    //char c;
    int nextIdBicicleta = 0;
    int nextIdTrabajo = 0;

    eBicicleta bicicleta[TAM];/* =
    {
        {nextIdBicicleta, "PEPE", 1000, 5000, 'a', 30}
    };*/
    eTrabajo trabajos[TAM_TRAB];
    eFecha fechas[TAM_FECH];

    eTipo tipos[TAM_TIP] =
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };

    eColor colores[TAM_COL] =
    {
        {5000, "Gris"},
        {5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"}
    };

    eServicio servicios[TAM_SERV] =
    {
        {20000, "Limpieza", 30},
        {20001, "Parche", 4000},
        {20002, "Centrado", 500},
        {20003, "Cadena", 450}
    };

    eRodado rodados[TAM_ROD] =
    {
        {26},
        {28},
        {30}
    };
    inicializarBicicletas(bicicleta, TAM);
    inicializarTrabajos(trabajos, TAM_TRAB);

    do
    {
        switch(menuPrinc())
        {
        case 1:
            if(altaBicicleta(bicicleta, TAM, tipos, TAM_TIP, colores, TAM_COL, rodados, TAM_ROD, &nextIdBicicleta))
            {
                printf("Alta realizada con exito\n");
            }
            else
            {
                printf("Hubo un problema al realizar el alta\n");
            }
            break;
        case 2:
            menuModifBicicleta(bicicleta, TAM, tipos, TAM_TIP, colores, TAM_COL, rodados, TAM_ROD);
            break;
        case 3:
            break;
        case 4:
            listarBicicletas(bicicleta, TAM, tipos, TAM_TIP, colores, TAM_COL);
            break;
        case 5:
            system("clear");
            listarTipos(tipos, TAM_TIP);
            break;
        case 6:
            system("clear");
            listarColores(colores, TAM_COL);
            break;
        case 7:
            listarServicios(servicios, TAM_SERV);
            break;
        case 8:
            altaTrabajo(trabajos, TAM_TRAB, bicicleta, TAM, servicios, TAM_SERV, tipos, TAM_TIP, colores, TAM_COL, fechas, &nextIdTrabajo);
            break;
        case 9:
            listarTrabajos(trabajos, TAM_TRAB, bicicleta, TAM, servicios, TAM_SERV);
            break;
        case 10:
            mostrarBicicletaColor(bicicleta, TAM, colores, TAM_COL, tipos, TAM_TIP);
            break;
        case 11:
            mostrarBicicletaTipo(bicicleta, TAM, tipos, TAM_TIP, colores, TAM_COL);
            break;
        case 12:
            verificacionMaterialBicicleta(bicicleta, TAM, tipos, TAM_TIP);
            break;
        case 13:
            listarBicicletasTipo(bicicleta, TAM, tipos, TAM_TIP, colores, TAM_COL);
            break;
        case 14:
            contadorTipoColor(bicicleta, TAM, tipos, TAM_TIP, colores, TAM_COL);
            break;
        case 15:
            informeColoresMasElegidos(bicicleta, TAM, colores, TAM_COL);
            break;
        case 20:
            seguir = 'n';
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
        __fpurge(stdin);
        getchar();
    }while(seguir != 'n');

    return 0;
}

























