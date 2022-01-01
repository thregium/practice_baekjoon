#include <stdio.h>

/*
문제 : N!의 끝에 붙는 0의 개수가 M(1 <= M <= 10^8)개인 가장 작은 N을 구한다.

해결 방법 : M의 크기가 약간 크므로 M을 6개 단위(N 기준 25 단위)로 계산해 나간다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int m, c = 0, l = 0;
    scanf("%d", &m);
    for (int i = 1;; i++) {
        l = c;
        c += 6;
        for (int j = i; j % 5 == 0; j /= 5) c++;
        if (m <= l + 4) {
            printf("%d", (i - 1) * 25 + (m - l) * 5);
            break;
        }
        else if (m < c) {
            printf("-1");
            break;
        }
    }
    return 0;
}