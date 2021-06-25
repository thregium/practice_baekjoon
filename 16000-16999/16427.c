#include <stdio.h>

/*
문제 : N(N <= 1000)가지 답안의 해결시간이 밀리초 단위로 주어질 때, 초 단위로 했을 때 이 해결시간중 가장 긴 것의
S(S <= 20)배 이상이 되는 가장 짧은 시간을 구한다. 해결시간은 최대 2000ms이다.

해결 방법 : 해결시간과 S가 적은 편이므로 해결시간을 입력받으며 만약 최대시간이 해결시간의 S배보다 적다면
최대시간을 증가시켜가며 찾아도 무리없이 돌릴 수 있다.

주요 알고리즘 : 수학, 사칙연산

출처 : PacNW 2018 J/W번 // SEUSA 2018D2 J번
*/

int m[128];

int main(void) {
    int n, s, time = 0;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        while (time * 1000 < m[i] * s) time++;
    }
    printf("%d", time);
    return 0;
}