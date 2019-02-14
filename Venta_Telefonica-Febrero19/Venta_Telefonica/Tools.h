#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED


#endif // TOOLS_H_INCLUDED

/** \brief solicita una respuesta por S (si) o por N (no) al usuario por pantalla
 *
 * \param mensaje que se muestra por pantalla
 * \return variable char que vale S o N
 */
char Responder(char mensaje[]);

/** \brief valida el rango de opciones a elegir
 *
 * \param entero que guarda la opcion
 * \param entero con el limite inferior
 * \param entero con el limite superior
 * \return
 */
void tools_ValidaMenu(int opcion,int limite_inferior,int limite_superior);


/** \brief filtra elementos segun un criterio
 *
 * \param variable del tipo estructura
 * \return
 */
int funcionFiltro(void* aux);


/** \brief pide el ingreso de un entero y lo valida
 *
 * \param texto que se muestra por pantalla
 * \param entero con el valor minimo permitido
 * \param entero con el valor maximo permitido
 * \return
 */
int tools_ingresarInt (char pregunta[], int minimo,int maximo);


/** \brief verifica que la longitud de la cadena sea igual a la cantidad maxima
 *
 * \param cadena de caracteres
 * \param cantidad que debe tener la cadena
 * \return 1 si ok
 *
 */
int tools_ValidarCantCaracteres(char* cadena,int cantidad);


/** \brief saca los espacios de una cadena de caracteres
 *
 * \param cadena de caracteres
 * \return
 *
 */

void tools_RemoveSpaces(char* source);


/** \brief pide el ingreso de un entero por pantalla y lo valilda
 *
 * \param mensaje para imprimir
 * \return
 */
int tools_PedirEntero(char mensaje[]);

int tools_ComparaNombre(void* eEmpleadoA,void* eEmpleadoB);


ArrayList* Compara_2ArrayList(ArrayList* this,ArrayList* that,int (*pFunc)(void*,void*));
