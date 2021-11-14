#include <stdio.h>

/*
문제 : 선로와 레버가 있을 때, 주어진 N(N <= 10)회의 동작 시 마네킹을 몇 개 치게 되는지 구한다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 선린 2회 E번
*/

char s[16];

int main(void) {
    int n, t = 1, p = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') t++;
        else if (s[i] == 'P') {
            if (t == 2) p = 2;
            else if (t == 1 && p == 0) p = 1;
            else if (t == 1 && p == 1) p = 0;
            else if (t <= 1) return 1;
        }
        else return 2;
    }
    if (t >= 3) {
        if (p == 2) printf("6");
        else if (p == 1) printf("1");
        else if (p == 0) printf("5");
        else return 3;
    }
    else printf("0");
    return 0;
}