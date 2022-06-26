#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 20000)���� 100�� ������ �ܾ �־�����. �� �ܾ�� ��� ���� ���̻��� ���̰� ���� ��
���� ����Ѵ�. ��, �׷��� ���� ���� ���� ��� ���� ó���� �����ϴ� ���� ����Ѵ�.

�ذ� ��� : �� �� ���ں��� ���ʷ� ������ ������. �� �� ���� ������ �� ���� ��� ���� ���ڸ� �����ϰ�,
�̸� �ݺ��Ѵ�. ��, �����ϴ� �������� ���� ������ ��� ó���� ������ ������ �����Ѵ�.
�Ź� 2�� �̻��� ����� ���� ù 2���� �ܾ Ȯ���� ������ ������ ������.
���������� ���� ���� ����ϸ� ������ ���´�.

�ֿ� �˰��� : ���ڿ�, ����, ���� ����
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