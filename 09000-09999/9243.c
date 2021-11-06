#include <stdio.h>

/*
문제 : 길이 1000 이하로 같은 길이의 1과 0으로 이루어진 두 문자열이 주어질 때, 두 번째 문자열이 첫 번째 문자열에서
비트를 N(N <= 20)회 반전한 것과 같은지 구한다.

해결 방법 : 비트를 홀수 회 반전하면 각 비트가 반대 상태가 되고, 짝수 회 반전하면 원래 상태로 돌아온다는 점을 이용한다.

주요 알고리즘 : 구현, 수학

출처 : NCPC 2013 G번
*/

char s1[1024], s2[1024];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    scanf("%s%s", s1, s2);
    for (int i = 0; s1[i]; i++) {
        if ((n & 1) ? (s1[i] == s2[i]) : (s1[i] != s2[i])) r = 0;
    }
    printf("%s", r ? "Deletion succeeded" : "Deletion failed");
    return 0;
}