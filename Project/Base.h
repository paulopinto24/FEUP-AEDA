#pragma once

#ifndef BASE_H
#define BASE_H


#include "Pessoa.h" 
#include "GPScoord.h"
#include "Entrega.h"

class Cliente;
class Administrativo;
class Entregador;
class Entrega;

using namespace std;

/**
 * Base da empresa (Porto, Lisboa ou Faro)
 */
class Base 
{
private:
	string distrito; /**< distrito onde se localiza a base (Porto, Lisboa ou Faro)*/
	string morada; /**< morada da base*/
	string concelho; /**< concelho da base (capital de distrito ou concelhos fronteira)*/
	GPScoord gps; /**< coordenadas GPS com valores para latitude e longitude*/
	vector<Cliente> clientes; /**< vector que contem os clientes inscritos na base */
	vector<Administrativo> admins; /**< vector que contem os administradores da base */
	vector<Entregador> entregs; /**< vector que contem os entregadores da base */
	vector<Restaurante> restaurantes; /**< vector que contem os restaurantes da base */
	vector<string> concelhosFront; /**< vector que contem os concelhos fronteira da base */
	vector<Cliente> lista_negra; /**< lista negra da base */
	vector<Entrega> historial; /**< historial de entregas da base */
	vector<string> historialStr; /**< historial de entregas da base em formato string */
public:
	/**
	 * @brief Construtor da classe Base
	 */
	Base();

	/**
	 * @brief Construtor da classe Base com parametros
	 * @param d - distrito da base
	 * @param m - morada da base
	 * @param c - concelho da base
	 * @param gpscoord - coordenadas GPS da base
	 */
	Base(const string d, const string m, const string c, GPScoord& gpscoord);

	//getters

	/**
	 * @brief Getter do distrito
	 * @return Retorna o distrito como string 
	 */
	string getDistrito();

	/**
	 * @brief Getter da morada
	 * @return Retorna a morada como string
	 */
	string getMorada();

	/**
	 * @brief Getter do concelho
	 * @return Retorna o concelho como string
	 */
	string getConcelho();

	/**
	 * @brief Getter da localizacao exata da base
	 * @return Retorna a localizacao como GPSCoord
	 */
	GPScoord getLocation();

	/**
	 * @brief Getter do cliente de indice i
	 * @param i - indice do cliente no vetor de clientes a ser retornado
	 * @return Retorna o cliente desejado
	 */
	Cliente getCliente(int i);

	/**
	 * @brief Getter da entrega de indice i
	 * @param i - indice da entrega no vetor historial a ser retornado
	 * @return Retorna a entrega desejada
	 */
	Entrega getHis(int i);

	/**
	 * @brief Getter do tamanho do vetor clientes
	 * @return Retorna o tamanho do vetor clientes
	 */
	int getClientesSize();

	/**
	 * @brief Getter do tamanho do vetor de administradores
	 * @return Retorna o tamanho do vetor de administradores
	 */
	int getAdminsS();

	/**
	 * @brief Getter do tamanho do vetor de entregadores
	 * @return Retorna o tamanho do vetor de entregadores
	 */
	int getEntregsS();

	/**
	 * @brief Getter do tamanho do vetor de restaurantes
	 * @return Retorna o tamanho do vetor de rrestaurantes
	 */
	int getRestaurantesS();

	/**
	 * @brief Getter do tamanho do vetor de concelhos fronteira
	 * @return Retorna o tamanho do vetor de concelhos fronteira
	 */
	int getFrontS();

	/**
	 * @brief Getter do tamanho da lista negra
	 * @return Retorna o tamanho da lista negra
	 */
	int getBlackS();

	/**
	 * @brief Getter do tamanho do historial
	 * @return Retorna o tamanho do historial
	 */
	int getHisS();

	/**
	 * @brief Getter do tamanho do historial (string)
	 * @return Retorna o tamanho do historial (string)
	 */
	int getEntregaStrS();

	/**
	 * @brief Getter de um administrador
	 * @param i - indice do administrador no vetor de administradores
	 * @return Retorna o administrador desejado
	 */
	Administrativo getAdmin(int i);

	/**
	 * @brief Getter de um entregador
	 * @param i - indice do entregador no vetor de entregadores
	 * @return Retorna o entregador desejado
	 */
	Entregador getEntreg(int i);

	/**
	 * @brief Getter de um restaurante
	 * @param i - indice do restaurante no vetor de restaurantes
	 * @return Retorna o restaurante desejado
	 */
	Restaurante getRes(int i);

	/**
	 * @brief Getter do vetor restaurantes
	 * @return Retorna o vetor restaurantes
	 */
	vector<Restaurante> getRestaurantes();

	/**
	 * @brief Getter de um concelho fronteira
	 * @param i - indice do concelho no vetor de concelhos fronteira
	 * @return Retorna o concelho desejado
	 */
	string getFront(int i);

	/**
	 * @brief Getter de um cliente banido
	 * @param i - indice do cliente no vetor da lista negra
	 * @return Retorna o cliente desejado
	 */
	Cliente getBlack(int i);

	/**
	 * @brief Getter de uma entrega
	 * @param i - indice da entrega no vetor do historial (string)
	 * @return Retorna a entrega desejado
	 */
	string getEntregaStr(int i);

	//adders

	/**
	 * @brief Adder de um cliente
	 * @param c - cliente a adicionar ao vetor de clientes
	 * @return Retorna true se for bem sucedido e false caso o cliente ja se encontre presente no vetor
	 */
	bool addCliente(Cliente c);

	/**
	 * @brief Adder de um administrativo
	 * @param ad - administrativo a adicionar ao vetor de administrativos
	 * @return Retorna true se for bem sucedido e false caso o administrador ja se encontre presente no vetor
	 */
	bool addAdmin(Administrativo& ad);

	/**
	 * @brief Adder de um entregador
	 * @param e - entregador a adicionar ao vetor de entregadores
	 * @return Retorna true se for bem sucedido e false caso o entregador ja se encontre presente no vetor
	 */
	bool addEntregador(Entregador &e);

	/**
	 * @brief Adder de um restaurante
	 * @param r - restaurante a adicionar ao vetor de restaurantes
	 * @return Retorna true se for bem sucedido e false caso o restaurante ja se encontre presente no vetor
	 */
	bool addRestaurante(Restaurante& r);

	/**
	 * @brief Adder de um cliente a lista negra
	 * @param c - cliente a adicionar a lista negra
	 */
	void addBlack(Cliente c);

	/**
	 * @brief Adder de um concelho
	 * @param s - concelho a adicionar ao vetor de concelhos fronteira
	 */
	void addFront(string s);

	/**
	 * @brief Adder de uma entrega
	 * @param e - entrega a adicionar ao historial
	 */
	void addEntrega(Entrega e);

	/**
	 * @brief Adder de uma entrega
	 * @param e - concelho a adicionar ao historial (string)
	 */
	void addEntregaStr(string e);

	//printers
	
	/**
	 * @brief Crias string com os diferentes restaurantes da base
	 * @return string que contem as informacoes a imprimir
	 */
	string printByRes();

	/**
	 * @brief Cria e imprime string com os diferentes restaurantes da base de uma determinada zona
	 * @param c - concelho ao qual os restaurantes a serem impressos devem pertencer
	 * @return indice do restaurante escolhido pelo utilizador
	 */
	int printByZone(string c);

	/**
	 * @brief Cria string com os diferentes restaurantes da base que oferecem produtos de custo inferior a um determinado preco
	 * @param p - preco maximo aceitavel de um prato
	 * @return string que contem as informacoes a imprimir
	 */
	string printByPrice(double p);

	/**
	 * @brief Cria string com os diferentes restaurantes da base que oferecem produtos de um determinado tipo
	 * @param t - tipo de culinaria em questao
	 * @return string que contem as informacoes a imprimir
	 */
	string printByType(string t);

	//deleters
	
	/**
	 * @brief Remove um cliente do vetor de clientes
	 * @param cliente - cliente a ser removido
	 */
	void deleteClient(Cliente cliente);

	//sorter
	
	/**
	 * @brief Da sort aos clientes
	 */
	void sortClientes();

	/**
	 * @brief Da sort a lista negra
	 */
	void sortBlack();
};


#endif // !BASE_H
