#ifndef DTCLIENTE
#define DTCLIENTE

#include "./DTUsuario.hh"
#include "./DTDireccion.hh"
#include "./DTCompra.hh"

#include <iostream>
#include <set>

class DTCompra;
class DTCliente : public DTUsuario
{
private:
  DTDireccion *direccion;
  std::string ciudadDeResidencia;
  std::set<DTCompra *> comprasPasadas;

public:
  DTDireccion *getDireccion();
  std::set<DTCompra *> getComprasPasadas();
  std::string getCiudadDeResidencia();
  DTCliente(std::string, DTFecha *, DTDireccion *, std::string);
  ~DTCliente();
};

#endif