#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 256)개의 자연수로 이루어진 배열에 선형 동차법을 이용해 나온 새로운 배열의 엔트로피가
최소가 되도록 하는 세 변수 S, A, C의 값을 구한다. 이 값들은 15 이하의 음이 아닌 정수여야 하며,
같은 엔트로피의 배열이 여럿인 경우 S -> A -> C가 작은 순으로 우선한다.
모듈로는 256이며, 엔트로피는 -(각 값의 등장 비율 * 그의 로그) 의 합이다.

해결 방법 : 모든 S, A, C에 대해 새로운 배열을 만들고 등장 횟수를 구한 다음 엔트로피를 구하고,
그 가운데 가장 작은 것일 때의 S, A, C를 구하면 된다. 이때 실수 오차에 유의한다.

주요 알고리즘 : 수학, 브루트 포스

출처 : JAG 2009S3 A번
*/

int ins[384], cnt[256];

int main(void) {
    int n, r, bs = -1, ba = -1, bc = -1;
    double bh = 999999999, h;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ins[i]);
    }
    for (int s = 0; s <= 15; s++) {
        for (int a = 0; a <= 15; a++) {
            for (int c = 0; c <= 15; c++) {
                r = s;
                for (int i = 1; i <= n; i++) {
                    r = ((a * r + c) & 255);
                    cnt[(ins[i] + r) & 255]++;
                }
                h = 0.0;
                for (int i = 0; i < 256; i++) {
                    if (cnt[i]) h -= cnt[i] / (double)n * log(cnt[i] / (double)n);
                    cnt[i] = 0;
                }
                if (bh - h > 0.0000001) {
                    bh = h;
                    bs = s, ba = a, bc = c;
                }
            }
        }
    }
    if (bs < 0) return 1;
    printf("%d %d %d", bs, ba, bc);
    return 0;
}