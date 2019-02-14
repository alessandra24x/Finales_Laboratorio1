#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Ventas.h"
#include "Gestion.h"
#include "Tools.h"
#include "Vista.h"



#define MASCARA_ARCHIVO "%[^,],%[^,],%[^,],%[^,],%[^\n]\n" //defino aca la mascara para el parser de mensajes
#define MASCARA_ARCHIVO2 "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" //defino la mascara para los usuarios
//#define MASCARA_ARCHIVO_FEED "%d,%s,%d,%d,%s,%d\n"
#define TIENE_ENCABEZADO 1

/*int cargarDesdeArchivo(ArrayList *this,const char* nombre,int (*pFunc)(void*,void*))
{
	int flag = 0;
	FILE *pArchivo;

    if(this !=NULL && nombre !=NULL)
    {
        pArchivo=fopen(nombre,"r");
        if(pArchivo != NULL)
        {
            flag=0;
		//pArchivo= fopen("nombre", "wb");
            if(pFunc(pArchivo,this)==0)
            {
                flag= 1;
                fclose(pArchivo);
            }
        }
    }
        if(flag ==1)
        {
	    printf("Carga Correcta:\n");
        system("pause");
        }
        else
        {
            printf("No se pudo cargar\n");
            system("pause");
        }
	return flag;

}  */

int cargarDesdeArchivo(ArrayList *this,const char* nombre)
{
	int flag = 0;
	FILE *pArchivo;

    if(this !=NULL && nombre !=NULL)
    {
        pArchivo=fopen(nombre,"r");
        if(pArchivo != NULL)
        {
            flag=0;
		//pArchivo= fopen("nombre", "wb");
            if(parserEstructura(pArchivo,this)==0)
            {
                flag= 1;
                fclose(pArchivo);
            }
        }
    }
        if(flag ==1)
        {
	    printf("Carga Correcta:\n");
    system("pause");
        }
        else
        {
            printf("No se pudo cargar\n");
            system("pause");
        }
	return flag;

}
/*

int parserEstructura(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int guardoDato;
    eVentas* record;
//    int cantidadDatosLeidos;
    char cabecera[50];
    char id[50];
    char mensaje[1600];
    char popu[50];
    char idusu[50];
    char menaje_limite[200];

    if(pFile != NULL && this!=NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO == 1)
        {
            fgets(cabecera, 80, pFile);//descarto la lectura del encabezado
        }
        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo_mensaje();
            if(record != NULL)
            {
                fscanf(pFile,MASCARA_ARCHIVO,id,idusu,popu,mensaje);
               // fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,idusu,popu,mensaje);
                    mensaje_set_id(record,atoi(id));
                    mensaje_set_idUsuario(record,atoi(idusu));
                    mensaje_set_popu(record,atoi(popu));
                    strncpy(menaje_limite,mensaje,200);// corto la longitud del mensaje
                    mensaje_set_texto(record,menaje_limite);

                    al_add(this, record);
                    cantidadFilasLeidas++;
            }
            else if(record==NULL)//Sin memoria
            {
                printf("No hay memoria suficiente:\n");
                system("pause");
                break;
            }
        }
    }
    return retorno;
}

*/
int parserEstructura(FILE* pFile, ArrayList* this)
{
    int retorno = -1;
    int cantidadFilasLeidas = 0;
    int guardoDato;
    void* record;
//    int cantidadDatosLeidos;
    char cabecera[50];
    char id[30];
    char variable2[30];
    char variable3[30];
    char variable4[50];
    char variable5[50];


    if(pFile != NULL && this!=NULL)
    {
        retorno = -2;
        if(TIENE_ENCABEZADO == 1)
        {
            fgets(cabecera, 80, pFile);//descarto la lectura del encabezado
        }
        while(!feof(pFile))
        {
            retorno = 0;
            record = nuevo_record();
            if(record != NULL)
            {
                fscanf(pFile,MASCARA_ARCHIVO,id,variable2,variable3,variable4,variable5);
                    ventas_set_id(record,atoi(id));
                    ventas_set_nombre_vendedor(record,variable2);
                    ventas_set_nivel(record,atoi(variable3));
                    ventas_set_CantVend(record,atoi(variable4));
                    ventas_set_monto(record,atof(variable5));
                    ventas_set_comision(record, 0);  // <3 besou

                    al_add(this, record);
                    cantidadFilasLeidas++;
            }
            else if(record==NULL)//Sin memoria
            {
                printf("No hay memoria suficiente:\n");
                system("pause");
                break;
            }
        }
    }
    return retorno;
}
int GuardarArchivoT(ArrayList* this, const char* nombre)
{
        int retorno=-1;
        int i;
        int tamanio=0;
        if(this!=NULL)
        {
            eVentas* record;
        //    void* record;
            FILE *f;
            f=fopen(nombre, "w");
            if(f==NULL)
            {
                retorno=0;
            }
            else
            {
                if(record !=NULL)
                {
                    tamanio=al_len(this);
                     fprintf(f,"ID,VENDEDOR,NIVEL,CANT VENDIDA,MONTO,COMISION\n");
                    for (i=0; i<tamanio; i++)
                    {
                    record = (void*)al_get(this, i);
                    fprintf(f,MASCARA_ARCHIVO2,ventas_get_id(record),ventas_get_nombre_vendedor(record),ventas_get_nivel(record),ventas_get_CantVend(record),ventas_get_monto(record),ventas_get_comision(record));
                    retorno=1;
                    }//fin for
                    }//fin if(aux!=NULL)
                fclose(f);
            }//fin else
        }// fin if(!=null)
        if(retorno==1)
        {
            printf("Se creo el archivo %s correctamente\n",nombre);
            system("pause");
        }
        else
        {
            printf("No se pudo crear el archivo %s\n",nombre);
            system("pause");
        }
        return retorno;
}

int arch_Alta_Empleado(ArrayList* this)
{
    int retorno=-1;
    int i,id;
    char resp;
    if(this !=NULL)
    {
        eVentas* emp;
        eVentas aux;
        retorno=0;
        do
        {
            system("cls");
            vista_ShowTitulo("INGRESO EMPLEADOS");
            aux.id=tools_siguienteId(this,ventas_get_id);

            vista_ingresarTexto(aux.nombre_vendedor,20,"Ingrese el nombre:\n");
          //  ingresarTexto(aux.,25,"Ingrese la direccion:\n");
            aux.nivel=tools_ingresarInt("Nivel",0,2);
            aux.cantidad_productos_vendidos=tools_ingresarInt("Ingrese la cantidad de productos vendidos",1,200);
            aux.monto_vendido=tools_ingresarFloat("Ingrese el monto",10,75000);

            emp=ventas_nuevoVendedor(aux.id,aux.nombre_vendedor,aux.nivel,aux.cantidad_productos_vendidos,aux.monto_vendido);
            ventas_set_monto(emp,aux.monto_vendido);

            if(emp !=NULL)
            {
                retorno=1;
                system("cls");
                vista_MuestraUnElemento(emp);
                resp=Responder("Confirma el ingreso de este empleado?(S/N)");
                if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                    system("pause");
                }
                else if(resp=='S')
                {
                    this->add(this,emp);
                    this->sort(this,tools_ComparaNombre,1);
                }

            }

        }while(Responder("Continua ingresando: (S/N)")=='S');

    }//fin if(this !=NULL)
}



//FALTA CARGAR Y GUARDAR ARCHIVO BINARIO
//********************************************************
/*int Estr_borrar_elemento(ArrayList* this,ArrayList* that)
{
    int retorno=-1;
    int element,indice;
    char resp;
    void* record;

    if(this !=NULL && that !=NULL)
    {
        retorno=0;
        element=Valida_PedirEntero("Ingrese el Codigo del producto a dar de baja:\n");
        if(element >0)
        {
            indice=prod_buscarId(this,element);
            record=al_get(this,indice);
            if(record ==NULL)
            {
             indice=prod_buscarId(that,element);
             record=al_get(that,indice);
             retorno=1;
            }
            if(record ==NULL)
            {
                printf("No se encontro el producto\n");
                vista_pausar();
            }
            else if(record !=NULL)
            {
            vista_Muestra1UnElemento(record);
            resp=Valida_confirmacion("Confirma dar de baja este producto?");
            if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                }
                else if(resp=='S')
                {
                 //prod=this->pop(this,this->indexOf(this, prod));
                 if(retorno==1)
                 {
                  record = that->pop(that, record);
                  free(record);
                  that->sort(that,prod_comparaProducto,1);
                  data_actualizarArchivo(that,NOM_ARCH2);
                 }
                 else
                 {
                    record = this->pop(that, record);
                    free(record);
                    this->sort(this,prod_comparaProducto,1);
                    data_actualizarArchivo(this,NOM_ARCH);
                 }
                 retorno=1;
                }
            }//fin else record !=NULL
         }//fin if(element)
    }//fin if(this)
    if(retorno==1)
    {
        printf("se dio de baja exitosamente:\n");
    }
    return retorno;
}
*/
