#include <stdio.h>

/*
문제 : 두 명이 N(N <= 10000)개의 카드를 각각 갖고 위에서부터 카드를 한 장씩 뒤집어 나간다.
이때, 뒤집은 카드 가운데 더 큰 수가 쓰인 카드를 가진 사람이 두 카드를 모두 갖는다. 같다면 서로 원래대로 돌려받는다.
이때, 두 명이 갖는 카드의 수의 합을 각각 구한다.

해결 방법 : N번 카드를 입력받으며 어느 쪽이 더 큰지 확인하고, 각 사람의 카드 합을 계산해 나가면 된다.

주요 알고리즘 : 구현

출처 : JOI 2006예 1번
*/

int main(void) {
    int n, a, b, ar = 0, br = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) ar += a + b;
        else if (a < b) br += a + b;
        else {
            ar += a;
            br += b;
        }
    }
    printf("%d %d", ar, br);
    return 0;
}