#ifndef DTVENDEDOR
#define DTVENDEDOR

#include "./DTUsuario.hh"
#include "./DTProducto.hh"
#include "./DTPromocion.hh"
#include "./DTCliente.hh"
#include <set>
class DTProducto;
class DTPromocion;
class DTCliente;

class DTVendedor : public DTUsuario
{
private:
  std::string codigoRUT;
  std::set<DTPromocion *> promociones;
  std::set<DTCliente*> suscriptores;
public:
  std::string getCodigoRUT();
  std::set<DTPromocion *> getPromociones();
  std::set<DTCliente> getSuscriptores();
  DTVendedor(std::string, DTFecha *, std::string, std::set<DTCliente*>);
  ~DTVendedor();
};

#endif