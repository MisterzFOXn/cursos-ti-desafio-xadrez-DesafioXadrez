#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nome[30];
    unsigned long int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    double pib_per_capita;
    float super_poder;
} Carta;

void calcular_dados(Carta *c) {
    // Densidade Populacional
    c->densidade_populacional = (float)c->populacao / c->area;

    // PIB per Capita
    c->pib_per_capita = c->pib / (double)c->populacao;

    // Super Poder:
    // População + Área + PIB + Pontos Turísticos + PIB per Capita + (1 / densidade)
    c->super_poder = 
        (float)c->populacao +
        c->area +
        (float)c->pib +
        (float)c->pontos_turisticos +
        (float)c->pib_per_capita +
        (1.0f / c->densidade_populacional);
}

int comparar(float valor1, float valor2, int menor_vence) {
    if (menor_vence) {
        return valor1 < valor2 ? 1 : 0; // menor vence
    } else {
        return valor1 > valor2 ? 1 : 0; // maior vence
    }
}

int main() {
    Carta c1, c2;

    // Entrada Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c1.estado);
    printf("Codigo da carta: ");
    scanf("%s", c1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c1.nome);
    printf("Populacao: ");
    scanf("%lu", &c1.populacao);
    printf("Area: ");
    scanf("%f", &c1.area);
    printf("PIB: ");
    scanf("%lf", &c1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &c1.pontos_turisticos);

    // Entrada Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c2.estado);
    printf("Codigo da carta: ");
    scanf("%s", c2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c2.nome);
    printf("Populacao: ");
    scanf("%lu", &c2.populacao);
    printf("Area: ");
    scanf("%f", &c2.area);
    printf("PIB: ");
    scanf("%lf", &c2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &c2.pontos_turisticos);

    // Calcular atributos derivados
    calcular_dados(&c1);
    calcular_dados(&c2);

    // Comparações
    printf("\nComparacao de Cartas:\n");
    printf("Populacao: Carta 1 venceu (%d)\n", comparar((float)c1.populacao, (float)c2.populacao, 0));
    printf("Area: Carta 1 venceu (%d)\n", comparar(c1.area, c2.area, 0));
    printf("PIB: Carta 1 venceu (%d)\n", comparar((float)c1.pib, (float)c2.pib, 0));
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", comparar((float)c1.pontos_turisticos, (float)c2.pontos_turisticos, 0));
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", comparar(c1.densidade_populacional, c2.densidade_populacional, 1));
    printf("PIB per Capita: Carta 1 venceu (%d)\n", comparar((float)c1.pib_per_capita, (float)c2.pib_per_capita, 0));
    printf("Super Poder: Carta 1 venceu (%d)\n", comparar(c1.super_poder, c2.super_poder, 0));

    return 0;
}
