#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)만개의 방이 있고, 각 방에 a_i(a_i <= 10^6)개의 물건이 있다. 모든 방의 물건 개수를
같게 만들도록 양 옆의 방으로 물건을 옮기는 것을 반복한다면 몇 회 반복해야 물건이 전부
옮겨지는 지 구한다. 모든 방의 물건 수 합은 N으로 나누어 떨어진다.

해결 방법 : 각 방에 최종적으로 남을 물건 개수를 계산한 다음, 그 값과의 차이를 계산하고
누적 합을 확인한다. 누적 합이 음수인 경우 그 개수만큼의 물건이 그 통로를 통해 전 방들로 이동해야 하고,
양수인 경우 그 개수만큼 그 통로를 통해 이후 방들로 이동해야 한다.
따라서, 항상 누적 합의 절댓값만큼의 값을 더해나가면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 누적 합

출처 : 설곽 2022 B번
*/

int a[204800];

int main(void) {
    int n;
    long long sum = 0, targ, psum = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % n) return 1;
    targ = sum / n;
    for (int i = 0; i < n; i++) {
        psum += a[i] - targ;
        res += llabs(psum);
    }
    printf("%lld", res);
    return 0;
}