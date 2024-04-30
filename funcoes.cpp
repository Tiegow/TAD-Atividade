#include "funcoes.h"

void cadastrar_astronauta(vector<astronauta> &lista)
{
    string nome;
    string cpf;
    int idade;

    cout << "Cadastrando astronauta" << endl;

    cout << "Nome: ";   cin >> nome;
    cout << "CPF: " ;   cin >> cpf;

    for(int i = 0; i < lista.size(); i++)
    {
        if(lista.at(i).getCPF() == cpf)
        {
            cout << "CPF " << cpf << " ja foi cadastrado." << endl;
            return;
        }
    }

    cout << "Idade: ";  cin >> idade;
    lista.push_back(astronauta(cpf, nome, idade));

    cout << "Astronauta " << nome << " cadastrado." << endl;
}

void cadastrar_voo(vector<voo> &lista)
{
    int codigo;

    cout << "Cadastrando voo" << endl;

    cout << "Codigo de voo: " << endl;
    cin >> codigo;

    for(int i = 0; i < lista.size(); i++)
    {
        if(lista.at(i).getCod() == codigo)
        {
            cout << "Voo de codigo " << codigo << " ja foi cadastrado." << endl;
            return;
        }
    }

    lista.push_back(voo(codigo));

    cout << "Voo " << codigo << " cadastrado (em planejamento)." << endl;
}

void voo_addAstro(vector<voo> &meus_voos, vector<astronauta> &meus_astronautas)
{
    if(meus_voos.empty() || meus_astronautas.empty())
    {
        cout << "Nao existem voos ou astronautas cadastrados." << endl;
        return;
    }

    int codigo;
    string cpf;

    cout << "Adicionando astronauta em voo" << endl;

    cout << "Codigo do voo: " << endl;
    cin >> codigo;

    for(int i = 0; i < meus_voos.size(); i++)
    {
        if(meus_voos.at(i).getCod() == codigo)
        {
            if(meus_voos.at(i).getSit() == "plan")
            {
                cout << "CPF do astronauta: " << endl;
                cin >> cpf;

                meus_voos.at(i).add_astronauta(cpf, meus_astronautas);
            }
            else
            {
                cout << "O voo nao esta em planejamento." << endl;
            }
            return;
        }
    }
    cout << "Voo de codigo " << codigo << " nao encontrado" << endl;
}

void voo_remAstro(vector<voo> &meus_voos)
{
    if(meus_voos.empty())
    {
        cout << "Nao existem voos cadastrados." << endl;
        return;
    }

    int codigo;
    string cpf;

    cout << "Removendo astronauta do voo" << endl;

    cout << "Codigo do voo: " << endl;
    cin >> codigo;

    for(int i = 0; i < meus_voos.size(); i++)
    {
        if(meus_voos.at(i).getCod() == codigo)
        {
            if(meus_voos.at(i).lista_passageiros.empty())
            {
                cout << "O voo nao tem passageiros para remover." << endl;
                return;
            }
            if(meus_voos.at(i).getSit() == "plan")
            {
                cout << "CPF do astronauta: " << endl;
                cin >> cpf;

                meus_voos.at(i).rem_astronauta(cpf);
                cout << "Astronauta removido." << endl;
            }
            else
            {
                cout << "O voo nao esta em planejamento." << endl;
            }
            return;
        }
    }
    cout << "Voo de codigo " << codigo << " nao encontrado" << endl;
}

void voo_lancar(vector<voo> &meus_voos)
{
    if(meus_voos.empty())
    {
        cout << "Nao existem voos cadastrados." << endl;
        return;
    }

    int codigo;
    cout << "Preparacao de lancamento" << endl;

    cout << "Codigo do voo: " << endl;
    cin >> codigo;

    for(int i = 0; i < meus_voos.size(); i++)
    {
        if(meus_voos.at(i).getCod() == codigo)
        {
            if(meus_voos.at(i).lista_passageiros.empty())
            {
                cout << "O voo precisa ter pelo menos um passageiro cadastrado." << endl;
                return;
            }
            if(meus_voos.at(i).getSit() != "plan")
            {
                cout << "O voo nao esta em planejamento." << endl;
                return;
            }

            for(int ls = 0; ls < meus_voos.at(i).lista_passageiros.size(); ls++)
            {
                if(meus_voos.at(i).lista_passageiros[ls]->getDisp() != "disp")
                {
                    cout << "O astronauta " << meus_voos.at(i).lista_passageiros[ls]->getNome() << " nao esta disponivel para decolar." << endl;
                    return;
                }
                
                meus_voos.at(i).lista_passageiros[ls]->setDisp("ndisp");
                meus_voos.at(i).lista_passageiros[ls]->historico_voos.push_back(codigo); //Registra o codigo do voo no historico do passageiro
            }
            meus_voos.at(i).setSit("curso");
            cout << "Voo lancado!" << endl;
            return;
        }
    }
    cout << "Voo de codigo " << codigo << " nao encontrado" << endl;
}

void voo_explodir(vector<voo> &meus_voos, vector<astronauta*> &R_I_P)
{
    if(meus_voos.empty())
    {
        cout << "Nao existem voos cadastrados." << endl;
        return;
    }

    int codigo;
    cout << "Iniciando protocolo de explosao" << endl;

    cout << "Codigo do voo: " << endl;
    cin >> codigo;

    for(int i_voo = 0; i_voo < meus_voos.size(); i_voo++) //Busca o voo do codigo informado
    {
        if(meus_voos.at(i_voo).getCod() == codigo)
        {
            if(meus_voos.at(i_voo).getSit() == "curso") //Voo so pode ser destruido em curso
            {
                for(int i_pasg = 0; i_pasg < meus_voos.at(i_voo).lista_passageiros.size(); i_pasg++) //Altera o estado dos passageiros no voo
                {
                    meus_voos.at(i_voo).lista_passageiros[i_pasg]->setDisp("ndisp");
                    R_I_P.push_back(meus_voos.at(i_voo).lista_passageiros[i_pasg]);
                }   
                meus_voos.at(i_voo).setSit("destruido"); //Altera o estado do voo
                cout << "Voo destruido!" << endl;
                return;
            }
            else 
            {
                cout << "O voo nao esta em curso. Encerrando sequencia de explosao" << endl;
                return;
            }
        }
    }
    cout << "Voo de codigo " << codigo << " nao encontrado" << endl;
}

void voo_fim(vector<voo> &meus_voos)
{
    if(meus_voos.empty())
    {
        cout << "Nao existem voos cadastrados." << endl;
        return;
    }

    int codigo;
    cout << "Codigo do voo: " << endl;
    cin >> codigo;

    for(int i_voo = 0; i_voo < meus_voos.size(); i_voo++) //Busca o voo do codigo informado
    {
        if(meus_voos.at(i_voo).getCod() == codigo)
        {
            if(meus_voos.at(i_voo).getSit() == "curso") //Voo so pode ser finalizado se estiver em curso
            {
                for(int i_pasg = 0; i_pasg < meus_voos.at(i_voo).lista_passageiros.size(); i_pasg++) //Altera o estado dos passageiros no voo
                {
                    meus_voos.at(i_voo).lista_passageiros[i_pasg]->setDisp("disp");
                }   
                meus_voos.at(i_voo).setSit("finalizado"); //Altera o estado do voo
                cout << "Voo finalizado." << endl;
                return;
            }
            else 
            {
                cout << "O voo nao esta em curso." << endl;
                return;
            }
        }
    }
    cout << "Voo de codigo " << codigo << " nao encontrado" << endl;
}

void listar_voos(vector<voo> &meus_voos)
{
    if(meus_voos.empty())
    {
        cout << "Nao existem voos cadastrados." << endl;
        return;
    }

    for(int i = 0; i < meus_voos.size(); i++)
    {
        cout << "Voo " << meus_voos.at(i).getCod() << ":" << endl;

        cout << " - Passageiros:" << endl;
        for(int j = 0; j < meus_voos.at(i).lista_passageiros.size(); j++)
        {
            cout << "   Astronauta " << meus_voos.at(i).lista_passageiros[j]->getNome() << endl;
        }
        cout << " - Situacao: " << meus_voos.at(i).getSit() << endl;
    }
}

void listar_mortos(vector<astronauta*> &R_I_P)
{
    if(R_I_P.empty())
    {
        cout << "Nao existem astronautas mortos." << endl;
        return;
    }

    cout << "Astronautas permanentemente indisponiveis: " << endl;
    for(int i = 0; i < R_I_P.size(); i++)
    {
        cout << R_I_P.at(i)->getNome() << ":" << endl;
        cout << "- CPF: " << R_I_P.at(i)->getCPF() << endl;
        cout << "- Historico de voos: " << endl;

        for(int v = 0; v < R_I_P.at(i)->historico_voos.size(); v++)
        {
            cout << "   Voo " << R_I_P.at(i)->historico_voos.at(v) << endl;
        }
    }
}