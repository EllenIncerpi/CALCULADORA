#include <stdio.h>
#include <stdlib.h> // Para system("cls") ou system("clear")
#include <string.h> // Para funções de string
#include <ctype.h>  // Para tolower()

// Protótipos das funções
void converterTemperatura();
void calcularArea();
void contarTamanhoFrase();
void verificarPalindromo();
void exibirMenuPrincipal();

int main() {
    int opcao;

    do {
        exibirMenuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Consumir o newline residual

        switch (opcao) {
            case 1:
                converterTemperatura();
                break;
            case 2:
                calcularArea();
                break;
            case 3:
                contarTamanhoFrase();
                break;
            case 4:
                verificarPalindromo();
                break;
            case 0:
                printf("Saindo da calculadora. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
                break;
        }
        printf("\nPressione Enter para continuar...");
        getchar(); // Aguarda o usuário pressionar Enter
        // Limpar a tela (opcional, dependendo do sistema operacional)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    } while (opcao != 0);

    return 0;
}

// Função para exibir o menu principal
void exibirMenuPrincipal() {
    printf("=======================================\n");
    printf("        CALCULADORA AVANCADA\n");
    printf("=======================================\n");
    printf("1 - Converter temperatura (Celsius <-> Fahrenheit)\n");
    printf("2 - Calcular area de figuras geometricas\n");
    printf("3 - Contar o tamanho de uma frase\n");
    printf("4 - Verificar se um texto eh palindromo\n");
    printf("0 - Sair\n");
    printf("=======================================\n");
}

// 1. Conversão de Temperatura
void converterTemperatura() {
    int subOpcao;
    float temperatura, resultado;

    printf("\n--- Conversao de Temperatura ---\n");
    printf("1 - Celsius para Fahrenheit\n");
    printf("2 - Fahrenheit para Celsius\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &subOpcao);
    getchar(); // Consumir o newline residual

    switch (subOpcao) {
        case 1:
            printf("Digite a temperatura em Celsius: ");
            scanf("%f", &temperatura);
            getchar();
            resultado = temperatura * 1.8 + 32;
            printf("%.2f Celsius equivalem a %.2f Fahrenheit.\n", temperatura, resultado);
            break;
        case 2:
            printf("Digite a temperatura em Fahrenheit: ");
            scanf("%f", &temperatura);
            getchar();
            resultado = (temperatura - 32) / 1.8;
            printf("%.2f Fahrenheit equivalem a %.2f Celsius.\n", temperatura, resultado);
            break;
        default:
            printf("Opcao invalida para conversao de temperatura.\n");
            break;
    }
}

// 2. Cálculo de Área
void calcularArea() {
    char subOpcaoArea;
    float base, altura, raio, area;
    const float PI = 3.14159;

    printf("\n--- Calculo de Area ---\n");
    printf("A - Triangulo\n");
    printf("B - Retangulo\n");
    printf("C - Circulo\n");
    printf("Escolha uma opcao (A, B ou C): ");
    scanf(" %c", &subOpcaoArea); // O espaço antes de %c ignora whitespaces
    getchar(); // Consumir o newline residual

    subOpcaoArea = tolower(subOpcaoArea); // Converte para minúscula para facilitar a comparação

    switch (subOpcaoArea) {
        case 'a': // Triângulo
            printf("Digite a base do triangulo: ");
            scanf("%f", &base);
            getchar();
            printf("Digite a altura do triangulo: ");
            scanf("%f", &altura);
            getchar();
            area = (base * altura) / 2;
            printf("A area do triangulo eh: %.2f\n", area);
            break;
        case 'b': // Retângulo
            printf("Digite a base do retangulo: ");
            scanf("%f", &base);
            getchar();
            printf("Digite a altura do retangulo: ");
            scanf("%f", &altura);
            getchar();
            area = base * altura;
            printf("A area do retangulo eh: %.2f\n", area);
            break;
        case 'c': // Círculo
            printf("Digite o raio do circulo: ");
            scanf("%f", &raio);
            getchar();
            area = PI * raio * raio;
            printf("A area do circulo eh: %.2f\n", area);
            break;
        default:
            printf("Opcao invalida para calculo de area.\n");
            break;
    }
}

// 3. Contar o tamanho de uma frase
void contarTamanhoFrase() {
    char frase[256]; // Buffer para armazenar a frase

    printf("\n--- Contar Tamanho da Frase ---\n");
    printf("Digite a frase: ");
    fgets(frase, sizeof(frase), stdin); // Lê a linha completa, incluindo espaços

    // Remove o newline que fgets pode adicionar no final
    frase[strcspn(frase, "\n")] = 0;

    printf("O tamanho da frase eh: %zu caracteres.\n", strlen(frase));
}

// 4. Verificar se um texto é palíndromo
void verificarPalindromo() {
    char texto[256];
    char textoLimpo[256];
    int i, j, len;
    int ehPalindromo = 1; // Assume que é palíndromo inicialmente

    printf("\n--- Verificar Palindromo ---\n");
    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);

    // Remove o newline
    texto[strcspn(texto, "\n")] = 0;

    // Limpar o texto (remover espaços e converter para minúsculas)
    len = strlen(texto);
    j = 0;
    for (i = 0; i < len; i++) {
        if (isalnum(texto[i])) { // Verifica se é alfanumérico
            textoLimpo[j++] = tolower(texto[i]);
        }
    }
    textoLimpo[j] = '\0'; // Adiciona o terminador nulo

    len = strlen(textoLimpo);
    for (i = 0; i < len / 2; i++) {
        if (textoLimpo[i] != textoLimpo[len - 1 - i]) {
            ehPalindromo = 0; // Não é palíndromo
            break;
        }
    }

    if (ehPalindromo) {
        printf("'%s' eh um palindromo!\n", texto);
    } else {
        printf("'%s' nao eh um palindromo.\n", texto);
    }
}
