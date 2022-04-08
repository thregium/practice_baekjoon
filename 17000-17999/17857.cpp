#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(N <= 10000)명의 사람이 있다. 각 사람은 임의의 자연수(2 <=, <= 10^6)를 갖는다.
1번째 사람부터 시작해 그 사람의 자연수 번째인 사람을 제거하고 다음 사람부터 다시 이를 반복한다.
이때, 마지막으로 남는 사람의 번호를 구한다.

해결 방법 : 큐에 사람들을 넣고 번호의 횟수만큼 큐를 돌려가며 사람을 제거하는 과정을 시뮬레이션한다.
단, 이 과정에서 시간을 줄이기 위해 자연수에 모듈로를 하는 것이 좋다.

주요 알고리즘 : 자료 구조, 큐, 시뮬레이션

출처 : ECNA 2019 F번
*/

queue<pair<int, int>> q;

int main(void) {
    int n, k;
    pair<int, int> p;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        q.push({ i, k });
    }
    while (q.size() > 1) {
        k = q.front().second;
        k %= q.size();
        if (k == 0) k = q.size();
        for (int i = k - 1; i >= 0; i--) {
            p = q.front();
            q.pop();
            if (i > 0) q.push(p);
        }
    }
    printf("%d", q.front().first);
    return 0;
}