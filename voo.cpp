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

void voo::add_astronauta(string cpf, vector<astronauta> &lista_astros)
{
    int index_passageiro = -1;

    for(int i = 0; i < lista_astros.size(); i++) //Verifica qual o passageiro que quer cadastrar
    {
        if(lista_astros.at(i).getCPF() == cpf) index_passageiro = i;
    }
    if(index_passageiro == -1)
    {
        cout << "Astronauta nao encontrado." << endl;
        return;
    }

    for(int j = 0; j < lista_passageiros.size(); j++) //Verifica se o passageiro ja esta no voo
    {
        if(lista_passageiros.at(j)->getCPF() == lista_astros.at(index_passageiro).getCPF())
        {
            cout << "Passageiro ja cadastrado no voo." << endl;
            return;
        }
    }

    lista_passageiros.push_back(&lista_astros.at(index_passageiro)); //Adiciona passageiro
    cout << "Astronauta " << lista_astros.at(index_passageiro).getNome() << " adicionado ao voo " << codigo << endl;
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