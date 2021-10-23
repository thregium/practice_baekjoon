#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : 일직선상으로 된 길에 N(N <= 10000)개의 주유소가 있다. 길의 길이는 10^6 이하고, 1만큼 갈 때 마다 기름이 1씩 필요하다.
길의 끝까지 가기 위해 필요한 최소 주유 횟수를 구한다. 도착할 수 없다면 -1을 출력한다.
각 주유소에는 기름이 각각의 고유한 양 만큼만 있다. 처음 있는 기름의 양은 10^6 이하고, 각 주유소에 있는 기름의 양은 100 이하다.

해결 방법 : 매번 현재 갈 수 있는 주유소 가운데 가장 많은 기름을 넣을 수 있는 곳에서 주유하면 된다.
주유로 인해 더 갈 수 있어지면 그 곳까지 포함하며 가장 많은 기름을 넣을 수 있는 곳을 찾는다.
이는 우선순위 큐를 이용해 빠르게 구할 수 있다. 현재 갈 수 있는 위치까지의 주유소의 기름 양을 우선순위 큐에 넣고
가장 큰 값을 꺼내오며 갈 수 있는 위치를 업데이트 하는 방식이다.
만약 도달할 수 있는 모든 주유소에서 기름을 넣었음에도 도착할 수 없다면 도착이 불가능한 것이므로 -1을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐
*/

int oil[10240][2];
priority_queue<int> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, d, o, p = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &oil[i][0], &oil[i][1]);
    }
    scanf("%d %d", &d, &o);
    qsort(oil, n, sizeof(int) * 2, cmp1);
    while (p < n && oil[p][0] <= o) {
        pq.push(oil[p][1]);
        p++;
    }
    while (o < d) {
        while (p < n && oil[p][0] <= o) {
            pq.push(oil[p][1]);
            p++;
        }
        if (pq.empty()) break;
        o += pq.top();
        pq.pop();
        r++;
    }
    if (o < d) printf("-1");
    else printf("%d", r);
    return 0;
}