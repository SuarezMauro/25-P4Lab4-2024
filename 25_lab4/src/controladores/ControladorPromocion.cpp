#include "../../include/controladores/ControladorPromocion.hh"
#include "../../include/fabrica/Fabrica.hh"

Promocion *ControladorPromocion::getPromocion(std::string nombrePromocion)
{
  return promociones[nombrePromocion];
}
std::set<DTPromocion *> ControladorPromocion::obtenerPromocionesVigentes()
{
  std::set<DTPromocion *> promosVigentes;
  for (auto it = promociones.begin(); it != promociones.end(); ++it)
  {
    DTPromocion *dtpromo = ((it)->second)->getDataPromocion();
    promosVigentes.insert(dtpromo);
  };
  return promosVigentes;
}
void ControladorPromocion::registrarDatosPromo(std::string nombre, std::string descripcion, DTFecha *fechaVencimiento, float porcentajeDescuento)
{
  if (promociones.count(nombre) == 0) // ver si fecha vencimiento > fecha actual?
  {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->fechaVencimiento = fechaVencimiento;
    this->porcentajeDescuento = porcentajeDescuento;
  }
}
void ControladorPromocion::asignarVendedor(std::string nickname)
{
  vendedor = Fabrica::getInterfazUsuario()->getVendedor(nickname);
}
void ControladorPromocion::agregarAPromo(int id, int cantMin)
{
  Producto *productoPromo = Fabrica::getInterfazProducto()->getProducto(id);
  productos.insert(productoPromo);
  InfoPromoProducto *infoProductoPromo = new InfoPromoProducto(id, cantMin);
  infoProductos.insert({id, infoProductoPromo});
  // DTProductoPromo *dataProductoPromo = new DTProductoPromo(id, nombre, cantMin, 0);
  // dtProductosPromo.insert({id, dataProductoPromo});
}
void ControladorPromocion::altaNuevaPromo()
{
  Promocion *promo = new Promocion(nombre, descripcion, fechaVencimiento, porcentajeDescuento, vendedor, productos, infoProductos);
  promociones.insert({promo->getNombre(), promo});
  for (auto it = productos.begin(); it != productos.end(); ++it)
  {
    (*it)->addPromocion(promo);
  }
  vendedor->añadirPromocion(promo);
  std::set<DTCliente*> clientesSusc = Fabrica::getInterfazUsuario()->listarSuscriptores(vendedor->getNickname());
  if (!clientesSusc.empty()){
    for (auto it = clientesSusc.begin(); it != clientesSusc.end(); it++){
    std::string nickCliente = (*it)->getNickname();
    Cliente* cliente = Fabrica::getInterfazUsuario()->getCliente(nickCliente);
    cliente->notificar(promo->getNombre(),vendedor->getNickname());
    }
  }
  infoProductos.clear();
  productos.clear();
  vendedor = NULL;
}
ControladorPromocion::ControladorPromocion() {}
ControladorPromocion::~ControladorPromocion() {}
ControladorPromocion *ControladorPromocion::instancia = nullptr;
ControladorPromocion *ControladorPromocion::getInstancia()
{
  if (instancia == nullptr)
  {
    instancia = new ControladorPromocion();
  }
  return instancia;
}

std::set<DTProducto *> ControladorPromocion::productosEnUnaPromo(std::string nombrePromo)
{
  Promocion *promo = promociones[nombrePromo];
  std::set<Producto *> productos = promo->getProductos();
  std::set<DTProducto *> aDevolver;
  for (auto it = productos.begin(); it != productos.end(); it++)
  {
    aDevolver.insert((*it)->getDataProducto());
  }
  return aDevolver;
}