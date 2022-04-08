#include <stdio.h>

/*
문제 : N(N <= 300)개 나라의 금, 은, 동메달 획득 개수(<= 999)가 구할 때, 1위인 국가를 구한다.
금->은->동메달이 많은 순으로 순위가 높고, 단독 1위인 국가가 있다.

해결 방법 : 금, 은, 동을 각각 1000000, 1000, 1 점수로 환산한 후 점수가 가장 높은 국가를 찾아
갱신해 나가면 된다. 입력에 주의한다.

주요 알고리즘 : 구현, 문자열

출처 : TOPC 2021 A번
*/

char buff[3145728], res[3145728];

int main(void) {
    int n, g, s, b, best = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d ", &g, &s, &b);
        fgets(buff, 3145728, stdin);
        if (g * 1000000 + s * 1000 + b > best) {
            best = g * 1000000 + s * 1000 + b;
            strcpy(res, buff);
        }
    }
    printf("%s", res);
    return 0;
}