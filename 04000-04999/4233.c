#include <stdio.h>

/*
문제 : 자연수 P와 A(P, A <= 10^9)가 주어질 때, 이 자연수가 가짜 소수인지 구한다. A^P % P = A인 경우이다.

해결 방법 : 먼저 주어진 자연수가 진짜 소수인지 구하고, 그러한 경우 가짜 소수가 아니다.
진짜 소수가 아니라면 분할 거듭제곱으로 문제의 식을 확인한다. 맞다면 가짜 소수이고, 아니라면 가짜 소수가 아니다.

주요 알고리즘 : 수학, 정수론, 페르마의 소정리, 소수 판정, 분할 거듭제곱

출처 : Waterloo 070923 C번
*/

int powe(int x, int y, int m) {
    if (y == 1) return x;
    int h = powe(x, y >> 1, m);
    h = ((long long)h * h) % m;
    if (y & 1) return ((long long)h * x) % m;
    else return h;
}

int main(void) {
    int p, a, t;
    while (1) {
        scanf("%d %d", &p, &a);
        if (a == 0) break;
        t = 1;
        for (int i = 2; i * i <= p; i++) {
            if (p % i == 0) {
                t = 0;
                break;
            }
        }
        if (t) {
            printf("no\n");
            continue;
        }
        if (powe(a, p, p) == a) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}