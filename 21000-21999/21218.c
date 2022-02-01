#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MOD 1029989

/*
문제 : 길이 300000 이하의 대문자로 이루어진 문자열이 주어진다. 이 문자열의 부분 문자열 가운데
2번 이상 등장하지 않는 가장 짧은 부분 문자열을 구한다.
그러한 것이 여러 개인 경우 가장 앞에 있는 것을 출력한다.

해결 방법 : 매개 변수 탐색과 라빈-카프 해싱을 이용해 풀 수 있다.
매개 변수 탐색에서는 가장 짧은 부분 문자열의 길이를 구한다. 이 과정에서 라빈-카프 해싱을 통해
각 부분 문자열의 중복 여부를 확인한다. 모든 부분 문자열이 중복인 경우 더 긴 쪽으로 옮기고,
중복이 아닌 것이 있다면 짧은 쪽으로 옮기면 된다. 길이를 알아냈다면 다시 한번 라빈-카프 해싱으로
해당 길이의 중복하지 않는 부분 문자열들 중 가장 시작점이 빠른 것을 찾아 출력하면 된다.

주요 알고리즘 : 문자열, 라빈-카프, 파라메트릭

출처 : SWERC 2020 K번
*/

typedef struct llst {
    struct llst* nxt;
    int pos;
} llst;

char s[327680];
int b26[327680] = { 1, };
llst* hashed[1048576];
int best;

int getres(int l, int m) {
    int t, t2, p;
    llst* last;
    int h = 0;
    for (int i = 0; i < m; i++) {
        h += b26[m - i - 1] * (s[i] - 'A');
        h %= MOD;
    }
    last = calloc(1, sizeof(llst));
    hashed[h] = last;
    for (int i = m; i < l; i++) {
        h *= 26;
        h -= b26[m] * (s[i - m] - 'A');
        h += s[i] - 'A';
        h %= MOD;
        if (h < 0) h += MOD;

        t = 0;
        for (llst* node = hashed[h]; node; node = node->nxt) {
            if (node->pos < 0) p = -node->pos - 1;
            else p = node->pos;
            t2 = 1;
            for (int j = 0; j < m && j < 100; j++) {
                if (s[p + j] != s[i - m + j + 1]) {
                    t2 = 0;
                    break;
                }
            }
            if (t2) {
                t = 1;
                if (node->pos >= 0) node->pos = -node->pos - 1;
                break;
            }
        }
        if (!t) {
            last = calloc(1, sizeof(llst));
            last->nxt = hashed[h];
            last->pos = i - m + 1;
            hashed[h] = last;
        }
    }

    t = 0, best = MOD;
    for (int i = 0; i < MOD; i++) {
        last = NULL;
        for (llst* node = hashed[i]; node; node = node->nxt) {
            if (last) free(last);
            if (node->pos >= 0) {
                t = 1;
                if (node->pos < best) best = node->pos;
            }
            last = node;
        }
        if (last) free(last);
        hashed[i] = NULL;
    }
    return t;
}

int main(void) {
    int l, hi, lo, mid;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 1; i <= l; i++) b26[i] = (b26[i - 1] * 26) % MOD;
    hi = l, lo = 1;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (getres(l, mid)) hi = mid;
        else lo = mid + 1;
    }
    //printf("%d\n", lo);
    getres(l, lo);
    for (int i = best; i < best + lo; i++) printf("%c", s[i]);
    return 0;
}