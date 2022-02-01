#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MOD 1029989

/*
���� : ���� 300000 ������ �빮�ڷ� �̷���� ���ڿ��� �־�����. �� ���ڿ��� �κ� ���ڿ� ���
2�� �̻� �������� �ʴ� ���� ª�� �κ� ���ڿ��� ���Ѵ�.
�׷��� ���� ���� ���� ��� ���� �տ� �ִ� ���� ����Ѵ�.

�ذ� ��� : �Ű� ���� Ž���� ���-ī�� �ؽ��� �̿��� Ǯ �� �ִ�.
�Ű� ���� Ž�������� ���� ª�� �κ� ���ڿ��� ���̸� ���Ѵ�. �� �������� ���-ī�� �ؽ��� ����
�� �κ� ���ڿ��� �ߺ� ���θ� Ȯ���Ѵ�. ��� �κ� ���ڿ��� �ߺ��� ��� �� �� ������ �ű��,
�ߺ��� �ƴ� ���� �ִٸ� ª�� ������ �ű�� �ȴ�. ���̸� �˾Ƴ´ٸ� �ٽ� �ѹ� ���-ī�� �ؽ�����
�ش� ������ �ߺ����� �ʴ� �κ� ���ڿ��� �� ���� �������� ���� ���� ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���-ī��, �Ķ��Ʈ��

��ó : SWERC 2020 K��
*/

typedef struct llst {
    struct llst* nxt;
    int pos;
} llst;

char s[327680];
int b26[327680] = { 1, };
llst* hashed[1048576];
int best;

int getres(int l, int m) {
    int t, t2, p;
    llst* last;
    int h = 0;
    for (int i = 0; i < m; i++) {
        h += b26[m - i - 1] * (s[i] - 'A');
        h %= MOD;
    }
    last = calloc(1, sizeof(llst));
    hashed[h] = last;
    for (int i = m; i < l; i++) {
        h *= 26;
        h -= b26[m] * (s[i - m] - 'A');
        h += s[i] - 'A';
        h %= MOD;
        if (h < 0) h += MOD;

        t = 0;
        for (llst* node = hashed[h]; node; node = node->nxt) {
            if (node->pos < 0) p = -node->pos - 1;
            else p = node->pos;
            t2 = 1;
            for (int j = 0; j < m && j < 100; j++) {
                if (s[p + j] != s[i - m + j + 1]) {
                    t2 = 0;
                    break;
                }
            }
            if (t2) {
                t = 1;
                if (node->pos >= 0) node->pos = -node->pos - 1;
                break;
            }
        }
        if (!t) {
            last = calloc(1, sizeof(llst));
            last->nxt = hashed[h];
            last->pos = i - m + 1;
            hashed[h] = last;
        }
    }

    t = 0, best = MOD;
    for (int i = 0; i < MOD; i++) {
        last = NULL;
        for (llst* node = hashed[i]; node; node = node->nxt) {
            if (last) free(last);
            if (node->pos >= 0) {
                t = 1;
                if (node->pos < best) best = node->pos;
            }
            last = node;
        }
        if (last) free(last);
        hashed[i] = NULL;
    }
    return t;
}

int main(void) {
    int l, hi, lo, mid;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 1; i <= l; i++) b26[i] = (b26[i - 1] * 26) % MOD;
    hi = l, lo = 1;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (getres(l, mid)) hi = mid;
        else lo = mid + 1;
    }
    //printf("%d\n", lo);
    getres(l, lo);
    for (int i = best; i < best + lo; i++) printf("%c", s[i]);
    return 0;
}