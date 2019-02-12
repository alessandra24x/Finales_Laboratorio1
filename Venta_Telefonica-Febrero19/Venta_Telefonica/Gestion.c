#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Archivo.h"
#include "Estructura.h"
#include "Tools.h"
#include "Vista.h"

int gestion_Recorre_ArrayList(ArrayList *this,int (*pFunc)(void*))
{
    int retorno=-1;
    int i;
    if(this!=NULL )
    {
        retorno=-2;
        if(this->isEmpty(this)==0)
        {//No esta vacio
            for(i=0; i<this->len(this) ; i++)
            {
                retorno=pFunc(al_get(this,i)); //llamada a una funcion que se pasa por parametro
            }
        }//if(this->isEmpty(this)==0)
    }//if(this!=NULL && Titulo!=NULL)
    return retorno;
}
/*eEstructura* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eEstructura *record;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))//si es 1 busca maximo
    {
        if(aux!=NULL)
        {
            aux=(al_get(this,i));
            for(i=1;i < al_len(this)-1;i++)
            {
                if(valor==1)
                {
                    if(pFunc(aux,al_get(this,i))==1)
                    {
                       record=aux;
                       returnAux=0;
                    }//fin if(pfunc)
                    else
                    {
                        aux=al_get(this,i);
                        record=aux;
                    }
                    }//fin if(valor)
                if(valor==0)
                {
                    if(pFunc(aux,al_get(this,i))==-1)
                    {
                        record=aux;
                      //  aux=al_get(this,i);
                    }
                else
                {
                 aux=al_get(this,i);
                 record=aux;
                }
                returnAux=0;
                }//fin if
            }//fin 1er for
          //  } //fin 2do for
        }//fin 1er for
    }
    return record;
}
*/
/*int gestion_buscarId(ArrayList* this, int cod)
{
    int retorno=0;
    int i;
    eEstructura* record;
    if(this!=NULL && cod >0)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;
    //    if(record !=NULL)
    //    {
            for(i=0;i<this->len(this);i++)
            {
            record=this->get(this,i);
            if(estruc_get_id(record)==cod)
            {
                retorno=i;
                break;
            }//fin if
            else if(estruc_get_id(record)!=cod)
            {
                retorno=-1;
            }
            }//fin for
//        }//fin if(record)
        }
    }//fin if(this!)
    return retorno;
}
int gestion_mover_elemento(ArrayList* this,ArrayList* that,int id)
{
    int retorno=-1;
    eEstructura* record=NULL;
    if(this!=NULL && that!=NULL)
    {
        retorno=0;
      // record = this->pop(this, this->indexOf(this, record));
        record = this->pop(this, id);
       if(record!=NULL)
       {
           that->add(that,record);
           this->sort(this,prod_comparaProducto,1); //ordena el array origen
           that->sort(that,prod_comparaProducto,1); //ordena el array destino
           printf("se movio correctamente\n");
           system("pause");
       }

        else
        {
            printf("No hay nada para mover\n");
            system("pause");
        }
    }
    return retorno;
}
int gestion_BuscarYMover_elemento(ArrayList* this,ArrayList* that)//buscar y mover eligiendo deposito
{
    int retorno=-1;
    int cod_prod,id,num_deposito;
    char resp;
    eProducto* prod;
    switch(vista_Pedir_Deposito(num_deposito))
    {
    case 0:
        vista_MostrarElementos(this,"Productos Deposito Nro 0",0,this->len(this));
        cod_prod=Valida_PedirEntero("Ingrese el Codigo del producto a mover:\n");
        if(cod_prod >0)
        {
            retorno=0;
            id=prod_buscarId(this,cod_prod);
            vista_Muestra1UnElemento(al_get(this,id));
            resp=Valida_confirmacion("Confirma mover este producto del deposito 0 al 1?");
            if(resp=='S')
            {
           // retorno=prod_mover(this,that,id);
            prod = this->pop(this, id);
            that->add(that,prod);
            this->sort(this,prod_comparaProducto,1);
            that->sort(that,prod_comparaProducto,1);
            printf("se movio correctamente\n");
            system("pause");
           // printf("retorno: %d",retorno);
           // system("pause");
           // retorno=1;
            }//fin if(resp)
        else
        {
            printf("Se cancelo la operacion:\n");
            retorno=2;
        }
    }//fin if(cod_prod)
    else
    {
        printf("Error no se encontro el codigo\n");
    }
    if(retorno=1)
    {
        printf("Se movio correctamente\n");
    }
    break;
    case 1:
        vista_MostrarElementos(that,"Productos Deposito Nro 1",0,that->len(that));
        cod_prod=Valida_PedirEntero("Ingrese el Codigo del producto a mover:\n");
        if(cod_prod >0)
        {
            retorno=0;
            id=prod_buscarId(that,cod_prod);
            vista_Muestra1UnElemento(al_get(that,id));
            resp=Valida_confirmacion("Confirma mover este producto del deposito 1 al 0?");
            if(resp=='S')
            {
           // retorno=prod_mover(this,that,id);
            prod = that->pop(that, id);
            this->add(this,prod);
            this->sort(this,prod_comparaProducto,1);
            that->sort(that,prod_comparaProducto,1);
            printf("se movio correctamente\n");
            system("pause");
           // printf("retorno: %d",retorno);
           // system("pause");
           // retorno=1;
            }//fin if(resp)
        else
        {
            printf("Se cancelo la operacion:\n");
            retorno=2;
        }
    }//fin if(cod_prod)
    else
    {
        printf("Error no se encontro el codigo\n");
    }
    if(retorno=1)
    {
        printf("Se movio correctamente\n");
    }
    break;
    }//fin switch
    return retorno;
}
*/
