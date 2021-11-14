#include <stdio.h>

/*
문제 : N(N <= 5000)명이 원형으로 있다. 매 라운드마다 i(라운드 번호)^3번째 사람을 제거한다면 마지막으로 남는 사람을 구한다.

해결 방법 : N이 커지면 i^3이 매우 커지기 때문에 나머지 연산을 사용한다. 제거할 사람이 몇 번째인지 구하고
그 사람 이후의 사람을 앞으로 당겨 오는 것을 반복한다. N - 1번 이를 반복하여 답을 찾으면 된다.

주요 알고리즘 : 수학
*/

int a[5120];

int main(void) {
    int n, p = 0, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (long long i = 1; i < n; i++) {
        e = (p + i * i * i - 1) % (n - i + 1);
        p = e % (n - i);
        for (int j = e; j <= (n - i); j++) {
            a[j] = a[j + 1];
        }
    }
    printf("%d", a[0]);
    return 0;
}