# TAD - Atividade
Este trabalho consiste na implementação de um programa em C++ que simula um sistema fictício de gestão de astronautas e voos espaciais. O programa foi produzido como uma atividade, apresentada na disciplina de Linguagem de Programação, na UFRN.
# Funcionamento e operações
Foi determinado pelo professor um conjunto de operações principais e regras sob as quais o programa deve funcionar:

    - Classe astronauta tem: cpf(string) nome (char[] ou string) e idade(int)

    - Classe voo têm: Código do voo(int), e a lista de passageiros (astronautas)

    - Cadastrar Astronauta

    - Cadastrar Voo

    - Adicionar Astronauta em Voo (por cpf)
        * Somente se o voo está em planejamento

    - Remover Astronauta de um Voo (por cpf)
        * Somente se o voo está em planejamento

    - Lançar um voo
        * Precisa que tenha pelo menos 1 astronauta e todos estarem disponíveis
        * Astronautas dele ficam indisponíveis

    - Explodir Voo
        * Astronautas dele morrem

    - Finalizar um voo (com sucesso)
        * Astronautas dele voltam a ficar disponíveis
    
    - Listar todos os voos (com os seus astronautas)
        * Planejados (com os astronautas)
        * Em curso (com os astronautas)
        * Finalizados (com os astronautas que estavam nele)
            * sinalizar se finalizado com sucesso ou não
    - Listar todos os astronautas mortos
        * cpf
        * nome
        * voos que participou
- ## Classe 'astronauta'
  A classe **astronauta** possui os atributos **cpf**, **nome**, **disp**, **idade** e **historico_voos**. O atributo **disp** representa a disponibilidade atual do astronauta e **historico_voos** é um vector para os códigos (int) de cada voo que o astronauta participou.
- ## Classe 'voo'
  A classe **voo** possui os atributos **codigo**, **situacao** e **lista_passageiros**. O atributo **codigo** é um número inteiro que representa um identificador único para cada voo. O atributo **situacao** representa o estado atual do voo cadastrado, podendo ser "planejamento", "curso" ou "finalizado". Ao cadastrar um novo voo, sua situação será automaticamente definida como "planejamento". **lista_passageiros** se trata de um vector de ponteiros para objetos da classe **astronauta** que registra os astronautas cadastrados no voo.
