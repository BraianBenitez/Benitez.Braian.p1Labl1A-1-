#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "bicicleta.h"
#include "color.h"
#include "tipo.h"
#include "funciones.h"
#include "trabajo.h"
#include "servicio.h"

int menuPrinc()
{
    int opcion;

    system("clear");
    printf("------ ABM Bicicletas ------\n\n");
    printf("  1- ALTA BICICLETA\n");
    printf("  2- MODIFICAR BICICLETA\n");
    printf("  3- BAJA BICICLETA\n");
    printf("  4- LISTAR BICICLETAS\n");
    printf("  5- LISTAR TIPOS\n");
    printf("  6- LISTAR COLORES\n");
    printf("  7- LISTAR SERVICIOS\n");
    printf("  8- ALTA TRABAJO\n");
    printf("  9- LISTAR TRABAJOS\n\n");

    printf("  10- MOSTRAR BICICLETAS DEL COLOR SELECCIONADO POR EL USUARIO\n");
    printf("  11- MOSTRAR BICICLETAS DE UN TIPO SELECCIONADO\n");
    printf("  12- INFORMAR SI HAY MAS DE UNA BICICLETA DE CARBONO O ALUMINIO Y MOSTRAR LA CANTIDAD\n");
    printf("  13- MOSTRAR LISTADO DE BICICLETAS SEPARADAS POR TIPO\n");
    printf("  14- CONTAR BICICLETAS POR COLOR Y TIPO INGRESADO\n");
    printf("  15- MOSTRAR EL LOS COLORES MAS ELEGIDOS POR LOS CLIENTES\n");
    printf("  20- SALIR\n");

    printf("Ingrese un numero que corresponda a la operacion que desea realizar: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModifBicicleta(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eRodado rodados[], int tamRod)
{
    int ingresarOpcion = -1;
    int ingresarId;
    int indice;
    int cambioIdTipo;
    int cambioIdRodado;

    if(bicicletas != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        system("clear");
        printf("------ MODIFICACION DE BICICLETA --------\n");
        printf("------------------------------------------\n");

        if(listarBicicletas(bicicletas, tam, tipos, tamTip, colores, tamCol))
        {
            printf("Ingrese el ID de la bicicleta que desea modificar: ");
            scanf("%d", &ingresarId);
            indice = buscarBicicleta(bicicletas, tam, ingresarId);
            if(indice == -1)
            {
                printf("No se encuentra ese ID en el sistema\n");
            }
            else
            {
                switch(subMenuBicicletas())
                {
                case 1:
                    listarTipos(tipos, tamTip);
                    printf("Ingrese el ID correspondiente al tipo que desea reasignar: ");
                    scanf("%d", &cambioIdTipo);
                    while(!validarIdTipo(tipos, tamTip, cambioIdTipo))
                    {
                        printf("ID ingresado no valido. Intente nuevamente\n");
                        printf("Ingrese el ID correspondiente al tipo que desea reasignar: ");
                        scanf("%d", &cambioIdTipo);
                    }
                    bicicletas[indice].idTipo = cambioIdTipo;
                    printf("Cambio realizado con exito\n");
                    break;
                case 2:
                    listarRodados(rodados, tamRod);
                    printf("Ingrese el ID correspondiente al rodado que desea reasignar: ");
                    scanf("%d", &cambioIdRodado);
                    while(!validacionRodado(cambioIdRodado, rodados, tamRod))
                    {
                        printf("ID ingresado no valido. Intente nuevamente\n");
                        printf("Ingrese el ID correspondiente al rodado que desea reasignar: ");
                        scanf("%d", &cambioIdRodado);
                    }
                    bicicletas[indice].rodado.numRodado = cambioIdRodado;
                    printf("Cambio realizado con exito\n");
                    break;
                default:
                    printf("Numero ingresado no valido\n");
                }
            }
        }
    }
    return ingresarOpcion;
}

int subMenuBicicletas()
{
    int ingresarOpcion;

    system("clear");
    printf("  1- MODIFICAR TIPO\n");
    printf("  2- MODIFICAR RODADO\n");
    printf("Seleccione una accion a realizar: ");
    __fpurge(stdin);
    scanf("%d", &ingresarOpcion);

    return ingresarOpcion;
}

int buscarBicicleta(eBicicleta bicicletas[], int tam, int idIngresado)
{
    int indice = -1;

    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(bicicletas[i].isEmpty == 0 && idIngresado == bicicletas[i].id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int inicializarBicicletas(eBicicleta bicicletas[], int tam)
{
    int retorno = 0;

    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            bicicletas[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int buscarLibre(eBicicleta bicicletas[], int tam)
{
    int indice = -1;

    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(bicicletas[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int indice = -1;

    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int validarIdTipo(eTipo tipos[], int tamTip, int idIngresado)
{
    int retorno = 0;
    if(tipos != NULL && tamTip > 0)
    {
        for(int i = 0; i < tamTip; i++)
        {
            if(idIngresado == tipos[i].id)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int validarIdColor(eColor colores[], int tamCol, int idIngresado)
{
    int retorno = 0;

    if(colores != NULL && tamCol > 0)
    {
        for(int i = 0; i < tamCol; i++)
        {
            if(idIngresado == colores[i].id)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int validarIdBicileta(eBicicleta bicicletas[], int tamBic, int idIngresado)
{
    int retorno = 0;

    if(bicicletas != NULL && tamBic > 0)
    {
        for(int i = 0; i < tamBic; i++)
        {
            if(idIngresado == bicicletas[i].id)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int validarIdservicio(eServicio servicios[], int tamServ, int idIngresado)
{
    int retorno = 0;

    if(servicios != NULL && tamServ > 0)
    {
        for(int i = 0; i < tamServ; i++)
        {
            if(idIngresado == servicios[i].id)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int validacionMaterial(char letraIngresada)
{
    int retorno = 0;

    if(letraIngresada == 'c' || letraIngresada == 'a')
        retorno = 1;

    return retorno;
}

void listarRodados(eRodado rodados[], int tam)
{
    if(rodados != NULL && tam > 0)
    {
        printf("  *** Listado de rodados *** \n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d\n", rodados[i].numRodado);
        }
    }
}

int validacionRodado(int rodadoIngresado, eRodado rodados[], int tam)
{
    int retorno = 0;

    if(rodados != NULL && tam > 0 && rodadoIngresado > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(rodadoIngresado == rodados[i].numRodado)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int validarIdBicicleta(eBicicleta bicicletas[], int tam, int idIngresado)
{
    int retorno = 0;

    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(idIngresado == bicicletas[i].id)
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int idIngresado, char variableDestino[])
{
    int retorno = 0;

    if(tipos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(idIngresado == tipos[i].id)
            {
                strcpy(variableDestino, tipos[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int cargarDescripcionColor(eColor colores[], int tam, int idIngresado, char variableDestino[])
{
    int retorno = 0;

    if(colores != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(idIngresado == colores[i].id)
            {
                strcpy(variableDestino, colores[i].nombreColor);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

void mostrarBicicleta(eBicicleta bicicleta, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    char descripcionTipo[20];
    char descripcionColor[20];

    cargarDescripcionTipo(tipos, tamTip, bicicleta.idTipo, descripcionTipo);
    cargarDescripcionColor(colores, tamCol, bicicleta.idColor, descripcionColor);

    printf("%d %20s %20s %20s        %c              %d \n",
           bicicleta.id,
           bicicleta.marca,
           descripcionTipo,
           descripcionColor,
           bicicleta.material,
           bicicleta.rodado.numRodado);
}


int listarBicicletas(eBicicleta bicicletas[], int tam, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int retorno = 0;
    int flag = 0;

    if(bicicletas != NULL && tam > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
       system("clear");
       printf("---- LISTADO DE BICICLETAS ------\n");
       printf("ID                MARCA               TIPO                 COLOR    MATERIAL        RODADO \n");
       printf("---------------------------------------------------------------------------------------------\n");

       for(int i = 0; i < tam; i++)
       {
           if(!bicicletas[i].isEmpty)
           {
               mostrarBicicleta(bicicletas[i], tipos, tamTip, colores, tamCol);
               flag = 1;
               retorno = 1;
           }
       }
       if(!flag)
       {
           printf("No hay bicicletas para mostrar\n");
       }
    }
       return retorno;
}

int inicializarTrabajos(eTrabajo trabajos[], int tam)
{
     int retorno = 0;

    if(trabajos != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int cargarDescripcionBicicleta(eBicicleta bicicletas[], int tam, int idIngresado, char variableDestino[])
{
    int retorno = 0;

    if(bicicletas != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(idIngresado == bicicletas[i].id)
            {
                strcpy(variableDestino, bicicletas[i].marca);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int cargarDescripcionServicio(eServicio servicios[], int tam, int idIngresado, char variableDestino[])
{
    int retorno = 0;

    if(servicios != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(idIngresado == servicios[i].id)
            {
                strcpy(variableDestino, servicios[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

void mostrarTrabajo(eTrabajo trabajo, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ)
{
    char descripcionBicicleta[20];
    char descripcionServicio[20];

    cargarDescripcionBicicleta(bicicletas, tamBic, trabajo.idBicicleta, descripcionBicicleta);
    cargarDescripcionServicio(servicios, tamServ, trabajo.idServicio, descripcionServicio);

    printf("%d %20s %20s  %02d/%02d/%d\n",
           trabajo.id,
           descripcionBicicleta,
           descripcionServicio,
           trabajo.fechas.dia,
           trabajo.fechas.mes,
           trabajo.fechas.anio
           );
}

int listarTrabajos(eTrabajo trabajos[], int tamTrab, eBicicleta bicicletas[], int tamBic, eServicio servicios[], int tamServ)
{
    int retorno = 0;
    int flag = 0;

    if(trabajos != NULL && tamTrab > 0 && bicicletas != NULL && tamBic > 0 && servicios != NULL && tamServ > 0)
    {
       system("clear");
       printf("---- LISTADO DE TRABAJOS ------\n");
       printf("ID                DESC. BIC               DESC. SERV            FECHA \n");
       printf("----------------------------------------------------------------------\n");

       for(int i = 0; i < tamTrab; i++)
       {
           if(!trabajos[i].isEmpty)
           {
               mostrarTrabajo(trabajos[i], bicicletas, tamBic, servicios, tamServ);
               flag = 1;
               retorno = 1;
           }
       }
       if(!flag)
       {
           printf("No hay trabajos para mostrar\n");
       }
    }
       return retorno;
}


// ----------------- INFORMES-------------------------------------------


int mostrarBicicletaColor(eBicicleta bicicletas[], int tamBic, eColor colores[], int tamCol, eTipo tipos[], int tamTip)
{
    int retorno = 0;
    int opcion;
    //eBicicleta auxBicicleta;

    if(bicicletas != NULL && tamBic > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        listarColores(colores, tamCol);
        printf("Ingrese el ID del color por el cual desea mostrar: ");
        scanf("%d", &opcion);
        while(!validarIdColor(colores, tamCol, opcion))
        {
            printf("El ID seleccionado no es valido. Intente nuevamente\n");
            printf("Ingrese el ID del color por el cual desea mostrar: ");
            scanf("%d", &opcion);
        }

        for(int i = 0; i < tamBic; i++)
        {
            if(opcion == bicicletas[i].idColor)
            {
                mostrarBicicleta(bicicletas[i], tipos, tamTip, colores, tamCol);
            }
        }

        /*
        for(int i = 0; i < tamBic - 1; i++)
        {
            for(int j = i + 1; i < tamBic; i++)
            {
                if(bicicletas[i].idColor > bicicletas[j].idColor)
                {
                    auxBicicleta = bicicletas[i];
                    bicicletas[i] = bicicletas[j];
                    bicicletas[j] = auxBicicleta;
                }
            }
        }
        */
        retorno = 1;
    }
    return retorno;
}

int mostrarBicicletaTipo(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int retorno = 0;
    int opcion;
    //eBicicleta auxBicicleta;

    if(bicicletas != NULL && tamBic > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        listarTipos(tipos, tamTip);
        printf("Ingrese el ID del tipo por el cual desea mostrar: ");
        scanf("%d", &opcion);
        while(!validarIdTipo(tipos, tamTip, opcion))
        {
            printf("El ID seleccionado no es valido. Intente nuevamente\n");
            printf("Ingrese el ID del tipo por el cual desea mostrar: ");
            scanf("%d", &opcion);
        }

        for(int i = 0; i < tamBic; i++)
        {
            if(opcion == bicicletas[i].idTipo)
            {
                mostrarBicicleta(bicicletas[i], tipos, tamTip, colores, tamCol);
            }
        }

        /*
        for(int i = 0; i < tamBic - 1; i++)
        {
            for(int j = i + 1; i < tamBic; i++)
            {
                if(bicicletas[i].idTipo > bicicletas[j].idTipo)
                {
                    auxBicicleta = bicicletas[i];
                    bicicletas[i] = bicicletas[j];
                    bicicletas[j] = auxBicicleta;
                }
            }
        }
        */
        retorno = 1;
    }
    return retorno;
}

int verificacionMaterialBicicleta(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTip)
{
    int retorno = 0;
    int contadorTot = 0;
    int contadorCarb = 0;
    int contadorAl = 0;


    if(bicicletas != NULL && tamBic > 0 && tipos != NULL && tamTip > 0)
    {
        for(int i = 0; i < tamBic; i++)
        {
            if(bicicletas[i].material == 'a' || bicicletas[i].material == 'c')
            {
                contadorTot++;
                if(bicicletas[i].material == 'a')
                    contadorAl++;
                else if(bicicletas[i].material == 'c')
                    contadorCarb++;
            }
        }
        if(contadorTot > 0 &&
           (contadorAl > 1 || contadorCarb > 1 )
           )
        {
            printf("Hay mas de una bicicleta de carbono o aluminio\n");
            printf("En total son %d, siendo de carbono unas %d, y de aluminio otras %d", contadorTot, contadorCarb, contadorAl);
        }
        retorno = 1;
    }
    return retorno;
}

int listarBicicletasTipo(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int retorno = 0;
    eBicicleta auxBicicleta;

    if(bicicletas != NULL && tamBic > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        for(int i = 0; i < tamBic - 1; i++)
        {
            for(int j = i + 1; i < tamBic; i++)
            {
                if(bicicletas[i].idTipo > bicicletas[j].idTipo)
                {
                    auxBicicleta = bicicletas[i];
                    bicicletas[i] = bicicletas[j];
                    bicicletas[j] = auxBicicleta;
                }
            }
        }
        listarBicicletas(bicicletas, tamBic, tipos, tamTip, colores, tamCol);
        retorno = 1;
    }
    return retorno;
}

int contadorTipoColor(eBicicleta bicicletas[], int tamBic, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int retorno = 0;
    int opcionColor;
    int opcionTipo;
    int contadorColor = 0;
    int contadorTipo = 0;

    if(bicicletas != NULL && tamBic > 0 && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        listarColores(colores, tamCol);
        printf("Elija el ID correspondiente al color que desea contar\n");
        scanf("%d", &opcionColor);
        while(!validarIdColor(colores, tamCol, opcionColor))
        {
            printf("ID ingresado no valido. Intente nuevamente\n");
            printf("Elija el ID correspondiente al color que desea contar: ");
            scanf("%d", &opcionColor);
        }
        printf("\n\n");

        listarTipos(tipos, tamTip);
        printf("Elija el ID correspondiente al tipo que desea contar\n");
        scanf("%d", &opcionTipo);
        while(!validarIdTipo(tipos, tamTip, opcionTipo))
        {
            printf("ID ingresado no valido. Intente nuevamente\n");
            printf("Elija el ID correspondiente al tipo que desea contar: ");
            scanf("%d", &opcionTipo);
        }

        for(int i = 0; i < tamBic; i++)
        {
            if(opcionColor == bicicletas[i].idColor)
                contadorColor++;
            if(opcionTipo == bicicletas[i].idTipo)
                contadorTipo++;
        }
        if(contadorColor > 0 || contadorTipo > 0)
        {
            printf("Resultado del conteo de tipos y colores:\n\n");
            printf("Cantidad de bicicletas con el color seleccionado: %d\n", contadorColor);
            printf("Cantidad de bicicletas con el tipo seleccionado: %d\n", contadorTipo);
        }
        else
            printf("No hay bicicletas con ese tipo o color\n");

        retorno = 1;
    }
    return retorno;
}

int informeColoresMasElegidos(eBicicleta bicicletas[], int tamBici, eColor colores[], int tamCol)
{
    int retorno = 0;

    int contadorGris = 0; //5000
    int contadorBlanco = 0; //5001
    int contadorAzul = 0; //5002
    int contadorNegro = 0; //5003
    int contadorRojo = 0; //5004


    if(bicicletas != NULL && tamBici > 0 && colores != NULL && tamCol > 0)
    {
        for(int i = 0; i < tamBici; i++)
        {
            if(bicicletas[i].idColor == 5000)
                contadorGris++;
            else
            {
                if(bicicletas[i].idColor == 5001)
                    contadorBlanco++;
                else
                {
                    if(bicicletas[i].idColor == 5002)
                        contadorAzul++;
                    else
                    {
                        if(bicicletas[i].idColor == 5003)
                            contadorNegro++;
                        else
                        {
                            if(bicicletas[i].idColor == 5004)
                                contadorRojo++;
                        }
                    }
                }
            }
        }
        printf("Informe de los colores mas elegidos por los clientes:\n\n");
        printf("Gris: %d\n", contadorGris);
        printf("Blanco: %d\n", contadorBlanco);
        printf("Azul:: %d\n", contadorAzul);
        printf("Negro: %d\n", contadorNegro);
        printf("Rojo: %d\n", contadorRojo);

        retorno = 1;
    }
    return retorno;
}
