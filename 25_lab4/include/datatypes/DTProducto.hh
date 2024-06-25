#ifndef DTPRODUCTO
#define DTPRODUCTO

#include "../TipoProducto.hh"
#include "./DTPromocion.hh"
#include "./DTVendedor.hh"
#include <iostream>

class DTPromocion;
class DTVendedor;

class DTProducto
{
private:
  int id;
  std::string nombre;
  std::string descripcion;
  float precio;
  int cantidadEnStock;
  bool enviado;
  TipoProducto tipo;
  DTVendedor *vendedor;
  DTPromocion *promocion;

public:
  int getId();
  std::string getNombre();
  std::string getDescripcion();
  float getPrecio();
  int getCantidadEnStock();
  bool enviadoCorrectamente();
  TipoProducto getTipoProducto();
  DTVendedor *getVendedor();
  DTPromocion *getPromocion();
  DTProducto(int, std::string, std::string, float, int, bool enviado, TipoProducto, DTVendedor *, DTPromocion *);
  ~DTProducto();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};
std::ostream &operator<<(std::ostream &out, DTProducto &obj); // cout Producto

#endif