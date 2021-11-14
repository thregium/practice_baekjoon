#include <stdio.h>
#include <stdlib.h>

/*
문제 : M(M <= 1000)개의 키보드 타이핑에 대해 시각과 키보드 번호, 입력한 문자가 주어질 때, 출력된 문자열을 구한다.
문자열은 시각 -> 번호 순서대로 표시된다.

해결 방법 : 입력을 구조체에 넣고 시각 -> 번호 순서대로 정렬한 다음 그 순서대로 문자들을 출력하면 된다.

주요 알고리즘 : 정렬

출처 : 전북대 2019 K번
*/

typedef struct key {
    int n;
    int t;
    char c;
} key;

key tp[1024];

int cmp1(const void* a, const void* b) {
    key ak = *(key*)a;
    key bk = *(key*)b;
    if (ak.t != bk.t) return ak.t > bk.t ? 1 : -1;
    return ak.n > bk.n ? 1 : ak.n == bk.n ? 0 : -1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &tp[i].n, &tp[i].t, &tp[i].c);
    }
    qsort(tp, m, sizeof(key), cmp1);
    for (int i = 0; i < m; i++) {
        printf("%c", tp[i].c);
    }
    return 0;
}