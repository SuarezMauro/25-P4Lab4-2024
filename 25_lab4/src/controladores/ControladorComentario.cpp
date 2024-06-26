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

void ControladorComentario::comentarProducto(std::string texto, DTFecha *fecha, int idProducto, std::string nickRemitente)
{
  Usuario *remitente = Fabrica::getInterfazUsuario()->getUsuario(nickRemitente);
  Producto *producto = Fabrica::getInterfazProducto()->getProducto(idProducto);
  DTProducto *dataProducto = producto->getDataProducto();
  Comentario *nuevoComentario = new Comentario(getNuevoID(), fecha, texto, nickRemitente, dataProducto); //id, fecha, nick remitente, infoproductocomentado
  remitente->añadirComentario(nuevoComentario);
  producto->añadirComentario(nuevoComentario);
  comentarios.insert(nuevoComentario);
}

void ControladorComentario::responderComentario(std::string texto, DTFecha *fecha, int idComentarioRespondido, std::string nickRemitente)
{
  Usuario *remitente = Fabrica::getInterfazUsuario()->getUsuario(nickRemitente);
  Comentario* comentarioRespondido = getComentario(idComentarioRespondido);
  Comentario *nuevoComentario = new Comentario(getNuevoID(), fecha, texto, nickRemitente, comentarioRespondido->getInfoProductoComentado());
  remitente->añadirComentario(nuevoComentario);
  comentarioRespondido->agregarRespuesta(nuevoComentario);
  comentarios.insert(nuevoComentario);
}

int ControladorComentario::getIdComentario(std::string textoComentario) 
{ 
  int retorno = 0;
  for (std::set<Comentario *>::iterator it = comentarios.begin(); (it != comentarios.end()); it++)
  {
    if ((*it)->getTexto() == textoComentario)
    {
      return (*it)->getId();
    }
  }
  return retorno;
}

void ControladorComentario::eliminarComentario(int idComentario)
{
  Comentario *aBorrar = getComentario(idComentario);
  std::set<Comentario*> respuestas = aBorrar->getRespuestas();
  if (!respuestas.empty()) {
    for (auto it = respuestas.begin(); it != respuestas.end(); it++)
    {
      eliminarComentario((*it)->getId());
    }
  }

  IControladorUsuario* controladorUsuario = Fabrica::getInterfazUsuario();
  Usuario * user = controladorUsuario->getUsuario(aBorrar->getNickRemitente());
  user->eliminarComentario(aBorrar);
  
  Comentario* padre = buscarPadre(aBorrar);
  if (padre != nullptr) 
  {
    padre->eliminarRespuesta(aBorrar);
  } else {
    IControladorProducto* controladorProducto = Fabrica::getInterfazProducto();
    Producto* prod = controladorProducto->getProducto(aBorrar->getInfoProductoComentado()->getId());
    prod->eliminarComentario(aBorrar);
  }
  comentarios.erase(aBorrar);
  delete aBorrar;
}

Comentario* ControladorComentario::buscarPadre(Comentario* comentario){
  for (std::set<Comentario *>::iterator it = comentarios.begin(); it != comentarios.end(); it++){
    std::set<Comentario*> respuestas = (*it)->getRespuestas();
    if (respuestas.find(comentario) != respuestas.end()){
      return(*it);
    }
  }
  return nullptr;
}

ControladorComentario::~ControladorComentario() {}
ControladorComentario::ControladorComentario()
{
  nuevoID = 0;
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