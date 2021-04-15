#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 시리얼 번호들이 주어질 때, 길이가 짧은 순, 자릿수의 합이 작은 순, 사전순 순서로 정렬한다.

해결 방법 : 구조체를 정의해 문자열과, 자릿수의 합, 길이를 저장해놓고 조건에 맞게 정렬한다.

주요 알고리즘 : 문자열, 정렬
*/

typedef struct cer {
    char s[64]; //문자열
    int l; //길이
    int n; //자릿수의 합
} cer;

cer a[1024];

int cmp1(const cer* a, const cer* b) {
    if (a->l > b->l) return 1;
    else if (a->l < b->l) return -1;
    if (a->n > b->n) return 1;
    if (a->n < b->n) return -1;
    return strcmp(a->s, b->s);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i].s);
        a[i].l = strlen(a[i].s);
        a[i].n = 0;
        for (int j = 0; j < a[i].l; j++) {
            if (isdigit(a[i].s[j])) a[i].n += a[i].s[j] - '0';
        }
    }
    qsort(a, n, sizeof(cer), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i].s);
    }
    return 0;
}