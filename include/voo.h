#ifndef VOO_H
#define VOO_H

#include "astronauta.h"
#include <vector>

class voo
{
    private:
        int codigo; 
        string situacao;
    public:
        vector<astronauta*> lista_passageiros;

        voo(int codigo);
        voo();
        ~voo();

        int getCod();
        string getSit();
        void setSit(string sit);

        void add_astronauta(string cpf, vector<astronauta> &lista);
        void rem_astronauta(string cpf);
};

#endif