#include <stdio.h>

/*
문제 : N(N <= 10)명의 출제위원이 각각 내는 문제의 난이도가 주어질 때, K(K <= 14)개의 문제를 문제에 주어진 방식으로
내는 동안 만들어지는 난이도의 합을 구한다.

해결 방법 : 문제에 주어진대로 구현한다. 배열의 종료 처리에 유의한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : NEERC 2015 E번
*/

int prob[16][16];

int main(void) {
    int n, k, x, s = 0, c = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) prob[i][j] = -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            scanf("%d", &prob[i][j]);
        }
    }
    for (int i = 0;; i++) {
        for (int j = 0; j < n; j++) {
            if (prob[j][i] < 0) {
                c++;
                s += 50;
            }
            else if (prob[j][i] >= s) {
                c++;
                s += prob[j][i];
            }
            if (c >= k) break;
        }
        if (c >= k) break;
    }
    printf("%d", s);
    return 0;
}