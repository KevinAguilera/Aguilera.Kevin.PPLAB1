#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "moto.h"
#include "type.h"
#include "color.h"
#include "service.h"
#include "work.h"
#include "extras.h"
#include "menu.h"

#define SIZE_MOTO 10
#define SIZE_TYPE 4
#define SIZE_COLOR 5
#define SIZE_SERVICE 4
#define SIZE_WORK 10
#define HARDCODESIZE 5
#define HARDCODESIZE_WORK 4


int main()
{
    eMoto motorcycles[SIZE_MOTO];
    eType types[SIZE_TYPE] = {{1000,"Enduro"}, {1001,"Chopera"}, {1002, "Scooter"}, {1003, "Ciclomotor"}};
    eColor colors[SIZE_COLOR] = {{10000,"Gris"}, {10001,"Negro"}, {10002, "Blanco"}, {10003, "Azul"}, {10004, "Rojo"}};
    eService services[SIZE_SERVICE] = {{20000, "Limpieza", 250}, {20001, "Ajuste", 300}, {20002, "Balanceo", 17}, {20003, "Cadena", 190}};
    eWork works[SIZE_WORK];

    char cont = 's';
    int nextIDMoto = 1000;
    int nextIDWork = 0;
    int flag = 0;


    moto_initializate(motorcycles, SIZE_MOTO);
    work_initializate(works, SIZE_WORK);

    moto_hardcode(motorcycles, HARDCODESIZE);
    nextIDMoto += HARDCODESIZE;

    work_hardcode(works, HARDCODESIZE_WORK);
    nextIDWork += HARDCODESIZE_WORK;


    do
    {
        switch(menu_main())
        {
        case 1:
            if(moto_load(nextIDMoto,motorcycles, SIZE_MOTO, types, SIZE_TYPE, colors, SIZE_COLOR)== 1)
            {
                nextIDMoto++;
            }
            flag = 1;
            break;
        case 2:

            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {

                moto_delate(motorcycles, SIZE_MOTO, types, SIZE_TYPE, colors, SIZE_COLOR);
            }

            break;
        case 3:
            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {

                moto_modify(motorcycles, SIZE_MOTO, types, SIZE_TYPE, colors, SIZE_COLOR);
            }

            break;
        case 4:

            if(flag == 0)
            {
                printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
            }
            else
            {
                moto_show(motorcycles,SIZE_MOTO, types, SIZE_TYPE, colors, SIZE_COLOR);
                system("pause");

            }

            break;
        case 5:
            type_show(types, SIZE_TYPE);
            break;
        case 6:
            color_show(colors, SIZE_COLOR);
            break;
        case 7:
            service_show(services, SIZE_SERVICE);
            break;
        case 8:
            if(work_load(nextIDWork, works, SIZE_WORK, motorcycles, SIZE_MOTO, types, SIZE_TYPE, colors, SIZE_COLOR, services, SIZE_SERVICE) == 1)
            {
                nextIDWork++;
            }
            break;
        case 9:
            work_show(works, SIZE_WORK, motorcycles, SIZE_MOTO, services, SIZE_SERVICE);
            break;
        case 10:
            if(confirm(10) == 1)
            {
                cont = 'n';
            }
            break;
        }
    }
    while(cont == 's');

    return 0;
}
