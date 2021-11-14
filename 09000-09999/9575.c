#include <stdio.h>
#include <stdlib.h>

/*
문제 : 크기가 50 이하인 세 자연수로 된 배열이 주어진다. 이때, 세 배열의 값의 합으로 만들 수 있는
서로 다른 5와 8만으로 이루어진 수의 개수를 구한다.

해결 방법 : 각 자연수 배열의 값에 대해 세 배열의 합을 구한 다음, 5와 8만으로 이루어져 있는지 구한다.
그렇다면 결과 배열에 넣는다. 탐색이 끝나면 결과 배열을 정렬한 다음 중복을 제거한 다음 개수를 구하면 된다.

주요 알고리즘 : 브루트 포스, 수학, 정렬
*/

int a[64], b[64], c[64], res[128000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, na, nb, nc, x, p = 0, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &na);
        for (int i = 0; i < na; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &nb);
        for (int i = 0; i < nb; i++) {
            scanf("%d", &b[i]);
        }
        scanf("%d", &nc);
        for (int i = 0; i < nc; i++) {
            scanf("%d", &c[i]);
        }

        p = 0, r = 0;
        for (int i = 0; i < na; i++) {
            for (int j = 0; j < nb; j++) {
                for (int k = 0; k < nc; k++) {
                    x = a[i] + b[j] + c[k];
                    for (int y = x; y; y /= 10) {
                        if (y % 10 != 5 && y % 10 != 8) {
                            x = 0;
                            break;
                        }
                    }
                    if (x) res[p++] = x;
                }
            }
        }
        qsort(res, p, sizeof(int), cmp1);
        for (int i = 0; i < p; i++) {
            if (i > 0 && res[i] == res[i - 1]) continue;
            r++;
        }
        printf("%d\n", r);
    }
    return 0;
}