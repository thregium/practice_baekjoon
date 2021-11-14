#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)개의 문자열 가운데 "anj"라는 문자열이 있는지 확인한다.

해결 방법 : strcmp() 함수를 사용한다.

주요 알고리즘 : 문자열, 구현

출처 : 선린 3회 B번
*/

char buff[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strcmp(buff, "anj")) r = 1;
    }
    if (r) printf("뭐야;");
    else printf("뭐야?");
    return 0;
}