#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id; // comienza en 1000
    char descripcion[20];
}eTipo;

#endif // TIPO_H_INCLUDED

void listarTipos(eTipo tipo[], int tam);
