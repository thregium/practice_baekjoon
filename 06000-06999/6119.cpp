#include <stdio.h>
#include <deque>
using namespace std;

/*
문제 : 빈 배열이 있다. S(S <= 100000)개의 연산 후 배열의 상태를 출력한다.
A L - 왼쪽에 새 수를 넣는다.
A R - 오른쪽에 새 수를 넣는다.
D L X - 왼쪽에서 X개의 수를 제거한다.
D R X - 오른쪽에서 X개의 수를 제거한다.
수를 넣을 때에는 1부터 차례로 올라간다.

해결 방법 : 덱을 이용하면 된다. A는 push연산, D는 pop연산(K회 반복)이다.

주요 알고리즘 : 자료 구조, 덱

출처 : USACO 2009O S2번
*/

deque<int> dq;

int main(void) {
    int s, x = 1, k;
    char ad, lr;
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
        scanf(" %c %c", &ad, &lr);
        if (ad == 'A') {
            if (lr == 'L') dq.push_front(x++);
            else dq.push_back(x++);
        }
        else {
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                if (lr == 'L') dq.pop_front();
                else dq.pop_back();
            }
        }
    }
    for (int i : dq) {
        printf("%d\n", i);
    }
    return 0;
}