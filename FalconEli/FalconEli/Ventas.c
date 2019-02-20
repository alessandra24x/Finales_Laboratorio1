#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Ventas.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"
#define JUNIOR 0
#define ESTANDAR 1
#define EXPERTO 2


eVentas* nuevo_record(void)
{
    eVentas* returnAux;
    returnAux = (eVentas*)malloc(sizeof(eVentas));
    return returnAux;
}
eVentas* ventas_nuevoVendedor(int id,char nombre[], int nivel,int vendidos,float monto)
{
    eVentas* retorno = NULL;
    eVentas* pVentas = malloc(sizeof(eVentas));

    if(pVentas != NULL)
    {
        ventas_set_id(pVentas,id);
        ventas_set_nombre_vendedor(pVentas,nombre);
        ventas_set_nivel(pVentas,nivel);
        ventas_set_CantVend(pVentas,vendidos);
        ventas_set_CantVend(pVentas,vendidos);
        ventas_set_monto(pVentas,monto);
        retorno = pVentas;
    }
    return retorno;
}

//*************GETTERS Y SETTERS ************************



int ventas_set_id(eVentas* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }
    return retorno;
}

int ventas_get_id(eVentas* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id;
    }
    return num;
}
int ventas_set_CantVend(eVentas* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->cantidad_productos_vendidos=num;
        retorno = 1;
    }
    return retorno;
}

int ventas_get_CantVend(eVentas* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->cantidad_productos_vendidos;
    }
    return num;
}


char* ventas_get_nombre_vendedor(eVentas* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->nombre_vendedor;
    }
    return texto;
}

int ventas_set_nombre_vendedor(eVentas* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->nombre_vendedor,texto);
        retorno =1;
    }
    return retorno;
}
int ventas_set_nivel(eVentas* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->nivel=num;
        retorno = 1;
    }
    return retorno;
}

int ventas_get_nivel(eVentas* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->nivel;
    }
    return num;
}

int ventas_set_monto(eVentas* this, float flotante)
{
    int retorno =0;
    if(this!=NULL)
    {
        this->monto_vendido=flotante;
        retorno =1;
    }
    return retorno;
}

float ventas_get_monto(eVentas* this)
{
    float flotante;
    if(this!=NULL)
    {
        flotante=this->monto_vendido;
    }
    return flotante;
}

int ventas_set_comision(eVentas* this, float flotante)
{
    int retorno =0;
    if(this!=NULL)
    {
        this->comision=flotante;
        retorno =1;
    }
    return retorno;
}

float ventas_get_comision(eVentas* this)
{
    float flotante;
   // printf("%f",this->comision);
    if(this!=NULL)
    {
        flotante=this->comision;
    }
    return flotante;
}

//**************FIN GETTERS Y SETTERS ************************
//*************************************************************

int CalcularSalary(eVentas* element)
{
    int auxiliar=0;
    int cont=0;
    int retorno=-1;
   // eEmpleado *element;

    if(element !=NULL)
    {
        retorno=0;
     //   switch (element->nivel)
        switch (ventas_get_nivel(element))
        {
          //  case JUNIOR:
            case 0:
                 auxiliar=ventas_get_monto(element)*0.02;
                retorno=1;
                break;
         // case EXPERTO && ESTANDAR:
            default:
                if(element->cantidad_productos_vendidos < 100 && element->cantidad_productos_vendidos >=1)
                    {
                      auxiliar=ventas_get_monto(element)*0.035;
                    }
                else
                    if(element->cantidad_productos_vendidos >= 100 )
                        {
                        auxiliar=ventas_get_monto(element)*0.05;
                        retorno=1;
                        }
                        break;
      }
        if(retorno=1)
            {
            ventas_set_comision(element,auxiliar);
            }
    }

    return retorno;
    }//fin if(element !=)

/*int est_compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno=-1;
    void *tmp_1;
    void *tmp_2;
    tmp_1=(void* ) pElementA;
    tmp_2=(void * ) pElementB;

   if(tmp_1-> > tmp_2->void)
    {
        retorno=1;
    }
    else
    {
        if(tmp_1->letra < tmp_2->letra)
        {
            retorno=0;
        }
    }
    return retorno;
}*/

int compara_elementos_Estructura(void* pElementA,void* pElementB)
{
    int retorno=0;
    eVentas *tmp_1;
    eVentas *tmp_2;
    tmp_1=(eVentas * ) pElementA;
    tmp_2=(eVentas * ) pElementB;

    if(tmp_1->nivel > tmp_2->nivel)
    {
        retorno=1;
    }
    else
    {
        retorno=-1;
        if(tmp_1->nivel < tmp_2->nivel)
        {
            retorno=1;
        }
    }
    return retorno;
}
int funcionQuefiltra(eVentas* item, int nivel)
{
 int retorno=-1;
 printf("%d",item->nivel);
 if(ventas_get_nivel(item)==nivel)
 {
     retorno=0;
 }
 return retorno;
}
int funcionQuefiltra1(eVentas* item)
{
 int retorno=-1;
 if(ventas_get_nivel(item)==1)
 {
     retorno=0;
 }
 return retorno;
}
int funcionQuefiltra2(eVentas* item)
{
 int retorno=-1;
 if(ventas_get_nivel(item)==2)
 {

     retorno=0;
 }
 return retorno;
}

int ventas_SeleccionarNivel(ArrayList* this)
{
    int retorno=-1;
    char resp;
    eVentas* niv;
    int opcion;
    ArrayList *ListaAux;
    ListaAux=al_newArrayList();

    printf("====================================================\n");
    printf("|\t0-JUNIOR\t1-ESTANDARD\t2-EXPERTO\t|\n");
    printf("====================================================\n");
  //  system("pause");
    switch(vista_Pedir_Nivel(opcion))
    {
    case 0:

      resp=Responder("Confirma seleccion de Nivel JUNIOR? (S/N)");
          if(resp='S')
          {
              retorno=0;
          }
          break;
    case 1:
        resp=Responder("Confirma seleccion de Nivel ESTANDARD? (S/N)");
          if(resp='S')
          {
              retorno=1;
          }
          break;
    case 2:
        resp=Responder("Confirma seleccion de Nivel EXPERTO? (S/N)");
          if(resp='S')
          {
              retorno=2;
          }
          break;

         }

         if(retorno=-1)
         {
             printf("Operación Cancelada\n");
             system("pause");
         }
         return retorno;
}

int ventas_buscarNombre(ArrayList* this, char nom[])
{
    int retorno=0;
    int i,valor;
    eVentas* emp;
    if(this!=NULL && nom !=NULL)
    {
        if(this->isEmpty(this)==0)
       {
        retorno=1;
    //    if(emp !=NULL)
    //    {
            for(i=0;i<this->len(this);i++)
            {
            emp=this->get(this,i);
          //  if()
           // if(ventas_get_nombre_vendedor(emp)==nom)
            valor=strcmp(ventas_get_nombre_vendedor(emp),nom);
            if(valor==0)
            {
                retorno=i;
                break;
            }//fin if
            else if(valor !=0)
            {
                retorno=-1;
            }
            }//fin for
//        }//fin if(emp)
        }
    }//fin if(this!)
    return retorno;
}
eVentas* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eVentas *emp;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))
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
                       emp=aux;
                       returnAux=0;
                    }//fin if(pfunc)
                    else
                    {
                        aux=al_get(this,i);
                        emp=aux;
                    }

                    }//fin if(valor)
                if(valor==0)
                {
                    if(pFunc(aux,al_get(this,i))==-1)
                    {
                        emp=aux;
                      //  aux=al_get(this,i);
                    }
                else
                {
                 aux=al_get(this,i);
                 emp=aux;
                }
                returnAux=0;
                }//fin if
            }//fin 1er for
          //  } //fin 2do for
        }//fin 1er for
    }

    return emp;
}
int comparaVendedor(void* eEmpleadoA,void* eEmpleadoB)
{
 //   eEmpleado *eEmpleadoA;
 //   eEmpleado *eEmpleadoB;
    if(((eVentas*)eEmpleadoA)->cantidad_productos_vendidos > ((eVentas*)eEmpleadoB)->cantidad_productos_vendidos)
    {
        return 1;
    }
    if(((eVentas*)eEmpleadoA)->cantidad_productos_vendidos < ((eVentas*)eEmpleadoB)->cantidad_productos_vendidos)
    {
        return -1;
    }
    return 0;


}







