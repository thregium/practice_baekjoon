#include <stdio.h>

/*
문제 : N(N <= 1000)개의 파일 용량과, 클러스터의 크기가 주어질 때, 디스크에서 차지하는 용량을 구한다.

해결 방법 : 파일 용량을 클러스터의 크기로 나눈 몫을 올림한 값에 클러스터의 크기를 곱한 값의 합을 구하면 된다.

주요 알고리즘 : 수학, 사칙연산
*/

int space[1024];

int main(void) {
    int n, m;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &space[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        r += (space[i] + (m - 1)) / m * m;
    }
    printf("%lld", r);
    return 0;
}