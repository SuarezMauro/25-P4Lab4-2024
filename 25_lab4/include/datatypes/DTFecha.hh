#ifndef DTFECHA
#define DTFECHA
#include <iostream>
#include <string>

class DTFecha
{
private:
  int dia;
  int mes;
  int anio;

public:
  int getDia();
  int getMes();
  int getAnio();
  std::string toString();
  int compararFecha(DTFecha *fecha);
  DTFecha *copiarFecha();
  DTFecha(int dia, int mes, int anio);
  ~DTFecha();
};

#endif
