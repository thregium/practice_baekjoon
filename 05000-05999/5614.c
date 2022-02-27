#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 100000)개의 주문이 주어진다. 이때, 이 주문들 중 같은 것의 주문은 합치고,
주문들을 이름의 길이 -> 이름의 사전순으로 정렬하여 출력한 결과를 출력한다.

해결 방법 : 문제의 조건대로 정렬한 다음, 다른 주문이 나올 때 마다
주문의 합을 계산해 출력하는 것을 반복하면 된다.

주요 알고리즘 : 구현, 문자열, 정렬

출처 : JOI 2006모2 3번
*/

typedef struct prod {
    char name[8];
    long long cnt;
} prod;

prod p[1048576];

int cmp1(const void* a, const void* b) {
    prod ai = *(prod*)a;
    prod bi = *(prod*)b;
    if (strlen(ai.name) != strlen(bi.name)) return strlen(ai.name) > strlen(bi.name) ? 1 : -1;
    else return strcmp(ai.name, bi.name);
}

int main(void) {
    int n;
    long long c = 0;
    scanf("%d", &n);
    if (n > 1000000) return 1;
    for (int i = 0; i < n; i++) {
        scanf(" %s %d", p[i].name, &p[i].cnt);
    }
    qsort(p, n, sizeof(prod), cmp1);
    for (int i = 0; i < n; i++) {
        if (i > 0 && strcmp(p[i].name, p[i - 1].name)) {
            printf("%s %lld\n", p[i - 1].name, c);
            c = p[i].cnt;
        }
        else c += p[i].cnt;
    }
    printf("%s %lld\n", p[n - 1].name, c);
    return 0;
}