#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MOD 314159

/*
���� : 100000�� ������ �ҹ��ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ����� 2ȸ �̻� ������ �κ� ���ڿ� ���
���� �� �� �� ���� ������ ���� ���� �κ� ���ڿ��� ã�´�.

�ذ� ��� : ���-ī�� �ؽ̰� �Ű� ���� Ž���� ����  �׷��� �κ� ���ڿ��� ���̸� ã�� ����,
�ٽ� ���-ī�� �ؽ��� ���� �׷��� �κ� ���ڿ����� �ϳ��� ���캸�� ���� ������ ���� ���� ���� ã���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���-ī��

��ó : MidC 2018 K��
*/

typedef struct llst {
    int st;
    struct llst* nx;
} llst;

char s[204800], res[204800];
llst* ls[320000];

int l;

int find(int n, int m) {
    if (n <= 0) return 1;

    llst* prev = NULL;
    for (int i = 0; i < MOD; i++) {
        prev = ls[i];
        if (!prev) continue;
        for (llst* j = ls[i]->nx; j; j = j->nx) {
            free(prev);
            prev = j;
        }
        free(prev);
        ls[i] = NULL;
    }

    int mul = 1, hash = 0;
    for (int i = 0; i < n; i++) {
        mul = (mul * 26) % MOD;
        hash = (hash * 26 + s[i]) % MOD;
    }

    int r;
    for (int i = n - 1; i < l; i++) {
        for (llst* j = ls[hash]; j; j = j->nx) {
            r = 1;
            for (int k = 0; k < n; k++) {
                if (s[j->st + k] != s[i - n + 1 + k]) {
                    r = 0;
                    break;
                }
            }
            if (r) {
                if (m == 0) return 1;
                r = 0;
                for (int ii = 0; ii < n; ii++) {
                    if (s[ii + i - n + 1] < res[ii]) {
                        r = 1;
                        break;
                    }
                    else if (s[ii + i - n + 1] > res[ii]) break;
                }
                if (r) {
                    for (int ii = 0; ii < n; ii++) res[ii] = s[ii + i - n + 1];
                }
            }
        }

        llst* x = malloc(sizeof(llst));
        x->nx = ls[hash];
        x->st = i - n + 1;
        ls[hash] = x;

        hash = (26 * hash + (MOD - mul) * s[i - n + 1] + s[i + 1]) % MOD;
    }

    return 0;
}

int main(void) {
    int hi, lo, mi;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\MCPC2018\\repeatedsubstrings\\data\\secret\\secret13.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\MCPC2018\\repeatedsubstrings\\data\\secret\\secret13_t.out", "w", stdout);
    //scanf("%d\n", &l);
    scanf("%s", s);
    l = strlen(s);
    /*
    for (int i = 0; i < l; i++) {
        scanf("%c", &s[i]);
    }
    printf("\n%d\n", strlen(s));
    */
    hi = l - 1;
    lo = 0;
    while (hi > lo) {
        mi = (hi + lo + 1) / 2;
        if (find(mi, 0)) {
            lo = mi;
        }
        else {
            hi = mi - 1;
        }
    }
    res[0] = 127;
    find(hi, 1);
    //printf("%d\n", hi);
    printf("%s\n", res);
    return 0;
}