#pragma once

#ifndef UGHEATSFD_H
#define UGHEATSFD_H

#include "Base.h"

/**
 * Empresa UghEats Food Delivery
 */
class UghEatsFD
{
private:
	vector<Base> bases; /**< Vetor que contem as tres diferentes bases da empresa */
public:

	/**
	 * @brief Construtor da classe UghEats
	 */
	UghEatsFD();

	/**
	 * @brief Getter da  base de indice int no vetor 
	 * @return Base desejada
	 */
	Base& getBase(int);

	/**
	 * @brief Adiciona uma base a empresa
	 * @param b - base a adicionar
	 */
	void addBase(Base b);

	/**
	 * @brief Permite o utilizador verificar os lucros dos servicos da empresa
	 */
	void getProfit();

	/**
	 * @brief Permite o utilizador banir um cliente
	 */
	void banUser();
};




#endif // !_UGHEATSFD_H