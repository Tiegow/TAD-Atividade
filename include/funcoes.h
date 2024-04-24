#ifndef FUNCS_H
#define FUNCS_H

#include "voo.h"

void cadastrar_astronauta(vector<astronauta> &lista);
void cadastrar_voo(vector<voo> &lista);
void voo_addAstro(vector<voo> &meus_voos, vector<astronauta> &meus_astronautas);
void listar_voos(vector<voo> &meus_voos);
void voo_remAstro(vector<voo> &meus_voos);
void voo_lancar(vector<voo>& meus_voos, vector<astronauta>& meus_astronautas);
void voo_explodir(vector<voo>& meus_voos, vector<astronauta>& meus_astronautas);

#endif