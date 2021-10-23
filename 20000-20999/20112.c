#include <stdio.h>

/*
문제 : 주어진 N * N(N <= 100) 크기의 배열이 사토르 마방진인지 구한다.

해결 방법 : 배열의 각 칸에 대해서 행과 열을 바꾼 칸도 모두 같은지 확인하면 된다. 다른 칸이 있으면 사토르 마방진이 아니고,
모두 같다면 사토르 마방진이다.

주요 알고리즘 : 구현

출처 : 경북대 2020 A번
*/

char s[128][128];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != s[j][i]) r = 0;
        }
    }
    printf("%s", r ? "YES" : "NO");
    return 0;
}