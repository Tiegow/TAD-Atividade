#include "voo.h"

voo::voo(int cod)
{
    codigo = cod;
    lista_passageiros.clear();
    situacao = "plan";
}

voo::voo()
{
    codigo = 0;
    lista_passageiros.clear();
    situacao = "plan";
}

voo::~voo()
{
}

int voo::getCod()
{
    return codigo;
}

string voo::getSit()
{
    return situacao;
}
void voo::setSit(string sit)
{
    situacao = sit;
}

void voo::add_astronauta(string cpf, vector<astronauta>* lista)
{
    for(int i = 0; i < lista->size(); i++)
    {
        if(lista->at(i).getCPF() == cpf)
        {
            lista_passageiros.push_back(&lista->at(i));
            cout << "Astronauta " << lista->at(i).getNome() << " adicionado ao voo " << codigo << endl;
            return;
        }
    }
    cout << "Astronauta nao encontrado." << endl;
}

void voo::rem_astronauta(string cpf)
{
    auto j = lista_passageiros.begin();

    for(j; j != lista_passageiros.end(); j++)
    {
        if((*j)->getCPF() == cpf)
        {
            lista_passageiros.erase(j);
            cout << "Astronauta removido." << endl;
            return;
        }
    }
    cout << "O astronauta nao esta cadastrado no voo" << endl;
}