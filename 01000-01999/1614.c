#include <stdio.h>

/*
문제 : 5개의 손가락으로 번갈아가며 수를 셀 때, N번째 손가락을 M번 이하로 사용하여 셀 수 있는
가장 큰 수를 구한다.

해결 방법 : N의 값과 M의 홀짝성에 따라 경우를 나누어 해결한다.

주요 알고리즘 : 수학, 케이스 워크

출처 : SRM 390D2 1번
*/

int main(void) {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    if (n == 1) printf("%lld", m * 8);
    else if (n == 2) {
        if (m & 1) printf("%lld", m / 2 * 8 + 7);
        else printf("%lld", m / 2 * 8 + 1);
    }
    else if (n == 3) {
        if (m & 1) printf("%lld", m / 2 * 8 + 6);
        else printf("%lld", m / 2 * 8 + 2);
    }
    else if (n == 4) {
        if (m & 1) printf("%lld", m / 2 * 8 + 5);
        else printf("%lld", m / 2 * 8 + 3);
    }
    else if (n == 5) printf("%lld", m * 8 + 4);
    return 0;
}