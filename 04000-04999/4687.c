#include <stdio.h>

/*
문제 : N(N <= 26)개의 문자로 이루어진 집합 S의 연산 #이 주어진다. 먼저 집합 S와 #의 표를 출력하고,
S가 반군인지, 반군이라면 교환법칙도 성립하는지 구하고, 반군이 아니라면 닫혀있지 않은지 또는 결합법칙이 성립하지 않는지 구한다.

해결 방법 : 먼저 집합 S와 연산 #을 입력받은 후 집합과 표를 출력한다. 이는 직접 구현한다.
그 후 S의 종류를 확인한다. 우선 닫혀있지 않은 연산인지 확인한다. S에 없는 문자가 연산시 나오면 닫혀있지 않은 연산이다.
그리고 결합법칙을 만족하는지 확인한다. 이는 미리 역변환 테이블을 만들어서 빠르게 확인하는 것이 좋다.
결합법칙을 만족하지 않은 쌍이 있다면 역시 반군이 아니다.
마지막으로 교환법칙을 만족하는지 확인한다. 이때도 마찬가지로 경우에 따라 출력하면 된다.

주요 알고리즘 : 구현, 수학

출처 : MidC 1996 F번?
*/

char table[32][32], s[32];
int ref[32];

void printres(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ref[table[i][j] - 'a'] < 0) {
                printf("NOT A SEMIGROUP: %c#%c = %c  WHICH IS NOT AN ELEMENT OF THE SET\n", s[i], s[j], table[i][j]);
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (table[ref[table[i][j] - 'a']][k] != table[i][ref[table[j][k] - 'a']]) {
                    printf("NOT A SEMIGROUP: (%c#%c)#%c IS NOT EQUAL TO %c#(%c#%c)\n", s[i], s[j], s[k], s[i], s[j], s[k]);
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (table[i][j] != table[j][i]) {
                printf("SEMIGROUP BUT NOT COMMUTATIVE  (%c#%c IS NOT EQUAL TO %c#%c)\n", s[i], s[j], s[j], s[i]);
                return;
            }
        }
    }
    printf("COMMUTATIVE SEMIGROUP\n");
}

int main(void) {
    int n;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM7\\SEMIGRP.IN", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM7\\SEMIGRP_T.OUT", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n <= 0) break;
        for (int i = 0; i < 32; i++) ref[i] = -1;
        scanf("%s", s);
        for (int i = 0; i < n; i++) {
            ref[s[i] - 'a'] = i;
            scanf("%s", table[i]);
        }
        printf("S = {");
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(",");
            printf("%c", s[i]);
        }
        printf("}\n #|%s\n -+", s);
        for (int i = 0; i < n; i++) printf("-");
        printf("\n");
        for (int i = 0; i < n; i++) {
            printf(" ");
            printf("%c|", s[i]);
            printf("%s\n", table[i]);
        }
        printf("\n");
        printres(n);
        printf("------------------------------\n\n");
    }
    return 0;
}