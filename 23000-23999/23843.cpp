#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 10000)개의 2^i 꼴의 수가 주어질 때, M(M <= 10)개로 나누어 담아 합이 가장 큰 것의 합이 가장 작도록 할 때,
그 합을 구한다.

해결 방법 : 가장 큰 수부터 차례로 지금까지 중 가장 작은 곳에 담아가면 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : 인천대 2021 C번
*/

int t[10240];
priority_queue<int, vector<int>, greater<int>> q;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, n, sizeof(int), cmp1);
    for (int i = 0; i < m; i++) q.push(0);
    for (int i = 0; i < n; i++) {
        x = q.top();
        q.pop();
        q.push(x + t[i]);
    }
    for (int i = 1; i < m; i++) q.pop();
    printf("%d", q.top());
    return 0;
}
