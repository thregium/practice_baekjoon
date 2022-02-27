#include <stdio.h>

/*
문제 : H * W(H, W <= 3000) 크기의 격자에 'J', 'O', 'I'가 쓰여 있다.
서로 다른 (i, j, k, l)(1 <= i < k <= H)(1 <= j <= l <= W)에 대해
'J'는 (i, j), 'O'는 (i, l), 'I'는 (k, j)에 있는 순서쌍의 개수를 구한다.

해결 방법 : 'O'와 'I'는 'J'와 평행한 곳에 있기 때문에,
'J'마다 양쪽의 'O'와 'I' 개수를 곱해서 답을 얻을 수 있다.
오른쪽으로의 'O' 개수와 아래쪽으로의 'I' 개수를 누적 합을 이용해
각각 미리 구해두면 이 값들을 빠르게 찾을 수 있다.

주요 알고리즘 : 수학, 조합론, 누적 합

출처 : JOI 2019 1번
*/

char s[3072][3072];
short icnt[3072][3072], ocnt[3072][3072];

int main(void) {
    int h, w;
    long long r = 0;
    scanf("%d %d", &h, &w);
    for (int i = 1; i <= h; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= w; j++) {
            if (s[i][j] == 'I') icnt[i][j] = 1;
            else if (s[i][j] == 'O') ocnt[i][j] = 1;
        }
    }
    for (int i = 1; i <= w; i++) {
        for (int j = h - 1; j > 0; j--) icnt[j][i] += icnt[j + 1][i];
    }
    for (int i = 1; i <= h; i++) {
        for (int j = w - 1; j > 0; j--) ocnt[i][j] += ocnt[i][j + 1];
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (s[i][j] != 'J') continue;
            r += (long long)ocnt[i][j + 1] * icnt[i + 1][j];
        }
    }
    printf("%lld\n", r);
    return 0;
}