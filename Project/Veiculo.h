#pragma once

#include <string>

using namespace std;

/**
 *   Ve�culo pertencente � empresa e que � conduzido por um entregador da mesma
 */
class Veiculo
{
private:
	string marca; /**< marca do ve�culo*/
	string tipo; /**< tipo de ve�culo*/
	string dataAquisicao; /**< data em que a empresa adquiriu o ve�culo*/
	string matricula; /**< matr�cula do ve�culo*/
	int numero_entregas; /**< n�mero de entregas efetuadas com o ve�culo*/
	float kms; /**< quil�metros percorridos pelo ve�culo*/
public:
	/**
	 * @brief Construtor da classe Ve�culo
	 */
	Veiculo();

	/**
	 * @brief Construtor da classe Administrativo
	 * @param m - Marca do ve�culo
	 * @param t - Tipo de ve�culo
	 * @param da - data em que a empresa adquiriu o ve�culo
	 */
	Veiculo(string m, string t, string da, string mat, int ne, float km);

	/**
	 * @brief Permite obter o tipo de ve�culo
	 * @return Retorna o tipo de ve�culo
	 */
	string getTipo();

	/**
	 * @brief Permite obter a marca do ve�culo
	 * @return Retorna a marca do ve�culo
	 */
	string getMarca();

	/**
	 * @brief Permite obter a data em que a empresa adquiriu o ve�culo
	 * @return Retorna a data em que a empresa adquiriu o ve�culo
	 */
	string getDataAquisicao();

	/**
	 * @brief Permite obter a matr�cula do ve�culo
	 * @return Retorna a a matr�cula do ve�culo
	 */
	string getMatricula();

	/**
	 * @brief Permite obter o n�mero de entregas realizadas com o ve�culo
	 * @return Retorna o n�mero de entregas realizadas com o ve�culo
	 */
	int getEntregas();

	/**
	 * @brief Permite obter o n�mero de quil�metros percorridos pelo ve�culo
	 * @return Retorna o n�mero de quil�metros percorridos pelo ve�culo
	 */
	float getKms();

	/**
	 * @brief Permite alterar a marca de um ve�culo
	 * @param m - Nova marca atribu�da ao ve�culo
	 */
	void setMarca(string m);

	/**
	 * @brief Permite alterar o tipo de ve�culo
	 * @param t - Nova tipo atribu�do ao ve�culo
	 */
	void setTipo(string t);

	/**
	 * @brief Permite alterar a data em que a empresa adquiriu o ve�culo
	 * @param m - Nova data de aquisi��o do ve�culo
	 */
	void setDataAquisicao(string);

	/**
	 * @brief Adiciona ao ve�culo o n�mero de kms percorridos numa entrega e �ncrementa em 1 o n�mero de entregas
	 */
	void doEntrega();

	/**
	 * @brief Overload do operador de igualidade para a classe Veiculo
	 * @param v - Ve�culo a ser comparado
	 * @return Retorna true caso os ve�culos a ser comparados forem iguais, caso contr�rio retorna falso
	 */
	bool operator == (const Veiculo& v) const;

	/**
	 * @brief Overload do operador de menor para a classe Veiculo
	 * @param v - Ve�culo a ser comparado
	 * @return Retorna true caso o ve�culo tenha menor n�mero de entregas realizadas, em caso de empate retorna true se o ve�culo tiver menor n�mero de kms percorridos
	 */
	bool operator < (const const Veiculo& v) const;
};


