#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED



typedef struct
{
    int id;
    char nombre_vendedor [20];
    int  nivel;
    int cantidad_productos_vendidos;
    float monto_vendido;
    float comision;
}eVentas;

#endif // ESTRUCTURA_H_INCLUDED

eVentas* nuevo_record(void);
int CalcularSalary(eVentas* element);
int ventas_set_monto(eVentas* this, float flotante);
float ventas_get_monto(eVentas* this);
int ventas_set_comision(eVentas* this, float flotante);
float ventas_get_comision(eVentas* this);
int ventas_set_nivel(eVentas* this, int num);
int ventas_get_nivel(eVentas* this);
int ventas_set_id(eVentas* this, int num);
int ventas_get_id(eVentas* this);
int ventas_set_CantVend(eVentas* this, int num);
int ventas_get_CantVend(eVentas* this);
char* ventas_get_nombre_vendedor(eVentas* this);
int ventas_set_nombre_vendedor(eVentas* this, char* texto);

