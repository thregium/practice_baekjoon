#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 100)마리의 소들이 있다. M마리의 소들은 주어지는 순서대로 배치되어야 하고, K마리의 소들은 주어지는
위치에 배치되어야 한다. 각 소들을 배치하는 방법이 반드시 있다고 할 때, 1번 소가 있을 수 있는 가장 앞쪽 위치를 구한다.

해결 방법 : 먼저 주어진 소가 K마리 가운데 하나인지 확인한다. 그렇다면 해당하는 위치에 배치하면 된다.
M마리 가운데 하나라면 M마리 가운데 1번 소 이전의 위치가 확정된 가장 뒤쪽 소부터 확인하며 아직 빈 곳에 M마리의
소들을 배치하며 1번 소가 나오는 위치를 찾으면 된다.
둘 다 아닌 경우에는 M마리의 소들을 역순으로 확인하며 배치할 수 있는 가장 뒤쪽에 소들을 배치해 놓은 다음,
아직 비어있는 가장 앞쪽 칸에 1번 소를 배치하면 된다.

주요 알고리즘 : 그리디 알고리즘, 구현, 케이스 워크

출처 : USACO 2018O B2번
*/

int order[128], rel[128][2], relchk[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("milkorder.in", "r");
        fo = fopen("milkorder.out", "w");
    }
    int n, m, k, c, p, inc = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &rel[i][0]);
        if (rel[i][0] == 1) inc = i;
        relchk[rel[i][0]] = i;
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &c, &p);
        order[p] = c;
        if (relchk[c]) rel[relchk[c]][1] = p;
        if (c == 1) {
            printf("%d", order[c]); //K마리 가운데 하나인 경우
            return 0;
        }
    }

    if (inc) {
        while (rel[inc][1] == 0 && inc > 0) inc--;
        p = rel[inc][1];
        inc++;
        while (1) {
            while (order[++p]);
            if (rel[inc][0] == 1) {
                printf("%d", p); //M마리 가운데 하나인 경우
                return 0;
            }
            inc++;
        }
    }
    else {
        c = m;
        for (int i = n; i > 0 && c > 0; i--) {
            while (c > 0 && rel[c][1]) {
                i = rel[c--][1];
            }
            while (i > 0 && order[i]) i--;
            if (c <= 0 || i <= 0) break;
            order[i] = rel[c][0];
            c--;
        }
        for (int i = 1; i <= n; i++) {
            if (order[i] == 0) {
                printf("%d", i); //둘 다 아닌 경우
                return 0;
            }
        }
    }

    return 0;
}