#include "../../include/datatypes/DTProducto.hh"

int DTProducto::getId()
{
  return id;
}
std::string DTProducto::getNombre()
{
  return nombre;
}
std::string DTProducto::getDescripcion()
{
  return descripcion;
}
float DTProducto::getPrecio()
{
  return precio;
}
int DTProducto::getCantidadEnStock()
{
  return cantidadEnStock;
}
bool DTProducto::enviadoCorrectamente()
{
  return enviado;
}
TipoProducto DTProducto::getTipoProducto()
{
  return tipo;
}
DTVendedor *DTProducto::getVendedor()
{
  return vendedor;
}
DTPromocion *DTProducto::getPromocion()
{
  return promocion;
}
DTProducto::DTProducto(int id, std::string nombre, std::string descripcion, float precio, int cantidad, bool enviado, TipoProducto tipoProducto, DTVendedor *vendedor, DTPromocion *promocion)
{
  this->id = id;
  this->nombre = nombre;
  this->descripcion = descripcion;
  this->precio = precio;
  this->cantidadEnStock = cantidad;
  this->enviado = enviado;
  this->tipo = tipoProducto;
  this->vendedor = vendedor;
  this->promocion = promocion;
}
DTProducto::~DTProducto(){};
// Sobrecarga de operador '<<'
void DTProducto::setPrint(std::ostream &out)
{
  out << id << ", " << nombre;
}
std::ostream &operator<<(std::ostream &out, DTProducto &obj)
{
  obj.setPrint(out);
  return out;
}
