#include "../../include/controladores/ControladorComentario.hh"
#include "../../include/fabrica/Fabrica.hh"

Comentario *ControladorComentario::getComentario(int id)
{
  Comentario *retorno = NULL;
  bool encontrado = false;
  for (std::set<Comentario *>::iterator it = comentarios.begin(); (it != comentarios.end()) && !encontrado; it++)
  {
    if ((*it)->getId() == id)
    {
      retorno = *it;
      encontrado = true;
    }
  }
  return retorno;
}
int ControladorComentario::getNuevoID()
{
  nuevoID++;
  return nuevoID;
}
std::set<DTComentario *> ControladorComentario::listarComentariosUsuario(std::string nickname)
{
  std::set<DTComentario *> listaComentarios;
  Usuario *usuario = Fabrica::getInterfazUsuario()->getUsuario(nickname);
  listaComentarios = usuario->listarComentarios();
  return listaComentarios;
}
std::set<DTComentario *> ControladorComentario::listarComentariosProducto(int id)
{
  std::set<DTComentario *> listaComentarios;
  Producto *producto = Fabrica::getInterfazProducto()->getProducto(id);
  listaComentarios = producto->listarComentarios();
  return listaComentarios;
}
void ControladorComentario::comentarProducto(std::string comentario, DTFecha *fecha, int idProducto, std::string nickRemitente)
{
  Usuario *remitente = Fabrica::getInterfazUsuario()->getUsuario(nickRemitente);
  Producto *producto = Fabrica::getInterfazProducto()->getProducto(idProducto);
  DTProducto *dataProducto = producto->getDataProducto();

  Comentario *nuevoComentario = new Comentario(getNuevoID(), fecha, comentario, nickRemitente, NULL, dataProducto);

  remitente->añadirComentario(nuevoComentario);
  producto->añadirComentario(nuevoComentario);
  comentarios.insert(nuevoComentario);
}
void ControladorComentario::responderComentario(std::string comentario, DTFecha *fecha, int idComentario, std::string nickRemitente)
{
  Usuario *remitente = Fabrica::getInterfazUsuario()->getUsuario(nickRemitente);
  Comentario *comentarioRespondido = getComentario(idComentario);
  Comentario *nuevoComentario = new Comentario(getNuevoID(), fecha, comentario, nickRemitente, comentarioRespondido, NULL);
  remitente->añadirComentario(nuevoComentario);
  comentarioRespondido->agregarRespuesta(nuevoComentario);
  comentarios.insert(nuevoComentario);
}
void ControladorComentario::eliminarComentario(int idComentario)
{
  bool encontrado = false;
  for (std::set<Comentario *>::iterator it = comentarios.begin(); (it != comentarios.end()) && !encontrado; it++)
  {
    if ((*it)->getId() == idComentario)
    {
      Comentario *aBorrar = *it;
      comentarios.erase(aBorrar);
      delete aBorrar;
      encontrado = true;
    }
  }
}
ControladorComentario::~ControladorComentario() {}
ControladorComentario::ControladorComentario()
{
  nuevoID = 1;
}
ControladorComentario *ControladorComentario::instancia = NULL;
ControladorComentario *ControladorComentario::getInstancia()
{
  if (instancia == NULL)
  {
    instancia = new ControladorComentario();
  }
  return instancia;
}