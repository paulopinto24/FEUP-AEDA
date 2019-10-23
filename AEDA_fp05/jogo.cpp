/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
    if ( frase.length() == 0 ) return 0;

    unsigned n=1;
    size_t pos = frase.find(' ');
    while (pos != string::npos) {
        frase = frase.substr(pos+1);
        pos = frase.find(' ');
        n++;
    }
    return n;
}

Jogo::Jogo()
{
    list<Crianca> criancas;
    this->criancas = criancas;
}

Jogo::Jogo(list<Crianca>& lc2)
{
    this->criancas = lc2;
}

void Jogo::insereCrianca(const Crianca &c1)
{
    criancas.push_back(c1);
}

list<Crianca> Jogo::getCriancasJogo() const
{
    list<Crianca> res;
    res = criancas;
    return res;
}

string Jogo::escreve() const
{
    string res;
    for(Crianca const& i : criancas){
        res = res + i.escreve() + "\n";
    }
    return res;
}

Crianca& Jogo::perdeJogo(string frase)
{
    int nr = numPalavras(frase);

    cout << "nr = " << nr << endl;
    cout << "size of list = " << criancas.size() << endl;

    int ind;
    if(nr % criancas.size() == 0)
        ind = criancas.size() - 1;
    else ind = nr % criancas.size() - 1;

    cout << "ind = " << ind << endl;
    auto it = next(criancas.begin(), ind);

    while(criancas.size() > 1) {

        if(nr % criancas.size() == 0)
            ind = criancas.size() - 1;
        else ind = nr % criancas.size() - 1;

        cout << "ind = " << ind << endl;
        it = next(criancas.begin(), ind);
        criancas.erase(it);
        it = next(criancas.begin(), 0);
    }

    Crianca *c1 = new Crianca(it->getNome(), it->getIdade());
    return *c1;
}

list<Crianca>& Jogo::inverte()
{
    criancas.reverse();
    return criancas;
}

list<Crianca> Jogo::divide(unsigned id)
{
    list<Crianca> res;
    for (list<Crianca>::iterator it=criancas.begin(); it != criancas.end(); ++it){
        if(it->getIdade() > id){
            res.push_back(*it);
            criancas.erase(it);
        }
    }
    return res;
}

void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
    for(Crianca const& i : l1){
        insereCrianca(i);
    }
}

bool Jogo::operator==(Jogo& j2)
{
    if(j2.getCriancasJogo().size() != criancas.size()){
        return false;
    }
    list<Crianca>::iterator it2= j2.getCriancasJogo().begin();
    for (list<Crianca>::iterator it1= criancas.begin(); it1 != criancas.end(); ++it1){
        if(it1->getNome() != it2->getNome() || it1->getIdade() != it2->getIdade()){
            return false;
        }
        ++it2;
    }
    return true;
}

list<Crianca> Jogo::baralha() const
{
    list<Crianca> res;
    int size = criancas.size();
    int count = 0;

    while(count != criancas.size()){
        auto it = next(criancas.begin(), rand() % size);
        res.push_back(*it);
        size--;
        count++;
    }

    return res;
}