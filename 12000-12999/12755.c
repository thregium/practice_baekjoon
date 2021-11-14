#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^8)이 주어질 때, 모든 자연수를 오름차순으로 이어 적는다면 N번째 숫자는 무엇인지 구한다.

해결 방법 : N번째까지 숫자들을 직접 확인해가며 찾으면 된다. N번째가 되기 전까지 자릿수 단위로만
수들을 더해나가 속도를 좀 더 빠르게 할 수도 있다.

주요 알고리즘 : 브루트 포스, 수학

출처 : 전북대 2016 A번
*/

int a[16];

int digitcount(int x) {
    if (x < 10) return 1;
    else if (x < 100) return 2;
    else if (x < 1000) return 3;
    else if (x < 10000) return 4;
    else if (x < 100000) return 5;
    else if (x < 1000000) return 6;
    else if (x < 10000000) return 7;
    else if (x < 100000000) return 8;
    else if (x < 1000000000) return 9;
    else return 10;
}

int main(void) {
    int n, c = 0, r;
    scanf("%d", &n);
    for (int i = 1; n > c; i++) {
        c += digitcount(i);
        if (c >= n) {
            c -= digitcount(i);
            r = i;
            for (int j = 0; r; j++) {
                a[digitcount(i) - j] = r % 10;
                r /= 10;
            }
            printf("%d", a[n - c]);
            break;
        }
    }
    return 0;
}