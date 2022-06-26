#include <stdio.h>

/*
문제 : N(N <= 100)회의 값의 변화가 주어질 때, 그 변화를 이용하여 그래프를 그린다.

해결 방법 : 각 지점의 위치를 잡고 그래프를 그려나간다. 그 후 그래프가 있는 지점만 모아 출력하면 된다.

주요 알고리즘 : 구현

출처 : COCI 20/21#2 1번
*/

char s[128], res[256][128];

int main(void) {
    int n, now = 128, isprinting;
    scanf("%d", &n);
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < n; j++) res[i][j] = '.';
    }
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            res[now][i] = '/';
            now--;
        }
        else if (s[i] == '-') {
            now++;
            res[now][i] = '\\';
        }
        else res[now][i] = '_';
    }
    for (int i = 0; i < 256; i++) {
        isprinting = 0;
        for (int j = 0; j < n; j++) {
            if (res[i][j] != '.') isprinting = 1;
        }
        if (isprinting) printf("%s\n", res[i]);
    }
    return 0;
}