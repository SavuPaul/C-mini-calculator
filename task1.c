#include <stdio.h>

int main() {
    int N = 0, i = 0, j = 0;
    scanf("%d", &N);
    float term[N], result = 0;
    char op[N-1];

    for (i = 0; i < N; i++) {
        if (N == 1) {
            scanf("%f", &result);
            printf("%f\n", result);
            return 0;
        }
        scanf("%f", &term[i]);
    }  // citirea vectorului de operanzi

    for (i = 0; i < N; i++) {
        scanf("%c", &op[i]);
    }  // citirea vectorului de operatii

    // prelucrarea vectorilor pentru efectuarea operatiilor
    result = term[0];
    for (i = 1, j = 1; i < N; i++, j++) {
        switch (op[j]) {
            case '+':
                result = result + term[i];
                break;

            case '-':
                result = result - term[i];
                break;

            case '*':
                result = result * term[i];
                break;

            case '/':
                result = result / term[i];
                break;
        }
    }

    printf("%f\n", result);
    return 0;
}
