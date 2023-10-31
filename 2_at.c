#include <stdio.h>

int classificaSalario (float salario, int *maior_minimo, int *menor_minino) {
    if (salario > 1400) {
        *maior_minimo = *maior_minimo+1;
        return 1;
    }
    if (salario == 1400) return 0;
    if (salario < 1400) {
        *menor_minino = *menor_minino+1;
        return -1;
    }
}

void mostraClassifica (char sexo, float salario, int status) {
    printf("Sexo: %s \n", sexo == 'M' || sexo == 'm' ? "Masculino" : "Feminino");
    printf("Salario: R$ %.2f \n", salario);
    if(status == -1) {
        printf("Salario menor que o minimo \n");
    } else if(status == 0) {
        printf("Salario igual que o minimo \n");
    } else {
        printf("Salario maior que o minimo \n");
    }
    printf("\n");
}

int main () {
    int iteracao = 1;
    char sexo;
    float salario;
    int maior_minimo = 0;
    int menor_minimo = 0;

    do {

        printf("Salario do funcionario %d \n", iteracao);
        printf("Informe M(Masculino) ou F(Feminino): ");
        scanf("%s", &sexo);
        printf("Informe o salario: ");
        scanf("%f", &salario);

        if(salario > 1) {
            mostraClassifica(sexo, salario, classificaSalario(salario, &maior_minimo, &menor_minimo));
        }

        iteracao++;
    } while (salario > 1);

    printf("TOTAL DE FUNCIONARIOS \n");
    printf("Num. de funcionarios que ganham um salario maior que o minimo: %d \n", maior_minimo);
    printf("Num. de funcionarios que ganham um salario menor que o minimo: %d \n", menor_minimo);

    return 0;    
}