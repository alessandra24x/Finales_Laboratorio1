#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED



typedef struct
{
    int id;
    char nombre [20];
    char email[20];
    char dni[10];
    char producto [20];
    char observaciones [100];
}eCliente;

#endif // ESTRUCTURA_H_INCLUDED

eCliente* nuevo_record(void);
eCliente* cliente_nuevoVendedor(int id,char nombre[], char email[],char dni[],char producto [],char observaciones[]);
int cliente_set_id(eCliente* this, int num);
int cliente_get_id(eCliente* this);
char* cliente_get_nombre_cliente(eCliente* this);
int cliente_set_nombre_cliente(eCliente* this, char* texto);
char* cliente_get_email(eCliente* this);
int cliente_set_email(eCliente* this, char* texto);
char* cliente_get_dni(eCliente* this);
int comparaVendedor(void* eEmpleadoA,void* eEmpleadoB);
int ComparaNombre(void* eEmpleadoA,void* eEmpleadoB);
int ComparaProducto(void* eEmpleadoA,void* eEmpleadoB);
