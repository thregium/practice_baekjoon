#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 300000)개의 정점으로 이루어진 트리가 주어진다. 루트 정점에서 빵을 Q(Q <= 300000)개
떨어뜨리는 동안 빵이 떨어지는 정점을 각각 구한다. 각 정점은 1번째 자식 정점으로 연결되며,
빵이 떨어질 때 마다 연결되는 정점을 다음 자식 정점으로 바꾸어 나간다.
자식 정점이 없는 정점에 최종적으로 빵이 떨어지게 된다.

해결 방법 : 각 정점에 i번째로 빵이 떨어질 때, i % (자식 정점 수) + 1번째 자식 정점으로 빵이
내려간다. 이를 반복하면 답을 구할 수 있지만, 연속해서 자식 수가 1인 정점이 나오는 경우
최악의 경우에는 O(N^2)의 시간이 소요된다. 하지만 이 경우에는 압축을 해도 상관 없기 때문에
간선들을 1개로 압축해주면 O(NlogN)의 시간에 답을 구할 수 있다.

주요 알고리즘 : 수학, 정수론, 트리

출처 : CTU 2021 P번
*/

vector<int> chd[327680];

int compress(int x) {
    if (chd[x].size() == 1) return chd[x][0] = compress(chd[x][0]);
    else return x;
}

int main(void) {
    int n, q, x, t, s;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        chd[x].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        compress(i);
    }
    for (int i = 0; i < q; i++) {
        x = 0, t = i, s;
        while (chd[x].size()) {
            s = chd[x].size();
            x = chd[x][t % s];
            t /= s;
        }
        printf("%d\n", x);
    }
    return 0;
}