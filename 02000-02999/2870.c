#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 100자 이하의 소문자와 숫자로 이루어진 문자열 N(N <= 100)개가 주어질 때,
모든 문자열에 나오는 수들을 오름차순으로 정렬한 결과를 출력한다.

해결 방법 : 문자열에서 숫자가 나오는 곳이 나오면 수 문자열에 해당 구간을 복사한다.
이때, 0은 복사하지 않기 위해 따로 변수를 두어야 한다.
복사가 끝났으면 정렬을 한다. 길이(내림차순)-> 사전순 으로 정렬하면 된다.

주요 알고리즘 : 문자열, 파싱, 정렬

출처 : COCI 10/11#2 2번
*/

char s[128][128], num[10240][128];

int cmp1(const void* a, const void* b) {
    int ai = strlen((char*)a);
    int bi = strlen((char*)b);
    if (ai != bi) return ai > bi ? 1 : -1;
    else return strcmp(a, b);
}

int main(void) {
    int n, p = 0, pp, ns;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; s[i][j]; j++) {
            if (isdigit(s[i][j])) {
                pp = 0, ns = 0;
                while (isdigit(s[i][j])) {
                    if (ns > 0 || s[i][j] != '0') {
                        ns = 1;
                        num[p][pp++] = s[i][j];
                    }
                    j++;
                }
                if (strlen(num[p]) == 0) strcpy(num[p], "0");
                p++;
            }
        }
    }
    qsort(num, p, sizeof(char) * 128, cmp1);
    for (int i = 0; i < p; i++) {
        printf("%s\n", num[i]);
    }
    return 0;
}