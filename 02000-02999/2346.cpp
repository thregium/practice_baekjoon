#include <stdio.h>
#include <deque>
using namespace std;

/*
문제 : N(N <= 1000)개의 풍선이 있을 때, 이 풍선들을 1번부터 차례로 규칙에 맞게 터뜨린 순서를 구한다.
규칙은 풍선에 쓰인 수 X가 양수인 경우 시계방향으로 X번째, 음수인 경우 반시계방향으로 -X번째 풍선을 터뜨리는 것이다.
단, 이미 터진 풍선은 세지 않는다.

해결 방법 : 덱을 이용해 푸는 것이 가능하다. 시계방향으로 움질일 때에는 (X - 1)만큼 덱의 뒤로 앞에 있던 수들을 보내고,
반시계방향으로 움직일 때에는 -X만큼 덱의 앞으로 뒤에 있던 수들을 꺼내오면 된다.

주요 알고리즘 : 자료구조, 덱
*/

deque<pair<int, int>> dq;

int main(void) {
    int n, a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        dq.push_back(pair<int, int>(a, i));
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", dq.front().second);
        a = dq.front().first;
        dq.pop_front();
        if (i == n - 1) break;
        while (a > 1) {
            dq.push_back(dq.front());
            dq.pop_front();
            a--;
        }
        while (a < 0) {
            dq.push_front(dq.back());
            dq.pop_back();
            a++;
        }
    }
    return 0;
}