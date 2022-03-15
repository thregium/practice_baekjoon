#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <queue>
#define INF 1234567890987654321
using namespace std;

/*
문제 : L(L <= 50)개의 자연수(<= 10^9)가 주어진다. 모든 자연수들을 양 옆의 주어진 자연수 사이의
서로 다른 두 수 안에 포함되는 구간의 개수를 기준으로 오름차순으로 정렬하고,
그 개수가 같은 경우 자연수의 오름차순으로 정렬하였을 때, 앞에서부터 N(N <= 100)개의 수를 구한다.

해결 방법 : 주어진 자연수들부터 자연수들을 pair로 구간 개수와 함께 묶어 우선순위 큐에 넣고
하나씩 꺼내나간다. 꺼낸 자연수의 앞뒤 자연수들을 아직 보지 않았다면 우선순위 큐에 다시 넣고
개수를 확인해 나간다. 단, 처음에 넣을 때, 양 옆 수의 차이가 2인 경우 사이에 있는 수는
구간 개수가 0이므로 미리 우선순위 큐에 넣어둬야 한다.

주요 알고리즘 : 그리디 알고리즘, 자료 구조, 우선순위 큐, 셋

출처 : SRM 438D1 1번
*/

int s[64];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
set<int> vis;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, n, x, t;
    scanf("%d", &l);
    for (int i = 1; i <= l; i++) {
        scanf("%d", &s[i]);
        pq.push(make_pair(0, s[i]));
        vis.insert(s[i]);
    }
    qsort(s, l + 1, sizeof(int), cmp1);
    if (s[1] != 1) {
        pq.push(make_pair(s[1] - 2, 1));
        vis.insert(1);
    }
    for (int i = 1; i < l; i++) {
        if (s[i] + 2 == s[i + 1]) {
            pq.push(make_pair(0, s[i] + 1));
            vis.insert(s[i] + 1);
        }
    }
    scanf("%d", &n);
    while (n--) {
        x = pq.top().second;
        printf("%d ", x);
        pq.pop();
        if (x - 1 > 0 && vis.find(x - 1) == vis.end()) {
            for (int i = 0; i < l; i++) {
                if (s[i] < x - 1 && x - 1 < s[i + 1]) {
                    pq.push(make_pair((long long)(s[i + 1] - (x - 1)) * ((x - 1) - s[i]) - 1, x - 1));
                    vis.insert(x - 1);
                    break;
                }
            }
        }
        if (vis.find(x + 1) == vis.end()) {
            t = 0;
            for (int i = 0; i < l; i++) {
                if (s[i] < x + 1 && x + 1 < s[i + 1]) {
                    pq.push(make_pair((long long)(s[i + 1] - (x + 1)) * ((x + 1) - s[i]) - 1, x + 1));
                    vis.insert(x + 1);
                    t = 1;
                    break;
                }
            }
            if (s[l] < x + 1) {
                vis.insert(x + 1);
                pq.push(make_pair(INF, x + 1));
            }
        }
    }
    return 0;
}