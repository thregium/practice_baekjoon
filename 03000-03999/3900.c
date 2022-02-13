#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 정점으로 이루어진 가중치(<= 10000) 그래프가 있다. 이 그래프의 스패닝 트리 가운데
가장 가중치가 큰 간선과 가장 작은 간선의 차이가 가장 작은 스패닝 트리의 가중치 차이를 구한다.
스패닝 트리를 만들 수 없는 경우 -1을 출력한다.

해결 방법 : 그래프의 모든 간선을 크기 순으로 정렬한 다음, 하한을 고정하고 MST를 만들어 나간다.
스패닝 트리가 만들어지는 지점의 가중치 차이를 확인하고 결괏값을 갱신한다.
이를 MST가 만들어지지 않을 때 까지 반복한다. MST가 만들어지지 않는다면 하한이 더 큰 경우
MST가 만들어질 수 없으므로 탐색을 종료할 수 있다.
이 과정에서 가중치 차이가 가장 작은 것의 그 값을 구하고 답을 출력하면 된다.

주요 알고리즘 : 그래프 이론, MST, 투 포인터

출처 : Tokyo 2007 F번
*/

int ed[5120][3], g[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, m, r, e, c;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &ed[i][1], &ed[i][2], &ed[i][0]);
        }
        qsort(ed, m, sizeof(int) * 3, cmp1);
        r = 103000;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) g[j] = 0;
            c = 0, e = i - 1;
            for (int j = i; j < m; j++) {
                e = j;
                if (find(ed[j][1]) != find(ed[j][2])) {
                    uni(ed[j][1], ed[j][2]);
                    c++;
                }
                if (c == n - 1) {
                    if (ed[j][0] - ed[i][0] < r) r = ed[j][0] - ed[i][0];
                    break;
                }
            }
            if (e == m - 1 && c < n - 1) break;
        }
        printf("%d\n", r == 103000 ? -1 : r);
    }
    return 0;
}