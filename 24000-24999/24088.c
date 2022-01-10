#include <stdio.h>

/*
문제 : N(N <= 2000)명의 사람들 중 K(1 < K < N)명은 빨간 팀, 나머지 N - K명은 하얀 팀이라고 한다.
이때, N - 1명의 팀 정보가 주어지면 나머지 1명은 무슨 팀에 속하는 지 구한다.

해결 방법 : 빨간 팀과 하얀 팀의 남은 사람 수를 세 나가며 입력마다 팀을 확인하고 그 팀의 남은 수를 1씩 줄여나간다.
남은 사람 수가 1명인 팀이 나머지 1명이 속하는 팀이다.

주요 알고리즘 : 구현

출처 : JOI 2022예1 3-3번
*/

int main(void) {
    int n, k, r, w;
    char c;
    scanf("%d%d\n", &n, &k);
    r = k, w = n - k;
    for (int i = 1; i < n; i++) {
        scanf("%c", &c);
        if (c == 'R') r--;
        else w--;
    }
    if (r) printf("R");
    else printf("W");
    return 0;
}