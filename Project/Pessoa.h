#pragma once

#include <iostream>

#include "Veiculo.h"
#include "Restaurante.h"
#include "Base.h"
#include "Encomenda.h"


using namespace std;

class Base;

/**
 *   Pessoa que participa na empresa
 */
class Pessoa
{
private:
	string nome; /**< Nome da pessoa*/
	string NIF; /**< NIF da pessoa*/
public:
	/**
	 * @brief Construtor da classe Utilizador
	 */
	Pessoa();

	/**
	 * @brief Construtor da classe Utilizador
	 * @param n - Nome atribuido a pessoa
	 * @param nif - NIF atribuido a pessoa
	 */
	Pessoa(string n, string nif);

	/**
	 * @brief Permite obter o NIF da pessoa
	 * @return Retorna o NIF da pessoa
	 */
	string getNIF();

	/**
	 * @brief Permite obter o Nome da pessoa
	 * @return Retorna o Nome da pessoa
	 */
	string getNome();

	/**
	 * @brief Overload do operador de igualdade para a classe Pessoa
	 * @param c - Pessoa a ser comparada
	 * @return Retorna verdadeiro se os NIF's das Pessoas forem iguais, caso contrário retorna falso
	 */
	bool operator == (Pessoa& p);

	int encomenda();

	/**
	 * @brief Overload do operador "menor que" para a classe Pessoa
	 * @param c - Pessoa a ser comparada
	 * @return Retorna verdadeiro se o NIF da Pessoa à esquerda do operador for menor do que o da direita, caso contrário retorna falso
	 */
	bool operator < (const Pessoa& p) const;
};

/**
 *   Pessoa que é um cliente na empresa
 */
class Cliente : public Pessoa
{
private:
	string email; /**< email do cliente*/
	string morada; /**< morada do cliente*/
	string concelho; /**< concelho onde o cliente reside*/
	string base; /**< base onde o cliente esta inscrito*/
public:
	/**
	 * @brief Construtor da classe Cliente
	 * @param n - Nome do cliente
	 * @param nif - NIF do cliente
	 * @param e - email do cliente
	 * @param m - morada do cliente
	 * @param c - concelho onde o cliente reside
	 * @param b - base em que o cliente se vai inscrever
	 */
	Cliente(string n, string nif, string e, string m, string c, string b);
	
	/**
	 * @brief Permite alterar o email do cliente
	 * @param email - novo email do cliente
	 */
	void setEmail(string email);

	/**
	 * @brief Permite alterar a morada do cliente
	 * @param email - nova morada do cliente
	 */
	void setMorada(string morada);

	/**
	 * @brief Permite alterar o concelho onde reside o cliente
	 * @param email - novo concelho de residencia do cliente
	 */
	void setConcelho(string concelho);

	/**
	 * @brief Permite obter o email do cliente
	 * @return Retorna o email do cliente
	 */
	string getEmail();

	/**
	 * @brief Permite obter o concelho de residencia do cliente
	 * @return Retorna o concelho de residencia do cliente
	 */
	string getConcelho();

	int encomenda(Base& b);

	/**
	 * @brief Permite obter a morada do cliente
	 * @return Retorna a morada do cliente
	 */
	string getMorada();

	/**
	 * @brief Overload do operador de igualdade para a classe Cliente
	 * @param c - Cliente a ser comparado
	 * @return Retorna verdadeiro se os NIF's dos Clientes forem iguais, caso contrário retorna falso
	 */
	bool operator == (const Cliente&) const; 
};

/**
 *   Pessoa que é funcionário na empresa
 */
class Funcionario : public Pessoa
{
private:
	string dataNasc; /**< data de nascimento do funcionário*/
	double salario; /**< salario do funcionário*/
public:
	/**
	 * @brief Construtor da classe Funcionario
	 * @param n - Nome do funcionário
	 * @param nif - NIF do funcionário
	 * @param dn - data de nascimento do funcionário
	 * @param s - salário do funcionário
	 */
	Funcionario(string n, string nif, string dn, double s);

	/**
	 * @brief Permite obter a data de nascimento do funcionário
	 * @return Retorna a data de nascimento do funcionário
	 */
	string getDataNasc();

	/**
	 * @brief Permite obter o salário do funcionário
	 * @return Retorna o salário do funcionário
	 */
	double getSalario();
};

/**
 *   Pessoa que é funcionário do tipo administrativo na empresa
 */
class Administrativo : public Funcionario
{
private:
	string funcao; /**< função do funcionário do tipo administrativo*/
public:
	/**
	 * @brief Construtor da classe Administrativo
	 * @param n - Nome do funcionário do tipo administrativo
	 * @param nif - NIF do funcionário do tipo administrativo
	 * @param dn - data de nascimento do funcionário do tipo administrativo
	 * @param s - salário do funcionário do tipo administrativo
	 * @param f - função do funcionário do tipo administrativo
	 */
	Administrativo(string n, string nif, string dn, double s, string f);
	
	/**
	 * @brief Permite obter a função do funcionário do tipo administrativo
	 * @return Retorna a função do funcionário do tipo administrativo
	 */
	string getFunc();
};

/**
 *   Pessoa que é funcionário do tipo entregador na empresa
 */
class Entregador : public Funcionario
{
private:
	Veiculo veiculo; /**< veículo conduzido pelo funcionário do tipo entregador*/
	double comissao; /**< comissão do funcionário do tipo entregador*/
public:
	/**
	 * @brief Construtor da classe Entregador
	 * @param n - Nome do funcionário do tipo entregador
	 * @param nif - NIF do funcionário do tipo entregador
	 * @param dn - data de nascimento do funcionário do tipo entregador
	 * @param s - salário do funcionário do tipo entregador
	 * @param v - veiculo conduzido pelo funcionário do tipo entregador
	 */
	Entregador(string n, string nif, string dn, double s, Veiculo &v);
	
	/**
	 * @brief Permite alterar a comissão do funcionário do tipo entregador
	 */
	void setCom(double comissao);
	
	/**
	 * @brief Permite obter o veículo conduzido pelo funcionário do tipo entregador
	 * @return Retorna o veículo conduzido pelo funcionário do tipo entregador
	 */
	Veiculo getVeiculo();

	/**
	 * @brief Permite obter a comissão do funcionário do tipo entregador
	 * @return Retorna a comissão do funcionário do tipo entregador
	 */
	double getComissao();

	/**
	 * @brief Realiza a função doEntrega() da classe veículo
	 */
	void doEntrega() {
		this->veiculo.doEntrega();
	}
};

