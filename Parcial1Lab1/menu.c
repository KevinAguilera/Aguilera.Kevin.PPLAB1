#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "extras.h"
#include "validations.h"


int menu_main()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  ____________________________________");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *                MENU                *");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *    1.  ALTA DE MOTO                *");
    printf("\n\t\t\t\t *    2.  BAJA DE MOTO                *");
    printf("\n\t\t\t\t *    3.  MODIFICACION DE MOTO        *");
    printf("\n\t\t\t\t *    4.  LISTAR MOTOS                *");
    printf("\n\t\t\t\t *    5.  LISTAR TIPOS                *");
    printf("\n\t\t\t\t *    6.  LISTAR COLORES              *");
    printf("\n\t\t\t\t *    7.  LISTAR SERVICIOS            *");
    printf("\n\t\t\t\t *    8.  ALTA TRABAJO                *");
    printf("\n\t\t\t\t *    9.  LISTAR TRABAJOS             *");
    printf("\n\t\t\t\t *    10. SALIR                       *");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *____________________________________*\n\n");
    option = getOption(10);

	return option;
}

int menu_motoModify()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |          QUE DESEA MODIFICAR?         |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. COLOR                           |");
    printf("\n\t\t\t\t |    2. CILINDRADA                      |");
    printf("\n\t\t\t\t |    3. VOLVER                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(3);

    return option;
}
