#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED


#endif // VISTA_H_INCLUDED


/** \brief Muestra el menu de inicio
 *
 * \param opciones para imprimir en el menu
 * \return
 *
 */
void vista_ShowMenu(char *opcion);

/** \brief Imprime un titulo por pantalla
 *
 * \param Titulo que se desea imprimir
 * \return
 *
 */
void vista_ShowTitulo(char titulo[]);


/** \brief Imprime un elemento de tipo de la estructura
 *
 * \param elemento del tipo de la estructura
 * \return
 *
 */
int vista_MuestraUnElemento(void * record);



/** \brief Muestra un listado de los elementos del ArrayList
 *
 * \param ArrayList
 * \param Titulo del listado que se muestra en pantalla
 * \param nombre de la funcion que muestra 1 elemento
 * \param entero que representa desde donde se va a imprimir
 * \param entero que respresenta hasta donde se va a imprimir
 * \return
 */
int vista_MuestraElementos(ArrayList *this,char *Titulo,char *Subtitulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado);


/** \brief pide el ingreso de un texto y lo valida
 *
 * \param variable de caracteres
 * \param entero que representa la longitud del texto
 * \param pregunta que se imprime por pantalla
 * \return variable con el texto ingresado
 */
void vista_ingresarTexto (char texto[], int cantTexto, char pregunta[]);


int vista_MuestraUnElementoUsuario(void * record);
//int vista_MuestraUnFEED(eFeed * record);
//int Muestra1UnElementoSalario(eVentas * emp);
