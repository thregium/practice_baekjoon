#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(void) {
    int t, k;
    long long x, y, res = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &x);
            pq.push(x);
        }
        res = 0;
        while (pq.size() > 1) {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            res += x + y;
            pq.push(x + y);
        }
        printf("%lld\n", res);
        while (!pq.empty()) pq.pop();
    }
    return 0;
}