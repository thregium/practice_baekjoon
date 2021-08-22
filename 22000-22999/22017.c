#include <stdio.h>
#define INF 1012345678

/*
문제 : 길이 N(N <= 200000)의 0과 1로 이루어진 수열을 만들려고 한다. 처음에는 왼쪽에서부터 원하는 개수의 수가 1, 이후 수들은 0인 상태이고,
그 뒤로 이 상태에서 수 하나의 상태를 뒤집는데 1초가 걸린다. 이때, 가장 빠르게 수열을 만든다면 몇 초가 걸리는지 구한다.

해결 방법 : 왼쪽에서부터 0의 수를 센 배열과 오른쪽에서부터 1의 수를 센 배열을 만든다.
그 다음 0번째 수(모두 0인 경우)부터 N번째 수(모두 1인 경우)까지 해당 수까지의 0의 수와 해당 수 이후의 1의 수의 합을 확인한 후
가장 큰 값을 구하면 된다.

주요 알고리즘 : 누적 합

출처 : JOIG 2021 3번
*/

int a[204800], lsum[204800], rsum[204800];

int main(void) {
    int n, r = INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        lsum[i] = lsum[i - 1] + (!a[i]);
    }
    for (int i = n; i >= 1; i--) {
        rsum[i] = rsum[i + 1] + (!!a[i]);
    }
    for (int i = 0; i <= n; i++) {
        if (lsum[i] + rsum[i + 1] < r) r = lsum[i] + rsum[i + 1];
    }
    printf("%d", r);
    return 0;
}