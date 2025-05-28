//Bicliotecas
#include <stdio.h>
#include <string.h>

//
int main(){

    int opcao;

}


//Menu
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

//1- Temperatura
void converterTemperatura() {

}

//2- Area de figuras geometricas
void calcularArea () {

}

//3- Contar caracteres - tamanho de uma frase
void contarTamanhoFrase() {
    char frase[256]; // Buffer para armazenar a frase

  printf("\n--- Contar Tamanho da Frase ---\n");
  printf("Digite a frase: ");
  fgets(frase, sizeof(frase), stdin); // Le a linha completa, incluindo espaços

  // Remove o newline que fgets pode adicionar no final
  frase[strcspn(frase, "\n")] = 0;

  printf("O tamanho da frase eh: %zu caracteres.\n", strlen(frase));
}

//4- Verificar se um texto eh palíndromo

// Chamar funções
void converterTemperatura();
void calcularArea();
void contarTamanhoFrase();
void verificarPalindromo();
void exibirMenuPrincipal();
