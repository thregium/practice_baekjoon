#include <stdio.h>

/*
문제 : N(N <= 100)개의 자연수로 이루어진 배열에 대해 L년부터 R(1 <= L <= R <= 4000)년까지의
일반화된 윤년의 개수를 구한다. 일반화된 윤년은 그 해의 연도가 나누어 떨어지는 배열의 가장 앞 수의 번호를 확인해서
홀수인 경우 일반화된 윤년, 짝수라면 평년으로 구분한다. 그러한 수가 없는 경우 N이 짝수인 경우에만 일반화된 윤년이다.

해결 방법 : 문제에 주어진 것을 배열을 돌면서 확인하면 된다.

주요 알고리즘 : 수학, 구현

출처 : JAG 2018D B번
*/

int a[64];

int main(void) {
    int n, l, r, res, c;
    while (1) {
        scanf("%d %d %d", &n, &l, &r);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        res = 0;
        for (int i = l; i <= r; i++) {
            c = -1;
            for (int j = 0; j < n; j++) {
                if (i % a[j] == 0) {
                    c = (~j & 1);
                    break;
                }
            }
            if (c < 0) res += (~n & 1);
            else res += (c & 1);
        }
        printf("%d\n", res);
    }
    return 0;
}