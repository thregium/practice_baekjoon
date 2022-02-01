#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 10^6)개의 구간[S, E](1 <= S <= E <= 10^9)이 주어질 때, 각 구간에 속하는 점이
최소 1개 이상씩은 있도록 점들을 배치하려고 한다. 이때, 배치해야 하는 점의 최소 개수를 구한다.

해결 방법 : 각 구간을 끝점 순서대로 정렬한 다음, 아직 점을 배치하지 않은
가장 끝점이 빠른 구간의 끝점마다 점을 배치한다. 점을 배치하지 않은 구간인지 여부는 우선순위 큐를 통해
시작점이 빠른 순서로 정렬하고 시작점이 점을 배치한 끝점 이전인 모든 구간에 대해 점을 배치하였음을
확인하면 된다. 이를 반복하며 모든 구간에 점을 배치한 다음 점의 개수를 세면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐, 정렬

출처 : Brasil 2011 F번
*/

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
char vis[1048576];
int focus[1048576][2];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r, last;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2011\\foco.in", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &focus[i][0], &focus[i][1]);
        }
        qsort(focus, n, sizeof(int) * 2, cmp1);
        for (int i = 0; i < n; i++) {
            pq.push(pair<int, int>(focus[i][0], i));
        }
        r = 0, last = -1;
        while (pq.size()) {
            for (int i = last + 1; i < n; i++) {
                if (vis[i]) continue;
                while (pq.size() && pq.top().first <= focus[i][1]) {
                    vis[pq.top().second] = 1;
                    pq.pop();
                }
                last = i;
                r++;
                break;
            }
        }
        printf("%d\n", r);
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }
    }
    return 0;
}