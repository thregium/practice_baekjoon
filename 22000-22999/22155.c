#include <stdio.h>

/*
문제 : N(N <= 121)개의 문제에 대해 분기와 조건 명령어의 수(<= 10, 음이 아닌 정수)가 각각 주어질 때,
단순한 문제인지 여부를 구한다. 단순한 문제는 분기가 2개, 조건문이 1개 이하거나 분기가 1개, 조건문이 2개 이하인 문제이다.

해결 방법 : 문제에 주어진 조건을 확인해서 맞는지 여부를 출력하면 된다.

주요 알고리즘 : 구현

출처 : RCC 2012Q2 A번
*/

int main(void) {
    int n, in, fn;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &in, &fn);
        if ((in <= 2 && fn <= 1) || (in <= 1 && fn <= 2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}