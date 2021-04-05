#include <stdio.h>

/*
문제 : a^b % 10의 값을 구한다. (a <= 100, b <= 1000000)

해결 방법 : a * b % n == (a % n) * (b % n) % n이다. 따라서 a * a % 10을 b회 반복하면 된다.

주요 알고리즘 : 수학, 정수론
*/

int main(void) {
    int t, a, b, s;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        s = a % 10;
        for(int j = 1; j < b; j++) s = (s * a) % 10;
        if(s == 0) printf("10\n");
        else printf("%d\n", s);
    }
    return 0;
}