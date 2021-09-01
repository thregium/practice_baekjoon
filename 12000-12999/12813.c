#include <stdio.h>

/*
문제 : 길이 10만의 비트 문자열 A, B가 주어질 때, A & B, A | B, A ^ B, ~A, ~B를 한 값들을 각각 구한다.

해결 방법 : 각 결괏값들의 길이 역시 10만일 것이다. 따라서, 10만번씩 반복하며 각 비트들의 값들을 출력하고
개행하는 것을 반복하면 된다.

주요 알고리즘 : 문자열, 수학
*/

const int n = 100000;
char a[103000], b[103000];

int main(void) {
    scanf("%s%s", a, b);
    for (int i = 0; i < n; i++) printf("%c", ((a[i] - '0') & (b[i] - '0')) + '0');
    printf("\n");
    for (int i = 0; i < n; i++) printf("%c", ((a[i] - '0') | (b[i] - '0')) + '0');
    printf("\n");
    for (int i = 0; i < n; i++) printf("%c", ((a[i] - '0') ^ (b[i] - '0')) + '0');
    printf("\n");
    for (int i = 0; i < n; i++) printf("%c", (!(a[i] - '0')) + '0');
    printf("\n");
    for (int i = 0; i < n; i++) printf("%c", (!(b[i] - '0')) + '0');
    printf("\n");
    return 0;
}