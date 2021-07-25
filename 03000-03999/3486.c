#include <stdio.h>

/*
문제 : 두 자연수 A, B(A, B <= 10^8)가 주어질 때, A와 B의 자릿수를 뒤집은 두 수의 합을 뒤집은 값을 구한다.

해결 방법 : 어떠한 수를 뒤집기 위해서는 어떠한 수의 뒤에서부터 나머지 연산을 통해 자릿수를 알아낸 후,
10을 곱해가며 앞쪽 자릿수부터 차례로 채워나가면 된다. 나머지는 이 연산을 이용해 풀면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : CERC 1998 A번
*/

int rev(int n) {
    int r = 0;
    for (int i = n; i; i /= 10) {
        r *= 10;
        r += i % 10;
    }
    return r;
}

int main(void) {
    int t, a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", rev(rev(a) + rev(b)));
    }
    return 0;
}