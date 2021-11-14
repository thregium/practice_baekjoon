#include <stdio.h>
#include <stdlib.h>
#define SEC 100000000

/*
문제 : N(N <= 10^6), 테스트 케이스 수 T(T <= 10), 시간 제한 L(L <= 10)이 주어질 때, 1초에 10^8회 연산이 가능하다면
주어진 시간 복잡도(O(N), O(N^2), O(N^3), O(2^N), O(N!))에 대해 시간 제한 내에 연산이 가능한지 구한다.
단, 상수는 1로 생각한다.

해결 방법 : N에 대한 시간 복잡도의 식을 계산한 후 T를 곱한 값이 10^8 * L 이하인 경우 시간 제한 내로 통과 가능하다.
그런데, 그대로 값을 계산하면 오버플로가 나기 때문에 각 시간 복잡도를 계산하는 과정에서 제한을 넘어가는 순간
시간 초과로 계산해야 한다.

O(N)인 경우는 N이 10^6에 T가 10이더라도 항상 10^8 이하의 연산 횟수를 가지므로
시간 제한 내 통과 가능하다. O(N^2)의 경우는 long long 범위 내이므로 그대로 연산하면 되고,
O(N^3)의 경우는 O(N^2)을 지나서 가면 된다. O(2^N)의 경우에는 T에서 시작해서 2를 N번 곱해나간다.
중간에 L * 10^8을 넘으면 TLE를 출력하고, 끝까지 넘지 않았다면 통과이다.
O(N!)도 비슷한 방식으로 T에서 시작해서 팩토리얼을 곱해나가는 방식을 쓰면 된다.

주요 알고리즘 : 구현, 케이스 워크

출처 : Calgary 2013 A번
*/

char s[16];

int main(void) {
    int c;
    long long n, t, l, x;
    scanf("%d", &c);
    for (int cc = 0; cc < c; cc++) {
        scanf("%s %lld %lld %lld", s, &n, &t, &l);
        if (!strcmp(s, "O(N)")) printf("May Pass.\n");
        else if (!strcmp(s, "O(N^2)")) {
            if (n * n * t <= l * SEC) printf("May Pass.\n");
            else printf("TLE!\n");
        }
        else if (!strcmp(s, "O(N^3)")) {
            if (n * n * t > l * SEC) printf("TLE!\n");
            else if (n * n * n * t > l * SEC) printf("TLE!\n");
            else printf("May Pass.\n");
        }
        else if (!strcmp(s, "O(2^N)")) {
            x = t;
            for (int i = 0; i < n; i++) {
                x <<= 1;
                if (x > l * SEC) {
                    printf("TLE!\n");
                    break;
                }
            }
            if (x <= l * SEC) printf("May Pass.\n");
        }
        else if (!strcmp(s, "O(N!)")) {
            x = t;
            for (int i = 1; i <= n; i++) {
                x *= i;
                if (x > l * SEC) {
                    printf("TLE!\n");
                    break;
                }
            }
            if (x <= l * SEC) printf("May Pass.\n");
        }
        else return 1;
    }
    return 0;
}