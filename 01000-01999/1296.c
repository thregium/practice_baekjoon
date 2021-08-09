#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 50)�� ��� ���� ������ �� �´� ��� �� ���ĺ� ������ ���� ���� ����� ã�´�. (���� ���� ���� ����)

�ذ� ��� : �� ����� �̸��� �ִ� L, O, V, E�� ������ �� ���� ���� ������ ����� ���� ���� ���� ����� ã���� �ȴ�.
�̶�, ���ĺ������� ���� ����� ã�ƾ� �ϱ� ������ ������ ���� ������� ã�� ���� ����.

�ֿ� �˰��� : ����, ���ڿ�, ����
*/

char oms[32], girls[64][32];

int main(void) {
    int n, r = 0;
    long long l, o, v, e, p, rp = -1;
    scanf("%s%d", oms, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", girls[i]);
    }
    qsort(girls, n, sizeof(char) * 32, strcmp);
    for (int i = 0; i < n; i++) {
        l = 0, o = 0, v = 0, e = 0;
        for (int j = 0; oms[j]; j++) {
            if (oms[j] == 'L') l++;
            if (oms[j] == 'O') o++;
            if (oms[j] == 'V') v++;
            if (oms[j] == 'E') e++;
        }
        for (int j = 0; girls[i][j]; j++) {
            if (girls[i][j] == 'L') l++;
            if (girls[i][j] == 'O') o++;
            if (girls[i][j] == 'V') v++;
            if (girls[i][j] == 'E') e++;
        }
        p = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
        if (p > rp) {
            r = i;
            rp = p;
        }
    }
    printf("%s", girls[r]);
    return 0;
}