#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 50)개의 공항명이 주어질 때, 모든 공항의 공항 코드가 겹치지 않기 위해서는 앞에서부터
최소 몇 자의 공항 코드를 봐야 하는 지 구한다. 공항 코드는 맨 앞자와 모음의 다음 글자들을 따온다.
끝까지 봐도 공항 코드가 전부 같은 경우에는 -1을 출력한다.

해결 방법 : 각 공항의 공항 코드를 처음부터 끝까지 저장해둔 다음, 1글자씩 늘려가며 모든 공항의 쌍끼리
겹치는 경우는 없는 지 확인한다. 그러한 경우가 없어지면 그때까지 본 문자 수를 출력하면 된다.
그러한 경우가 끝까지 있다면 -1을 출력한다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : JAG 2015D B번
*/

char s[64][64], code[64][64], cpy[64][64];

int isvowel(char c) {
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') return 1;
    else return 0;
}

int main(void) {
    int n, p, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            p = 0;
            for (int j = 0; s[i][j]; j++) {
                if (j == 0 || isvowel(s[i][j - 1])) code[i][p++] = s[i][j];
            }
        }
        t = 0;
        for (int i = 0; i < 64; i++) {
            t = 1;
            for (int j = 0; j < n; j++) {
                cpy[j][i] = code[j][i];
            }
            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (!strcmp(cpy[j], cpy[k])) t = 0;
                }
            }
            if (t) {
                printf("%d\n", i + 1);
                break;
            }
        }
        if (!t) printf("-1\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 64; j++) {
                code[i][j] = 0;
                cpy[i][j] = 0;
            }
        }
    }
    return 0;
}