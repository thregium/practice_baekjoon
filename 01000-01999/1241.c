#include <stdio.h>

/*
문제 : N(N <= 100000)개의 자연수(<= 10^6)가 주어진다. 각 자연수의 약수가 되는 서로 다른 자연수가
주어진 값에서 몇 개인지 각 수마다 구한다.

해결 방법 : 각 수가 나온 개수를 센 다음, 소인수분해를 제곱근 시간에 하면서 각 소인수에 해당하는
수의 개수를 센다. 거기서 1을 빼면 각 수의 답이 된다.

주요 알고리즘 : 수학, 소인수분해
*/

int a[103000], cnt[1048576];

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        r = 0;
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j) continue;
            r += cnt[j];
            if (j * j == a[i]) break;
            r += cnt[a[i] / j];
        }
        printf("%d\n", r - 1);
    }
    return 0;
}