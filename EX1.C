#include <stdio.h>
#include <string.h> // Para strcpy

// Definindo a estrutura Aluno
typedef struct {
    char nome[50];
    int matricula;
    float notas[3]; // notas[0] = N1, notas[1] = N2, notas[2] = N3
    float media;
} Aluno;

// Protótipos das funções
void cadastrarAlunos(Aluno alunos[], int numAlunos);
void calcularMedia(Aluno *aluno); // Recebe um ponteiro para o Aluno
void exibirListas(const Aluno alunos[], int numAlunos);

int main() {
    int numAlunos;
    Aluno turma[10]; // Vetor de structs para armazenar até 10 alunos

    printf("--- Sistema de Notas ---\n");

    // Solicita o número de alunos e valida a entrada
    do {
        printf("Quantos alunos deseja cadastrar (maximo de 10)? ");
        scanf("%d", &numAlunos);
        if (numAlunos <= 0 || numAlunos > 10) {
            printf("Numero de alunos invalido. Por favor, digite um valor entre 1 e 10.\n");
        }
    } while (numAlunos <= 0 || numAlunos > 10);

    // Chama a função para cadastrar os alunos
    cadastrarAlunos(turma, numAlunos);

    // Exibe as listas de aprovados, exame e reprovados
    exibirListas(turma, numAlunos);

    return 0;
}

// Função para entrada de dados dos alunos
void cadastrarAlunos(Aluno alunos[], int numAlunos) {
    for (int i = 0; i < numAlunos; i++) {
        printf("\n--- Cadastro do Aluno %d ---\n", i + 1);

        // Limpa o buffer do teclado antes de ler a string
        getchar(); 

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        // Remove o '\n' lido por fgets, se houver
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Notas (N1 N2 N3, separadas por espaco): ");
        scanf("%f %f %f", &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2]);

        // Calcula a média do aluno imediatamente após a entrada das notas
        calcularMedia(&alunos[i]); // Passa o endereço do struct para a função
    }
}

// Função para cálculo da média
void calcularMedia(Aluno *aluno) {
    // N1 e N2 valem 30% cada, N3 vale 40%
    aluno->media = (aluno->notas[0] * 0.30) +
                   (aluno->notas[1] * 0.30) +
                   (aluno->notas[2] * 0.40);
}

// Função para exibição das listas
void exibirListas(const Aluno alunos[], int numAlunos) {
    printf("\n--- Aprovados ---\n");
    int encontrouAprovados = 0;
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].media >= 7.0) {
            printf("%s (%d) - Media: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
            encontrouAprovados = 1;
        }
    }
    if (!encontrouAprovados) {
        printf("Nenhum aluno aprovado.\n");
    }

    printf("\n--- Exame ---\n");
    int encontrouExame = 0;
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].media >= 4.0 && alunos[i].media < 7.0) {
            printf("%s (%d) - Media: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
            encontrouExame = 1;
        }
    }
    if (!encontrouExame) {
        printf("Nenhum aluno de exame.\n");
    }

    printf("\n--- Reprovados ---\n");
    int encontrouReprovados = 0;
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].media < 4.0) {
            printf("%s (%d) - Media: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
            encontrouReprovados = 1;
        }
    }
    if (!encontrouReprovados) {
        printf("Nenhum aluno reprovado.\n");
    }
}
