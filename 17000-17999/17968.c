#include <stdio.h>

/*
문제 : N(N <= 1000)번째 산불 수열 값을 구한다. 산불 수열은 a[0] = 1, a[1] = 1로 정의한 이후로, 이전의 어떤 3개의
일정한 간격의 수열도 등차수열이 되지 않도록 하는 가장 작은 수로 정의한 수열이다.

해결 방법 : 문제에 주어진대로 구현한다. 이전 값들을 미리 저장해둬야 한다.

주요 알고리즘 : 브루트 포스, 다이나믹 프로그래밍

출처 : Seoul 2019 A번
*/

int mem[1024];

int main(void) {
    int n, t;
    scanf("%d", &n);
    mem[0] = 1, mem[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int k = 1;; k++) {
            t = 1;
            for (int j = 1; i - j * 2 >= 0; j++) {
                if (mem[i - j] - mem[i - j * 2] == k - mem[i - j]) {
                    t = 0;
                    break;
                }
            }
            if (t) {
                mem[i] = k;
                break;
            }
        }
    }
    printf("%d", mem[n]);
    return 0;
}