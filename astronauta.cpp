#include "astronauta.h"

astronauta::astronauta(string c, string n, int i) 
{
    cpf = c;
    nome = n;
    idade = i;
    disp = "disp";
}

astronauta::astronauta() 
{
    cpf = "";
    nome = "";
    idade = 0;
    disp = "disp";
}

astronauta::~astronauta()
{
}

string astronauta::getNome()
{
    return nome;
}
string astronauta::getCPF()
{
    return cpf;
}

string astronauta::getDisp()
{
    return disp;
}
void astronauta::setDisp(string ds)
{
    disp = ds;
}

int astronauta::getIdade()
{
    return idade;
}

