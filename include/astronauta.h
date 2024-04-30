#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <iostream>
#include <vector>
using namespace std;

class astronauta
{
    private:
        string cpf;
        string nome;
        string disp;
        int idade;      
    public:
        vector<int> historico_voos;

        astronauta(string cpf, string nome, int idade);
        astronauta();
        ~astronauta();

        string getNome();
        string getCPF();

        string getDisp();
        void setDisp(string disp);
        
        int getIdade();
};

#endif