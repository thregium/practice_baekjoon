#include <stdio.h>

/*
문제 : 1 이상 1000 미만의 소숫점 4자리 값이 주어질 때, 이 값을 곱해서 원래 수의 맨 앞 자리 숫자를
맨 뒤로 옮긴 것과 같아지는 10^8 이하 자연수를 오름차순으로 출력한다.

해결 방법 : 10^8까지 모든 수에 대해 그렇게 되는 지 확인한다. 단, 제한시간이 짧고 실수 오차가 생길 수
있기 때문에 구현에 여러모로 주의해야 한다.

주요 알고리즘 : 브루트 포스, 케이스 워크

출처 : NCPC 2013 C번
*/

int get10(int x) {
    if (x >= 10000000) return 10000000;
    else if (x >= 1000000) return 1000000;
    else if (x >= 100000) return 100000;
    else if (x >= 10000) return 10000;
    else if (x >= 1000) return 1000;
    else if (x >= 100) return 100;
    else if (x >= 10) return 10;
    else return 1;
}

int main(void) {
    long long c, xt, r = 0;
    double x, y;
    scanf("%lf", &x);
    if (x + 0.00000001 - (int)x < 0.000005) {
        xt = (int)(x + 0.0000001);
        for (long long a = 1; a < 10000000; a++) {
            c = a * xt;
            if (c == 10 * (a % get10(a)) + a / get10(a)) {
                printf("%lld\n", a);
                r++;
            }
        }
        for (long long a = 10000000; a < 100000000; a++) {
            c = a * xt;
            if (c == 10 * (a % 10000000) + a / 10000000) {
                printf("%lld\n", a);
                r++;
            }
        }
    }
    else {
        for (long long a = 1; a < 100000000; a++) {
            y = a * x + 0.0000001;
            if (y - (long long)y >= 0.00005) continue;
            c = y;
            if (c == 10 * (a % get10(a)) + a / get10(a)) {
                printf("%lld\n", a);
                r++;
            }
        }
    }
    if (r == 0) printf("No solution");
    return 0;
}