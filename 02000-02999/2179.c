#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 20000)개의 100자 이하의 단어가 주어진다. 이 단어들 가운데 공통 접미사의 길이가 가장 긴
쌍을 출력한다. 단, 그러한 것이 여러 개인 경우 가장 처음에 등장하는 쌍을 출력한다.

해결 방법 : 맨 앞 글자부터 차례로 정렬해 나간다. 그 후 같은 글자인 것 끼리 모아 다음 글자를 정렬하고,
이를 반복한다. 단, 정렬하는 과정에서 같은 글자인 경우 처음에 등장한 순서로 정렬한다.
매번 2개 이상인 덩어리에 대해 첫 2개의 단어를 확인해 정답을 갱신해 나간다.
최종적으로 나온 답을 출력하면 정답이 나온다.

주요 알고리즘 : 문자열, 정렬, 분할 정복
*/

typedef struct word {
    char s[128];
    int ord;
} word;

word wd[20480];
char res1[128], res2[128];
int wpos, rlen = -1, rpos1 = -1, rpos2 = -1;

int cmp1(const void* a, const void* b) {
    word ai = *(word*)a;
    word bi = *(word*)b;
    if (ai.s[wpos] != bi.s[wpos]) return ai.s[wpos] > bi.s[wpos] ? 1 : -1;
    return ai.ord > bi.ord ? 1 : ai.ord == bi.ord ? 0 : -1;
}

void track(int st, int ed, int p) {
    int last = st;
    if (st == ed) return;
    if (p > rlen || (p == rlen && wd[st].ord < rpos1) ||
        (p == rlen && wd[st].ord == rpos1 && wd[st + 1].ord < rpos2)) {
        rlen = p;
        rpos1 = wd[st].ord;
        rpos2 = wd[st + 1].ord;
        strcpy(res1, wd[st].s);
        strcpy(res2, wd[st + 1].s);
    }
    wpos = p;
    qsort(wd + st, ed - st + 1, sizeof(word), cmp1);
    for (int i = st + 1; i <= ed; i++) {
        if (wd[i].s[p] != wd[i - 1].s[p]) {
            track(last, i - 1, p + 1);
            last = i;
        }
    }
    track(last, ed, p + 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", wd[i].s);
        wd[i].ord = i;
    }
    track(0, n - 1, 0);
    if (rlen < 0) return 1;
    printf("%s\n%s", res1, res2);
    return 0;
}