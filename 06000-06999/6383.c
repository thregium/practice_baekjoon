#include <stdio.h>

/*
문제 : 1000 이하의 번호를 갖는 각 노드들의 연결 상태가 주어진다. 주어진 노드들은 전부 연결된 상태인데,
한 노드를 제거해서 연결 요소가 여러개로 나뉘는 경우를 번호 순으로 찾고 몇 개로 나뉘는지 구한다.

해결 방법 : 모든 번호에 대해 번호 순으로 등장한 노드라면 해당 노드를 제거한 채로 플러드필을 통해
연결 요소의 개수를 찾는다. 만약 2개 이상인 경우 해당하는 값을 출력한다.

주요 알고리즘 : 그래프 이론, 브루트 포스, 플러드필

출처 : GNY 2000 H번
*/

int node[1024], vis[1024], edge[1024][1024];

void dfs(int x, int spf) {
    vis[x] = 1;
    for (int i = 1; i <= edge[x][0]; i++) {
        if (vis[edge[x][i]] || edge[x][i] == spf) continue;
        dfs(edge[x][i], spf);
    }
}

int main(void) {
    int a, b, subs, cnt;
    for (int tt = 1;; tt++) {
        cnt = 0;
        while (1) {
            scanf("%d", &a);
            if (a == 0) break;
            scanf("%d", &b);
            node[a] = 1;
            node[b] = 1;
            edge[a][++edge[a][0]] = b;
            edge[b][++edge[b][0]] = a;
            cnt++;
        }
        if (cnt == 0) break;

        printf("Network #%d\n", tt);
        cnt = 0;
        for (int i = 1; i <= 1000; i++) {
            if (!node[i]) continue;
            subs = 0;
            for (int j = 1; j <= 1000; j++) {
                if (node[j] && !vis[j] && j != i) {
                    dfs(j, i);
                    subs++;
                }
            }
            if (subs > 1) {
                printf("  SPF node %d leaves %d subnets\n", i, subs);
                cnt++;
            }
            for (int j = 1; j <= 1000; j++) vis[j] = 0;
        }
        if (cnt == 0) printf("  No SPF nodes\n");
        printf("\n");
        for (int i = 1; i <= 1000; i++) {
            node[i] = 0;
            edge[i][0] = 0;
        }
    }
    return 0;
}