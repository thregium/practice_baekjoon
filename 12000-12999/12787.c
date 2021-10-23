#include <stdio.h>

/*
문제 : 64비트 부호 없는 정수를 IP 형태로 바꾸거나 64비트 IP를 정수 형태로 바꾼다.

해결 방법 : IP는 각각을 입력받은 다음, 앞쪽부터 더해서 곱해나가면 되고, 정수는 입력받은 다음, 뒤쪽부터 잘라나가면 된다.
64비트 '부호 없는' 정수를 입출력해야 함에 유의한다.

주요 알고리즘 : 구현, 수학

출처 : 인하대 2016 J번
*/

unsigned long long x[8];

int main(void) {
    int t, m;
    unsigned long long n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &m);
        if (m == 1) {
            scanf("%llu.%llu.%llu.%llu.%llu.%llu.%llu.%llu", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7]);
            n = 0;
            for (int i = 0; i < 8; i++) {
                n <<= 8;
                n += x[i];
            }
            printf("%llu\n", n);
        }
        else if (m == 2) {
            scanf("%llu", &n);
            for (int i = 7; i >= 0; i--) {
                x[i] = (n & 255);
                n >>= 8;
            }
            printf("%llu.%llu.%llu.%llu.%llu.%llu.%llu.%llu\n", x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7]);
        }
        else return 1;

    }
    return 0;
}