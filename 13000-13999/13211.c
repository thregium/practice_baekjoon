#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 문자열과 M(M <= 100000)개의 문자열이 주어진다.
이때, M개의 문자열 가운데 N개의 문자열에 포함되는 문자열의 개수를 구한다.
각 문자열의 길이는 15 이하고, 알파벳과 숫자로 이루어져 있다.

해결 방법 : N개의 문자열들을 정렬한 다음, M개의 문자열을 입력 받을 때 마다
N개의 문자열에서 이분 탐색을 통해 있는 지 찾은 다음, 있는 것의 개수를 구하면 된다.

주요 알고리즘 : 문자열, 정렬, 이분 탐색

출처 : MCO 2014 A번
*/

char s[103000][16], buff[16];

int main(void) {
    int n, m, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(char) * 16, strcmp);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        if (bsearch(buff, s, n, sizeof(char) * 16, strcmp)) r++;
    }
    printf("%d", r);
    return 0;
}