#ifndef USUARIO
#define USUARIO

#include "./datatypes/DTFecha.hh"
#include "./datatypes/DTUsuario.hh"

class Usuario
{
private:
  std::string nickname;
  std::string password;
  DTFecha *fechaNacimiento;

public:
  std::string getNickname();
  std::string getPassword();
  DTFecha *getFechaNacimiento();
  Usuario(std::string nickname, std::string password, DTFecha *fechaNacimiento);
  ~Usuario();
};

#endif