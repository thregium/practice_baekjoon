#include <stdio.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : 길이 N(N <= 100000)의 수직선상에 절댓값 10000 이하의 자연수 a_i가 쓰여 있다. 양수가 쓰인 칸에는
1부터 a_i까지의 시간동안 한번에 하나씩 사람이 나온다. 음수가 쓰인 칸은 -a_i의 시간이 흐르면
움직일 수 없는 칸이 된다. 각 사람은 시간 1에 1칸씩 양 옆으로 움직일 수 있다면
0이 쓰인 칸으로 갈 수 있는 사람의 최대 인원수를 구한다.

해결 방법 : 각 칸에서 0인 칸으로 갈 수 있는 사람의 최대 인원수를 각각 구하고 그 칸의 인원수와 비교해
더 작은 값을 전부 더하면 답이 될 것이다. 최대 인원수는 우선순위 큐를 이용해 구할 수 있다.
0이 쓰인 칸에서부터 최대 인원수를 무한대로 둔 다음 우선순위 큐에 넣어둔다.
우선순위 큐는 인원수가 많은 순으로 정렬한다. 우선순위 큐에서 방문하지 않은 칸마다 양 옆의
최대 인원수를 구해서 갱신하고 다시 우선순위 큐에 넣는 것을 반복하여 모든 칸의 최대 인원수를 구할 수 있다.
최대 인원수는 현재 인원수 - 1과 -a_i(a_i가 음수인 경우) 중 더 작은 값이다.
처음의 최대 인원수는 0으로 초기화되어 있어야 한다.

주요 알고리즘 : 자료 구조, 우선순위 큐

출처 : JAG 2013S2 B번
*/

priority_queue<pair<int, int>> pq;
int a[103000], cap[103000], vis[103000];

int main(void) {
    int n, x, c, cc, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            pq.push(pair<int, int>(INF, i));
            cap[i] = INF;
        }
    }
    while (pq.size()) {
        c = pq.top().first;
        x = pq.top().second;
        pq.pop();
        if (vis[x]) continue;
        else vis[x] = 1;

        if (x - 1 >= 0 && !vis[x - 1]) {
            cc = c - 1;
            if (a[x - 1] < 0 && -a[x - 1] < cc) cc = -a[x - 1];
            if (cap[x - 1] < cc) {
                pq.push(pair<int, int>(cc, x - 1));
                cap[x - 1] = cc;
            }
        }
        if (x + 1 < n && !vis[x + 1]) {
            cc = c - 1;
            if (a[x + 1] < 0 && -a[x + 1] < cc) cc = -a[x + 1];
            if (cap[x + 1] < cc) {
                pq.push(pair<int, int>(cc, x + 1));
                cap[x + 1] = cc;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            c = a[i];
            if (cap[i] < a[i]) c = cap[i];
            r += c;
        }
    }
    printf("%d\n", r);
    return 0;
}