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
	 * @return Retorna verdadeiro se os NIF's das Pessoas forem iguais, caso contr�rio retorna falso
	 */
	bool operator == (Pessoa& p);

	int encomenda();

	/**
	 * @brief Overload do operador "menor que" para a classe Pessoa
	 * @param c - Pessoa a ser comparada
	 * @return Retorna verdadeiro se o NIF da Pessoa � esquerda do operador for menor do que o da direita, caso contr�rio retorna falso
	 */
	bool operator < (const Pessoa& p) const;
};

/**
 *   Pessoa que � um cliente na empresa
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
	 * @return Retorna verdadeiro se os NIF's dos Clientes forem iguais, caso contr�rio retorna falso
	 */
	bool operator == (const Cliente&) const; 
};

/**
 *   Pessoa que � funcion�rio na empresa
 */
class Funcionario : public Pessoa
{
private:
	string dataNasc; /**< data de nascimento do funcion�rio*/
	double salario; /**< salario do funcion�rio*/
public:
	/**
	 * @brief Construtor da classe Funcionario
	 * @param n - Nome do funcion�rio
	 * @param nif - NIF do funcion�rio
	 * @param dn - data de nascimento do funcion�rio
	 * @param s - sal�rio do funcion�rio
	 */
	Funcionario(string n, string nif, string dn, double s);

	/**
	 * @brief Permite obter a data de nascimento do funcion�rio
	 * @return Retorna a data de nascimento do funcion�rio
	 */
	string getDataNasc();

	/**
	 * @brief Permite obter o sal�rio do funcion�rio
	 * @return Retorna o sal�rio do funcion�rio
	 */
	double getSalario();
};

/**
 *   Pessoa que � funcion�rio do tipo administrativo na empresa
 */
class Administrativo : public Funcionario
{
private:
	string funcao; /**< fun��o do funcion�rio do tipo administrativo*/
public:
	/**
	 * @brief Construtor da classe Administrativo
	 * @param n - Nome do funcion�rio do tipo administrativo
	 * @param nif - NIF do funcion�rio do tipo administrativo
	 * @param dn - data de nascimento do funcion�rio do tipo administrativo
	 * @param s - sal�rio do funcion�rio do tipo administrativo
	 * @param f - fun��o do funcion�rio do tipo administrativo
	 */
	Administrativo(string n, string nif, string dn, double s, string f);
	
	/**
	 * @brief Permite obter a fun��o do funcion�rio do tipo administrativo
	 * @return Retorna a fun��o do funcion�rio do tipo administrativo
	 */
	string getFunc();
};

/**
 *   Pessoa que � funcion�rio do tipo entregador na empresa
 */
class Entregador : public Funcionario
{
private:
	Veiculo veiculo; /**< ve�culo conduzido pelo funcion�rio do tipo entregador*/
	double comissao; /**< comiss�o do funcion�rio do tipo entregador*/
public:
	/**
	 * @brief Construtor da classe Entregador
	 * @param n - Nome do funcion�rio do tipo entregador
	 * @param nif - NIF do funcion�rio do tipo entregador
	 * @param dn - data de nascimento do funcion�rio do tipo entregador
	 * @param s - sal�rio do funcion�rio do tipo entregador
	 * @param v - veiculo conduzido pelo funcion�rio do tipo entregador
	 */
	Entregador(string n, string nif, string dn, double s, Veiculo &v);
	
	/**
	 * @brief Permite alterar a comiss�o do funcion�rio do tipo entregador
	 */
	void setCom(double comissao);
	
	/**
	 * @brief Permite obter o ve�culo conduzido pelo funcion�rio do tipo entregador
	 * @return Retorna o ve�culo conduzido pelo funcion�rio do tipo entregador
	 */
	Veiculo getVeiculo();

	/**
	 * @brief Permite obter a comiss�o do funcion�rio do tipo entregador
	 * @return Retorna a comiss�o do funcion�rio do tipo entregador
	 */
	double getComissao();

	/**
	 * @brief Realiza a fun��o doEntrega() da classe ve�culo
	 */
	void doEntrega() {
		this->veiculo.doEntrega();
	}
};

