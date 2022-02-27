#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MOD 314159

/*
문제 : 100000자 이하의 소문자로 이루어진 문자열이 주어질 때, 이 문자열에서 2회 이상 나오는 부분 문자열 가운데
가장 긴 것 중 사전 순으로 가장 빠른 부분 문자열을 찾는다.

해결 방법 : 라빈-카프 해싱과 매개 변수 탐색을 통해  그러한 부분 문자열의 길이를 찾은 다음,
다시 라빈-카프 해싱을 통해 그러한 부분 문자열들을 하나씩 살펴보며 사전 순으로 가장 빠른 것을 찾으면 된다.

주요 알고리즘 : 문자열, 라빈-카프

출처 : MidC 2018 K번
*/

typedef struct llst {
    int st;
    struct llst* nx;
} llst;

char s[204800], res[204800];
llst* ls[320000];

int l;

int find(int n, int m) {
    if (n <= 0) return 1;

    llst* prev = NULL;
    for (int i = 0; i < MOD; i++) {
        prev = ls[i];
        if (!prev) continue;
        for (llst* j = ls[i]->nx; j; j = j->nx) {
            free(prev);
            prev = j;
        }
        free(prev);
        ls[i] = NULL;
    }

    int mul = 1, hash = 0;
    for (int i = 0; i < n; i++) {
        mul = (mul * 26) % MOD;
        hash = (hash * 26 + s[i]) % MOD;
    }

    int r;
    for (int i = n - 1; i < l; i++) {
        for (llst* j = ls[hash]; j; j = j->nx) {
            r = 1;
            for (int k = 0; k < n; k++) {
                if (s[j->st + k] != s[i - n + 1 + k]) {
                    r = 0;
                    break;
                }
            }
            if (r) {
                if (m == 0) return 1;
                r = 0;
                for (int ii = 0; ii < n; ii++) {
                    if (s[ii + i - n + 1] < res[ii]) {
                        r = 1;
                        break;
                    }
                    else if (s[ii + i - n + 1] > res[ii]) break;
                }
                if (r) {
                    for (int ii = 0; ii < n; ii++) res[ii] = s[ii + i - n + 1];
                }
            }
        }

        llst* x = malloc(sizeof(llst));
        x->nx = ls[hash];
        x->st = i - n + 1;
        ls[hash] = x;

        hash = (26 * hash + (MOD - mul) * s[i - n + 1] + s[i + 1]) % MOD;
    }

    return 0;
}

int main(void) {
    int hi, lo, mi;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\MCPC2018\\repeatedsubstrings\\data\\secret\\secret13.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\MCPC2018\\repeatedsubstrings\\data\\secret\\secret13_t.out", "w", stdout);
    //scanf("%d\n", &l);
    scanf("%s", s);
    l = strlen(s);
    /*
    for (int i = 0; i < l; i++) {
        scanf("%c", &s[i]);
    }
    printf("\n%d\n", strlen(s));
    */
    hi = l - 1;
    lo = 0;
    while (hi > lo) {
        mi = (hi + lo + 1) / 2;
        if (find(mi, 0)) {
            lo = mi;
        }
        else {
            hi = mi - 1;
        }
    }
    res[0] = 127;
    find(hi, 1);
    //printf("%d\n", hi);
    printf("%s\n", res);
    return 0;
}