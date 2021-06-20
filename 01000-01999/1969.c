#include <stdio.h>

/*
���� : A, C, G, T�� �̷���� ���� M(M <= 50)�� ���ڿ� N(N <= 1000)���� ���� ��, �� ���ڿ���� �ع� �Ÿ��� ���� ���� ���ڿ���
����ϰ� �� ���ڿ��� �ع� �Ÿ��� ����Ѵ�. �ع� �Ÿ��� ���� ���ڿ��� �ִٸ� ���� ������ �ռ��� ���ڿ��� ����Ѵ�.

�ذ� ��� : �� �� ���ں��� Ȯ���ϸ� �� ������ �ع� �Ÿ��� ���� ���� ���ڸ� ���ʷ� �����Ѵ�.
���ڿ��� �ع� �Ÿ��� ��� ������ �ع� �Ÿ��� �հ� ����.

�ֿ� �˰��� : ���Ʈ ����, ���ڿ�

��ó : Seoul 2006 B��
*/

char dna[1024][64], best[64];
char* nc = "ACGT";

int main(void) {
    int n, m, hd = 0, thd, tbst;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", dna[i]);
    }

    for (int i = 0; i < m; i++) {
        tbst = 65536;
        for (int j = 0; j < 4; j++) {
            thd = 0;
            for (int k = 0; k < n; k++) {
                if (nc[j] != dna[k][i]) thd++;
            }
            if (thd < tbst) {
                best[i] = nc[j];
                tbst = thd;
            }
        }
        hd += tbst;
    }
    printf("%s\n%d", best, hd);
    return 0;
}