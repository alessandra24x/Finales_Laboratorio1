#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayList.h"
#include "Archivo.h"
#include "Cliente.h"
//#include "Gestion.h"
#include "Tools.h"


#define MASCARA_IMPRIMIR "%d\t%d\t%d\t%.50s\t\n"
#define MASCARA_IMPRIMIR2 "%2d\t%10s\t%20\t%8s\t%10s\t%10s\n"
#define MASCARA_IMPRIMIR3 "%4d\t%10s\t%2d\t\t%3d\t\t%2.2f\n"

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
int vista_MuestraUnElemento(eCliente * record)
{
    int retorno=-1;
    if(record !=NULL)
    {
        printf(MASCARA_IMPRIMIR2,cliente_get_id(record),cliente_get_nombre_cliente(record),cliente_get_email(record),cliente_get_dni(record),cliente_get_producto(record),cliente_get_observaciones(record));
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
        printf("| ID\tNOMBRE\t\tE-MAIL\tDNI\t\tPRODUCTO\t\tOBSERVACIONES|\n");
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

int vista_Pedir_Nivel(int choice)
{
    int retorno=0;
   // system("cls");
    vista_ShowTitulo("\n\t\tSELECCIONAR EL NIVEL DE VENDEDORES\n");
    choice=tools_PedirEntero("Ingrese el Nro de nivel del vendedor (0,1,2):\n");//se puede pasar por parametro del main??
    if(choice ==0 || choice==1 || choice==2)
    {
        retorno=choice;
    }
    else
    {
        printf("Debe ingresar una opcion valida (0,1,2)");
    }
    return retorno;
}


