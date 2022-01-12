#include <stdio.h>

/*
문제 : 2 이상의 자연수 X(X <= 1299709)가 주어질 때, 이 수를 포함하는 소수 사이 수열의 길이를 구한다.
소수 사이 수열은 인접한 두 소수 사이에 있는 합성수로 이루어진 수열이다. 만약 소수 사이 수열에 포함되지 않는 수인 경우
0을 출력하면 된다.

해결 방법 : X가 소수인 경우 소수 사이 수열에 포함되지 않고, 그 외에는 X보다 큰 첫 소수에서 작은 마지막 소수를 빼면 된다.

주요 알고리즘 : 수학, 소수 판정, 브루트 포스

출처 : Tokyo 2007 B번
*/

int prime[103000];
int pp = 0;

int main(void) {
    int n, t;
    for (int i = 2; i <= 1299709; i++) {
        t = 1;
        for (int x = 2; x * x <= i; x++) {
            if (i % x == 0) {
                t = 0;
                break;
            }
        }
        if (t) prime[pp++] = i;
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < pp; i++) {
            if (prime[i] == n) {
                printf("0\n");
                break;
            }
            else if (prime[i] > n) {
                printf("%d\n", prime[i] - prime[i - 1]);
                break;
            }
        }
    }
    return 0;
}