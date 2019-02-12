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




