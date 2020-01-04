#pragma once

#include "UghEatsFD.h"
#include "Exceptions.h"
#include <fstream>

using namespace std;

/**
* @brief Carrega a aplicacao lendo a info necessaria de documentos de texto
* @param p1 - pointer para aplicacao a ser carregada
* @return Retorna 0 se bem sucedido, outro valor quando nao e bem sucedido
*/
int loadApplication(UghEatsFD *p1);

/**
* @brief Salva a aplicacao escrevendo a info necessaria em documentos de texto
* @param p1 - pointer para aplicacao a ser salvada
* @return Retorna 0 se bem sucedido, outro valor quando nao e bem sucedido
*/
int saveApplication(UghEatsFD *p1);

/**
* @brief Separa os diferentes elementos de uma string separados por ponto e virgula
* @param line - linha a ser processada
* @return Retorna vetor com os elementos processados
*/
vector<string> parseBySemiColon(string line);

/**
* @brief Separa os diferentes elementos de uma string separados por barra
* @param line - linha a ser processada
* @return Retorna vetor com os elementos processados
*/
vector<string> parseBySlash(string line);

/**
* @brief Processa informacao de modo a criar uma base da empresa
* @param vec - vetor com elementos necessarios a criacao da base
* @return Retorna a base criada com a informacao contida em vec
*/
Base parseBase(vector<string> vec, UghEatsFD* p1);

void valid_option(string opt, int inf, int sup);
