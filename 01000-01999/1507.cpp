#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : 모든 간선의 상호간의 거리가 주어질 때, 이 조건을 만족시키는 간선의 길이 합의 최솟값을 구한다.
그러한 간선 집합이 없다면 -1을 출력한다.

해결 방법 : 가장 짧은 거리부터 차례대로 살펴보며 최단거리를 확인한다. 만약 해당 두 정점 사이 거리가 주어진 거리와 같다면
간선을 추가하지 않고 넘어간다. 더 멀다면 간선을 추가하고 넘어간다. 더 짧은 경우는 모순이므로 -1을 출력한다.
최단거리는 다익스트라 등의 알고리즘을 이용한다.
이를 반복해 모든 정점에 대해 확인한 다음 결괏값을 구하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, 그리디 알고리즘
*/

int dists[512][3], tdist[32];
int dip = 0;
vector<pair<int, int>> road[32];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, d, p, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &d);
            if (i >= j) continue;
            dists[dip][0] = d;
            dists[dip][1] = i;
            dists[dip][2] = j;
            dip++;
        }
    }
    qsort(dists, dip, sizeof(int) * 3, cmp1);
    for (int i = 0; i < dip; i++) {
        for (int j = 0; j < n; j++) {
            tdist[j] = INF;
        }
        pq.push(pair<int, int>(0, dists[i][1]));
        while (pq.size()) {
            p = pq.top().second;
            d = pq.top().first;
            pq.pop();
            if (d >= tdist[p]) continue;
            tdist[p] = d;
            for (auto rd : road[p]) {
                pq.push(pair<int, int>(d + rd.first, rd.second));
            }
        }
        if (tdist[dists[i][2]] == dists[i][0]) continue;
        else if (tdist[dists[i][2]] < dists[i][0]) {
            printf("-1");
            return 0;
        }
        r += dists[i][0];
        road[dists[i][1]].push_back(pair<int, int>(dists[i][0], dists[i][2]));
        road[dists[i][2]].push_back(pair<int, int>(dists[i][0], dists[i][1]));
    }
    printf("%d", r);
    return 0;
}