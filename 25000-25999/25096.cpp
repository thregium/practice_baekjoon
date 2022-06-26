#include <stdio.h>
#include <deque>
using namespace std;

/*
문제 : N(N <= 100000)개의 자연수가 덱에 있다. 덱의 왼쪽과 오른쪽 가운데 한 개의 수를 빼내는 작업을
반복할 때 이전의 최댓값 이상인 수가 나오는 횟수의 최댓값을 구한다.

해결 방법 : 매번 양쪽 가운데 더 작은 쪽을 주면 이전의 최댓값 이상인 수열의 길이가 가장 길어진다.

주요 알고리즘 : 자료 구조, 덱, 그리디 알고리즘

출처 : GCJ 2022B A번
*/

deque<int> dq;

int main(void) {
    int t, n, x, h, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        dq.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            dq.push_back(x);
        }
        r = 0, h = 0;
        while (dq.size()) {
            if (dq.front() < dq.back()) {
                if (dq.front() >= h) {
                    h = dq.front();
                    r++;
                }
                dq.pop_front();
            }
            else {
                if (dq.back() >= h) {
                    h = dq.back();
                    r++;
                }
                dq.pop_back();
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}