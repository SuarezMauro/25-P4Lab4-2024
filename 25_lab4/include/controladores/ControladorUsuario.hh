#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

#include "../interfaces/IControladorUsuario.hh"
#include "../Cliente.hh"
#include "../Vendedor.hh"

#include <set>

class ControladorUsuario : public IControladorUsuario
{
private:
  std::set<Cliente *> clientes;
  std::set<Vendedor *> vendedores;
  static ControladorUsuario *instancia;
  ControladorUsuario();

public:
  static ControladorUsuario *getInstancia();                                              // Implementado
  Cliente *getCliente(std::string);                                                       // Implementado
  Vendedor *getVendedor(std::string);                                                     // Implementado
  void altaNuevoCliente(std::string, std::string, DTFecha *, DTDireccion *, std::string); // Implementado
  void altaNuevoVendedor(std::string, std::string, DTFecha *, std::string);               // Implementado
  void realizarSuscripciones(std::string, std::set<std::string>);                         // Implementado
  void eliminarSuscripciones(std::string, std::set<std::string>);                         // Implementado
  std::set<DTUsuario *> listarUsuarios();                                                 // Implementado
  std::set<DTCliente *> listarClientes();                                                 // Implementado
  std::set<DTVendedor *> listarVendedores();                                              // Implementado
  std::set<DTVendedor *> listarVendedoresNoSuscritos(std::string);                        // Implementado
  std::set<DTProducto *> listarProductosVendedor(std::string);                            // Implementado
  std::set<DTNotificacion *> listarNotificaciones(std::string);
  std::set<DTVendedor *> listarSuscripciones(std::string);
  std::set<DTComentario *> listarComentariosUsuario(std::string);
  ~ControladorUsuario();

  std::set<DTVendedor *> listarVendedoresSuscritos(std::string);
  // void RegistroNuevoProducto(std::string nickVendedor, Producto *producto);
};

#endif