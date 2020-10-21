
#ifndef INFORMS_H_INCLUDED
#define INFORMS_H_INCLUDED


#endif // INFORMS_H_INCLUDED

/** \brief Muestra el menu de informes y hace lo indicado en la opcion
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \return void
 *
 */
void inform(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eService services[], int sizeServices, eWork works[], int sizeWorks);


/** \brief Muestra las motos del color seleccionado por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_motoXcolor(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Muestra las motos del tipo seleccionado por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_motoXtype(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Informa la o las motos de mayor cilindrada
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_motoWithHigherCilindrada(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Muestra un listado de las motos separadas por tipo
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_motoXAllTypes(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Informa la cantidad de motos que hay de un tipo y color ingresado por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_motoCountByColorAndType(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors);

/** \brief Muestra todos los trabajos realizados en una moto ingresada por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */

void inform_motoAndWorks(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeService);
/** \brief Informa la suma de los importes de los servicios que se le hicieron a una moto y la fecha
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_sumOfAmountsOfWorks(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeServices);
/** \brief Muestra las motos a las que se le realizo un servicio ingresado por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colore
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_serviceAndMotos(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeServices);
/** \brief Muestra todos los servicios realizados en una fecha ingresada por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_serviceXdate(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eWork works[], int sizeWorks, eService services[], int sizeServices);

