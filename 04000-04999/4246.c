#include <stdio.h>

/*
문제 : 200자 이하의 문자열과 열 수가 주어질 때, 해당 열의 암호문을 평문으로 바꾼다.
암호는 해당 열의 행렬을 만든 다음, 문자열을 세로로 쓰고, 이를 행 단위로 지그재그로 읽어서 만들었다.
각 문자열의 길이는 열 수의 배수이다.

해결 방법 : 각 열 별로 해당하는 문자들을 차례로 읽어나간다. 마지막 줄에 주의한다.

주요 알고리즘 : 문자열, 구현

출처 : ECNA 2004 G번
*/

char s[256];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s", s);
        for (int i = 0; i < n; i++) {
            for (int j = i; s[j]; j += n * 2) {
                printf("%c", s[j]);
                if (s[j + n * 2 - i * 2 - 1]) printf("%c", s[j + n * 2 - i * 2 - 1]);
            }
        }
        printf("\n");
        for (int i = 0; s[i]; i++) s[i] = '\0';
    }
    return 0;
}