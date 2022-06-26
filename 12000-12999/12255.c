#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 103000

/*
문제 : N(N <= 150)개의 L(L <= 40)개 비트로 이루어진 문자열들이 있다.
모든 문자열의 비트들을 뒤집는 과정을 반복하여 원하는 비트들로 이루어진 문자열의 집합과
동일한 문자열들의 집합을 만들 수 있는 지 구한다. 주어진 문자열들과 원하는 문자열들은 모두 서로 다르다.

해결 방법 : 목표 비트 문자열을 정렬한 다음, 앞에서부터 하나씩 뒤집은 것과 뒤집지 않은 것을
붙여가며 해당 문자열까지 정렬한 결과가 같은 지 확인한다.
같지 않다면 바로 탐색을 종료한다. 이 탐색으로 끝까지 간 것 중 뒤집은 횟수가 가장 적은 것을 고르면 된다.

주요 알고리즘 : 비트마스킹, 백트래킹, 정렬

출처 : GCJ 2014A A2번
*/

char ini[256][64], req[256][64], res[256][64], sti[256][64];
int resc;

void track(int n, int l, int p, int r) {
    if (l == p) {
        if (r < resc) resc = r;
        return;
    }
    else if (r >= resc) return;
    int ok = 1;
    for (int i = 0; i < n; i++) {
        res[i][p] = ini[i][p];
        res[i][p + 1] = '\0';
        strcpy(sti[i], res[i]);
    }
    qsort(sti, n, sizeof(char) * 64, strcmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) {
            if (sti[i][j] != req[i][j]) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) break;
    }
    if (ok) track(n, l, p + 1, r);

    ok = 1;
    for (int i = 0; i < n; i++) {
        res[i][p] = '1' - ini[i][p] + '0';
        res[i][p + 1] = '\0';
        strcpy(sti[i], res[i]);
    }
    qsort(sti, n, sizeof(char) * 64, strcmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) {
            if (sti[i][j] != req[i][j]) {
                ok = 0;
                break;
            }
        }
        if (ok == 0) break;
    }
    if (ok) track(n, l, p + 1, r + 1);
}

int main(void) {
    int t, n, l;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++) {
            scanf("%s", ini[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", req[i]);
        }
        qsort(req, n, sizeof(char) * 64, strcmp);

        resc = INF;
        track(n, l, 0, 0);
        if (resc == INF) printf("Case #%d: NOT POSSIBLE\n", tt);
        else printf("Case #%d: %d\n", tt, resc);
    }
    return 0;
}