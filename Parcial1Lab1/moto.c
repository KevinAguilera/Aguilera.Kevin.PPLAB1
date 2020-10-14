#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "moto.h"

#include "validations.h"
#include "menu.h"
#include "extras.h"

#define EMPTY 0
#define TAKEN 1

void moto_hardcode(eMoto motorcycles[], int motorcyclesToHardcode)
{
    int ids[] = {1000,1001,1002,1003,1004};
    char brands[][20] = {"Honda", "Suzuki", "Harley", "Yamaha", "Kawasaki"};
    int idsType[] = {1000,1001,1002,1003,1004};
    int idsColor[] = {10000,10001,10002,10003,10004};
    int cilindradas[] = {50,125,500,600,750};

    for(int i=0; i<motorcyclesToHardcode; i++)
    {
        motorcycles[i].id = ids[i];
        strcpy(motorcycles[i].brand, brands[i]);
        motorcycles[i].idType = idsType[i];
        motorcycles[i].idColor = idsColor[i];
        motorcycles[i].cilindrada =  cilindradas[i];
        motorcycles[i].state = TAKEN;
    }
}

void moto_initializate(eMoto motorcycles[], int sizeMotorcycles)
{
    for(int i=0; i<sizeMotorcycles; i++)
    {
        motorcycles[i].state = EMPTY;
    }
}
int moto_findFreeSpace(eMoto motorcycles[], int sizeMotorcycles)
{
    int ret = -1;

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == EMPTY)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int moto_findOne(int id, eMoto motorcycles[], int sizeMotorcycles)
{
    int ret = -1;

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].id == id && motorcycles[i].state == TAKEN)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int moto_load(int id, eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColor)
{
    eMoto auxMoto;
    int index = moto_findFreeSpace(motorcycles, sizeMotorcycles);
    int ok = 0;

    system("cls");
    printf("\n\t*** ALTA ************************************************************************************\n\n");

    if(index == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system("pause");
    }
    else
    {

        auxMoto.id = id;

        validations_getText(auxMoto.brand,"\n\tIngrese la marca: ", "\n\t(!) Error. Caracteres invalidos.\n", 2, 20, 4);

        type_show(types, sizeTypes);
        validations_getUnsignedInt(&auxMoto.idType,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 1000-1003\n",1,1003,1000,1003,4);

        validations_getUnsignedInt(&auxMoto.cilindrada,"\n\tIngrese la cilindrada: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 50-2500\n",1, 2500,50,2500,4);

        auxMoto.state = TAKEN;

        motorcycles[index] = auxMoto;

        printf("\n\n\t\t>>> Cargado exitosamente <<<\n\n\n");
        system("cls");
        ok = 1;

    }
    return ok;
}

void moto_delate(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int id;
    int index;

    system("cls");
    printf("\n\t*** BAJA ************************************************************************************\n\n");

    moto_show(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = moto_findOne(id, motorcycles, sizeMotorcycles);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de una moto con el ID: %d <<<\n\n\n", id);
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\t\tLa moto que se dara de baja es:");
        printf("\n\t\t _________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA          ");
        printf("\n\t\t _________________________________________________________________________________\n");
        moto_showOne(motorcycles[index], types, sizeTypes, colors, sizeColors);
        printf("\n\t\t _________________________________________________________________________________\n\n");

        if(confirm(2))
        {
            motorcycles[index].state = EMPTY;
        }
    }
}

void moto_modify(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int id;
    int index;
    int newCilindrada;
    int newIDColor;

    system("cls");
    printf("\n\t*** MODIFICACION ****************************************************************************\n\n");

    moto_show(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = moto_findOne(id, motorcycles, sizeMotorcycles);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de una moto con el ID: %d <<<\n\n\n", id);
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\t\tLa moto que se modificara es:");
        printf("\n\t\t __________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA            ");
        printf("\n\t\t __________________________________________________________________________________\n");
        moto_showOne(motorcycles[index], types, sizeTypes, colors, sizeColors);
        printf("\n\t\t __________________________________________________________________________________\n\n");

        switch(menu_motoModify())
        {
        case 1:
            color_show(colors, sizeColors);
            validations_getUnsignedInt(&newIDColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);
            if(confirm(3))
            {
                motorcycles[index].idColor = newIDColor;
            }
            break;
        case 2:
            validations_getUnsignedInt(&newCilindrada,"\n\tIngrese la cilindrada: ", "\n\t(!) Error. Ingrese un valor numerico entero desde 50 hasta 2500.\n",1,2500,50,2500,4);
            if(confirm(3))
            {
                motorcycles[index].cilindrada = newCilindrada;
            }
            break;
        }

        printf("\n");
        printf("\n\t\t __________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA          ");
        printf("\n\t\t __________________________________________________________________________________\n");
        moto_showOne(motorcycles[index], types, sizeTypes, colors, sizeColors);
        printf("\n\t\t __________________________________________________________________________________\n\n");

        system("pause");
    }
}

void moto_show(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int flag = 0;

    printf("\n\t\t ______________________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA               ");
    printf("\n\t\t ______________________________________________________________________________________\n");
    moto_sort(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors);
    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == TAKEN)
        {
            moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}

void moto_showOne(eMoto x, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    char typeDescription[20];
    char colorName[20];

    moto_loadTypeDescription(typeDescription, x.idType, types, sizeTypes);
    moto_loadColorName(colorName, x.idColor, colors, sizeColors);


    printf("\n\t\t    %5d  %15s   %15s  %10s         %5d         \n", x.id, x.brand, typeDescription, colorName, x.cilindrada);
}

void moto_sort(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    eMoto auxMoto;

    for(int i=0; i<sizeMotorcycles-1; i++)
    {
        for(int j=i+1; i<sizeMotorcycles; i++)
        {
            if(motorcycles[i].idType > motorcycles[j].idType)
            {
                auxMoto = motorcycles[i];
                motorcycles[i] = motorcycles[j];
                motorcycles[j] = auxMoto;
            }
            else if(motorcycles[i].idType == motorcycles[j].idType && motorcycles[i].id > motorcycles[j].id)
            {
                auxMoto = motorcycles[i];
                motorcycles[i] = motorcycles[j];
                motorcycles[j] = auxMoto;
            }
        }
    }
}

int moto_loadTypeDescription(char description[], int id, eType types[], int sizeTypes)
{
    int ok = 0;

    for(int i=0; i<sizeTypes; i++)
    {
        if(types[i].id == id)
        {
            strcpy(description, types[i].description);
            ok = 1;
        }
    }

    return ok;
}

int moto_loadColorName(char colorName[], int id, eColor colors[], int sizeColors)
{
    int ok = 0;

    for(int i=0; i<sizeColors; i++)
    {
        if(colors[i].id == id)
        {
            strcpy(colorName, colors[i].colorName);
            ok = 1;
        }
    }

    return ok;
}

