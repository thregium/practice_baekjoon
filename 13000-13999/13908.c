#include <stdio.h>

/*
문제 : N(N <= 7)자리 0 이상의 정수들 가운데 M(M <= N)개의 주어진 숫자들이 모두 쓰인 정수들을 찾는다.

해결 방법 : N자리 이하의 모든 수에 대해 각 숫자들이 전부 쓰였는지 매번 확인해보면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : 서강대 12회M A번
*/

int nums[16], chk[16];
int b10[8] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int main(void) {
    int n, m, x, r = 0, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        nums[x] = 1;
    }
    for (int i = 0; i < b10[n]; i++) {
        for (int j = 0; j < 10; j++) chk[j] = 0;
        t = 1;
        for (int j = i, j2 = 0; j2 < n; j /= 10, j2++) {
            chk[j % 10]++;
        }
        for (int j = 0; j < 10; j++) {
            if (nums[j] && !chk[j]) {
                t = 0;
                break;
            }
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}