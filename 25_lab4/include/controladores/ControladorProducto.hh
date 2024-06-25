#ifndef CONTROLADOR_PRODUCTO
#define CONTROLADOR_PRODUCTO

#include "../interfaces/IControladorProducto.hh"

#include <iostream>
#include <set>

class ControladorProducto : public IControladorProducto
{
private:
  std::set<Producto *> productos;
  static ControladorProducto *instancia;
  int lastID;
  ControladorProducto();

public:
  void enviarProd(Producto *);
  static ControladorProducto *getInstancia();
  Producto *getProducto(int);
  void registrarDatosProductos(std::string, float, int, std::string, TipoProducto, std::string);
  DTProducto *obtenerProductoDisponible(int);
  std::set<DTProducto *> obtenerProductosDisponibles(); // falta hacerla en el cpp // agregado PD chequearlo.
  ~ControladorProducto();
};

#endif