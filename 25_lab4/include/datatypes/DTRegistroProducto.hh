#ifndef DTREGISTRO_PRODUCTO
#define DTREGISTRO_PRODUCTO

#include <iostream>
#include "./DTPromocion.hh"

class DTRegistroProducto
{
private:
  int id;
  std::string nombre;
  DTPromocion *promocion;
  int cantidad;
  float precio;

public:
  int getId();
  std::string getNombre();
  int getCantidad();
  float getPrecio();
  DTPromocion *getInfoPromo();
  DTRegistroProducto(int, std::string, int, float, DTPromocion *); // id,nombre,cantidad,precio
  ~DTRegistroProducto();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, DTRegistroProducto &obj); // cout DTRegistroProducto

#endif