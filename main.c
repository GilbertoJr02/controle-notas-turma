#include <stdio.h>

int main() {

    int quantidade = 0;
    int turmaCadastrada = 0;

    int codigos[20];
    int faltas[20];
    float notas[20][3];

    int opcao;

    do {

        printf("\n=====================================\n");
        printf(" CONTROLE DE NOTAS DA TURMA\n");
        printf("=====================================\n");
        printf("1 - Cadastrar turma\n");
        printf("2 - Listar alunos\n");
        printf("3 - Consultar codigo\n");
        printf("4 - Relatorio da turma\n");
        printf("0 - Sair\n");
        printf("=====================================\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1: {

                char resposta;

                if (turmaCadastrada) {

                    printf("\nJa existe uma turma cadastrada.\n");
                    printf("Deseja substituir? (S/N): ");
                    scanf(" %c", &resposta);

                    if (resposta != 'S' && resposta != 's') {
                        break;
                    }
                }

                do {

                    printf("\nDigite a quantidade de alunos (1 a 20): ");
                    scanf("%d", &quantidade);

                    if (quantidade < 1 || quantidade > 20) {
                        printf("Quantidade invalida!\n");
                    }

                } while (quantidade < 1 || quantidade > 20);

                for (int i = 0; i < quantidade; i++) {

                    printf("\n=========================\n");
                    printf("ALUNO %d\n", i + 1);
                    printf("=========================\n");

                    int codigoValido;

                    do {

                        codigoValido = 1;

                        printf("Codigo: ");
                        scanf("%d", &codigos[i]);

                        if (codigos[i] <= 0) {
                            printf("Codigo deve ser maior que zero!\n");
                            codigoValido = 0;
                        }

                        for (int j = 0; j < i; j++) {

                            if (codigos[i] == codigos[j]) {
                                printf("Codigo ja cadastrado!\n");
                                codigoValido = 0;
                                break;
                            }
                        }

                    } while (!codigoValido);

                    for (int j = 0; j < 3; j++) {

                        do {

                            printf("Nota %d: ", j + 1);
                            scanf("%f", &notas[i][j]);

                            if (notas[i][j] < 0 || notas[i][j] > 10) {
                                printf("Nota invalida! Digite entre 0 e 10.\n");
                            }

                        } while (notas[i][j] < 0 || notas[i][j] > 10);
                    }

                    do {

                        printf("Faltas: ");
                        scanf("%d", &faltas[i]);

                        if (faltas[i] < 0 || faltas[i] > 20) {
                            printf("Quantidade de faltas invalida!\n");
                        }

                    } while (faltas[i] < 0 || faltas[i] > 20);
                }

                turmaCadastrada = 1;

                printf("\nTurma cadastrada com sucesso!\n");

                break;
            }

            case 2: {

                if (!turmaCadastrada) {
                    printf("\nNenhuma turma cadastrada!\n");
                    break;
                }

                printf("\n========== LISTA DE ALUNOS ==========\n");

                for (int i = 0; i < quantidade; i++) {

                    float media;
                    float frequencia;

                    media = (notas[i][0] +
                             notas[i][1] +
                             notas[i][2]) / 3.0;

                    frequencia = ((20 - faltas[i]) / 20.0) * 100;

                    printf("\n----------------------------------\n");
                    printf("Codigo: %d\n", codigos[i]);

                    printf("Notas: %.1f | %.1f | %.1f\n",
                           notas[i][0],
                           notas[i][1],
                           notas[i][2]);

                    printf("Faltas: %d\n", faltas[i]);

                    printf("Media: %.2f\n", media);

                    printf("Frequencia: %.2f%%\n", frequencia);

                    printf("Situacao: ");

                    if (media >= 7 && frequencia >= 75) {

                        printf("APROVADO");

                    }
                    else if (media >= 5 && frequencia >= 75) {

                        printf("RECUPERACAO");

                    }
                    else {

                        if (media < 5 && frequencia < 75) {
                            printf("REPROVADO (media e frequencia)");
                        }
                        else if (media < 5) {
                            printf("REPROVADO (media)");
                        }
                        else {
                            printf("REPROVADO (frequencia)");
                        }
                    }

                    printf("\n");
                }

                break;
            }

            case 3: {

                if (!turmaCadastrada) {
                    printf("\nNenhuma turma cadastrada!\n");
                    break;
                }

                int codigoBusca;
                int encontrou = 0;

                printf("\nDigite o codigo do aluno: ");
                scanf("%d", &codigoBusca);

                for (int i = 0; i < quantidade; i++) {

                    if (codigos[i] == codigoBusca) {

                        float media;
                        float frequencia;

                        media =
                            (notas[i][0] +
                             notas[i][1] +
                             notas[i][2]) / 3.0;

                        frequencia =
                            ((20 - faltas[i]) / 20.0) * 100;

                        printf("\n========== ALUNO ENCONTRADO ==========\n");

                        printf("Codigo: %d\n", codigos[i]);

                        printf("Notas: %.1f | %.1f | %.1f\n",
                               notas[i][0],
                               notas[i][1],
                               notas[i][2]);

                        printf("Faltas: %d\n", faltas[i]);

                        printf("Media: %.2f\n", media);

                        printf("Frequencia: %.2f%%\n", frequencia);

                        printf("Situacao: ");

                        if (media >= 7 && frequencia >= 75) {

                            printf("APROVADO");

                        }
                        else if (media >= 5 && frequencia >= 75) {

                            printf("RECUPERACAO");

                        }
                        else {

                            if (media < 5 && frequencia < 75) {
                                printf("REPROVADO (media e frequencia)");
                            }
                            else if (media < 5) {
                                printf("REPROVADO (media)");
                            }
                            else {
                                printf("REPROVADO (frequencia)");
                            }
                        }

                        printf("\n");

                        encontrou = 1;
                        break;
                    }
                }

                if (!encontrou) {

                    printf("\nAluno nao encontrado!\n");
                }

                break;
            }

        case 4: {

            if (!turmaCadastrada) {
                printf("\nNenhuma turma cadastrada!\n");
                break;
            }

            float somaMedias = 0;
            float somaAvaliacao1 = 0;
            float somaAvaliacao2 = 0;
            float somaAvaliacao3 = 0;

            int aprovados = 0;
            int recuperacao = 0;
            int reprovados = 0;

            float maiorMedia;
            float menorMedia;

            int codigoMaior;
            int codigoMenor;

            for (int i = 0; i < quantidade; i++) {

                float media;
                float frequencia;

                media = (notas[i][0] +
                        notas[i][1] +
                        notas[i][2]) / 3.0;

                frequencia = ((20 - faltas[i]) / 20.0) * 100;

                somaMedias += media;

                somaAvaliacao1 += notas[i][0];
                somaAvaliacao2 += notas[i][1];
                somaAvaliacao3 += notas[i][2];

                if (i == 0) {
                    maiorMedia = media;
                    menorMedia = media;

                    codigoMaior = codigos[i];
                    codigoMenor = codigos[i];
                }

                if (media > maiorMedia) {
                    maiorMedia = media;
                    codigoMaior = codigos[i];
                }

                if (media < menorMedia) {
                    menorMedia = media;
                    codigoMenor = codigos[i];
                }

                if (media >= 7 && frequencia >= 75) {
                    aprovados++;
                }
                else if (media >= 5 && frequencia >= 75) {
                    recuperacao++;
                }
                else {
                    reprovados++;
                }
            }

            float mediaGeral = somaMedias / quantidade;

            float mediaAvaliacao1 = somaAvaliacao1 / quantidade;
            float mediaAvaliacao2 = somaAvaliacao2 / quantidade;
            float mediaAvaliacao3 = somaAvaliacao3 / quantidade;

            float percAprovados =
                (aprovados * 100.0) / quantidade;

            float percRecuperacao =
                (recuperacao * 100.0) / quantidade;

            float percReprovados =
                (reprovados * 100.0) / quantidade;

            printf("\n========================================\n");
            printf("         RELATORIO DA TURMA\n");
            printf("========================================\n");

            printf("Quantidade de alunos: %d\n", quantidade);

            printf("Media geral da turma: %.2f\n", mediaGeral);

            printf("\nAPROVADOS: %d (%.2f%%)\n",
                aprovados,
                percAprovados);

            printf("RECUPERACAO: %d (%.2f%%)\n",
                recuperacao,
                percRecuperacao);

            printf("REPROVADOS: %d (%.2f%%)\n",
                reprovados,
                percReprovados);

            printf("\nMaior media: %.2f\n", maiorMedia);
            printf("Codigo do aluno: %d\n", codigoMaior);

            printf("\nMenor media: %.2f\n", menorMedia);
            printf("Codigo do aluno: %d\n", codigoMenor);

            printf("\nMedia Avaliacao 1: %.2f\n",
                mediaAvaliacao1);

            printf("Media Avaliacao 2: %.2f\n",
                mediaAvaliacao2);

            printf("Media Avaliacao 3: %.2f\n",
                mediaAvaliacao3);

            break;
        }

            case 0:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}