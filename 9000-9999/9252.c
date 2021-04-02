#include <stdio.h>
#include <string.h>

/*
문제 : 두 문자열의 LCS를 출력한다.

해결 방법 : LCS의 길이를 먼저 구한 후, LCS의 마지막 원소부터 역순으로 LCS를 구해나간다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

char a1[1024], a2[1024], s[1024];
int am[1024][1024];

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int x, c = 0;
    scanf("%s%s", &a1, &a2);
    int l1 = strlen(a1), l2 = strlen(a2);
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (a1[i] == a2[j]) am[i + 1][j + 1] = am[i][j] + 1;
            else am[i + 1][j + 1] = max(am[i + 1][j], am[i][j + 1]);
        }
    }
    printf("%d\n", am[l1][l2]);
    x = l2;
    for (int i = l1; i >= 1; i--) {
        if (am[i][x] > am[i - 1][x]) {
            //printf("%c", a1[i - 1]);
            s[c++] = a1[i - 1];
            while (am[i][x] == am[i][x - 1]) {
                x--;
            }
            x--;
        }
    }
    if (c > 0) {
        for (int i = c - 1; i >= 0; i--) {
            printf("%c", s[i]);
        }
    }
    return 0;
}