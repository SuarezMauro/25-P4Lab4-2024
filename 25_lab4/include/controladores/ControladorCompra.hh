#ifndef CONTROLADOR_COMPRA
#define CONTROLADOR_COMPRA

#include "../datatypes/DTFecha.hh"
#include "../Compra.hh"
#include <set>
#include <iostream>
#include "../interfaces/IControladorCompra.hh"
#include "../datatypes/DTUsuario.hh"
#include "../Producto.hh"

class ControladorCompra : public IControladorCompra
{
private:
    std::set<Compra *> comprasExitosas;
    Compra *compraActual;
    static ControladorCompra *instancia;
    ControladorCompra();

public:
    std::set<DTCompra *> getDataComprasExitosas();
    static ControladorCompra *getInstancia();
    DTCompra *obtenerDatosCompra();
    bool estaEnCompra(int);
    void crearCompra(std::string, int, int, int); // dia/mes/anio de hoy
    void agregarProductoACompra(int, int);
    void registrarCompraExitosa(bool b);
    void calcularDescuentos();
    ~ControladorCompra();
};

#endif