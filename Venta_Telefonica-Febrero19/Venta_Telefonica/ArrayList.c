#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int flag=0;
    //void** aux;

    if(this!=NULL && pElement!=NULL)
    {
        if(this->size == this->reservedSize)
        {
            if(resizeUp(this))// devuelve 0 si da ok
           {
             flag=1;// marca que no agregue el elemento porque no hay espacio
           }
        }
        if(flag==0)
         {
                //this->pElements[this->size]=pElement;
        *(this->pElements+this->size)=pElement;
           this->size++;
           returnAux=0;
         }


    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
        {
        free(this);
        returnAux=0;
        }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;


    if(this!=NULL && index>=0 && index < this->len(this)) //es < estricto porque size apunta al proximo valor
    {
        returnAux=this->pElements[index];
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement!=NULL)
    {
        returnAux=0;
        for(i=0;i<this->len(this);i++)
        {
            if(this->get(this,i)==pElement)
            {
                returnAux=1;
                break;
            }//fin if(this->)
        }//fin for
    }//fin if(this!=)

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL)
    {
        if(index<(this->size) && index>=0)
          {
              *(this->pElements+index)=pElement;
              returnAux=0;
          }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && index>=0 && index < al_len(this))
    {
     if(contract(this,index)==0)
     {
        this->size--;
        resizeDown(this);
        returnAux=0;
     }
       /* metrica=this->reservedSize-this->size;
        for(i=index;i<this->size;i++)
        {
          /*  if(this->pElements[i]==this->pElements[index])
            {
                free(this->pElements[i]);
                this->pElements[i]=NULL;
                returnAux=0;
            }*/
   //         this->pElements[i]=this->pElements[i+1];
  //)      }//fin for
 //       this->size--;
 //       returnAux=0;*/
  //  }//fin if(this!
/*
    if(metrica==0)
    {
        pElements=realloc(pElements,reserveSize+)
    }   */
}//fin if(this!=NULL)
    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        free(this->pElements);
        this->size=0;
        returnAux=0;
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
   // int i;

    if(this!=NULL)
    {
     returnAux=al_subList(this,0,al_len(this));
    }//fin if(this!)

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL && index < al_len(this) && index >=0)
    {
        if(expand(this,index)==0)
           {
             //returnAux=al_set(this->pElements,index,pElement);
             returnAux=al_set(this,index,pElement);
           }
      //  if(this->size==this->reservedSize)
      //  {
     //       resizeUp(this);
     //   }
   // if(index < this->size)
  //  {

  //  }
  //  else
   //     if(index==this->size)
   // {
    //    al_add(this,pElement);
   // }

    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=0 && pElement!=NULL)
    {
        for(i=0;i<=al_len(this);i++)
        {
           // if(this->pElements[i]==pElement)
            if(al_get(this,i)==pElement)
            {
            returnAux=i;
            break;
            }
        }//fin for
    }//fin if

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(al_len(this)==0)
            returnAux=1;
        else
            if(al_len(this)>0)
            returnAux=0;
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index >=0 && index< al_len(this))
    { //  returnAux=*(this->pElements+index);
        returnAux=al_get(this,index);
        al_remove(this,index);
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux = NULL;

    int cant,i;
    if(this!=NULL)
    {
        if(from>=0 && from<to && from<this->len(this) && to >from && to<=this->len(this))
        {
        returnAux=al_newArrayList();
        //cant=this->size;
          for(i=from;i<to;i++)
          {
            //  al_add(returnAux,this->pElements[i]);
              al_add(returnAux,al_get(this,i));
          }//fin for(i=from)

        }//fin if from
    }//fin this!

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int i,cont=0;

    if(this!=NULL && this2!=NULL)
    {
        returnAux=0;

        if(al_len(this) >= al_len(this2) && al_len(this)>0 && al_len(this2) >0)
        {
            for(i=0;i<al_len(this);i++)
            {
                if(al_contains(this,al_get(this2,i))==1)
                   cont++;
            else
               {
                break;
                }
            }//fin for(i=0)

            if(cont==al_len(this2))
            {
                returnAux=1;
            }

        }//fin if(cant<)
        else
        returnAux=0;

    }//fin if(this)


    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int* aux;
    int i,j;

    if(this!= NULL && pFunc!=NULL && (order==0 || order==1))
    {
        if(aux!=NULL)
        {
            for(i=0;i < al_len(this)-1;i++)
            {
                for(j=i+1;j<al_len(this);j++)
                {
                    if(order==0)
                    {
                        if(pFunc(al_get(this,i),al_get(this,j))==-1)
                        {
                        aux=al_get(this,i);
                        al_set(this,i,al_get(this,j));
                        al_set(this,j,aux);
                    }//fin if
                returnAux=0;
                }//fin if(order==0)
                if(order==1)
                {
                    if(pFunc(al_get(this,i),al_get(this,j))==1)
                    {
                        aux=al_get(this,i);
                        al_set(this,i,al_get(this,j));
                        al_set(this,j,aux);

                    }
                returnAux=0;
                }//fin if
            }//fin 1er for
            } //fin 2do for
        }//fin 1er for
    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** aux;

    aux = realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));

    if(aux != NULL)
    {
        this->reservedSize+= AL_INCREMENT;
        this->pElements = aux;
        returnAux = 0;
    }
    return returnAux;

}

int resizeDown(ArrayList* this)
{
    int returnAux=-1;
    void **aux;

    if(this!=NULL)
    {
        if(al_len(this)+ AL_INCREMENT > this->reservedSize)
        {
            aux=(void**)realloc(this->pElements,sizeof(void*)*(al_len(this)+AL_INCREMENT));
            if(aux !=NULL)
            {
                returnAux = 0;
                this->pElements=aux;
                this->reservedSize=al_len(this)+AL_INCREMENT;
            }
        }//fin(al_len)
    }
    return returnAux;
}




/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(index!=NULL && index < this->len(this) && this!=NULL)
    {

        for(i=this->len(this);i>index;i--)
        {
          //  if(i==this->len(this))
            if(i==al_len(this))
            {
               if(al_add(this,al_get(this,i))==0)
               returnAux=0;

            }//fin if(i==)
            else
            {
                 //this->pElements[i+1]=this->pElements[i];
                 if(al_set(this,i+1,al_get(this,i))==0)
                    returnAux=0;
            }

        }//fin for

    }//fin if(index

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && index < al_len(this))
    {
        for(i=index;i<al_len(this);i++)
        {
          //  this->pElements[i]=this->pElements[i+1];
            al_set(this,i,al_get(this,i+1));
        }
        returnAux=0;

    }//fin if

    return returnAux;
}

//***********************FUNCIONES DE ARRAYlIST PERSONALES***********************
ArrayList* al_filter2(ArrayList* listIn , int (*functionFilter)(void* ,void*),ArrayList* listBuscar,int Existe)
{
    ArrayList *ListaTemp=NULL;
    ListaTemp= al_newArrayList();

    if(listIn!=NULL && functionFilter!=NULL && ListaTemp!=NULL && listBuscar!=NULL && ( Existe==0 || Existe==1 ))
    {
        for(int i=0;i<listIn->len(listIn);i++)
        {
                if( functionFilter(listBuscar,listIn->get(listIn,i) )== Existe )
                {
                    ListaTemp->add(ListaTemp,listIn->get(listIn,i) );
                }
        }
        return ListaTemp;
    }
}
int al_mapp(ArrayList *this, int (*funcion)(void*))
{
    int retorno=-1;
   // ArrayList* ListaAuxiliar;
  //  ListaAuxiliar=al_newArrayList();
    int cont=0;
    int i;
    if(this !=NULL)
    {
        retorno=0;
        for(i=0;i<this->len(this);i++)
        {
          if(funcion(this->get(this,i))==1);//se lo paso a la funcion
            {
                cont++;
                //ListaAuxiliar->add(this,this->get(this,i));
                //ListaAuxiliar=al_add(this,this->get(this,i));
            }//fin if

        }//fin for

    }//fin if(lista!=NULL)
    if(cont==al_len(this))
    {
        retorno=1;
    }
    return retorno;
}
int al_map(ArrayList *this, int (*funcion)(void*))
{
    int retorno=-1;
   // ArrayList* ListaAuxiliar;
  //  ListaAuxiliar=al_newArrayList();
    int cont=0;
    int i;
    if(this !=NULL)
    {
        retorno=0;
        for(i=0;i<this->len(this);i++)
        {
          if(funcion(this->get(this,i))==1);//se lo paso a la funcion
            {
                cont++;
                //ListaAuxiliar->add(this,this->get(this,i));
                //ListaAuxiliar=al_add(this,this->get(this,i));
            }//fin if

        }//fin for

    }//fin if(lista!=NULL)
    if(cont==al_len(this))
    {
        retorno=1;
    }
    return retorno;
}
ArrayList* al_filter(ArrayList* this ,int (*Pfunc)(void*))
{
    int i;
    ArrayList *ListaAux=NULL;
    ListaAux= al_newArrayList();

    if(this!=NULL && Pfunc!= NULL && ListaAux !=NULL)
    {
        for(i=0;i<this->len(this);i++)
        {
                if( Pfunc(this->get(this,i) )==0  )
                {
                    ListaAux->add(ListaAux,this->get(this,i) );
                }
        }
    }
    return ListaAux;
}
ArrayList* al_eliminaDuplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_clone(this);
        if(ListAux!=NULL)
        {
            for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
            {
                for(int j=i+1;j < ListAux->len(ListAux) ; )
                {
                    if(pFunc(al_get(ListAux,i),al_get(ListAux,j))==0)
                    {
                      ListAux->pop(ListAux,j);
                    }
                    else
                    {
                        j++;
                    }
                }//FIN for(int j=i+1;j < ListAux->len(ListAux) ;j++)
            }//FIN for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
        }
    }
    return ListAux;
}
ArrayList* al_Muestra_Duplicados(ArrayList* this, int (*pFunc)(void* ,void*))
{
    ArrayList* ListAux;
    int cont=0;
  //  ArrayList* ListDupl;
    if(this!= NULL && pFunc!=NULL )
    {
        ListAux=al_newArrayList();
        if(ListAux!=NULL)
        {
            for(int i=0; i< ( this->len(this) ) -1 ;i++) //recorreo el ArrayList, hago un burbujeo
            {
                ListAux->add(ListAux,al_get(this,i));//agrego la primer ocurrencia al ArrayList
                for(int j=i+1;j < this->len(this);j++ )
                {
                    if(pFunc(al_get(this,i),al_get(this,j))==0) //evaluo si son iguales
                    {
                    ListAux->add(ListAux,al_get(this,j));//agrego las ocurrencias
                    }//fin if(pFunc
                }//FIN for(int j=i+1;j < ListAux->len(ListAux) ;j++)
            }//FIN for(int i=0; i< ( ListAux->len(ListAux) ) -1 ;i++)
        }

        ListAux->sort(ListAux,pFunc,0); //ordeno
    }
    return ListAux;
}
int al_map2(ArrayList *this, int (*funcion)(void*))
{
    int retorno=-1;
   // ArrayList* ListaAuxiliar;
  //  ListaAuxiliar=al_newArrayList();
    int cont=0;
    int i;
    if(this !=NULL)
    {
        retorno=0;
        for(i=0;i<this->len(this);i++)
        {
          if(funcion(this->get(this,i))==1);//se lo paso a la funcion
            {
                cont++;
                //ListaAuxiliar->add(this,this->get(this,i));
                //ListaAuxiliar=al_add(this,this->get(this,i));
            }//fin if

        }//fin for

    }//fin if(lista!=NULL)
    if(cont==al_len(this))
    {
        retorno=1;
    }
    return retorno;
}
