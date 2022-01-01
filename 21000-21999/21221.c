#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 격자에 '#'으로 이루어진 문자가 주어질 때,
이 문자를 굵게(오른쪽, 아래로 2 * 2단위로 넓히기) 만든다.

해결 방법 : 오른쪽 아래부터 역순으로 확인하며 왼쪽 또는 위 또는 왼쪽 위가 '#'인 경우 '#'으로 바꾸면 된다.

주요 알고리즘 : 구현

출처 : COCI 20/21#6 1번
*/

char s[128][128];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i > 0 && s[i - 1][j] == '#') s[i][j] = '#';
            else if (j > 0 && s[i][j - 1] == '#') s[i][j] = '#';
            else if (i > 0 && j > 0 && s[i - 1][j - 1] == '#') s[i][j] = '#';
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}