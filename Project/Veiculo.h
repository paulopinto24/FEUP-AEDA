#pragma once

#include <string>

using namespace std;

/**
 *   Veículo pertencente à empresa e que é conduzido por um entregador da mesma
 */
class Veiculo
{
private:
	string marca; /**< marca do veículo*/
	string tipo; /**< tipo de veículo*/
	string dataAquisicao; /**< data em que a empresa adquiriu o veículo*/
	string matricula; /**< matrícula do veículo*/
	int numero_entregas; /**< número de entregas efetuadas com o veículo*/
	float kms; /**< quilómetros percorridos pelo veículo*/
public:
	/**
	 * @brief Construtor da classe Veículo
	 */
	Veiculo();

	/**
	 * @brief Construtor da classe Administrativo
	 * @param m - Marca do veículo
	 * @param t - Tipo de veículo
	 * @param da - data em que a empresa adquiriu o veículo
	 */
	Veiculo(string m, string t, string da, string mat, int ne, float km);

	/**
	 * @brief Permite obter o tipo de veículo
	 * @return Retorna o tipo de veículo
	 */
	string getTipo();

	/**
	 * @brief Permite obter a marca do veículo
	 * @return Retorna a marca do veículo
	 */
	string getMarca();

	/**
	 * @brief Permite obter a data em que a empresa adquiriu o veículo
	 * @return Retorna a data em que a empresa adquiriu o veículo
	 */
	string getDataAquisicao();

	/**
	 * @brief Permite obter a matrícula do veículo
	 * @return Retorna a a matrícula do veículo
	 */
	string getMatricula();

	/**
	 * @brief Permite obter o número de entregas realizadas com o veículo
	 * @return Retorna o número de entregas realizadas com o veículo
	 */
	int getEntregas();

	/**
	 * @brief Permite obter o número de quilómetros percorridos pelo veículo
	 * @return Retorna o número de quilómetros percorridos pelo veículo
	 */
	float getKms();

	/**
	 * @brief Permite alterar a marca de um veículo
	 * @param m - Nova marca atribuída ao veículo
	 */
	void setMarca(string m);

	/**
	 * @brief Permite alterar o tipo de veículo
	 * @param t - Nova tipo atribuído ao veículo
	 */
	void setTipo(string t);

	/**
	 * @brief Permite alterar a data em que a empresa adquiriu o veículo
	 * @param m - Nova data de aquisição do veículo
	 */
	void setDataAquisicao(string);

	/**
	 * @brief Adiciona ao veículo o número de kms percorridos numa entrega e íncrementa em 1 o número de entregas
	 */
	void doEntrega();

	/**
	 * @brief Overload do operador de igualidade para a classe Veiculo
	 * @param v - Veículo a ser comparado
	 * @return Retorna true caso os veículos a ser comparados forem iguais, caso contrário retorna falso
	 */
	bool operator == (const Veiculo& v) const;

	/**
	 * @brief Overload do operador de menor para a classe Veiculo
	 * @param v - Veículo a ser comparado
	 * @return Retorna true caso o veículo tenha menor número de entregas realizadas, em caso de empate retorna true se o veículo tiver menor número de kms percorridos
	 */
	bool operator < (const const Veiculo& v) const;
};


