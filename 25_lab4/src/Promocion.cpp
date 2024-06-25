#include "../include/Promocion.hh"

std::string Promocion::getNombre()
{
    return nombre;
}

std::string Promocion::getDescripcion()
{
    return descripcion;
}

DTFecha *Promocion::getFechaDeVencimiento()
{
    return fechaDeVencimiento;
}

Vendedor *Promocion::getVendedor()
{
    return vendedor;
}

std::set<Producto *> Promocion::getProductos()
{
    return productos;
}

Producto *Promocion::getProducto(int id)
{
    for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            return *it;
        }
    }
    return NULL;
}

std::map<int, InfoPromoProducto *> Promocion::getInfoProductos()
{
    return infoProductos;
}

InfoPromoProducto *Promocion::getInfoProducto(int id)
{
    for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            return infoProductos.at(id);
        }
    }
    return NULL;
}

float Promocion::getPorcentajeDescuento()
{
    return porcentajeDescuento;
}

void Promocion::setNombre(std::string n)
{
    nombre = n;
}

void Promocion::setDescripcion(std::string d)
{
    descripcion = d;
}

void Promocion::setFechaDeVencimiento(DTFecha *f)
{
    fechaDeVencimiento = f;
}

void Promocion::setVendedor(Vendedor *v)
{
    vendedor = v;
}

void Promocion::setProductos(std::set<Producto *> p)
{
    productos = p;
}

void Promocion::setInfoProductos(std::map<int, InfoPromoProducto *> pi)
{
    infoProductos = pi;
}

DTPromocion *Promocion::getDataPromocion() // revisar
{
    std::map<int, DTProductoPromo *> dataProductosPromo;
    for (std::set<Producto *>::iterator it = productos.begin(); it != productos.end(); ++it)
    {
        int cantMin = infoProductos[(*it)->getId()]->getCantidadMinima();
        float porcentajeDesc = getPorcentajeDescuento();
        DTProductoPromo *nuevaData = new DTProductoPromo((*it)->getId(), (*it)->getNombre(), cantMin, porcentajeDesc);
        dataProductosPromo.insert({(*it)->getId(), nuevaData});
    }
    DTPromocion *dataPromocion = new DTPromocion(nombre, descripcion, fechaDeVencimiento->copiarFecha(), porcentajeDescuento, vendedor->getDataVendedor(), dataProductosPromo);
    return dataPromocion;
}
Promocion::Promocion(std::string nombre, std::string descripcion, DTFecha *fechaVencimiento, float porcentajeDescuento, Vendedor *vendedor, std::set<Producto *> productos, std::map<int, InfoPromoProducto *> infoProductos)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->fechaDeVencimiento = fechaVencimiento;
    this->porcentajeDescuento = porcentajeDescuento;
    this->vendedor = vendedor;
    this->productos = productos;
    this->infoProductos = infoProductos;
}
Promocion::~Promocion() {}