#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 100000)개의 문제에 대해 자연수로 된 카테고리(<= 10^9)가 각 문제마다 주어지면 맨 앞에서부터 문제를 풀 때,
모든 카테고리의 문제를 적어도 하나는 풀기 위해 풀어야 하는 문제 수를 구한다.

해결 방법 : 이는 다르게 보면 맨 앞에서부터 볼 때 새로운 카테고리인 문제 가운데 맨 뒤에 있는 문제의 번호와 같다.
이는 해시셋을 통해 간단히 구할 수 있다.

주요 알고리즘 : 자료 구조, 해시셋

출처 : Tunisia 2013 A번
*/

unordered_set<int> u;

int main(void) {
    int t, n, x, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        u.clear();
        r = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (u.find(x) != u.end()) continue;
            r = i;
            u.insert(x);
        }
        if (r == 0) return 1;
        printf("Case %d: %d\n", tt, r);
    }
    return 0;
}