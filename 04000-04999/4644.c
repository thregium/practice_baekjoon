#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
���� : N(N <= 20)���� ���� ���� ���� �̸�(<= 10��)�� �� ������ Ǭ ����/ Ǭ �ð��� �־��� ��,
�� ���� ����ǥ�� ����Ѵ�. ������ Ǭ ���� �� -> Ǭ �ð� �� -> Ǭ �ð��� ����������� �Ű�����.

�ذ� ��� : �� ���� Ǭ ���� �� ��, Ǭ �ð� ��, ������� ���� ����ü�� �����, �� ������ �Է¹�����
�� ������ ����Ѵ�. �׸��� ���� ������� ������ ���� �� ������� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, ����

��ó : MidC 2002 A��
*/

typedef struct team {
    char name[16];
    int svd, sum, aveg;
    int prob[7];
} team;

team tm[32];

int cmp1(const void* a, const void* b) {
    team ai = *(team*)a;
    team bi = *(team*)b;
    if (ai.svd != bi.svd) return ai.svd < bi.svd ? 1 : -1;
    if (ai.sum != bi.sum) return ai.sum > bi.sum ? 1 : -1;
    if (ai.aveg != bi.aveg) return ai.aveg > bi.aveg ? 1 : -1;
    return strcmp(ai.name, bi.name);
}

int main(void) {
    int n, r;
    double gsum;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2002\\rank\\rank.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2002\\rank\\rank_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", tm[i].name);
            gsum = 0.0;
            for (int j = 0; j < 7; j++) {
                scanf("%d", &tm[i].prob[j]);
                tm[i].sum += tm[i].prob[j];
                if (tm[i].prob[j] > 0) {
                    tm[i].svd++;
                    gsum += log(tm[i].prob[j]);
                }
            }
            if (tm[i].svd > 0) {
                gsum /= tm[i].svd;
                tm[i].aveg = exp(gsum) + 0.500000001;
            }
        }
        qsort(tm, n, sizeof(team), cmp1);
        printf("CONTEST %d\n", tt);
        r = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && (tm[i].svd != tm[i - 1].svd || tm[i].sum != tm[i - 1].sum ||
                tm[i].aveg != tm[i - 1].aveg)) r = i + 1;
            printf("%02d %-10s %1d %4d %3d ", r, tm[i].name, tm[i].svd, tm[i].sum, tm[i].aveg);
            for (int j = 0; j < 7; j++) {
                printf("%3d%c", tm[i].prob[j], j == 6 ? '\n' : ' ');
            }
        }
        for (int i = 0; i < n; i++) {
            tm[i].aveg = 0, tm[i].sum = 0, tm[i].svd = 0;
        }
    }
    return 0;
}