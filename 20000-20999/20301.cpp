#include <stdio.h>
#include <deque>
using namespace std;

/*
문제 : N, K, M(N, K, M <= 5000)이 주어질 때, (N, K) 요세푸스 순열에서 M번마다 방향을 반전한 것의 결과를 출력한다.

해결 방법 : 요세푸스 순열처럼 하되, 큐 대신 덱을 이용햐어 M번마다 방향을 반전시키면 된다.

주요 알고리즘 : 자료 구조, 덱

출처 : 서강대 2020M C번
*/

deque<int> dq;

int main(void) {
    int n, k, m, cnt = 0, dir = 0;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    while (dq.size()) {
        if (dir == 0) {
            for (int i = 1; i < k; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            printf("%d\n", dq.front());
            dq.pop_front();
            cnt++;
            if (cnt == m) {
                cnt = 0;
                dir = 1;
            }
        }
        else {
            for (int i = 1; i < k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            printf("%d\n", dq.back());
            dq.pop_back();
            cnt++;
            if (cnt == m) {
                cnt = 0;
                dir = 0;
            }
        }
    }
    return 0;
}