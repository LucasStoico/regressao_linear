#include <stdio.h>
#include <math.h>

int main() {
    
    int n;

    // Solicita ao usuário o número de pontos de dados
    printf("Digite o número de pontos de dados: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Pelo menos dois pontos de dados são necessários para calcular a correlação e a regressão linear.\n");
        return 1;
    }

    double x[n], y[n];

    // Solicita ao usuário os valores de x
    printf("Digite os valores de x:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
    }

    // Solicita ao usuário os valores de y
    printf("Digite os valores de y:\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }

    // Calcula as somas necessárias para a regressão linear e a correlação de Pearson
    double soma_x = 0, soma_y = 0, soma_xy = 0, soma_x_quadrado = 0, soma_y_quadrado = 0;
    for (int i = 0; i < n; i++) {
        soma_x += x[i];
        soma_y += y[i];
        soma_xy += x[i] * y[i];
        soma_x_quadrado += x[i] * x[i];
        soma_y_quadrado += y[i] * y[i];
    }

    // Calcula os coeficientes da regressão linear
    double coeficiente_angular = (n * soma_xy - soma_x * soma_y) / (n * soma_x_quadrado - soma_x * soma_x);
    double coeficiente_linear = (soma_y - coeficiente_angular * soma_x) / n;

    // Calcula a correlação de Pearson
    double correlacao = (n * soma_xy - soma_x * soma_y) / (sqrt((n * soma_x_quadrado - soma_x * soma_x) * (n * soma_y_quadrado - soma_y * soma_y)));

    // Exibe os resultados
    printf("A equação da regressao linear é: y = %.4fx + %.4f\n", coeficiente_angular, coeficiente_linear);
    printf("O coeficiente de correlação de Pearson é: %.4f\n", correlacao);

    return 0;
}
