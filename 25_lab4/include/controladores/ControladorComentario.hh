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
  void comentarProducto(std::string, DTFecha *, int, std::string);
  void responderComentario(std::string, DTFecha *, int, std::string);
  void eliminarComentario(int);
  static ControladorComentario *getInstancia();
  ~ControladorComentario();
};

#endif