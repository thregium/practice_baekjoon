#include <stdio.h>

/*
문제 : +60분, +10분, -10분, +1분, -1분 버튼을 최소한으로 눌러 N(N <= 10^7)분을 맞추는 방법을 찾는다.
횟수가 같은 경우 사전순으로 빠른 것을 우선한다.

해결 방법 : 60분마다 반복됨을 이용하면 각 부분의 경계를 확인하여 답을 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 수학

출처 : 정올 2020_1 초2번
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n % 60 >= 36) {
            printf("%d 0 %d ", n / 60 + 1, (60 - n % 60 + 4) / 10);
            if (n % 10 < 5) printf("%d 0\n", n % 10);
            else printf("0 %d\n", 10 - n % 10);
        }
        else {
            printf("%d %d 0 ", n / 60, (n % 60 + 4) / 10);
            if (n % 10 <= 5) printf("%d 0\n", n % 10);
            else printf("0 %d\n", 10 - n % 10);
        }
    }
    return 0;
}