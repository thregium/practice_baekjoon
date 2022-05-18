#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 5자 이상 12자 이하의 문자열과 12 * 10^6 이하의 자연수가 주어질 때, 문자열에서 5개의 문자를
선택하여 문제에 주어진 식을 계산하여 주어진 수를 만들 수 있는 문자열 가운데 사전순으로 가장 늦은
문자열을 출력한다. 없는 경우 "no solution"을 출력한다.

해결 방법 : 주어진 문자열을 문자 순서대로 정렬한 다음, 사전순으로 답을 탐색해 나간다.
답이 되는 조합을 발견하면 이를 답에 덮어씌우는 것을 반복하고, 최종적으로 나온 답을 출력하면 된다.
처음 상태가 그대로라면 답이 없는 것이다.

주요 알고리즘 : 브루트 포스

출처 : MidC 2002 D번
*/

char s[16], res[8];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

long long getform(long long v, long long w, long long x, long long y, long long z) {
    return v - w * w + x * x * x - y * y * y * y + z * z * z * z * z;
}

int main(void) {
    long long targ, len;
    while (1) {
        scanf("%lld %s", &targ, s);
        if (targ == 0) break;
        len = strlen(s);
        qsort(s, len, sizeof(char), cmp1);

        strcpy(res, "-----");
        for (long long v = 0; v < len; v++) {
            for (long long w = 0; w < len; w++) {
                if (w == v) continue;
                for (long long x = 0; x < len; x++) {
                    if (x == v || x == w) continue;
                    for (long long y = 0; y < len; y++) {
                        if (y == v || y == w || y == x) continue;
                        for (long long z = 0; z < len; z++) {
                            if (z == v || z == w || z == x || z == y) continue;

                            if (getform(s[v] - 'A' + 1, s[w] - 'A' + 1, s[x] - 'A' + 1,
                                s[y] - 'A' + 1, s[z] - 'A' + 1) == targ) {
                                res[0] = s[v];
                                res[1] = s[w];
                                res[2] = s[x];
                                res[3] = s[y];
                                res[4] = s[z];
                            }
                        }
                    }
                }
            }
        }

        if (res[0] == '-') printf("no solution\n");
        else printf("%s\n", res);
    }
    return 0;
}