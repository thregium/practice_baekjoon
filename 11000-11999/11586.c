#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 격자를 K의 값에 맞게 뒤집어 출력한다.
1인 경우 뒤집지 않고, 2인 경우 좌우 반전, 3인 경우 상하 반전이다.

해결 방법 : 2차원 배열을 이용한다. 상하 반전은 행을 반대 순서로 돌면 되고, 좌우 반전은 각 행에서 열을 반대 순서로 돌면 된다.

주요 알고리즘 : 구현

출처 : 인하대 2015 L번
*/

char s[128][128];

int main(void) {
    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    scanf("%d", &k);
    switch (k) {
    case 1:
        for (int i = 0; i < n; i++) {
            printf("%s\n", s[i]);
        }
        break;
    case 2:
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) printf("%c", s[i][j]);
            printf("\n");
        }
        break;
    case 3:
        for (int i = n - 1; i >= 0; i--) {
            printf("%s\n", s[i]);
        }
        break;
    default:
        return 1;
    }
    return 0;
}