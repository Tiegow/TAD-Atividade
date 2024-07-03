# TAD - Atividade C++
Este trabalho consiste na implementação de um programa em C++ que simula um sistema fictício de gestão de astronautas e voos espaciais. O programa foi produzido como uma atividade, apresentada na disciplina de Linguagem de Programação, na UFRN.
# Funcionamento e operações
O programa funciona com um conjunto de operações principais, distribuidas em 9 interfaces, que podem ser acessadas a partir da tela inicial:

<img src="/imgs/Telainicial.png">

Ao digitar a opção desejada, a operação vai ser iniciada e, ao finalizar, os comandos da tela inicial voltam a ficar disponiveis.

<img src="/imgs/Cadastrarastronauta.png">

- ## Classe 'astronauta'
  A classe **astronauta** possui os atributos **cpf**, **nome**, **disp**, **idade** e **historico_voos**. O atributo **disp** representa a disponibilidade atual do astronauta e **historico_voos** é um vector para os códigos (int) de cada voo que o astronauta participou.
- ## Classe 'voo'
  A classe **voo** possui os atributos **codigo**, **situacao** e **lista_passageiros**. O atributo **codigo** é um número inteiro que representa um identificador único para cada voo. O atributo **situacao** representa o estado atual do voo cadastrado, podendo ser "planejamento", "curso" ou "finalizado". Ao cadastrar um novo voo, sua situação será automaticamente definida como "planejamento". **lista_passageiros** se trata de um vector de ponteiros para objetos da classe **astronauta** que registra os astronautas cadastrados no voo.
# Compilação
Execute os comandos no terminal para compilar e executar o programa:

Compilar:
```
g++ -o astro main.cpp funcoes.cpp astronauta.cpp voo.cpp -I .\include
```

Executar:
```
./astro
```
