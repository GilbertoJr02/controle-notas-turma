Planejamento do Projeto
Problema
Desenvolver um sistema capaz de realizar o controle de notas de uma turma.

Estruturas
Vetor de códigos
int codigos[20];
Vetor de faltas
int faltas[20];
Matriz de notas
float notas[20][3];
Algoritmo de Cadastro
Ler quantidade de alunos.
Validar intervalo entre 1 e 20.
Ler código do aluno.
Validar código não repetido.
Ler três notas.
Validar notas entre 0 e 10.
Ler faltas.
Validar faltas entre 0 e 20.
Algoritmo de Classificação
Aprovado
Média maior ou igual a 7.
Frequência maior ou igual a 75%.
Recuperação
Média entre 5 e 6,99.
Frequência maior ou igual a 75%.
Reprovado
Média menor que 5.
Ou frequência menor que 75%.
Fórmulas
Média
media = (n1 + n2 + n3) / 3.0;
Frequência
frequencia = ((20 - faltas) / 20.0) * 100;