#include <stdio.h>

int main() {
    // Declaração das variáveis da Carta 1    
    char nome_pais1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade1;
    float pib_per_capita1;
    float super_poder1;

    // Declaração das variáveis da Carta 2
    char nome_pais2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade2;
    float pib_per_capita2;
    float super_poder2;

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
    densidade1 = (area1 > 0) ? (float)populacao1 / area1 : 0;
    densidade2 = (area2 > 0) ? (float)populacao2 / area2 : 0;
    
    // Cálculo do PIB per capita 
    pib_per_capita1 = (populacao1 > 0) ? (pib1 * 1000000000) / populacao1 : 0;
    pib_per_capita2 = (populacao2 > 0) ? (pib2 * 1000000000) / populacao2 : 0;
    
    // Cálculo do Super Poder
    super_poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + 
                  pib_per_capita1 + ((densidade1 > 0) ? (1.0/densidade1) : 0);
    
    super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + 
                  pib_per_capita2 + ((densidade2 > 0) ? (1.0/densidade2) : 0);

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

    // Menu interativo para escolha dos atributos
    int atributo1, atributo2;
    
    // Primeiro atributo
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    
    int valido = 0;
    while (!valido) {
        printf("Escolha o primeiro atributo:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("Digite sua opção (1-5): ");
        scanf("%d", &atributo1);
        
        if (atributo1 >= 1 && atributo1 <= 5) {
            valido = 1;
        } else {
            printf("Opção inválida! Tente novamente.\n\n");
        }
    }

    // Segundo atributo
    valido = 0;
    while (!valido) {
        printf("\nEscolha o segundo atributo:\n");
        
        // Menu dinâmico
        if (atributo1 == 1) {
            printf("2 - Área\n3 - PIB\n4 - Número de Pontos Turísticos\n5 - Densidade Demográfica\n");
        } else if (atributo1 == 2) {
            printf("1 - População\n3 - PIB\n4 - Número de Pontos Turísticos\n5 - Densidade Demográfica\n");
        } else if (atributo1 == 3) {
            printf("1 - População\n2 - Área\n4 - Número de Pontos Turísticos\n5 - Densidade Demográfica\n");
        } else if (atributo1 == 4) {
            printf("1 - População\n2 - Área\n3 - PIB\n5 - Densidade Demográfica\n");
        } else {
            printf("1 - População\n2 - Área\n3 - PIB\n4 - Número de Pontos Turísticos\n");
        }
        
        printf("Digite sua opção: ");
        scanf("%d", &atributo2);
        
        if (atributo2 >= 1 && atributo2 <= 5) {
            if (atributo2 != atributo1) {
                valido = 1;
            } else {
                printf("Erro: Você não pode escolher o mesmo atributo duas vezes! Tente novamente.\n\n");
            }
        } else {
            printf("Opção inválida! Tente novamente.\n\n");
        }
    }

    // Variáveis para armazenar os valores dos atributos escolhidos
    float valor1_carta1, valor1_carta2; 
    float valor2_carta1, valor2_carta2; 

    // Comparação do primeiro atributo
    printf("\n=== COMPARAÇÃO DOS ATRIBUTOS ===\n");
    printf("PRIMEIRO ATRIBUTO: ");
    
    switch(atributo1) {
        case 1: // População
            valor1_carta1 = populacao1;
            valor1_carta2 = populacao2;
            printf("População\n");
            printf("%s: %lu\n", nome_pais1, populacao1);
            printf("%s: %lu\n", nome_pais2, populacao2);
            printf("Vencedor: %s\n", (populacao1 > populacao2) ? nome_pais1 : 
                                     (populacao2 > populacao1) ? nome_pais2 : "Empate");
            break;
            
        case 2: // Área
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            printf("Área\n");
            printf("%s: %.2f km²\n", nome_pais1, area1);
            printf("%s: %.2f km²\n", nome_pais2, area2);
            printf("Vencedor: %s\n", (area1 > area2) ? nome_pais1 : 
                                     (area2 > area1) ? nome_pais2 : "Empate");
            break;
            
        case 3: // PIB
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            printf("PIB\n");
            printf("%s: %.2f bilhões\n", nome_pais1, pib1);
            printf("%s: %.2f bilhões\n", nome_pais2, pib2);
            printf("Vencedor: %s\n", (pib1 > pib2) ? nome_pais1 : 
                                     (pib2 > pib1) ? nome_pais2 : "Empate");
            break;
            
        case 4: // Pontos Turísticos
            valor1_carta1 = pontos_turisticos1;
            valor1_carta2 = pontos_turisticos2;
            printf("Pontos Turísticos\n");
            printf("%s: %d\n", nome_pais1, pontos_turisticos1);
            printf("%s: %d\n", nome_pais2, pontos_turisticos2);
            printf("Vencedor: %s\n", (pontos_turisticos1 > pontos_turisticos2) ? nome_pais1 : 
                                     (pontos_turisticos2 > pontos_turisticos1) ? nome_pais2 : "Empate");
            break;
            
        case 5: // Densidade Demográfica
            valor1_carta1 = densidade1;
            valor1_carta2 = densidade2;
            printf("Densidade Demográfica (menor vence)\n");
            printf("%s: %.2f hab/km²\n", nome_pais1, densidade1);
            printf("%s: %.2f hab/km²\n", nome_pais2, densidade2);
            printf("Vencedor: %s\n", (densidade1 < densidade2) ? nome_pais1 : 
                                     (densidade2 < densidade1) ? nome_pais2 : "Empate");
            break;
    }

    // Comparação do segundo atributo
    printf("\nSEGUNDO ATRIBUTO: ");
    
    switch(atributo2) {
        case 1: // População
            valor2_carta1 = populacao1;
            valor2_carta2 = populacao2;
            printf("População\n");
            printf("%s: %lu\n", nome_pais1, populacao1);
            printf("%s: %lu\n", nome_pais2, populacao2);
            printf("Vencedor: %s\n", (populacao1 > populacao2) ? nome_pais1 : 
                                     (populacao2 > populacao1) ? nome_pais2 : "Empate");
            break;
            
        case 2: // Área
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            printf("Área\n");
            printf("%s: %.2f km²\n", nome_pais1, area1);
            printf("%s: %.2f km²\n", nome_pais2, area2);
            printf("Vencedor: %s\n", (area1 > area2) ? nome_pais1 : 
                                     (area2 > area1) ? nome_pais2 : "Empate");
            break;
            
        case 3: // PIB
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            printf("PIB\n");
            printf("%s: %.2f bilhões\n", nome_pais1, pib1);
            printf("%s: %.2f bilhões\n", nome_pais2, pib2);
            printf("Vencedor: %s\n", (pib1 > pib2) ? nome_pais1 : 
                                     (pib2 > pib1) ? nome_pais2 : "Empate");
            break;
            
        case 4: // Pontos Turísticos
            valor2_carta1 = pontos_turisticos1;
            valor2_carta2 = pontos_turisticos2;
            printf("Pontos Turísticos\n");
            printf("%s: %d\n", nome_pais1, pontos_turisticos1);
            printf("%s: %d\n", nome_pais2, pontos_turisticos2);
            printf("Vencedor: %s\n", (pontos_turisticos1 > pontos_turisticos2) ? nome_pais1 : 
                                     (pontos_turisticos2 > pontos_turisticos1) ? nome_pais2 : "Empate");
            break;
            
        case 5: // Densidade Demográfica
            valor2_carta1 = densidade1;
            valor2_carta2 = densidade2;
            printf("Densidade Demográfica (menor vence)\n");
            printf("%s: %.2f hab/km²\n", nome_pais1, densidade1);
            printf("%s: %.2f hab/km²\n", nome_pais2, densidade2);
            printf("Vencedor: %s\n", (densidade1 < densidade2) ? nome_pais1 : 
                                     (densidade2 < densidade1) ? nome_pais2 : "Empate");
            break;
    }

    // Cálculo final
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;

    // Resultado Final
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Soma dos atributos para %s: %.2f\n", nome_pais1, soma_carta1);
    printf("Soma dos atributos para %s: %.2f\n", nome_pais2, soma_carta2);
    
    if (soma_carta1 > soma_carta2) {
        printf("\n RESULTADO: Carta 1 (%s) VENCEU A RODADA! \n", nome_pais1);
    } else if (soma_carta2 > soma_carta1) {
        printf("\n RESULTADO: Carta 2 (%s) VENCEU A RODADA! \n", nome_pais2);
    } else {
        printf("\n RESULTADO: EMPATE! \n");
    }

    return 0;
}