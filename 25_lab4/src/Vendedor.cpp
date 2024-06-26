#include "../include/Vendedor.hh"

std::string Vendedor::getCodigoRUT()
{
  return codigoRUT;
}
DTVendedor *Vendedor::getDataVendedor()
{
  std::set<DTPromocion*> datapromos;
  for(auto it = promociones.begin(); it != promociones.end();it++){
    datapromos.insert((*it)->getDataPromocion());
  }
  DTVendedor *dataVendedor = new DTVendedor(getNickname(), getFechaNacimiento(), codigoRUT,datapromos, suscriptores);
  return dataVendedor;
}
DTProducto *Vendedor::getDataProducto(int id)
{
  DTProducto *dataProducto = NULL;
  bool encontrado = false;
  for (std::set<Producto *>::iterator it = productos.begin(); (it != productos.end()) && !encontrado; it++)
  {
    if ((*it)->getId() == id)
    {
      dataProducto = (*it)->getDataProducto();
      encontrado = true;
    }
  }
  return dataProducto;
}
std::set<DTCliente *> Vendedor::getSuscriptores(){
  return suscriptores;
};
void Vendedor::añadirPromocion(Promocion *promocion)
{
  promociones.insert(promocion);
}
void Vendedor::añadirProducto(Producto *producto)
{
  productos.insert(producto);
}
void Vendedor::añadirSuscriptor(DTCliente *suscriptor)
{
  suscriptores.insert(suscriptor);
}
void Vendedor::removerPromocion(Promocion *promocion)
{
  promociones.erase(promocion);
}
void Vendedor::removerProducto(Producto *producto)
{
  productos.erase(producto);
}
void Vendedor::removerSuscriptor(DTCliente *suscriptor)
{
  suscriptores.erase(suscriptor);
}
std::set<DTProducto *> Vendedor::listarProductos()
{
  std::set<DTProducto *> listaProductos;
  for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); it++)
  {
    DTProducto *dataProducto = (*it)->getDataProducto();
    listaProductos.insert(dataProducto);
  }
  return listaProductos;
}
Vendedor::Vendedor(std::string nickname, std::string password, DTFecha *fechaNacimiento, std::string codigoRUT) : Usuario(nickname, password, fechaNacimiento)
{
  this->codigoRUT = codigoRUT;
}
Vendedor::~Vendedor()
{
  Usuario::~Usuario();
}