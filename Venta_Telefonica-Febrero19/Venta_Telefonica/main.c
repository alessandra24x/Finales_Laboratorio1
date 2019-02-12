#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Ventas.h"
#include "Tools.h"
#include "Vista.h"

#define NOM_ARCH "data.csv"
#define NOM_ARCH2 "data2.csv"



int main()
{

    int opcion;
    char seguir='S';

     ArrayList *ListaVentas;
    ListaVentas=al_newArrayList();


     if(ListaVentas!=NULL)
    {
        while(seguir=='S')
        {
            vista_ShowMenu("\n1:Cargar Archivos\n2:Implementar el filtro\n3:Listar Ventas\n");
            scanf("%d",&opcion);
            tools_ValidaMenu(opcion,0,3);
            switch(opcion)
            {
            case 1:
                cargarDesdeArchivo(ListaVentas,NOM_ARCH);
                if(ListaVentas !=NULL)
                {
                     vista_MuestraElementos(ListaVentas,"LISTA DE VENTAS","POR VENDEDORES",vista_MuestraUnElemento,0,ListaVentas->len(ListaVentas),25);
                     //GuardarArchivoT(ListaVentas,NOM_ARCH2);
                }
                else
                    printf("NADA PARA MOSTRAR");
                   // pause();
                break;
            case 2:
                if(al_map(ListaVentas,CalcularSalary)==1)
                 {
                       printf("Se pudieron calcular todas las comisiones\n");
                       system("pause\n");
                       vista_MuestraElementos(ListaVentas,"LISTA DE VENDEDORES","SE CALCULAN COMISI8ONES",vista_MuestraUnElemento,0,ListaVentas->len(ListaVentas),25);
                       system("pause\n");
                   }

                    else
                        printf("No se pudieron calcular todos\n");
                    break;


            case 3:
                break;
            case 0:
                seguir='N';




            }

        }

    }

    return 0;
}
