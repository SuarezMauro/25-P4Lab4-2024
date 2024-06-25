#ifndef PROMOCION
#define PROMOCION

#include "./datatypes/DTFecha.hh"
#include "./datatypes/DTPromocion.hh"
#include "./InfoPromoProducto.hh"
#include "./Producto.hh"
#include "./Vendedor.hh"

#include <iostream>
#include <set>
#include <map>

class Producto;
class Vendedor;

class Promocion
{
private:
    std::string nombre;
    std::string descripcion;
    DTFecha *fechaDeVencimiento;
    float porcentajeDescuento;
    Vendedor *vendedor;
    std::set<Producto *> productos;
    std::map<int, InfoPromoProducto *> infoProductos;

public:
    std::string getNombre();
    std::string getDescripcion();
    DTFecha *getFechaDeVencimiento();
    Vendedor *getVendedor();
    std::set<Producto *> getProductos();
    Producto *getProducto(int);
    std::map<int, InfoPromoProducto *> getInfoProductos();
    InfoPromoProducto *getInfoProducto(int);
    float getPorcentajeDescuento();

    void setNombre(std::string);
    void setDescripcion(std::string);
    void setFechaDeVencimiento(DTFecha *);
    void setVendedor(Vendedor *);
    void setProductos(std::set<Producto *>);
    void setInfoProductos(std::map<int, InfoPromoProducto *>);

    DTProductoPromo *getDataProductoPromo();
    DTPromocion *getDataPromocion();

    Promocion(std::string, std::string, DTFecha *, float, Vendedor *, std::set<Producto *>, std::map<int, InfoPromoProducto *>);
    ~Promocion();
};

#endif