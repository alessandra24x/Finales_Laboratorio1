#ifndef GESTION_H_INCLUDED
#define GESTION_H_INCLUDED




#endif // GESTION_H_INCLUDED

/** \brief Recorre todo el ArrayList e invoca una funcion para realizar alguna operacion
 *
 * \param ArrayList
 * \param funcion
 * \return la evaluacion de la funcion invocada
 */

int gestion_Recorre_ArrayList(ArrayList *this,int (*pFunc)(void*));


/** \brief busca por id en un ArrayList
 *
 * \param ArrayList
 * \param int elemento a buscar
 * \return int posicion del valor buscado
 */

int gestion_buscarId(ArrayList* this, int cod);

/** \brief Mueve un elemento seleccionado de un ArrayList a otro
 *
 * \param ArrayList origen
 * \param ArrayList destino
 * \param id del elemento a mover
 * \return 1 si ok
 */
int gestion_mover_elemento(ArrayList* this,ArrayList* that,int id);
