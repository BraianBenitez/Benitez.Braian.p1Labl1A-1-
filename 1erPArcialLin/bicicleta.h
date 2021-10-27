#include "color.h"
#include "fecha.h"
#include "tipo.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int numRodado;
}eRodado;

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material;
    eRodado rodado;
    //eFecha fecha;
    int isEmpty;
}eBicicleta;

#endif // BICICLETA_H_INCLUDED

int altaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamTipo, eColor colores[], int tamColor, eRodado rodados[], int tamRod, int* pId);

int modificarTipoBicicleta(eBicicleta bicicletas[], int maxId, eTipo tipos[], int tamTip, int idBicicleta);

int modificarRodadoBicicleta(eBicicleta bicicletas[], int tam, eRodado rodados[], int tamRod, int idBicicleta);
