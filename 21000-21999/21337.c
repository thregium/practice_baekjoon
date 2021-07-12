#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
문제 : N(N <= 100)개의 수가 주어질 때, N 이하의 수인 경우 Ai(Ai <= 10^9), N보다 큰 경우에는 해당 수 이하의
두 자연수로 나누어 재귀적으로 최솟값을 찾는 수열이 있다. 이 수열의 K(K <= 10^9)번째 값을 Q(Q <= 100000)회 찾는다.

해결 방법 : DP를 통해 가능한 값들을 채우다 보면 일정한 주기로 증가량이 반복된다는 것을 알 수 있다.
이 증가량은 최대 N^2까지 가능하므로 모든 N^2 이하의 주기에 대해 해당하는 반복이 있는지 확인해서 주기를 구한다.
그 다음 주기가 나오면, 주기마다 증가하는 값을 구하고, 이후 들어오는 입력에 대해서는 구했던 값에서
나온 주기의 수만큼을 이용해 구하면 된다.

주요 알고리즘 : DP, 그리디 알고리즘

출처 : NWERC 2020 A번
*/

int a[128];
long long mem[20480], diff[20480];

int main(void) {
    int n, q, k, t, rep = 0, reps;
    long long repn = 0;
    scanf("%d %d", &n, &q);
    srand(time(NULL));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        //a[i] = rand();
    }
    for (int i = 1; i <= 20000; i++) {
        if (i <= n) mem[i] = a[i];
        else {
            mem[i] = mem[i - 1] + mem[1];
            for (int j = 1; j <= i - j; j++) {
                if (mem[j] + mem[i - j] < mem[i]) mem[i] = mem[j] + mem[i - j];
            }
        }
        diff[i] = mem[i] - mem[i - 1];
    }
    for (int i = 5000; i > 0; i--) {
        t = 1;
        for (int j = 1; j <= i; j++) {
            if (diff[10000 + j] != diff[10000 + i + j]) t = 0;
        }
        if (t) {
            rep = i;
            for (int j = 1; j <= i; j++) {
                repn += diff[10000 + j];
            }
            break;
        }
    }
    if (!rep) return 1;
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        if (k > 20000) {
            reps = (k - 14000) / rep;
            printf("%lld\n", reps * repn + mem[k - reps * rep]);
        }
        else printf("%lld\n", mem[k]);
    }
    return 0;
}