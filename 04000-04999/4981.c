#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 길이 N(2 <= N <= 72)의 소문자로 이루어진 문자열이 주어질 때, 이 문자열을 두 부분으로 자르고,
두 문자열을 각각 뒤집거나 그대로인 상태로 순서들 바꾸거나 그대로 붙여 만들 수 있는 문자열의 가짓수를 구한다.

해결 방법 : 직접 가능한 모든 위치에서 문자열을 자른 다음 뒤집거나 그대로 두는 것을 반복해
만들 수 있는 문자열의 가짓수를 센다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : JDC 2006 B번
*/

char train[96], sub1[96], sub2[96], conf[1024][96];

void swapc(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void revstr(char* s) {
    int l = strlen(s);
    for (int i = 0, j = l - 1; i < j; i++, j--) {
        swapc(&s[i], &s[j]);
    }
}

void confadd(int* c) {
    strcpy(conf[*c], sub1);
    strcat(conf[(*c)++], sub2);
    strcpy(conf[*c], sub2);
    strcat(conf[(*c)++], sub1);
}

int main(void) {
    int t, l, cnt, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", train);
        cnt = 0;
        l = strlen(train);
        for (int i = 1; i < l; i++) {
            for (int j = 0; j < i; j++) sub1[j] = train[j];
            sub1[i] = '\0';
            strcpy(sub2, train + i);
            confadd(&cnt);
            revstr(sub1);
            confadd(&cnt);
            revstr(sub2);
            confadd(&cnt);
            revstr(sub1);
            confadd(&cnt);
        }

        qsort(conf, cnt, sizeof(char) * 96, strcmp);
        r = 0;
        for (int i = 0; i < cnt; i++) {
            if (i == 0 || strcmp(conf[i], conf[i - 1])) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}