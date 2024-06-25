#ifndef USUARIO
#define USUARIO

#include "./datatypes/DTUsuario.hh"
#include "./Comentario.hh"

class Comentario;

class Usuario
{
private:
  std::string nickname;
  std::string password;
  DTFecha *fechaNacimiento;
  std::set<Comentario *> comentarios;

public:
  std::string getNickname();
  std::string getPassword();
  DTFecha *getFechaNacimiento();
  DTUsuario *getDataUsuario();
  std::set<DTComentario *> listarComentarios();
  void añadirComentario(Comentario *);
  void eliminarComentario(Comentario *);
  Usuario(std::string nickname, std::string password, DTFecha *fechaNacimiento);
  ~Usuario();
};

#endif