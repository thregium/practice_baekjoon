#include <stdio.h>

/*
문제 : 길이 N(N <= 200)의 대소문자로 이루어진 문자열에서
A번째부터 B번째까지의 문자들을 뒤집은 문자열을 출력한다.

해결 방법 : A번째에서 B번째까지 주어진 구간의 양 끝에서 시작하여 두 구간이 만날 때 까지
양쪽의 문자들을 바꾸면 된다.

주요 알고리즘 : 문자열, 구현

출처 : JOI 2020예1 2-2번
*/

char s[256];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    scanf("%s", s + 1);
    for (int i = a, j = b; i < j; i++, j--) {
        swap(&s[i], &s[j]);
    }
    printf("%s\n", s + 1);
    return 0;
}