#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 그림이 주어진다. 이때, 이 그림을 가로로 반으로 접었을 때 물감이 묻은 형태를 출력한다.
물감이 겹치는 경우는 없다. 또한, M은 짝수이다.

해결 방법 : 각 줄마다 반대쪽 위치를 확인하며 한 쪽에 물감이 묻었다면 반대쪽도 같은 물감을 묻힌 다음 출력하면 된다.

주요 알고리즘 : 구현

출처 : 인천대 2021 A번
*/

char s[64];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            if (s[j] != '.') s[m - j - 1] = s[j];
        }
        printf("%s\n", s);
    }
    return 0;
}