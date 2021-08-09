#include <stdio.h>

/*
문제 : 2 * 10^8 이하의 자연수 N이 주어질 때, N의 배수를 계속 쓰다가 0부터 9까지의 모든 숫자를 쓰게 되는 첫 배수는
몇 배일 때인지 구한다.

해결 방법 : 항상 10배 이하에서는 답이 나옴을 알 수 있다. 따라서, 각 자리의 개수를 매 배수마다 센 다음,
전부 1 이상이 되는 경우가 나오는 경우 그때의 배수를 구하면 된다.

주요 알고리즘 : 브루트 포스, 수학

출처 : PacNW 2012 B번
*/

int cnt[10];

int main(void) {
    int t;
    long long n;
    while (scanf("%lld", &n) != EOF) {
        for (int i = 0; i < 10; i++) {
            cnt[i] = 0;
        }
        for (int i = 1;; i++) {
            for (long long x = n * i; x; x /= 10) cnt[x % 10]++;
            t = 1;
            for (int j = 0; j < 10; j++) {
                if (!cnt[j]) t = 0;
            }
            if (t) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}