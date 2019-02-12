#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED




#endif // ARCHIVO_H_INCLUDED


/** \brief Abre un archivo para escritura
 *
 * \param ArrayList
 * \param nombre del archivo
 * \return 1 si el archivo se pudo abrir,0 si no se pudo abrir
 *
 */
int cargarDesdeArchivo(ArrayList *this,const char* nombre);//int (*pFunc)(void*));

/** \brief hace el parser del archivo y lo guarda en la estructura
 *
 * \param puntero a archivo
 * \param puntero al ArrayList
 * \return 0 si no hubo error
 *
 */
int parserEstructura(FILE* pFile, ArrayList* this);

/** \brief guarda un archivo de texto
 *
 * \param puntero al ArrayList
 * \param nombre del archivo a guardar
 * \return 1 si esta OK, 0 si hubo error
 *
 */
int GuardarArchivoT(ArrayList* this, const char* nombre);

int parserEstructuraUsuario(FILE* pFile, ArrayList* this);
