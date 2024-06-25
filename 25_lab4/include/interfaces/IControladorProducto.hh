#ifndef I_CONTROLADOR_PRODUCTO
#define I_CONTROLADOR_PRODUCTO

#include "../datatypes/DTProducto.hh"
#include "../datatypes/DTComentario.hh"
#include "../TipoProducto.hh"
#include "../Producto.hh"

#include <iostream>
#include <set>

class IControladorProducto
{
public:
  virtual void enviarProd(Producto *) = 0;
  virtual Producto *getProducto(int) = 0;
  virtual void registrarDatosProductos(std::string nombre, float precio, int cant, std::string des, TipoProducto tipo, std::string nickVendedor) = 0;
  virtual DTProducto *obtenerProductoDisponible(int) = 0;
  virtual std::set<DTProducto *> obtenerProductosDisponibles() = 0;
};

#endif