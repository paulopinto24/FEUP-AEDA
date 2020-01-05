#pragma once

#ifndef UGHEATSFD_H
#define UGHEATSFD_H

#include "Base.h"

#include <unordered_set>

struct funcHash {
	size_t operator() (const Funcionario p) const {
		return stoi(p.getNIF());
	}

	bool operator() (const Funcionario& p1, const Funcionario& p2) const
	{
		if (p1.getNIF() == p2.getNIF()) {
			return true;
		}
		else {
			return false;
		}
	}

};

/**
 * Empresa UghEats Food Delivery
 */
class UghEatsFD
{
private:
	vector<Base> bases; /**< Vetor que contem as tres diferentes bases da empresa */
	unordered_set<string> funcionario_tab; /**< Tabela de dispersao que contem os funcionarios da empresa  */
	unordered_set<Funcionario, funcHash, funcHash> func; /**< Tabela de dispersao que contem os funcionarios da empresa  */
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

	/**
	 * @brief Permite inserir um funcionario na tabela de dispersao de funcionarios
	 */

	void show_func();

	int funcionario_tabS();

	/**
	* @brief Permite ver os NIFs de todos os funcionarios da empresa
	* @param f - Funcioanrio a adicionar
	*/
	void ins_func(Funcionario f);

	/**
	 * @brief Permite ver de forma estruturada os funcionarios da empresa
	 */
	void check_func_records();

	/**
	 * @brief Permite ver de forma estruturada os veículos da empresa
	 */
	void checkVehicles();
};




#endif // !_UGHEATSFD_H