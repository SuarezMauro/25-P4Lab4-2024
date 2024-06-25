#ifndef DTCOMPRA
#define DTCOMPRA
#include "./DTFecha.hh"
#include "./DTCliente.hh"
#include "./DTRegistroProducto.hh"

#include <iostream>
#include <set>

class DTCliente;
class DTCompra
{
private:
  DTFecha *fechaDeCompra;
  std::set<DTRegistroProducto *> registroProductos;
  float montoFinal;
  DTCliente *cliente;

public:
  DTFecha *getFechaDeCompra();
  DTRegistroProducto *getRegistroProducto(int);
  std::set<DTRegistroProducto *> getRegistroProductos();
  float getMontoFinal();
  DTCliente *getCliente();
  DTCompra(DTFecha *, float, std::set<DTRegistroProducto *>, DTCliente *);
  ~DTCompra();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, DTCompra &obj); // cout

#endif