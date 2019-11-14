#include "Entrega.h"



Entrega::Entrega(Encomenda enc, Entregador ent)
{
	custoFixo = enc.getpFixo();
	custoTotal = enc.getpTotal();
	entregador.push_back(ent);
}

void Entrega::setSuccess(bool ans)
{
	success = ans;
}

double Entrega::getCustoTotal()
{
	return custoTotal;
}

Entregador Entrega::getEntregador()
{
	return entregador.at(0);
}





