#include "voo.h"
#include "funcoes.h"

int main()
{   
    vector<astronauta> meus_astronautas;
    vector<astronauta*> R_I_P;
    vector<voo> meus_voos;

    int painel;

    do
    {
        cout << "X**  Sistema de gestao de voos da Safe Travels Spacelines  **X" << endl;
        cout << "Selecione uma das opcoes a seguir:" << endl;
        cout << "   |1 - Cadastrar astronauta" << endl;
        cout << "   |2 - Cadastrar voo" << endl;
        cout << "   |3 - Adicionar astronauta em voo" << endl;
        cout << "   |4 - Remover astronauta do voo" << endl;
        cout << "   |5 - Lancar um voo" << endl;
        cout << "   |6 - Explodir um voo (!!!)" << endl;
        cout << "   |7 - Finalizar um voo" << endl;
        cout << "   |8 - Listar voos" << endl;
        cout << "   |9 - Listar fatalidades" << endl;
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
            voo_lancar(meus_voos);
            break;
        case 6:
            voo_explodir(meus_voos, R_I_P);
            break;
        case 7:
            voo_fim(meus_voos);
            break;
        case 8:
            listar_voos(meus_voos);
            break;
        case 9:
            listar_mortos(R_I_P);
            break;
        default:
            break;
        }
    } while (painel != 0);

    cout << "Fim." << endl;

    return 0;
}

//g++ -o astro main.cpp funcoes.cpp astronauta.cpp voo.cpp -I .\include