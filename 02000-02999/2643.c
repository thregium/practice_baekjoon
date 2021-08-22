#include <stdio.h>

/*
문제 : N(N <= 100)개의 직사각형이 있다. 이때, 이 직사각형을 높이와 너비가 단조 감소하는 순서로 쌓을 때,
쌓을 수 있는 직사각형의 최대 개수를 구한다. 직사각형의 높이와 너비는 1000 이하며 높이와 너비가 모두 같은 경우(또는 90도 돌려서 같은 경우)는 없다.
또한, 직사각형을 90도 돌려서 쌓는 것도 가능하다.

해결 방법 : 모든 직사각형의 쌍에 대해 한쪽의 높이와 너비가 모두 다른 쪽 이하인 경우 작은 쪽으로 향하는 간선을 추가한다.
높이와 너비가 같은 경우가 없기 때문에 이 그래프는 항상 DAG가 된다. 따라서, 위상 정렬을 통해 가장 많이 쌓을 수 있는 이전 정점의 값을
매번 더해가며 가장 많이 쌓을 수 있는 경우를 찾으면 된다.

주요 알고리즘 : 그래프 이론, 위상 정렬

출처 : 정올 1999 초3번
*/

int papers[128][2], revs[128][128], eds[128][128], best[128], ins[128], vis[128];

int main(void) {
    int n, r = 0, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &papers[i][0], &papers[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        best[i] = 1;
        for (int j = i + 1; j <= n; j++) {
            if ((papers[i][0] == papers[j][0] && papers[i][1] == papers[j][1]) || (papers[i][1] == papers[j][0] && papers[i][0] == papers[j][1])) {
                best[i]++;
            }
            else if ((papers[i][0] <= papers[j][0] && papers[i][1] <= papers[j][1]) || (papers[i][1] <= papers[j][0] && papers[i][0] <= papers[j][1])) {
                eds[j][++eds[j][0]] = i;
                revs[i][++revs[i][0]] = j;
                ins[i]++;
            }
            else if ((papers[i][0] >= papers[j][0] && papers[i][1] >= papers[j][1]) || (papers[i][1] >= papers[j][0] && papers[i][0] >= papers[j][1])) {
                eds[i][++eds[i][0]] = j;
                revs[j][++revs[j][0]] = i;
                ins[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j] || ins[j]) continue;
            vis[j] = 1;
            t = 0;
            for (int k = 1; k <= revs[j][0]; k++) {
                if (best[revs[j][k]] > t) t = best[revs[j][k]];
            }
            best[j] += t;
            for (int k = 1; k <= eds[j][0]; k++) {
                ins[eds[j][k]]--;
            }
            if (best[j] > r) r = best[j];
            break;
        }
    }
    printf("%d", r);
    return 0;
}