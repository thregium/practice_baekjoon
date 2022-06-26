#include <stdio.h>

/*
문제 : N(N <= 10000)개의 명제들이 알파벳을 이용해 주어지면, 그 명제들을 이용해 증명 가능한
자명하지 않은 문제들을 전부 출력한다.

해결 방법 : 전건에서 후건으로 가는 간선을 전부 만든 다음, 플로이드-워셜 알고리즘을 이용해
간접적으로 증명 가능한 명제들을 전부 구하고 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜
*/

int ok[52][52];

int toint(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

char tochar(int x) {
    if (x < 26) return x + 'A';
    else return x + 'a' - 26;
}

int main(void) {
    int n, r = 0;
    char c1, c2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c => %c", &c1, &c2);
        ok[toint(c1)][toint(c2)] = 1;
    }
    for (int k = 0; k < 52; k++) {
        for (int i = 0; i < 52; i++) {
            for (int j = 0; j < 52; j++) {
                ok[i][j] |= (ok[i][k] & ok[k][j]);
            }
        }
    }
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == j) continue;
            r += ok[i][j];
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == j || (!ok[i][j])) continue;
            printf("%c => %c\n", tochar(i), tochar(j));
        }
    }
    return 0;
}