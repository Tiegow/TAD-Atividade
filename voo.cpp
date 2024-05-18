#include "voo.h"

voo::voo(int cod)
{
    codigo = cod;
    situacao = "planejamento";
}

voo::voo()
{
    codigo = 0;
    situacao = "planejamento";
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
    for(int i = 0; i < lista_astros.size(); i++) //Procura qual o passageiro que quer cadastrar
    {
        if(lista_astros.at(i).getCPF() == cpf)
        {
            if(lista_astros.at(i).getDisp() == "pndisp") //Verifica se o astronauta esta morto
            {
                cout << "Astronauta esta permanentemente indisponivel." << endl;
                return;
            }
            for(int j = 0; j < lista_passageiros.size(); j++) 
            {
                if(lista_passageiros.at(j)->getCPF() == lista_astros.at(i).getCPF()) //Verifica se o passageiro ja esta no voo
                {
                    cout << "Passageiro ja cadastrado no voo." << endl;
                    return;
                }
            }
            
            lista_passageiros.push_back(&lista_astros.at(i)); //Adiciona passageiro
            cout << "Astronauta " << lista_astros.at(i).getNome() << " adicionado ao voo " << codigo << endl;
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

void voo::lancar()
{
    if(lista_passageiros.empty())
    {
        cout << "O voo precisa ter pelo menos um passageiro cadastrado." << endl;
        return;
    }
    if(situacao != "planejamento")
    {
        cout << "O voo nao esta em planejamento." << endl;
        return;
    }

    for(int i_pasg = 0; i_pasg < lista_passageiros.size(); i_pasg++)
    {
        if(lista_passageiros[i_pasg]->getDisp() != "disp")
        {
            cout << "O astronauta " << lista_passageiros[i_pasg]->getNome() << " nao esta disponivel para decolar." << endl;
            return;
        }
        
        lista_passageiros[i_pasg]->setDisp("ndisp");
        lista_passageiros[i_pasg]->historico_voos.push_back(codigo); //Registra o codigo do voo no historico do passageiro
    }
    situacao = "curso";
    cout << "Voo lancado!" << endl;
}

void voo::explodir(vector<astronauta*> &R_I_P)
{
    if(situacao != "curso") //Voo so pode ser destruido em curso
    {
        cout << "O voo nao esta em curso. Encerrando sequencia de explosao" << endl;
        return;
    }

    for(int i_pasg = 0; i_pasg < lista_passageiros.size(); i_pasg++) //Altera o estado dos passageiros no voo
    {
        lista_passageiros[i_pasg]->setDisp("pndisp");
        R_I_P.push_back(lista_passageiros[i_pasg]);
    }   
    situacao = "destruido"; //Altera o estado do voo
    cout << "Voo destruido!" << endl;
}

void voo::finalizar()
{
    if(situacao != "curso") //Voo so pode ser finalizado se estiver em curso
    {
        cout << "O voo nao esta em curso." << endl;
        return;
    }

    for(int i_pasg = 0; i_pasg < lista_passageiros.size(); i_pasg++) //Altera o estado dos passageiros no voo
    {
        lista_passageiros[i_pasg]->setDisp("disp");
    }   
    situacao = "finalizado"; //Altera o estado do voo
    cout << "Voo finalizado." << endl;
}