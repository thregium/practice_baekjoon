#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N + M(N, M <= 100000)개의 이름이 주어질 때, 이름의 가짓수를 구한다.
각 이름은 10자 이하의 알파벳 소문자로 이루어져 있다.

해결 방법 : N + M개의 이름들을 전부 입력받고 정렬한다. 그 다음 앞의 것과 다른 이름의 개수를 세면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : CornH 2015 7번
*/

char name[103000 * 2][16];

int main(void) {
    int t, n, m, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n + m; i++) {
            scanf("%s", name[i]);
        }
        qsort(name, n + m, sizeof(char) * 16, strcmp);
        r = 1;
        for (int i = 1; i < n + m; i++) {
            if (strcmp(name[i], name[i - 1])) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}