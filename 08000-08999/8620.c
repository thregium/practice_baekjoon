#include <stdio.h>

/*
문제 : 'A'부터 'Z'까지의 알파벳이 쓰인 박스들에 대해 N(N <= 10^6)개의 기록이 주어진다.
처음에는 모든 박스가 비어있고, 각 기록마다 박스에 상품이 X(X <= 2000)개까지 추가되거나
감소된다. 이때, 기록에 언급된 박스의 이름과 상품 개수들을 사전순으로 출력한다.

해결 방법 : 박스의 개수는 최대 26개이므로 각 박스마다 상품의 개수를 계산해 나간 다음,
언급된 박스마다 상품의 개수와 박스의 이름을 출력하면 된다.

주요 알고리즘 : 구현

출처 : JPOI 2008 1-2번
*/

int box[26], chk[26];

int main(void) {
    int n, x;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &x);
        box[c - 'A'] += x;
        chk[c - 'A'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (chk[i]) {
            printf("%c %d\n", i + 'A', box[i]);
        }
    }
    return 0;
}