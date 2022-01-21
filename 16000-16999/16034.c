#include <stdio.h>

/*
문제 : 자연수 N(N < 10^9)이 주어질 때, N을 하나 이상의 연속한 자연수의 합으로 나타내는 방법 가운데
가장 많은 자연수를 사용하는 방법을 구한다.

해결 방법 : 연속한 자연수의 합을 생각해보면 홀수 개의 자연수를 더한 경우 홀수(자연수의 개수) *
자연수(중앙값)이 되고, 짝수 개의 자연수를 더한 경우 홀수(중앙값 2개의 합) * 짝수(자연수의 개수)가 된다.
따라서, 이 합은 반드시 홀수를 인수로 가지며, 홀수 인수를 통해 그 경우를 살펴볼 수 있다.

이제 N의 모든 약수를 구한 다음, 각 홀수 인수마다 그것을 자연수의 개수 또는 중앙값 2개의 합으로
연속된 자연수를 만들 수 있는 지 살핀다. 이는 첫 값이 1 이상인지만 살펴보면 된다.
가능한 경우 가운데 자연수를 가장 많이 사용한 경우의 사용한 자연수 개수를 각 경우를 살펴보며 찾는다.
그 값을 찾았다면 이제 중앙값을 통해 시작점도 빠르게 찾아낼 수 있다. 시작점과 중앙값을 구하고
각 값들을 출력하면 된다.

주요 알고리즘 : 수학, 정수론

출처 : JDC 2018 C번
*/

int div[1024];

int main(void) {
    int n, dc, r, s;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        dc = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i) continue;
            div[dc++] = i;
            div[dc++] = n / i;
        }
        r = 0;
        for (int i = 0; i < dc; i++) {
            if (~div[i] & 1) continue;
            if (n / div[i] > (div[i] >> 1)) {
                if (div[i] > r) r = div[i];
            }
            else {
                if (n / div[i] * 2 > r) r = n / div[i] * 2;
            }
        }
        if (r & 1) s = n / r - (r >> 1);
        else s = n / r - (r >> 1) + 1;
        printf("%d %d\n", s, r);
    }
    return 0;
}