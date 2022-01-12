#include <stdio.h>

/*
문제 : N(N <= 13200)엔의 금액을 10, 50, 100, 500엔 동전을 이용하여 내려고 한다.
금액 이상의 동전을 내면 점원은 거스름돈을 주는데, 동전의 개수를 최소화하여 준다.
이때, N과 각 동전의 개수(<= 20)가 주어지면 남는 동전의 개수가 최소화되도록 동전을 주는 방법을 구한다.
단, 돈을 낼 수 없는 경우는 주어지지 않으며, 의미 없는 교환(같은 금액의 동전을 받는 경우)은 없어야 한다.

해결 방법 : 동전을 내는 모든 경우를 시도해보며 받는 동전의 개수를 확인한다.
받는 동전의 개수는 단위가 맞아떨어지기 때문에 큰 동전부터 돌려주는 것으로 빠르게 알 수 있다.
또한, 동전의 개수를 적은 개수부터 내면 처음 나오는 최솟값에서 의미없는 교환이 나오지 않기 때문에,
처음 나오는 최솟값을 구하면 그것이 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 브루트 포스

출처 : JAG 2005D B번
*/

int coincount(int x) {
    return x / 500 + x / 100 % 5 + x / 50 % 2 + x / 10 % 5;
}

int main(void) {
    int n, m, a, b, c, d, best, ra, rb, rc, rd;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2005D\\data\\B\\input\\B4", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2005D\\data\\B\\output\\B4_t", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        best = 103000, ra = -1, rb = -1, rc = -1, rd = -1;
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                for (int k = 0; k <= c; k++) {
                    for (int l = 0; l <= d; l++) {
                        m = i * 10 + j * 50 + k * 100 + l * 500;
                        if (m < n) continue;
                        if (coincount(m - n) - i - j - k - l < best) {
                            best = coincount(m - n) - i - j - k - l;
                            ra = i, rb = j, rc = k, rd = l;
                        }
                    }
                }
            }
        }
        if (ra < 0) return 1;
        if (ra) printf("10 %d\n", ra);
        if (rb) printf("50 %d\n", rb);
        if (rc) printf("100 %d\n", rc);
        if (rd) printf("500 %d\n", rd);
        printf("\n");
    }
    return 0;
}