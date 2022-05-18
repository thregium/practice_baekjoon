#include <stdio.h>
#include <stdlib.h>

/*
문제 : N * N(N <= 512, N은 2의 자연수 제곱) 크기의 0과 1로 이루어진 배열이 주어진다.
이때, 이 배열을 쿼드트리로 바꾼 후 레벨 순회한 것을 16진수로 인코딩한 값을 구한다.

해결 방법 : 쿼드트리를 재귀를 통해 만든 다음, 각 정점의 값을 배열에 넣고,
다시 배열을 차례로 정렬한 다음 문자열로 바꿔서 최종적으로 16진수로 바꾸면 된다.

주요 알고리즘 : 구현, 분할 정복, 재귀

출처 : Kaosiung 2003 B번
*/

int a[512][512], nds[262144][3];
char s[1048576];
int ndcnt;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai < bi ? 1 : ai == bi ? 0 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void maketree(int sz, int x, int y) {
    int o = 0, z = 0, val = 0;
    for (int i = x; i < x + sz; i++) {
        for (int j = y; j < y + sz; j++) {
            if (a[i][j] == 0) z = 1;
            else o = 1;
        }
    }

    if (!z) val = 1;
    else if (!o) val = 0;
    else {
        val = -1;
        maketree(sz >> 1, x, y);
        maketree(sz >> 1, x, y + (sz >> 1));
        maketree(sz >> 1, x + (sz >> 1), y);
        maketree(sz >> 1, x + (sz >> 1), y + (sz >> 1));
    }
    nds[ndcnt][0] = sz;
    nds[ndcnt][1] = x * 1024 + y;
    nds[ndcnt++][2] = val;
}

int main(void) {
    int t, n, l, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        ndcnt = 0;
        maketree(n, 0, 0);
        qsort(nds, ndcnt, sizeof(int) * 3, cmp1);
        l = 0;
        for (int i = 0; i < ndcnt; i++) {
            if (nds[i][2] == 0) {
                s[l++] = '0';
                s[l++] = '0';
            }
            else if (nds[i][2] == 1) {
                s[l++] = '0';
                s[l++] = '1';
            }
            else s[l++] = '1';
        }

        r = 0;
        for (int i = l % 4 - 1; i >= 0; i--) {
            r += (s[i] - '0') << (l % 4 - 1 - i);
        }
        printf("%X", r);
        for (int i = l % 4; i < l; i += 4) {
            r = 0;
            for (int j = 0; j < 4; j++) {
                r += (s[i + j] - '0') << (3 - j);
            }
            printf("%X", r);
        }
        printf("\n");
    }
    return 0;
}