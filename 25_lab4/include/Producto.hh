#ifndef PRODUCTO
#define PRODUCTO
#include <iostream>
#include "./datatypes/DTProducto.hh"
#include "./datatypes/DTVendedor.hh"
#include "./TipoProducto.hh"
#include "./Promocion.hh"
#include "./Vendedor.hh"

class Promocion;
class Vendedor;

class Producto
{
private:
  int id;
  std::string nombre;
  std::string descripcion;
  float precio;
  int cantidadEnStock;
  bool enviado;
  TipoProducto tipo;
  Vendedor *vendedor;
  Promocion *promocion;

public:
  int getId();
  std::string getNombre();
  std::string getDescripcion();
  float getPrecio();
  int getCantidadEnStock();
  bool enviadoCorrectamente();
  DTVendedor *getInfoVendedor();
  TipoProducto getTipoProducto();
  DTProducto *getDataProducto();
  Promocion *getPromocion();
  void setId(int);
  void setNombre(std::string);
  void setDescrpcion(std::string);
  void setPrecio(float);
  void setCantidadEnStock(int);
  void setEnviado(bool);
  void setTipoProducto(TipoProducto);
  void addPromocion(Promocion *);
  void setVendedor(Vendedor *);
  Producto(int, std::string, std::string, float, int, TipoProducto, Vendedor *);
  ~Producto();
  void setPrint(std::ostream &out); // Sobrecarga de operador '<<'
};

std::ostream &operator<<(std::ostream &out, Producto &obj); // cout Producto

#endif