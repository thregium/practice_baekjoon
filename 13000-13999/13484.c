#include <stdio.h>

/*
문제 : N(N <= 100)개월간의 인터넷 사용량과 인터넷 요금제의 용량 X가 주어진다면, 다음 달에 쓸 수 있는 용량을 구한다.
쓰지 않은 용량은 전부 다음 달로 이월된다.

해결 방법 : 쓰지 않은 용량은 전부 다음달로 이월되기 때문에 매 달마다 쓸 수 있는 용량과의 차이를 구해 더한 다음
다음 달에 원래 쓸 수 있는 X를 더하면 된다.

주요 알고리즘 : 구현

출처 : COCI 16/17#1 1번
*/

int main(void) {
    int x, n, p, s = 0;
    scanf("%d%d", &x, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        s += x - p;
    }
    printf("%d", s + x);
    return 0;
}
