#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Cliente.h"
//#include "Gestion.h"
#include "Tools.h"
//#include "Vista.h"



#define MASCARA_ARCHIVO "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" //defino aca la mascara para el parser de mensajes
#define MASCARA_ARCHIVO2 "%s,%s,%s\n"
//#define MASCARA_ARCHIVO2 "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" //defino la mascara para los usuarios
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
    char buffer [6][512];
//    int cantidadDatosLeidos;
    char cabecera[50];
    char id[30];
    char variable2[50];
    char variable3[50];
    char variable4[50];
    char variable5[50];
    char variable6[100];
    char variable7[512];


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
                fscanf(pFile,MASCARA_ARCHIVO,id,variable2,variable3,variable4,variable5,variable7);
                    cliente_set_id(record,atoi(id));
                    cliente_set_nombre_cliente(record,variable2);
                    cliente_set_email(record,variable3);
                    cliente_set_dni(record,variable4);
                    cliente_set_producto(record,variable5);
              //      strncpy(variable6, variable7, 20);
                    cliente_set_observaciones(record,variable7);
             //  strncpy(dest, src, 10);

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
            eCliente* record;
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
                     fprintf(f,"DNI,NOMBRE,EMAIL\n");
                    for (i=0; i<tamanio; i++)
                    {
                    record = (void*)al_get(this, i);
                    fprintf(f,MASCARA_ARCHIVO2,cliente_get_dni(record),cliente_get_nombre_cliente(record),cliente_get_email(record));
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

/*int arch_Alta_Empleado(ArrayList* this)
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

int arch_borrar(ArrayList* this)
{
    int retorno=-1;
    int cod_emp,indice;
    char resp;
    char nom[20];
    eVentas* emp;

    if(this !=NULL)
    {
        retorno=0;
        printf("Ingrese el nombre del Vendedor\n");
        fflush(stdin);
        scanf("%s",nom);
        printf("hola\n");
        printf("%s",nom);
     //   nom=RemoveSpaces(nom);
        if(nom !=NULL)
        {
           // indice=emp_buscarId(this,cod_emp);
            indice=ventas_buscarNombre(this,nom);
            emp=al_get(this,indice);
            if(emp ==NULL)
            {
             printf("No se encontro el vendedor:\n");
             system("pause");
             retorno=-1;
            }
            else if(emp !=NULL)
            {
            vista_MuestraUnElemento(emp);
            resp=Valida_confirmacion("Confirma dar de baja este vendedor?");
            if(resp=='N')
                {
                    printf("Operacion cancelada\n");
                }
                else if(resp=='S')
                {
                  emp = this->pop(this, emp);
                  free(emp);
                  this->sort(this,tools_ComparaNombre,1);
                 // data_actualizarArchivo(that,NOM_ARCH2);
                }
            }//fin else emp !=NULL

         }//fin if(cod_emp)

    }//fin if(this)
    if(retorno==1)
    {
        printf("se dio de baja exitosamente:\n");
    }
    return retorno;
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

