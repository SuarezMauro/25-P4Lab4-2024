#ifndef I_CONTROLADOR_COMENTARIO
#define I_CONTROLADOR_COMENTARIO

#include "../Comentario.hh"

#include <iostream>
#include <set>

class IControladorComentario
{
public:
  virtual Comentario *getComentario(int) = 0;
  virtual int getNuevoID() = 0;
  virtual std::set<DTComentario *> listarComentariosUsuario(std::string) = 0;
  virtual std::set<DTComentario *> listarComentariosProducto(int) = 0;
  virtual void comentarProducto(std::string, DTFecha *, int, std::string) = 0;
  virtual void responderComentario(std::string, DTFecha *, int, std::string) = 0;
  virtual void eliminarComentario(int) = 0;
};

#endif