#include "../../include/controladores/ControladorProducto.hh"
#include "../../include/fabrica/Fabrica.hh"

void ControladorProducto::enviarProd(Producto *producto)
{
  producto->setEnviado(true);
}
Producto *ControladorProducto::getProducto(int id)
{
  Producto *producto = NULL;
  bool encontrado = false;
  for (std::set<Producto *>::iterator it = productos.begin(); (it != productos.end()) && !encontrado; it++)
  {
    if ((*it)->getId() == id)
    {
      producto = *it;
      encontrado = true;
    }
  }
  return producto;
}
DTProducto *ControladorProducto::obtenerProductoDisponible(int id)
{
  for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
  {
    if ((*it)->getId() == id)
    {
      DTProducto *dataProducto = (*it)->getDataProducto();
      return dataProducto;
    }
  }
  return NULL;
}
void ControladorProducto::registrarDatosProductos(std::string nombre, float precio, int cantidadEnStock, std::string descripcion, TipoProducto tipo, std::string nickVendedor)
{
  lastID++;
  Vendedor *vendedor = Fabrica::getInterfazUsuario()->getVendedor(nickVendedor);
  Producto *nuevoProducto = new Producto(lastID, nombre, descripcion, precio, cantidadEnStock, tipo, vendedor);
  this->productos.insert(nuevoProducto);
  vendedor->añadirProducto(nuevoProducto);
}
ControladorProducto::ControladorProducto() {}
ControladorProducto::~ControladorProducto(){};
ControladorProducto *ControladorProducto::instancia = NULL;
ControladorProducto *ControladorProducto::getInstancia()
{
  if (instancia == NULL)
  {
    instancia = new ControladorProducto();
    instancia->lastID = 0;
  }
  return instancia;
}

std::set<DTProducto *> ControladorProducto::obtenerProductosDisponibles()
{
  std::set<DTProducto *> dataProducto;
  for (auto it = productos.begin(); it != productos.end(); ++it)
  {
    DTProducto *agregar = (*it)->getDataProducto();
    dataProducto.insert(agregar);
  }
  return dataProducto;
}

