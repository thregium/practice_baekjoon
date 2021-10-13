#include <stdio.h>

/*
문제 : N * M(N, M <= 10) 크기의 문자들과 N * (M * 2) 크기의 문자들이 주어질 때, 첫 번째 문자들이 두 번째 문자들을
축약하여 만들어진 것인지 구한다.

해결 방법 : 첫 번째 문자들을 확인하며 두 번째 문자들의 2배 위치, 2배 + 1 위치에 있는 문자들과 같은지 매번 확인하면 된다.
하나라도 다르다면 아닌 것이고, 전부 같다면 맞는 것이다.

주요 알고리즘 : 구현

출처 : kriiicon 3회 ㄸ번
*/

char e1[32][32], e2[32][32];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", e1[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", e2[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (e1[i][j] != e2[i][j * 2] || e1[i][j] != e2[i][j * 2 + 1]) {
                printf("Not Eyfa");
                return 0;
            }
        }
    }
    printf("Eyfa");
    return 0;
}