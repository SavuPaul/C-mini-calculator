#include <stdio.h>

int main() {
    int N = 0, i = 0, j = 0, prio = 0, found = 0, prio2 = 1;
    scanf("%d", &N);
    int deplasare = N-2;
    float term[N], result = 0, res = 0;
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

    // verificam cate operatii prioritare exista
    for (i = 1; i < N; i++) {
        if (op[i] == '/' || op[i] == '*') {
            prio++;
        }
    }

    for (j = 1; deplasare >= 0; j++) {
        found = 0;
        if ((op[j] == '+' || op[j] == '-') && prio == 0) {
            if (op[j] == '+') {
                res = term[j-1] + term[j];
            }
            if (op[j] == '-') {
                res = term[j-1] - term[j];
            }
        }

        if (op[j] == '*' || op[j] == '/') {
            if (op[j] == '*') {
                res = term[j-1] * term[j];
            }
            if (op[j] == '/') {
                res = term[j-1] / term[j];
            }
            prio--;
            found = 1;
        }  // efectuarea prioritara a * si /

        if (found == 0 && prio != 0) {
            continue;
        }
        deplasare--;

        term[j-1] = res;
        // deplasarea vectorilor cu o pozitie la stanga
        for (i = j; i < N-1; i++) {
            term[i] = term[i+1];
        }
        for (i = j; i < N-1; i++) {
            op[i] = op[i+1];
        }
        N--;
        j--;
        if (prio == 0 && prio2 == 1) {
            j = 0;
            prio2 = 0;
        }
    }
    result = term[0];
    printf("%f\n", result);
    return 0;
}
