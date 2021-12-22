#include <stdio.h>
#include <string.h>

/*
문제 : 문자열과 그 문자열의 길이보다 작은 자연수 N이 주어질 때, N칸만큼 왼쪽으로 시프트시킨 문자열을 구한다.

해결 방법 : 각 문자에 대해 (i + l - n) mod l번째 문자를 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : MHSPC 2013 P2번
*/

char w[103000];

int main(void) {
    int t, l, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %d", w, &n);
        l = strlen(w);
        //if (n == 1) return 1;
        printf("Shifting %s by %d positions gives us: ", w, n);
        for (int i = 0; i < l; i++) {
            printf("%c", w[(i + l - n) % l]);
        }
        printf("\n");
    }
    return 0;
}