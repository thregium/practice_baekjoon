#include <stdio.h>
#include <stdlib.h>

/*
문제 : 0이 아니고 절댓값이 10^6 이하인 정수 Y가 주어질 때, Y를 근으로 갖는 이차방정식을 출력한다.
단, 모든 항의 계수는 0이어서는 안 되며, 10^6 이하의 절댓값이어야 한다.

해결 방법 : Y의 절댓값이 1이 아니라면 (1, -Y(- 1 or + 1), -abs(Y))의 계수를 갖는
이차방정식을 출력하면 된다. 일차항의 계수는 절댓값이 줄어드는 방향으로 1만큼 가야 한다.
Y의 절댓값이 1인 경우는 직접 처리하면 된다.

주요 알고리즘 : 수학, 구성적, 케이스 워크

출처 : OC 18/19_4 E번
*/

int main(void) {
    int t, y;
    long long r, a, b, c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &y);
        a = 1;
        b = -y;
        if (y > 0) b++;
        else b--;
        c = y;
        if (y > 0) c *= -1;
        if (y == 1) {
            a = 1, b = -2, c = 1;
        }
        else if (y == -1) {
            a = 1, b = 2, c = 1;
        }
        if (a == 0 || b == 0 || c == 0) return -1;
        if (llabs(a) > 1000000 || llabs(b) > 1000000 || llabs(c) > 1000000) return 1;
        else if (a * y * y + b * y + c != 0) return 2;
        printf("%lld %lld %lld\n", a, b, c);
    }
    return 0;
}
