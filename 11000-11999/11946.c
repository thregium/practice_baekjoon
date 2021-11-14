#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� �����ڿ� M(M <= 15)���� ������ �ִ�. Q(Q <= 10000)���� ���� ����� �־��� ��,
�� ��ϵ�� ��������� ����ǥ�� ����Ѵ�. �������� ��� ��ȣ ������ ����Ѵ�.

�ذ� ��� : ���� ����� �־����� AC�� �߱� �������� �ش� ������ ���Ƽ�� ���δ�.
AC�� �߸� �ش� ������ ���Ƽ�� Ȯ���� Ȯ���Ѵ�. �� ���ķ� �� ������ ������ ������ �����Ѵ�.
��� ����� ������ ��� ���� ��� ������ ���� Ȯ���Ͽ� Ǭ ���� ���� ���Ƽ�� ���Ѵ�.
�� ����, �̸� ������� �����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : ����� 2016 E��
*/

char buff[8];
int prob[128][16], res[128][3];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 2);
    bi = *((int*)b + 2);
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *(int*)a;
    bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, q;
    int time, team, num;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %s", &time, &team, &num, buff);
        if (prob[team][num] > 0) continue;
        if (!strcmp(buff, "AC")) {
            prob[team][num] = prob[team][num] * -20 + time;
            if (prob[team][num] == 0) prob[team][num] = 1012345678;
        }
        else {
            prob[team][num]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        res[i][0] = i;
        for (int j = 1; j <= m; j++) {
            if (prob[i][j] > 0) {
                res[i][1]++;
                if (prob[i][j] == 1012345678) continue;
                else res[i][2] += prob[i][j];
            }
        }
    }
    qsort(res + 1, n, sizeof(int) * 3, cmp1);
    for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
    }
    return 0;
}