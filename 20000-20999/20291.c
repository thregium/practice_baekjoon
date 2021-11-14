#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 50000)개의 파일명(. 1개와 소문자, 100자)이 주어질 때, 확장자의 종류와 개수를 사전순으로 출력한다.

해결 방법 : 파일명에서 strchr 함수를 이용해 확장자의 위치를 찾은 후 새 배열에 복사한다.
이 배열을 정렬한 다음, 중복을 세면서 종류와 개수를 각각 구해서 출력하면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : 서강대 2020C A번
*/

char buff[128], ext[51200][128];

int main(void) {
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (!strchr(buff, '.')) return 1;
        strcpy(ext[i], strchr(buff, '.') + 1);
    }
    qsort(ext, n, sizeof(char) * 128, strcmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && !strcmp(ext[i], ext[i - 1])) {
            c++;
            continue;
        }
        if (i > 0) printf("%d\n", c);
        c = 1;
        printf("%s ", ext[i]);
    }
    printf("%d", c);
    return 0;
}