#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 10^9 이하의 자연수 N을 2진수로 표현한 문자열과 3진수로 표현한 문자열에서 각각 1자씩 잘못된 문자열들이 주어진다.
이때, N이 유일하다면 나올 수 있는 N을 구한다.

해결 방법 : 각 문자열에서 1자씩 다르게 표현한 문자열에서 얻을 수 있는 N의 후보들을 각각 저장한다.
그 후, 후보들 가운데 2번 나타나는 수를 찾으면 답이 된다.

주요 알고리즘 : 브루트 포스, 수학, 문자열

출처 : USACO 2011N B2번
*/

char base2[64], base3[64], temp[64];
long long cand[1024];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long t, p = 0;
    scanf("%s%s", base2, base3);
    strcpy(temp, base2);
    for (int i = 0; temp[i]; i++) {
        for (char j = '0'; j <= '1'; j++) {
            if (base2[i] == j || (i == 0 && j == '0')) continue;
            temp[i] = j;
            cand[p++] = strtoll(temp, NULL, 2);
        }
        temp[i] = base2[i];
    }

    strcpy(temp, base3);
    for (int i = 0; temp[i]; i++) {
        for (char j = '0'; j <= '2'; j++) {
            if (base3[i] == j || (i == 0 && j == '0')) continue;
            temp[i] = j;
            cand[p++] = strtoll(temp, NULL, 3);
        }
        temp[i] = base3[i];
    }

    qsort(cand, p, sizeof(long long), cmp1);
    for (int i = 1; i < p; i++) {
        if (cand[i] == cand[i - 1]) {
            printf("%lld", cand[i]);
            return 0;
        }
    }
    return 1;
}