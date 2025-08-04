#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição de uma carta
struct Carta {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
};

// Função para exibir uma carta
void mostrarCarta(struct Carta carta) {
    printf("Nome: %s\n", carta.nome);
    printf("Força: %d\n", carta.forca);
    printf("Velocidade: %d\n", carta.velocidade);
    printf("Inteligência: %d\n", carta.inteligencia);
}

int main() {
    srand(time(NULL));

    // Criação de 3 cartas
    struct Carta cartas[3] = {
        {"Dragão", 90, 60, 40},
        {"Mago", 40, 50, 95},
        {"Guerreiro", 80, 70, 60}
    };

    // Escolher uma carta aleatória para o jogador e para o computador
    int idxJogador = rand() % 3;
    int idxComputador;

    // Evitar que peguem a mesma carta
    do {
        idxComputador = rand() % 3;
    } while (idxComputador == idxJogador);

    struct Carta jogador = cartas[idxJogador];
    struct Carta computador = cartas[idxComputador];

    // Mostrar carta do jogador
    printf("Sua carta:\n");
    mostrarCarta(jogador);

    // Jogador escolhe atributo
    int escolha;
    printf("\nEscolha o atributo para competir:\n");
    printf("1 - Força\n2 - Velocidade\n3 - Inteligência\n");
    scanf("%d", &escolha);

    int valorJogador, valorComputador;
    switch (escolha) {
        case 1:
            valorJogador = jogador.forca;
            valorComputador = computador.forca;
            break;
        case 2:
            valorJogador = jogador.velocidade;
            valorComputador = computador.velocidade;
            break;
        case 3:
            valorJogador = jogador.inteligencia;
            valorComputador = computador.inteligencia;
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    // Mostrar carta do computador
    printf("\nCarta do computador:\n");
    mostrarCarta(computador);

    // Verificar resultado
    printf("\nResultado:\n");
    if (valorJogador > valorComputador)
        printf("Você venceu!\n");
    else if (valorJogador < valorComputador)
        printf("Você perdeu!\n");
    else
        printf("Empate!\n");

    return 0;
}
