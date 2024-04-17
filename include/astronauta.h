#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <iostream>
using namespace std;

class astronauta
{
    private:
        string cpf;
        string nome;
        string disp;
        int idade;      
    public:
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