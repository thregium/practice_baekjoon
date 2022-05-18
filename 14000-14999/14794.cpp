#include <stdio.h>
#include <map>
using namespace std;

/*
문제 : 길이 N(N <= 10^18)의 구간이 주어질 때, 이 구간에서 양 끝 또는 뽑은 점 가운데 양 옆으로
가장 가까운 2개의 지점 사이 거리가 가장 먼 구간의 가장 왼쪽 점을 뽑는 것을 반복한다.
이때, K번째로 뽑은 구간의 양 옆 가운데 거리가 먼 것과 가까운 것의 거리를 각각 구한다.

해결 방법 : 맵에 각 구간 크기별로 개수를 저장해가면서 가장 큰 구간부터 구간 크기를 확인해나가면 된다.
그러하다 구간 크기의 개수가 K가 되는 순간의 구간 크기를 확인하고 그때 나누어지는 구간을 찾으면 답이다.

주요 알고리즘 : 자료 구조, 맵, 시뮬레이션?

출처 : GCJ 2017Q C3번
*/

map<long long, long long> mp;

int main(void) {
    int t;
    long long n, k, x, sz;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld %lld", &n, &k);
        mp.insert({ n, 1 });
        x = 0;
        while (k > 0) {
            x = (--mp.end())->first;
            sz = (--mp.end())->second;
            k -= sz;
            if (x > 1) {
                if (mp.find(x >> 1) == mp.end()) mp.insert({ x >> 1, sz });
                else mp[x >> 1] += sz;
            }
            if (x > 2) {
                if (mp.find((x - 1) >> 1) == mp.end()) mp.insert({ (x - 1) >> 1, sz });
                else mp[(x - 1) >> 1] += sz;
            }
            mp.erase(x);
        }
        printf("Case #%d: %lld %lld\n", tt, x >> 1, (x - 1) >> 1);
        mp.clear();
    }
    return 0;
}