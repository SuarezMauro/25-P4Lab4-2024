#ifndef DTVENDEDOR
#define DTVENDEDOR

#include "./DTUsuario.hh"
#include "./DTProducto.hh"
#include "./DTPromocion.hh"
#include <set>
class DTProducto;
class DTPromocion;

class DTVendedor : public DTUsuario
{
private:
  std::string codigoRUT;
  std::set<DTPromocion *> promociones;

public:
  std::string getCodigoRUT();
  std::set<DTPromocion *> getPromociones();
  DTVendedor(std::string, DTFecha *, std::string);
  ~DTVendedor();
};

#endif