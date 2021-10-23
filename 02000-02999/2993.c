#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 길이 50 이하의 소문자로 이루어진 문자열이 주어질 때, 각 문자열을 길이 1 이상의 세 부분으로 나누고
각 부분을 뒤집은 다음 붙인 문자열 가운데 사전순으로 가장 빠른 문자열을 구한다.

해결 방법 : 길이가 50이므로 세 부분으로 나누는 방법은 50^2 이하의 가짓수 뿐이다.
따라서 모든 경우를 직접 해본 다음 정렬을 통해 가장 사전순으로 빠른 문자열을 찾으면 된다.

주요 알고리즘 : 브루트 포스, 문자열, 정렬

출처 : COCI 07/08#4 3번
*/

char orig[64], made[4096][64];

int main(void) {
    int l, sz = 0, p;
    scanf("%s", orig);
    l = strlen(orig);
    for (int i = 0; i < l - 2; i++) {
        for (int j = i + 1; j < l - 1; j++) {
            p = 0;
            for (int k = i; k >= 0; k--) made[sz][p++] = orig[k];
            for (int k = j; k > i; k--) made[sz][p++] = orig[k];
            for (int k = l - 1; k > j; k--) made[sz][p++] = orig[k];
            sz++;
        }
    }
    qsort(made, sz, sizeof(char) * 64, strcmp);
    printf("%s", made[0]);
    return 0;
}