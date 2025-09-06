#include <stdio.h>

int main() {
    // Declaração das variáveis da Carta 1    
    char nome_pais1[20];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;

    // Declaração das variáveis da Carta 2
    char nome_pais2[20];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;

    // Leitura dos dados da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Nome do País: ");
    scanf("%s", nome_pais1);  

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Leitura dos dados da Carta 2
    printf("Cadastro da Carta 2:\n");
    printf("Nome do País: ");
    scanf("%s", nome_pais2); 

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);
    
    // Cálculo da densidade populacional
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;
    
    // Cálculo do PIB per capita 
    float pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    float pib_per_capita2 = (pib2 * 1000000000) / populacao2;
    
    // Cálculo do Super Poder para cada carta 
    float super_poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + 
                        pib_per_capita1 + (1.0/densidade1);
    
    float super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + 
                        pib_per_capita2 + (1.0/densidade2);

    // Exibição dos dados da Carta 1
    printf("\n=== CARTA 1 ===\n");
    printf("Nome do País: %s\n", nome_pais1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    // Exibição dos dados da Carta 2
    printf("\n=== CARTA 2 ===\n");
    printf("Nome do País: %s\n", nome_pais2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // MENU INTERATIVO PARA ESCOLHA DO ATRIBUTO DE COMPARAÇÃO
    int opcao;
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção (1-5): ");
    scanf("%d", &opcao);

    // COMPARAÇÃO DAS CARTAS BASEADA NA OPÇÃO ESCOLHIDA
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Carta 1 - %s \n", nome_pais1);
    printf("Carta 2 - %s \n", nome_pais2);
    
    switch(opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %lu\n", nome_pais1, populacao1);
            printf("%s: %lu\n", nome_pais2, populacao2);
            
            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", nome_pais1, area1);
            printf("%s: %.2f km²\n", nome_pais2, area2);
            
            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
            } else if (area2 > area1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões de reais\n", nome_pais1, pib1);
            printf("%s: %.2f bilhões de reais\n", nome_pais2, pib2);
            
            if (pib1 > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
            } else if (pib2 > pib1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", nome_pais1, pontos_turisticos1);
            printf("%s: %d\n", nome_pais2, pontos_turisticos2);
            
            if (pontos_turisticos1 > pontos_turisticos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
            } else if (pontos_turisticos2 > pontos_turisticos1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        case 5: // Densidade Demográfica (regra - menor valor vence)
            printf("Atributo: Densidade Demográfica (menor valor vence)\n");
            printf("%s: %.2f hab/km²\n", nome_pais1, densidade1);
            printf("%s: %.2f hab/km²\n", nome_pais2, densidade2);
            
            if (densidade1 < densidade2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_pais1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_pais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;
            
        default:
            printf("Opção inválida! Por favor, execute o programa novamente e escolha uma opção entre 1 e 5.\n");
            break;
    }

    return 0;
}