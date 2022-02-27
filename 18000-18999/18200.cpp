#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 20000)명의 사람들이 K(K <= 20000)대의 5인승 자동차를 이용해 경기장까지 가려고 한다.
각 사람은 운전해서 경기장까지 가는 데 T_i(T_i <= 10^6)만큼의 시간이 걸린다.
경기장까지 모든 사람을 데려다 주기 위해 필요한 최소 시간을 구한다.
모든 차가 경기장에 갈 필요는 없다.

해결 방법 : 우선 차가 K대 뿐이므로 많아야 가장 빨리 운전 가능한 K명의 사람들만
운전하면 되는 것을 알 수 있다. 경기장에 도달하는 순서대로 운전자들을 포함한 N명이 전부 도달하였는 지
확인한 다음 아직 도달하지 않았다면 그 운전자를 다시 돌려보낸다.
최대 5000번 이를 반복하면 모든 사람들을 데려다 주게 되고, 그때의 소요 시간을 찾으면 답이 된다.
이미 돌려 보냈던 운전자들도 돌려 보내지 않았다면 경기장에 있을 것이므로 생각하지 않아도 된다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : MidC 2019 C번
*/

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
int cartime[20480], cnt[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, p, x;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cartime[i]);
    }
    qsort(cartime, n, sizeof(int), cmp1);
    for (int i = 0; i < n && i < k; i++) {
        pq.push(make_pair(cartime[i], i));
    }
    p = n;
    while (n > 0) {
        r = pq.top().first;
        x = pq.top().second;
        pq.pop();
        pq.push(make_pair(r + cartime[x] * 2, x));
        if (cnt[x] == 0) n -= 5;
        else n -= 4;
        cnt[x]++;
    }
    printf("%lld", r);
    return 0;
}