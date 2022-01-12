#include <stdio.h>
#include <stdlib.h>

/*
���� : T(T <= 50)���� ���� P(P <= 10)���� ����, R(R <= 500)���� ���� ���� �αװ� �־��� ��,
�� ���� ����ǥ�� �ۼ��� ����Ѵ�. ���� �α��� �ð��� �� ������ �־�����, �ð� ������ �־�����,
���� �ð��� ������ �־����� �ʴ´�. ���� �α��� ����� ����/������ 2������ �����ȴ�. ����, ��Ģ�� ICPC ���� ������
����ǥ�� �� ��ȣ, �ذ� ���� ��, ���Ƽ ������ ����Ѵ�. ���� ���� ���Ƽ�� ���ٸ� ��ȣ�� ���� ������ ����Ѵ�.

�ذ� ��� : �� ���� �ذ��� �������� ���Ƽ�� �迭�� �����ϸ�, �� ���� �� ������ ���� �������,
���� ���θ� �� �迭�� �����Ѵ�. ������ ������ ������ ������ ������ ���� ���� ��� ������� �ø���,
������ ������ ������ ������� ������� �ҿ� �ð��� Ȯ���� ���Ƽ�� �߰��ϰ� �ذ��� �������� 1 �ø���.
��� �αװ� ������ �� ���� ������ ICPC ���� ������ ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : JAG 2012D B��
*/

int team[64][3], pen[64][16], ac[64][16];
char buff[16];

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
    int t, p, r, ti, pi, tm;
    while (1) {
        scanf("%d %d %d", &t, &p, &r);
        if (t == 0) break;

        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= p; j++) {
                pen[i][j] = 0;
                ac[i][j] = 0;
            }
            team[i][0] = i;
            team[i][1] = 0, team[i][2] = 0;
        }

        for (int i = 0; i < r; i++) {
            scanf("%d %d %d %s", &ti, &pi, &tm, buff);
            if (ac[ti][pi]) continue;
            if (buff[0] == 'C') {
                team[ti][1]++;
                team[ti][2] += pen[ti][pi] * 1200 + tm;
                ac[ti][pi] = 1;
            }
            else {
                pen[ti][pi]++;
            }
        }
        qsort(team + 1, t, sizeof(int) * 3, cmp1);

        for (int i = 1; i <= t; i++) {
            printf("%d %d %d\n", team[i][0], team[i][1], team[i][2]);
        }
    }
    return 0;
}