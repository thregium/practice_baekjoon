#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 50)���� �۹��� �ְ�, �� �۹��� �̸�, ����, ������ �ܰ�, ������ ����, ���� �ð�, ��Ȯ Ƚ�� ���� �־��� ��,
�� �۹��� ȿ���� ���� ������ ����Ѵ�. �۹��� ȿ���� ���� / ��ü ���� �ð��̴�. ȿ���� ���ٸ� �̸��� ������������ ����Ѵ�.

�ذ� ��� : �� �۹��� ���� �ð��� ������ ����� ����ü�� �ִ´�. �׸��� ȿ�� -> �̸� ������ �����ϸ� �ȴ�.
�̶�, ���� �ð��� ������ ��� ���ؾ� �ϴ� ������ ȿ�������� ���ϸ� �Ǽ� ������ ������ ���� �� �ֱ� �����̴�.

�ֿ� �˰��� : ����, ����

��ó : JAG 2010D B��
*/

typedef struct species {
    char l[32];
    long long rev;
    long long tm;
} species;

species spe[64];

int cmp1(const void* a, const void* b) {
    species ai = *(species*)a;
    species bi = *(species*)b;
    if (ai.rev * bi.tm != ai.tm * bi.rev) return ai.rev * bi.tm < ai.tm * bi.rev ? 1 : -1;
    else return strcmp(ai.l, bi.l);
}

int main(void) {
    int n, p, a, b, c, d, e, f, s, m;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2010D\\domestic-2010-judge-data\\domestic-2010-judge-data\\contest\\B\\B4", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2010D\\domestic-2010-judge-data\\domestic-2010-judge-data\\contest\\B\\B4_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d %d %d %d %d %d %d %d", spe[i].l, &p, &a, &b, &c, &d, &e, &f, &s, &m);
            spe[i].tm = a + b + c;
            for (int j = 0; j < m; j++) {
                spe[i].tm += d + e;
            }
            spe[i].rev = f * m * s - p;
        }
        qsort(spe, n, sizeof(species), cmp1);
        for (int i = 0; i < n; i++) {
            printf("%s\n", spe[i].l);
        }
        printf("#\n");
    }
    return 0;
}