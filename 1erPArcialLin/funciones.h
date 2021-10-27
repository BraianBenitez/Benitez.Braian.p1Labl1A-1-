/*#include "tipo.h"
#include "color.h"
#include "fecha.h"
#include "servicio.h"*/

#include "trabajo.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

int menuPrinc();
int menuModifBicicleta(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eRodado rodados[], int tamRod);
int subMenuBicicletas();

int inicializarBicicletas(eBicicleta bicicletas[], int tam);
int inicializarTrabajos(eTrabajo trabajos[], int tam);

int buscarBicicleta(eBicicleta bicicletas[], int tam, int idIngresado);
int buscarLibre(eBicicleta bicicletas[], int tam);

int validarIdTipo(eTipo tipos[], int tamTip, int idIngresado);

int validarIdColor(eColor colores[], int tamCol, int idIngresado);

int validacionMaterial(char letraIngresada);

void listarRodados(eRodado rodados[], int tam);

int validacionRodado(int rodadoIngresado, eRodado rodados[], int tam);

int validarIdBicicleta(eBicicleta bicicletas[], int tam, int idIngresado);

int cargarDescripcionTipo(eTipo tipos[], int tam, int idIngresado, char variableDestino[]);

int cargarDescripcionColor(eColor colores[], int tam, int idIngresado, char variableDestino[]);

void mostrarBicicleta(eBicicleta bicicleta, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
int listarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol);

int buscarLibreTrabajo(eTrabajo trabajos[], int tam);
int validarIdBicicleta(eBicicleta bicicletas[], int tam, int idIngresado);
int validarIdservicio(eServicio servicios[], int tamServ, int idIngresado);

int listarTrabajos(eTrabajo trabajos[], int tamTrab, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ);

int mostrarBicicletaColor(eBicicleta bicicletas[], int tamBic, eColor colores[], int tamCol, eTipo tipos[], int tamTip);

int mostrarBicicletaTipo(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTip, eColor colores[], int tamCol);

int verificacionMaterialBicicleta(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTip);



int listarBicicletasTipo(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTip, eColor colores[], int tamCol);



int contadorTipoColor(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTip, eColor colores[], int tamCol);

int informeColoresMasElegidos(eBicicleta bicicletas[], int tamBici, eColor colores[], int tamCol);









