#ifndef VENDEDOR
#define VENDEDOR

#include "./interfaces/IObservador.hh"
#include "./datatypes/DTVendedor.hh"
#include "./datatypes/DTProducto.hh"
#include "./Usuario.hh"
#include "./Cliente.hh"
#include "./Producto.hh"

#include <set>

class Producto;
class Promocion;
class Cliente;

class Vendedor : public Usuario
{
private:
  std::string codigoRUT;
  std::set<Producto *> productos;
  std::set<IObservador *> suscriptores;
  std::set<Promocion *> promociones;

public:
  std::string getCodigoRUT();
  DTVendedor *getDataVendedor();
  DTProducto *getDataProducto(int);
  void añadirPromocion(Promocion *);
  void añadirProducto(Producto *);
  void añadirSuscriptor(Cliente *);
  void removerPromocion(Promocion *);
  void removerProducto(Producto *);
  void removerSuscriptor(Cliente *);
  std::set<DTProducto *> listarProductos();
  Vendedor(std::string, std::string, DTFecha *, std::string);
  ~Vendedor();
};

#endif