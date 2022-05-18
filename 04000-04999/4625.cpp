#include <stdio.h>
#include <queue>
using namespace std;

/*
문제 : N(3 <= N <= 12)가지 색의 필요한 물감 양(<= 1000)과 회색의 필요한 물감 양 G(G<= 1000)이 주어진다.
회색 물감은 아무 물감이나 서로 다른 세 가지를 1씩 섞으면 1만큼 나온다고 하면, 필요한 물감 양을 채우기 위해
사야 하는 물감 세트의 수를 구한다. 물감 세트는 50 단위로 N가지 물감이 들어있다.

해결 방법 : 우선순위 큐를 이용해 가장 많은 3개의 색이 남는다면 3개의 색으로 회색을 1개 만들고,
회색이 필요하지만 남는 색이 없거나 색이 음수개만큼 있는 경우 물감을 보충하는 것을 반복하여
조건을 만족할 때 까지 물감을 보충한 횟수를 세면 된다. 처음 물감의 양은 -필요량과 같다.

주요 알고리즘 : 그리디 알고리즘, 우선순위 큐

출처 : MidC 2005 F번
*/

int a[16];
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(void) {
    int n, g, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            pq.push(-a[i]);
            pq2.push(-a[i]);
        }
        scanf("%d", &g);
        r = 0;
        while (g > 0 || pq2.top() < 0) {
            if (pq2.top() < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] = pq.top();
                    pq.pop();
                    pq2.pop();
                }
                for (int i = 0; i < n; i++) {
                    pq.push(a[i] + 50);
                    pq2.push(a[i] + 50);
                }
                r++;
            }
            else {
                for (int i = 0; i < 3; i++) {
                    a[i] = pq.top();
                    pq.pop();
                    pq2.pop();
                }
                if (a[2] <= 0) {
                    for (int i = 3; i < n; i++) {
                        a[i] = pq.top();
                        pq.pop();
                        pq2.pop();
                    }
                    for (int i = 0; i < n; i++) {
                        pq.push(a[i] + 50);
                        pq2.push(a[i] + 50);
                    }
                    r++;
                }
                else {
                    for (int i = 0; i < 3; i++) {
                        pq.push(a[i] - 1);
                        pq2.push(a[i] - 1);
                    }
                    g--;
                }
            }
        }
        printf("%d\n", r);
        while (pq.size()) pq.pop();
        while (pq2.size()) pq2.pop();
    }
    return 0;
}