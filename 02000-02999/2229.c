#include <stdio.h>

/*
문제 : N(N <= 1000)개의 수로 이루어진 배열에서 구간을 나눌 때, 각 구간의 최댓값과 최솟값의 차의 합이
최대가 될 때의 값을 구한다.

해결 방법 : 1차원 DP로 해당 칸까지 확인했을 때의 최댓값을 저장하고 DP를 한다. 역순으로 구간을 넓혀가며
어디까지 넓힐 때가 가장 좋은지 확인하면 된다.

주요 알고리즘 : DP
*/

int score[1024], mem[1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, hi, lo;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &score[i]);
    }
    for (int i = 1; i <= n; i++) {
        hi = score[i], lo = score[i];
        for (int j = i - 1; j >= 0; j--) {
            mem[i] = big(mem[i], mem[j] + hi - lo);
            if (score[j] > hi) hi = score[j];
            if (score[j] < lo) lo = score[j];
        }
    }
    printf("%d", mem[n]);
    return 0;
}