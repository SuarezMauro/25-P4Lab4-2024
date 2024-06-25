#include "../../include/datatypes/DTFecha.hh"

int DTFecha::getDia()
{
  return dia;
}
int DTFecha::getMes()
{
  return mes;
}
int DTFecha::getAnio()
{
  return anio;
}
std::string DTFecha::toString()
{
  std::string retorno = std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
  return retorno;
}
int DTFecha::compararFecha(DTFecha *fecha)
{
  if (anio > fecha->getAnio())
  {
    return 1;
  }
  else if (anio < fecha->getAnio())
  {
    return -1;
  }
  else if (mes > fecha->getMes())
  {
    return 1;
  }
  else if (mes < fecha->getMes())
  {
    return -1;
  }
  else if (dia > fecha->getDia())
  {
    return 1;
  }
  else if (dia < fecha->getDia())
  {
    return -1;
  }
  else
  {
    return 0;
  }
};
DTFecha *DTFecha::copiarFecha()
{
  DTFecha *copia = new DTFecha(dia, mes, anio);
  return copia;
}
DTFecha::DTFecha(int d, int m, int a)
{
  dia = d;
  mes = m;
  anio = a;
}
DTFecha::~DTFecha() {}
