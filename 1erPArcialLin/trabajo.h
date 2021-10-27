#include "fecha.h"
#include "servicio.h"
#include "bicicleta.h"
#include "color.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fechas;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED


int altaTrabajo(eTrabajo trabajos[], int tamTra, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eFecha fechas[], int* pId);
















