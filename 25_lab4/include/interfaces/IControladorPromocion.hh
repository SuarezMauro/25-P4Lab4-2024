#ifndef I_CONTROLADOR_PROMOCION
#define I_CONTROLADOR_PROMOCION

#include "../Promocion.hh"
#include <iostream>
#include "../datatypes/DTFecha.hh"

class IControladorPromocion
{
public:
  virtual Promocion *getPromocion(std::string) = 0;
  virtual std::set<DTPromocion *> obtenerPromocionesVigentes() = 0;
  virtual void agregarAPromo(int id, int cantidadMin) = 0;
  virtual void altaNuevaPromo() = 0;
  virtual void registrarDatosPromo(std::string nombre, std::string descripcion, DTFecha *fechaVencimiento, float porcentaje) = 0;
  virtual void asignarVendedor(std::string nombre) = 0;
  virtual std::set<DTProducto *> productosEnUnaPromo(std::string nombrePromocion) = 0;
};

#endif