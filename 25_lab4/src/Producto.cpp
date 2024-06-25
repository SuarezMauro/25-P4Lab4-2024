#include "../include/Producto.hh"

int Producto::getId()
{
  return id;
}
std::string Producto::getNombre()
{
  return nombre;
}
void Producto::setId(int i)
{
  id = i;
}
std::string Producto::getDescripcion()
{
  return descripcion;
}
float Producto::getPrecio()
{
  return precio;
}
int Producto::getCantidadEnStock()
{
  return cantidadEnStock;
}
bool Producto::enviadoCorrectamente()
{
  return enviado;
}
TipoProducto Producto::getTipoProducto()
{
  return tipo;
}
Promocion *Producto::getPromocion()
{
  return promocion;
}
DTProducto *Producto::getDataProducto()
{
  DTVendedor *infoVendedor = vendedor->getDataVendedor();
  DTPromocion *infoPromocion = NULL;
  if (promocion != NULL)
  {
    infoPromocion = promocion->getDataPromocion();
  }
  DTProducto *dataProducto = new DTProducto(id, nombre, descripcion, precio, cantidadEnStock, enviado, tipo, infoVendedor, infoPromocion);
  return dataProducto;
}
void Producto::setNombre(std::string n)
{
  nombre = n;
}
void Producto::setDescrpcion(std::string des)
{
  descripcion = des;
}
void Producto::setPrecio(float pr)
{
  precio = pr;
}
void Producto::setCantidadEnStock(int cant)
{
  cantidadEnStock = cant;
}
void Producto::setEnviado(bool e)
{
  enviado = e;
}
void Producto::setTipoProducto(TipoProducto t)
{
  tipo = t;
}
DTVendedor *Producto::getInfoVendedor()
{
  DTVendedor *infoVendedor = vendedor->getDataVendedor();
  return infoVendedor;
}

void Producto::setVendedor(Vendedor *v)
{
  vendedor = vendedor;
}
void Producto::addPromocion(Promocion *promocion)
{
  this->promocion = promocion;
}
Producto::Producto(int id, std::string nombre, std::string descripcion, float precio, int cantidad, TipoProducto tipo, Vendedor *vendedor)
{
  this->id = id;
  this->nombre = nombre;
  this->descripcion = descripcion;
  this->precio = precio;
  this->cantidadEnStock = cantidad;
  this->tipo = tipo;
  this->vendedor = vendedor;
  this->promocion = NULL;
}
Producto::~Producto(){};
// Sobrecarga de operador '<<'
void Producto::setPrint(std::ostream &out)
{
  out << id << ", " << nombre;
}
std::ostream &operator<<(std::ostream &out, Producto &obj)
{
  obj.setPrint(out);
  return out;
}