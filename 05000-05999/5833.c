#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 1부터 N(N <= 12, N은 짝수)까지의 수로 만들어진 순열 가운데 (N * 3 / 2)개의 쌍에 대한 거리 합이 가장 작은
순열의 거리 합을 구한다.

해결 방법 : 백트래킹을 통해 순열을 만들면서 현재까지의 거리와 앞으로 필요한 최소 거리를 구한다. 앞으로 필요한 최소 거리와
현재까지의 거리의 합이 최댓값 이상이 되는 시점에 탐색을 종료한다.
앞으로 필요한 거리는 현재 한쪽만 연결된 간선들의 개수를 다음 순열로 넘어갈 때 마다 구하여 이전 값에서 더한다.
(해당 간선들은 계속 이어지기 때문에), 만약 간선이 연결되면 해당 값은 현재까지의 거리로 넘긴다.

주요 알고리즘 : 백트래킹, 휴리스틱

출처 : USACO 2013O B4번
*/

int vis[16], ed[16][3], perm[16], order[16][16], dist[16][16];
const int fact[13] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600 };
int best = INF, stt;

int cmp1(const void* a, const void* b) {
    int ai = dist[stt][*(int*)a];
    int bi = dist[stt][*(int*)b];
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void track(int n, int x, int r, int c, int p) {
    //n : N, x : 현재 시도하는 번호, r : 현재까지의 거리, c : 한쪽만 연결된 간선의 수, p : 앞으로 필요한 최소 거리
    if (x > n) {
        if (r < best) best = r;
        return;
    }
    if (r + p >= best) return; //빠른 정리를 통한 최적화

    int nxt, radd, cadd; //nxt : 선택한 다음 수, radd : 해당 수를 선택하여 추가되는 거리
    //cadd : 해당 수를 선택하여 추가되는 한쪽만 연결된 간선의 수(음수가 될 수도 있음)
    for (int i = 1; i <= n; i++) {
        nxt = order[perm[x - 1]][i];
        if (vis[nxt]) continue;
        vis[nxt] = x; //해당 위치의 번호를 추가
        perm[x] = nxt;
        radd = 0, cadd = 0;
        for (int j = 0; j < 3; j++) {
            radd += (vis[ed[nxt][j]] ? vis[nxt] - vis[ed[nxt][j]] : 0);
            cadd += (!vis[ed[nxt][j]]) * 2 - 1;
        }
        track(n, x + 1, r + radd, c + cadd, p + c + cadd - radd);
        vis[nxt] = 0;
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("haywire.in", "r");
        fo = fopen("haywire.out", "w");
    }
    srand((unsigned)time(NULL));

    int n, pn, th, tr;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
            order[i][j] = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &ed[i][0], &ed[i][1], &ed[i][2]);
        for (int j = 0; j < 3; j++) {
            dist[i][ed[i][j]] = 1;
            dist[ed[i][j]][i] = 1;
        }
    }
    
    /*
    //무작위화 접근?
    for (int i = 0; i < 2000; i++) {
        //srand(rand() * 22 + 237 + i + rand() * (i + 39));
        pn = ((unsigned)rand() * 32768 + (unsigned)rand()) % fact[n];
        //if (i % 100 == 0) printf("%d\n", pn);
        for (int j = n; j > 0; j--) {
            pn %= fact[j];
            th = pn / fact[j - 1] + 1;
            for (int k = 1; k <= n; k++) {
                if (vis[k]) continue;
                if (--th == 0) {
                    vis[k] = 1;
                    perm[j] = k;
                    break;
                }
            }
        }

        tr = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 3; k++) {
                if (perm[ed[j][k]] > perm[j]) tr += perm[ed[j][k]] - perm[j];
            }
        }
        if (tr < best) best = tr;

        for (int j = 1; j <= n; j++) {
            vis[j] = 0;
            perm[j] = 0;
        }
    }

    //거리 정렬을 통한 우선순위?
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        stt = i;
        qsort(&order[i][1], n, sizeof(int), cmp1);
    }
    */

    track(n, 1, 0, 0, 0);
    printf("%d", best);
    return 0;
}