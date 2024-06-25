#include "../../include/datatypes/DTRegistroProducto.hh"

int DTRegistroProducto::getId()
{
  return id;
}
std::string DTRegistroProducto::getNombre()
{
  return nombre;
}
int DTRegistroProducto::getCantidad()
{
  return cantidad;
}
float DTRegistroProducto::getPrecio()
{
  return precio;
}
DTPromocion *DTRegistroProducto::getInfoPromo()
{
  return promocion;
}
DTRegistroProducto::DTRegistroProducto(int id, std::string nombre, int cantidad, float precio, DTPromocion *promocion)
{
  this->id = id;
  this->nombre = nombre;
  this->cantidad = cantidad;
  this->precio = precio;
  this->promocion = promocion;
}
DTRegistroProducto::~DTRegistroProducto() {}
// Sobrecarga de operador '<<'
void DTRegistroProducto::setPrint(std::ostream &out)
{
  out << id << ", " << nombre << ", " << cantidad << ", " << precio;
}
std::ostream &operator<<(std::ostream &out, DTRegistroProducto &obj)
{
  obj.setPrint(out);
  return out;
}