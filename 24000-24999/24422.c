#include <stdio.h>

/*
문제 : N(N <= 500000)명이 투표를 한다. 각 사람은 찬성 또는 반대를 하고, 자신 앞의 X_i명 중
Y_i명 이상이 찬성 투표를 하면 찬성에 투표하고, 그보다 적은 경우 반대에 투표한다.
최종적으로 찬성에 투표된 표 수를 구한다.

해결 방법 : 각 사람마다 찬반 여부를 확인한 다음 그 결과를 저장해 나가면 된다.
단, N이 크기 때문에 찬반 여부 확인과 저장에는 누적 합을 이용한다.

주요 알고리즘 : 구현, 시뮬레이션, 누적 합

출처 : JOIG 2022 3번
*/

int vote[524288];

int getsum(int a, int b) {
    return vote[b] - vote[a - 1];
}

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        if (getsum(i - x, i - 1) >= y) vote[i] = vote[i - 1] + 1;
        else vote[i] = vote[i - 1];
    }
    printf("%d", vote[n]);
    return 0;
}