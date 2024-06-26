#ifndef CONTROLADOR_COMENTARIO
#define CONTROLADOR_COMENTARIO

#include "../interfaces/IControladorComentario.hh"

class ControladorComentario : public IControladorComentario
{
private:
  std::set<Comentario *> comentarios;
  int nuevoID;
  static ControladorComentario *instancia;
  ControladorComentario();

public:
  Comentario *getComentario(int);
  int getNuevoID();
  std::set<DTComentario *> listarComentariosUsuario(std::string);
  std::set<DTComentario *> listarComentariosProducto(int);
  void comentarProducto(std::string comentario, DTFecha *fecha, int idProducto, std::string nickRemitente);
  void responderComentario(std::string, DTFecha *, int, std::string);
  void eliminarComentario(int);
  Comentario* buscarPadre(Comentario* idComentario);
  int getIdComentario(std::string textoComentario);
  static ControladorComentario *getInstancia();
  ~ControladorComentario();
};

#endif