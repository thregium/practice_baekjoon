#include <stdio.h>

/*
문제 : 길이 L(L <= 10^6)의 문자열이 주어질 때, 이 문자열의 가장 짧은 반복의 길이를 구한다.

해결 방법 : 이는 L에서 문자열의 접미사와 접두사의 공통 부분의 길이를 뺀 것과 같다.
KMP의 실패 함수를 이용하면 마지막 문자의 실패 함수가 답과 같게 되므로 간단히 해결 가능하다.

주요 알고리즘 : 문자열, KMP
*/

char s[1048576];
int f[1048576];

int main(void) {
    int l, p = -1;
    scanf("%d%s", &l, s);
    f[0] = -1;
    for (int i = 0; i < l; i++) {
        while (p > -1 && s[i] != s[p]) p = f[p];
        f[i + 1] = ++p;
    }
    printf("%d", l - f[l]);
    return 0;
}