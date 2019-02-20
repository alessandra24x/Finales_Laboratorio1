#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Cliente.h"
//#include "Gestion.h"
#include "Tools.h"
//#include "Vista.h"




eCliente* nuevo_record(void)
{
    eCliente* returnAux;
    returnAux = (eCliente*)malloc(sizeof(eCliente));
    return returnAux;
}
eCliente* ventas_nuevoVendedor(int id,char nombre[], char email[],char dni[],char producto [],char observaciones[])
{
    eCliente* retorno = NULL;
    eCliente* pVentas = malloc(sizeof(eCliente));

    if(pVentas != NULL)
    {
        cliente_set_id(pVentas,id);
        cliente_set_nombre_cliente(pVentas,nombre);
        cliente_set_email(pVentas,email);
        cliente_set_dni(pVentas,dni);
        cliente_set_producto(pVentas,producto);
        cliente_set_observaciones(pVentas,observaciones);
        retorno = pVentas;
    }
    return retorno;
}

//*************GETTERS Y SETTERS ************************



int cliente_set_id(eCliente* this, int num)
{
    int retorno = 0;
    if(this!=NULL)
    {
        this->id=num;
        retorno = 1;
    }
    return retorno;
}

int cliente_get_id(eCliente* this)
{
    int num;
    if(this!=NULL)
    {
        num=this->id;
    }
    return num;
}

char* cliente_get_nombre_cliente(eCliente* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->nombre;
    }
    return texto;
}

int cliente_set_nombre_cliente(eCliente* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->nombre,texto);
        retorno =1;
    }
    return retorno;
}

char* cliente_get_email(eCliente* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->email;
    }
    return texto;
}

int cliente_set_email(eCliente* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->email,texto);
        retorno =1;
    }
    return retorno;
}


char* cliente_get_dni(eCliente* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->dni;
    }
    return texto;
}

int cliente_set_dni(eCliente* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->dni,texto);
        retorno =1;
    }
    return retorno;
}


char* cliente_get_producto(eCliente* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->producto;
    }
    return texto;
}

int cliente_set_producto(eCliente* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->producto,texto);
        retorno =1;
    }
    return retorno;
}


char* cliente_get_observaciones(eCliente* this)
{
    char* texto = NULL;
    if(this!=NULL)
    {
        texto = this->observaciones;
    }
    return texto;
}

int cliente_set_observaciones(eCliente* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->observaciones,texto);
        retorno =1;
    }
    return retorno;
}


//**************FIN GETTERS Y SETTERS ************************
//*************************************************************

eCliente* BuscaMaximo(ArrayList* this, int (*pFunc)(void* ,void*),int valor)
{
   int returnAux = -1;
    ArrayList* aux;
    int i=0;
    eCliente *emp;

    if(this!= NULL && pFunc!=NULL && (valor==0 || valor==1))
    {
        if(aux!=NULL)
        {
            aux=(al_get(this,i));
            for(i=1;i < al_len(this)-1;i++)
            {
                if(valor==1)
                {
                    if(pFunc(aux,al_get(this,i))!=0)
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
                    if(pFunc(aux,al_get(this,i))==0)
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

    if(((eCliente*)eEmpleadoA)->nombre > ((eCliente*)eEmpleadoB)->nombre)
    {
        return 1;
    }
    if(((eCliente*)eEmpleadoA)->nombre < ((eCliente*)eEmpleadoB)->nombre)
    {
        return -1;
    }
    return 0;


}
int ComparaNombre(void* eEmpleadoA,void* eEmpleadoB)
{
    /*int retorno=-1;
    if (strcmp(((eCliente*)eEmpleadoA)->nombre,((eCliente*)eEmpleadoB)->nombre)==1)
    {
      retorno=1;
    }
    else if (strcmp(((eCliente*)eEmpleadoA)->nombre,((eCliente*)eEmpleadoB)->nombre)==-1)
    {
      retorno=0;

    }*/
    return strcmp(((eCliente*)eEmpleadoA)->nombre,((eCliente*)eEmpleadoB)->nombre);

}

int ComparaProducto(void* eEmpleadoA,void* eEmpleadoB)
{
  /*  int retorno=0;
    if (strcmp(((eCliente*)eEmpleadoA)->producto,((eCliente*)eEmpleadoB)->producto)==1)
    {
      retorno=1;
    }
    else if (strcmp(((eCliente*)eEmpleadoA)->producto,((eCliente*)eEmpleadoB)->producto)==-1)
    {
      retorno=-1;

    }*/
    return strcmp(((eCliente*)eEmpleadoA)->producto,((eCliente*)eEmpleadoB)->producto);;

}
/*int cliente_SeleccionarOpcion(int n)
{
    int retorno=-1;
    char resp;
    int opcion;

    printf("====================================================\n");
    printf("|\t0-CLIENTE CON MAS LLAMADAS\t1-PRODUCTO MAS CONSULTADO|\n");
    printf("====================================================\n");
    switch(opcion)
    {
    case 0:

      resp=Responder("Confirma seleccion de Nivel JUNIOR? (S/N)");
          if(resp='S')
          {
              retorno=0;
          }
          break;
    case 1:
        resp=Responder("Confirma seleccion de Nivel ESTANDARD? (S/N)");*/

