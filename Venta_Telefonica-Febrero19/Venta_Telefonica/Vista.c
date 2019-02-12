#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Archivo.h"
#include "Ventas.h"
#include "Gestion.h"
#include "Tools.h"


#define MASCARA_IMPRIMIR "%d\t%d\t%d\t%.50s\t\n"
#define MASCARA_IMPRIMIR2 "%4d\t%10s\t\t%d\t\t%d\t%12.2f\t%2.2f\n"
#define MASCARA_IMPRIMIR3 "%4d\t%10s\t%2d\t%3d\t%2.2f\n"

void vista_ShowMenu(char *opcion)
{
    int op;
    system("cls");
    printf("\n\n");
    printf("**********MENU PRINCIPAL**********\n\n");
    printf("Ingrese una opcion: \n");
    printf("%s \n",opcion);
    printf("\n0.  Salir \n");


}
void vista_ShowTitulo(char titulo[])
{
    printf("%s----\n\n",titulo);
}
//****************************FUNCIONES DE IMPRESION ******************************
//**********************************************************************************
int vista_MuestraUnElemento(eVentas * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
       // printf("%f\n",record->comision);
       // system("pause");
       if(ventas_get_comision(record) ==0)

         {
                retorno=0;
                printf(MASCARA_IMPRIMIR3,ventas_get_id(record),ventas_get_nombre_vendedor(record),ventas_get_nivel(record),ventas_get_CantVend(record),ventas_get_monto(record));
            }
            else
            {
                retorno=0;
              printf(MASCARA_IMPRIMIR2,ventas_get_id(record),ventas_get_nombre_vendedor(record),ventas_get_nivel(record),ventas_get_CantVend(record),ventas_get_monto(record),ventas_get_comision(record));
            }
    }
     return retorno;
}


int vista_MuestraElementos(ArrayList *this,char *Titulo,char * SubTitulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado)
{
    int retorno=-1;
    int i;
    int cont=0;
    if(this!=NULL && Titulo!=NULL)
    {
        if(this->isEmpty(this)==0)
        {
        retorno=0;
        system("cls");
        printf("\n\n-------- %s --------\n",Titulo);
        printf("\n%s\n",SubTitulo);
        printf("===============================================================================\n");
        printf("===============================================================================\n");
        printf("| ID\tNOMBRE\t\tNIVEL\tCANT. VENDIDA\t\tMONTO\t\tCOMISION|\n");
        printf("|\n");
        printf("================================================================================\n");
        if(this->isEmpty(this)==0)//No esta vacio
        {
            for(i=desde;i<hasta;i++)
            {
                if(cont!=0 && cont %paginado==0)
                {
                    system("pause");
                    system("cls");
                    printf("\n\n-------- %s --------\n",Titulo);
                }
                pFunc(al_get(this,i)); //llama a la funcion que muestra 1 elemento
                cont++;
            }
            if(cont!=0)
            {//pausa la ultima tanda de elementos mostrados
                system("pause");
            }
        }//if(this->isEmpty(this)==0)
        else
        {//o con error o sin datos a mostrar
            printf("\n Sin Datos a Motrar...\n");
            system("pause");
        }
       }
       else if(this->isEmpty !=0)
       {
           printf("Lista vacia\n");
           system("pause");
       }
    }//if(this!=NULL && Titulo!=NULL)
    return retorno;
}
//*****************************************************************
void vista_ingresarTexto (char texto[], int cantTexto, char pregunta[])
{
    char titulo [50];
    char auxtitulo [cantTexto-1];
    int i;

    printf("%s\t", pregunta);
    fflush(stdin);
    gets (titulo);
    for (i=0; i<cantTexto; i++)
    {
        auxtitulo[i]=titulo[i];
    }
    strcpy(texto, auxtitulo);
}
