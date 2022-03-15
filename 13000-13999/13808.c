#include <stdio.h>

/*
문제 : N(N <= 100)개의 국가가 있고, 각 국가는 M_i(M_i <= 10000)개 이하의 미사일들을 각각 갖고 있다.
각 미사일의 위력의 합이 가장 큰 국가와 가장 작은 국가의 위력 차이가 D(D <= 1000) 이하가 되어야 한다.
또한, 각 미사일의 위력은 1000 이하의 음이 아닌 정수이고, 미사일들은 순서대로 폐기하여야 할 때,
모든 국가의 모든 미사일을 폐기할 수 있는 지 구한다.

해결 방법 : 각 국가의 미사일들 가운데 폐기할 수 있는 것을 찾아 폐기하는 과정을 반복하면 된다.
폐기 과정에서 위력의 최댓값이 바뀔 수 있으므로 주의한다.

주요 알고리즘 : 구현, 시뮬레이션, 그리디 알고리즘, 스택

출처 : JAG 2009P B번
*/

int miss[128][10240], missc[128], pot[128];

int main(void) {
    int n, d, h, h2, c;
    while (1) {
        scanf("%d %d", &n, &d);
        if (n == 0) break;
        h = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &missc[i]);
            pot[i] = 0;
            for (int j = 0; j < missc[i]; j++) {
                scanf("%d", &miss[i][j]);
                pot[i] += miss[i][j];
            }
            if (pot[i] > h) h = pot[i];
        }
        while (1) {
            c = 0;
            for (int i = 0; i < n; i++) {
                if (missc[i] > 0 && pot[i] - miss[i][missc[i] - 1] >= h - d) {
                    c = 1;
                    pot[i] -= miss[i][missc[i] - 1];
                    missc[i]--;
                    h = 0;
                    for (int j = 0; j < n; j++) {
                        if (pot[j] > h) h = pot[j];
                    }
                    break;
                }
            }
            if (c) continue;
            for (int i = 0; i < n; i++) {
                if (pot[i] != h) continue;
                h2 = 0;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (pot[j] > h2) h2 = pot[j];
                }
                if (missc[i] > 0 && pot[i] - miss[i][missc[i] - 1] >= h2 - d) {
                    c = 1;
                    pot[i] -= miss[i][missc[i] - 1];
                    missc[i]--;
                    h = 0;
                    for (int j = 0; j < n; j++) {
                        if (pot[j] > h) h = pot[j];
                    }
                    break;
                }
            }
            if (!c) break;
        }

        h = 0;
        for (int i = 0; i < n; i++) {
            if (pot[i] > h) h = pot[i];
        }
        printf("%s\n", h ? "No" : "Yes");
    }
    return 0;
}