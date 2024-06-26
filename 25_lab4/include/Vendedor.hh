#ifndef VENDEDOR
#define VENDEDOR

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTVendedor.hh"
#include "./datatypes/DTProducto.hh"
#include "./datatypes/DTCliente.hh"
#include "./Usuario.hh"
#include "./Producto.hh"

#include <set>

class Producto;
class Promocion;

class Vendedor : public Usuario
{
private:
  std::string codigoRUT;
  std::set<Producto *> productos;
  std::set<DTCliente *> suscriptores;
  std::set<Promocion *> promociones;

public:
  std::string getCodigoRUT();
  DTVendedor *getDataVendedor();
  DTProducto *getDataProducto(int);
  std::set<DTCliente *> getSuscriptores();
  void añadirPromocion(Promocion *);
  void añadirProducto(Producto *);
  void añadirSuscriptor(DTCliente *);
  void removerPromocion(Promocion *);
  void removerProducto(Producto *);
  void removerSuscriptor(DTCliente *);
  std::set<DTProducto *> listarProductos();
  Vendedor(std::string, std::string, DTFecha *, std::string);
  ~Vendedor();
};

#endif