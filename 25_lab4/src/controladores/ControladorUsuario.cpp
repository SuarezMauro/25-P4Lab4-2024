#include "../../include/controladores/ControladorUsuario.hh"

void ControladorUsuario::altaNuevoCliente(std::string nickname, std::string password, DTFecha *fechaNacimiento, DTDireccion *direccion, std::string ciudadResidencia)
{
  Cliente *nuevoCliente = new Cliente(nickname, password, fechaNacimiento, direccion, ciudadResidencia);
  clientes.insert(nuevoCliente);
}
void ControladorUsuario::altaNuevoVendedor(std::string nickname, std::string password, DTFecha *fechaNacimiento, std::string codigoRUT)
{
  Vendedor *nuevoVendedor = new Vendedor(nickname, password, fechaNacimiento, codigoRUT);
  vendedores.insert(nuevoVendedor);
}
void ControladorUsuario::realizarSuscripciones(std::string nickCliente, std::set<std::string> nicksVendedores)
{
  Cliente *usuario = getCliente(nickCliente);
  for (std::set<std::string>::iterator nickVendedor = nicksVendedores.begin(); nickVendedor != nicksVendedores.end(); nickVendedor++)
  {
    Vendedor *suscripcion = getVendedor(*nickVendedor);
    usuario->añadirSuscripcion(suscripcion);
  }
}
void ControladorUsuario::eliminarSuscripciones(std::string nickCliente, std::set<std::string> nicksVendedores)
{
  Cliente *usuario = getCliente(nickCliente);
  for (std::set<std::string>::iterator nickVendedor = nicksVendedores.begin(); nickVendedor != nicksVendedores.end(); nickVendedor++)
  {
    Vendedor *suscripcion = getVendedor(*nickVendedor);
    usuario->removerSuscripcion(suscripcion);
  }
}
void ControladorUsuario::eliminarNotificaciones(std::string nickCliente)
{
  Cliente *cliente = getCliente(nickCliente);
  cliente->eliminarNotificaciones();
}
Cliente *ControladorUsuario::getCliente(std::string nickname)
{
  Cliente *retorno = NULL;
  bool encontrado = false;
  for (std::set<Cliente *>::iterator it = clientes.begin(); (it != clientes.end()) && !encontrado; it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      retorno = *it;
      encontrado = true;
    }
  }
  return retorno;
}
Vendedor *ControladorUsuario::getVendedor(std::string nickname)
{
  Vendedor *retorno = NULL;
  bool encontrado = false;
  for (std::set<Vendedor *>::iterator it = vendedores.begin(); (it != vendedores.end()) && !encontrado; it++)
  {
    if ((*it)->getNickname() == nickname)
    {
      retorno = *it;
      encontrado = true;
    }
  }
  return retorno;
}
Usuario *ControladorUsuario::getUsuario(std::string nickname)
{
  Usuario *retorno = getVendedor(nickname);
  if (retorno == NULL)
  {
    retorno = getCliente(nickname);
  }
  return retorno;
}
std::set<DTUsuario *> ControladorUsuario::listarUsuarios()
{
  std::set<DTUsuario *> listaUsuarios;
  for (std::set<Cliente *>::iterator itCliente = clientes.begin(); itCliente != clientes.end(); itCliente++)
  {
    DTUsuario *dataCliente = (*itCliente)->getDataCliente();
    listaUsuarios.insert(dataCliente);
  }
  for (std::set<Vendedor *>::iterator itVendedor = vendedores.begin(); itVendedor != vendedores.end(); itVendedor++)
  {
    DTUsuario *dataVendedor = (*itVendedor)->getDataVendedor();
    listaUsuarios.insert(dataVendedor);
  }
  return listaUsuarios;
}
std::set<DTCliente *> ControladorUsuario::listarClientes()
{
  std::set<DTCliente *> listaClientes;
  for (std::set<Cliente *>::iterator it = clientes.begin(); it != clientes.end(); it++)
  {
    DTCliente *dataCliente = (*it)->getDataCliente();
    listaClientes.insert(dataCliente);
  }
  return listaClientes;
}
std::set<DTVendedor *> ControladorUsuario::listarVendedores()
{
  std::set<DTVendedor *> listaVendedores;
  for (std::set<Vendedor *>::iterator it = vendedores.begin(); it != vendedores.end(); it++)
  {
    DTVendedor *dataVendedor = (*it)->getDataVendedor();
    listaVendedores.insert(dataVendedor);
  }
  return listaVendedores;
}
std::set<DTVendedor *> ControladorUsuario::listarVendedoresNoSuscritos(std::string nickname)
{
  std::set<DTVendedor *> listaNoSuscritos = listarVendedores();
  Cliente *usuario = getCliente(nickname);
  std::set<Vendedor *> suscripcionesUsuario = usuario->getSuscripciones();
  for (std::set<Vendedor *>::iterator it = suscripcionesUsuario.begin(); it != suscripcionesUsuario.end(); it++)
  {
    std::string nickSuscripcion = (*it)->getNickname();
    bool encontrado = false;
    for (std::set<DTVendedor *>::iterator dt = listaNoSuscritos.begin(); (dt != listaNoSuscritos.end()) && !encontrado; dt++)
    {
      if ((*dt)->getNickname() == nickSuscripcion)
      {
        DTVendedor *aBorrar = *dt;
        listaNoSuscritos.erase(aBorrar);
        delete aBorrar;
      }
    }
  }
  return listaNoSuscritos;
}

std::set<DTProducto *> ControladorUsuario::listarProductosVendedor(std::string nickname)
{
  Vendedor *vendedor = getVendedor(nickname);
  std::set<DTProducto *> listaProductos = vendedor->listarProductos();
  return listaProductos;
}
std::set<DTNotificacion *> ControladorUsuario::listarNotificaciones(std::string)
{
  std::set<DTNotificacion *> retorno;
  return retorno;
}
std::set<DTVendedor *> ControladorUsuario::listarSuscripciones(std::string)
{
  return std::set<DTVendedor *>();
}
std::set<DTComentario *> ControladorUsuario::listarComentariosUsuario(std::string)
{
  return std::set<DTComentario *>();
}
ControladorUsuario::ControladorUsuario() {}
ControladorUsuario::~ControladorUsuario() {}
ControladorUsuario *ControladorUsuario::instancia = NULL;
ControladorUsuario *ControladorUsuario::getInstancia()
{
  if (instancia == NULL)
  {
    instancia = new ControladorUsuario();
  }
  return instancia;
}

std::set<DTVendedor *> ControladorUsuario::listarVendedoresSuscritos(std::string nickname)
{
  std::set<DTVendedor *> listaSuscritos;
  Cliente *usuario = getCliente(nickname);
  std::set<Vendedor *> suscripcionesUsuario = usuario->getSuscripciones();
  for (std::set<Vendedor *>::iterator it = suscripcionesUsuario.begin(); it != suscripcionesUsuario.end(); it++)
  {
    DTVendedor *aInsertar = (*it)->getDataVendedor();
    listaSuscritos.insert(aInsertar);
  };
  return listaSuscritos;
}

/*void ControladorUsuario::RegistroNuevoProducto(std::string nickVendedor, Producto *producto)
{
  Vendedor *vendedor = getVendedor(nickVendedor);
  vendedor->añadirProducto(producto);
}*/
