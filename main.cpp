#include "voo.h"
#include "funcoes.h"

void teste(vector<voo> &meus_voos, vector<astronauta> &meus_astronautas)
{
    for(int i = 0; i < meus_voos.size(); i++)
    {
        cout << "Voo " << meus_voos.at(i).getCod() << ":" << endl;

        for(int j = 0; j < meus_voos.at(i).lista_passageiros.size(); j++)
        {
            cout << "Astronauta: " << meus_voos.at(i).lista_passageiros[j]->getNome() << endl;
            cout << "Situacao: " << meus_voos.at(i).lista_passageiros[j]->getDisp() << endl;
        }
    }
}

int main()
{   
    vector<astronauta> meus_astronautas;
    vector<voo> meus_voos;

    int painel;

    do
    {
        cout << endl << "X**  Sistema de gestao de voos da Safe Travels Spacelines  **X" << endl;
        cout << endl << "Selecione uma das opcoes a seguir:" << endl;
        cout << "   |1 - Cadastrar astronauta" << endl;
        cout << "   |2 - Cadastrar voo" << endl;
        cout << "   |3 - Adicionar astronauta em voo" << endl;
        cout << "   |4 - Remover astronauta do voo" << endl;
        cout << "   |5 - Lancar um voo" << endl;
        cout << "   |6 - Explodir um voo (!!!)" << endl;
        cout << "   |9 - Listar voos" << endl;
        cout << "   |0 - Fechar painel de controle" << endl;
        cin >> painel;

        switch (painel)
        {
        case 1:
            cadastrar_astronauta(meus_astronautas);
            break;
        case 2:
            cadastrar_voo(meus_voos);
            break;
        case 3:
            voo_addAstro(meus_voos, meus_astronautas);
            break;
        case 4:
            voo_remAstro(meus_voos);
            break;
        case 5:
            voo_lancar(meus_voos, meus_astronautas);
            break;
        case 6:
            voo_explodir(meus_voos, meus_astronautas);
            break;
        case 9:
            // listar_voos(meus_voos);
            teste(meus_voos, meus_astronautas);
            break;
        default:
            break;
        }
    } while (painel != 0);


    return 0;
}

//g++ -o astro main.cpp funcoes.cpp astronauta.cpp voo.cpp -I .\include