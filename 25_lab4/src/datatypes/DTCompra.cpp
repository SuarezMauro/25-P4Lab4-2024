#include "../../include/datatypes/DTCompra.hh"

DTFecha *DTCompra::getFechaDeCompra()
{
  return fechaDeCompra;
}
DTRegistroProducto *DTCompra::getRegistroProducto(int id)
{
  for (std::set<DTRegistroProducto *>::iterator it = registroProductos.begin(); it != registroProductos.end(); ++it)
  {
    if ((*it)->getId() == id)
    {
      return *it;
    }
  }
  return NULL;
}
std::set<DTRegistroProducto *> DTCompra::getRegistroProductos()
{
  return registroProductos;
}
float DTCompra::getMontoFinal()
{
  return montoFinal;
}
DTCliente *DTCompra::getCliente()
{
  return cliente;
}
DTCompra::DTCompra(DTFecha *f, float m, std::set<DTRegistroProducto *> reg, DTCliente *c)
{
  fechaDeCompra = f;
  montoFinal = m;
  registroProductos = reg;
  cliente = c;
}
DTCompra::~DTCompra()
{
  delete fechaDeCompra;
  while (!registroProductos.empty())
  {
    std::set<DTRegistroProducto *>::iterator inicio = registroProductos.begin();
    DTRegistroProducto *aBorrar = *inicio;
    registroProductos.erase(inicio);
    delete aBorrar;
    delete cliente;
  }
}
// Sobrecarga de operador '<<'
void DTCompra::setPrint(std::ostream &out)
{
  out << fechaDeCompra->toString() << ", " << montoFinal << std::endl;
  out << "Productos en compra" << std::endl;
  for (std::set<DTRegistroProducto *>::iterator it = registroProductos.begin(); it != registroProductos.end(); ++it)
  {
    out << *(*it) << std::endl;
  }
}
std::ostream &operator<<(std::ostream &out, DTCompra &obj)
{
  obj.setPrint(out);
  return out;
}
