#include <stdio.h>

float validaQuantidade(int quantidade) {
    if (quantidade <= 50) return 0;
    if(quantidade > 50 && quantidade <= 80)  {
        int pecas_com_adicional = quantidade - 50;
        return pecas_com_adicional * 0.5f;
    }

    float adicional = ((quantidade - 80) * 0.75f) + (30 * 0.50f);
    return adicional;
}

float calculaSalario(float adicional) {
    float final = (float) 600 + adicional;
    return final;
}

void mostraFinal(float salario) {
    printf("Valor total: %.2f \n", salario);
}

int main() {
    int quantidade;

    int iteracao = 1;
    do {
        printf("Salario do funcionario %d \n", iteracao);
        printf("Informe a quantidade de pecas produzidas no mes (-1 para encerrar): ");
        scanf("%d", &quantidade);

        if(quantidade != -1) {
            float adicional = validaQuantidade(quantidade);
            float salario = calculaSalario(adicional);
            mostraFinal(salario);
        }

        iteracao++;

    } while (quantidade != -1.f);

    printf("FIM DE PROGRAMA \n");

    return 0;
}