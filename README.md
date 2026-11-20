Sistema de Controle de Notas
Projeto desenvolvido para a disciplina de Lógica e Algoritmos de Programação I.

Objetivo
Desenvolver um sistema em linguagem C para gerenciamento de notas de alunos de uma turma.

O programa permite:

Cadastro de alunos;
Consulta por código;
Listagem dos alunos;
Cálculo de médias;
Cálculo de frequência;
Classificação dos alunos;
Geração de relatórios estatísticos.
Estruturas Utilizadas
Vetores
Matrizes
Estruturas de repetição
Estruturas de decisão
Funcionalidades
Cadastro
Cadastro de até 20 alunos contendo:

Código
Nota 1
Nota 2
Nota 3
Faltas
Consulta
Busca de aluno através do código informado.

Listagem
Exibição de todos os alunos cadastrados com:

Média
Frequência
Situação
Relatórios
Média geral da turma
Quantidade de aprovados
Quantidade em recuperação
Quantidade de reprovados
Maior média
Menor média
Média de cada avaliação
Compilação
gcc main.c -o controle_notas
Execução
./controle_notas