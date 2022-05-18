#include <stdio.h>
#include <string.h>

/*
문제 : 정이면체군의 곱을 구한다.

해결 방법 : 직접 손으로 풀어보며 규칙을 찾는다. 앞쪽 b의 홀짝성과 두 a의 계수에 의해 a가 결정되며,
두 b의 계수에 의해 b가 결정된다.

주요 알고리즘 : 수학

출처 : Phil 2013M D번
*/

char id[1024];

int main(void) {
    int m, n, p, x, z, y, w;
    while (1) {
        scanf("%s %d %d %d", id, &m, &n, &p);
        if (!strcmp(id, "ZZ")) break;
        for (int i = 0; i < p; i++) {
            scanf(" a%db%d a%db%d", &x, &z, &y, &w);
            printf("ProblemID %s: a%db%d * a%db%d = a%db%d\n",
                id, x, z, y, w, (x + ((z & 1) ? (m - y) : y)) % m, (z + w) % n);
        }
    }
    return 0;
}