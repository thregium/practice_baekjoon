#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 256)명의 등록된 이름(10자, 소문자)이 주어진다. 그리고 다시 M(M <= 256)명의 이름이 주어질 때,
순서대로 등록된 이름인지 확인하고 등록된 이름인 경우 개폐 여부를 바꾸어 출력한다.
등록되지 않은 이름이라면 등록되지 않았다고 출력한다.

해결 방법 : 각 사람의 이름을 정렬한 다음 이분 탐색을 통해 이름이 있는 지 확인한다.
그리고 경우에 맞는 출력을 하면 된다.

주요 알고리즘 : 문자열, 정렬, 이분 탐색

출처 : JAG 2012S3B A번
*/

char s[384][16], buff[16];

int main(void) {
    int n, m, d = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(char) * 16, strcmp);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        if (!bsearch(buff, s, n, sizeof(char) * 16, strcmp)) {
            printf("Unknown %s\n", buff);
            continue;
        }
        if (d) printf("Closed by %s\n", buff);
        else printf("Opened by %s\n", buff);
        d = !d;
    }
    return 0;
}