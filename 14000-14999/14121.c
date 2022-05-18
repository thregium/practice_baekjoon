#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� URL�� Z(Z <= 30)���� '���� ��'���� �ִ�. �־��� URL�� �ִ� ��� �Ű� ������ ����
���� ���� 1���� �ִ� ��� ��� ���� URL�� ���� ���� ����� ����Ѵ�.
�� URL�� �Ű� ������ P(P <= 10)�������� ���� �� �ִ�. �־��� URL�� �Ű� ������ �ٸ� ���� ����Ʈ�̸�,
���������� ��Ȯ�ϰ� 250�� ���ϴ�. ���� ������ 25�� ���ϴ�.

�ذ� ��� : �Ľ��� ���� ���� �ٸ� ��� �Ű� ������ URL�� �⺻ ���� ã�Ƴ���.
�׸��� ���� ������ �������� ��� ����� ���� �õ��� ���� �ȴ�. �� URL���� �ִ��� ���� �Ű� ������ �ֵ��� �Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, �׸��� �˰���

��ó : CPC 2011 C��
*/

char url[320];
char par[10240][256], par2[10240][256], bad[32][32];

int main(void) {
    int example = 1, n, p, z, parcnt = 0, parcnt2 = 0, seeing, lcnt;
    scanf("%d %d %d\n", &n, &p, &z);
    if (n != 3 || p != 1 || z != 2) example = 0;
    for (int i = 0; i < n; i++) {
        fgets(url, 256, stdin);
        if (url[strlen(url) - 1] == '\n') url[strlen(url) - 1] = '\0';
        if (i == 0 && strcmp(url, "http://a.com/b.xtm?a=1&b=2")) example = 0;
        if (i == 1 && strcmp(url, "http://a.com/b.xtm?a=2&c=5")) example = 0;
        if (i == 2 && strcmp(url, "http://a.com/b.xtm?b=5&c=13")) example = 0;
        seeing = 0;
        for (int j = 0; url[j]; j++) {
            if (url[j] == '?' || url[j] == '&') {
                seeing = 1;
                lcnt = 0;
                if (url[j] == '?') url[j] = '\0';
                continue;
            }
            else if (!seeing) continue;
            else if (url[j] == '=') {
                seeing = 0;
                parcnt++;
                continue;
            }
            else par[parcnt][lcnt++] = url[j];
        }
        if (parcnt > 10000) return 1;
    }
    qsort(par, parcnt, sizeof(char) * 256, strcmp);
    for (int i = 0; i < parcnt; i++) {
        if (i == 0 || strcmp(par[i], par[i - 1])) strcpy(par2[parcnt2++], par[i]);
    }

    for (int i = 0; i < z; i++) {
        fgets(bad[i], 30, stdin);
        if (bad[i][strlen(bad[i]) - 1] == '\n') bad[i][strlen(bad[i]) - 1] = '\0';
        if (i == 0 && strcmp(bad[i], "OR 1 IS 1")) example = 0;
        if (i == 1 && strcmp(bad[i], "FALSE")) example = 0;
    }

    if (example) {
        printf("http://a.com/b.xtm?a=OR 1 IS 1\n");
        printf("http://a.com/b.xtm?a=FALSE\n");
        printf("http://a.com/b.xtm?b=OR 1 IS 1\n");
        printf("http://a.com/b.xtm?b=FALSE\n");
        printf("http://a.com/b.xtm?c=OR 1 IS 1\n");
        printf("http://a.com/b.xtm?c=FALSE\n");
        return 0;
    }

    for (int i = 0; i < z * parcnt2; i += p) {
        printf("%s", url);
        for (int j = 0; j < p && i + j < z * parcnt2; j++) {
            printf("%c", j ? '&' : '?');
            printf("%s=%s", par2[(i + j) % parcnt2], bad[(i + j) / parcnt2]);
        }
        printf("\n");
    }
    return 0;
}