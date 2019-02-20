#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "Cliente.h"
#include "Tools.h"
#include "Archivo.h"
#include "Vista.h"
#define NOM_ARCH "data2.csv"
#define NOM_ARCH2 "clientes.csv"
//#define NOM_ARCH2 "data2.csv"

int main()
{
    int opcion,choice;
    char seguir='S';

    ArrayList *ListaLlamadas;
    ListaLlamadas=al_newArrayList();
    ArrayList *ListaAux;
    ListaAux=al_newArrayList();
    eCliente* cliente;


     if(ListaLlamadas!=NULL)
    {
        while(seguir=='S')
        {
            vista_ShowMenu("\n1: Cargar Archivos\n2: Imprimir llamadas\n3: Imprimir estadistica\n4: Generar Archivo de Clientes\n5:\n");
            scanf("%d",&opcion);
            tools_ValidaMenu(opcion,0,5);
            switch(opcion)
            {
            case 1:
                cargarDesdeArchivo(ListaLlamadas,NOM_ARCH);
                break;
            case 2:
                if(ListaLlamadas!=NULL)
                {
                     vista_MuestraElementos(ListaLlamadas,"LISTADO DE LLAMADAS","MUESTRA INCIDENCIAS",vista_MuestraUnElemento,0,ListaLlamadas->len(ListaLlamadas),25);
                }
                break;
            case 3:
             /*    printf("====================================================\n");
                printf("|\t0-CLIENTE CON MAS LLAMADAS\t1-PRODUCTO MAS CONSULTADO|\n");
                printf("====================================================\n");
                switch(opcion)
                    {
                    case 0:
                    resp=Responder("Confirma seleccion  (S/N)");
                    if(resp='S')
                    {*/
                    cliente=BuscaMaximo(ListaLlamadas,ComparaNombre,0);
                    system("cls");
                    printf("CLIENTE CON MAS LLAMADAS\n\n");
                    printf("===================================================\n");
                    printf("NOMBRE\t\tDNI\n");
                    printf("%s\t%s\n",cliente_get_nombre_cliente(cliente),cliente_get_dni(cliente));
                    printf("======================================================\n");
                    system("pause");
                    cliente=BuscaMaximo(ListaLlamadas,ComparaProducto,0);
                    system("cls");
                    printf("===================================================\n");
                    printf("ID DEL PRODUCTO\n");
                    printf("%s\n",cliente_get_producto(cliente));
                    printf("======================================================\n");
                    system("pause");
                    break;
            case 4:
                ListaAux=al_eliminaDuplicados(ListaLlamadas,ComparaNombre);
                if(ListaAux !=NULL)
                {
                GuardarArchivoT(ListaAux,NOM_ARCH2);
                }

                break;
            case 0:
                seguir='N';


                    }//FIN SWH

            }



        }//fin While




    return 0;
}
