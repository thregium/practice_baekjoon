#include <stdio.h>
#include <stdlib.h>

/*
���� : ������ �湮�ڵ��� ���� �ð����� �ɴ� �ڸ��� ��Ģ�� �־�����, ��� �湮�ڵ��� �Խǰ� ��� �ð��� �־��� ��,
�־����� �ڸ��� ����ִ� �ð��� �󸶳� �Ǵ��� ���Ѵ�.

�ذ� ��� : ��� �湮�ڵ��� �Խ� �ð��� ���� ������ ����, ������� ��� �¼��� ã�� ���� �̿� �ð����� �ش� �¼��� �����Ѵ�.
�̸� �ݺ��� ���� ��� �ð��� ���� �־����� �ڸ��� ����ִ� �ð��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : shake! 2020 A��
*/

int lbr[768][128];
int tm[512][2];

int timecvt(int a) {
    return (a - 900) / 100 * 60 + a % 100;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int ac = *((int*)a + 1);
    int bc = *((int*)b + 1);
    if (ai > bi) {
        return 1;
    }
    else if (ai < bi) {
        return -1;
    }
    else if (timecvt(ac) - timecvt(ai) > timecvt(bc) - timecvt(bi)) {
        return 1;
    }
    else if (timecvt(ac) - timecvt(ai) < timecvt(bc) - timecvt(bi)) {
        return -1;
    }
    else {
        return 0;
    }
}

int find_seat(int n, int s) {
    int a, x, mdist = 0, mdistp = 0;
    a = 1;
    for (int i = 1; i <= n; i++) {
        if (lbr[s][i]) a = 0;
    }
    if (a) return 1;
    for (int i = 1; i <= n; i++) {
        if (lbr[s][i]) continue;
        for (x = 1;; x++) {
            if (i - x >= 1 && lbr[s][i - x]) break;
            if (i + x <= n && lbr[s][i + x]) break;
        }
        if (x > mdist) {
            mdist = x;
            mdistp = i;
        }
    }
    return mdistp;
}

int main(void) {
    int n, t, p, stime, etime, seat, r = 0;
    scanf("%d %d %d", &n, &t, &p);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &tm[i][0], &tm[i][1]);
    }
    qsort(tm, t, sizeof(int) * 2, cmp1);
    for (int i = 0; i < t; i++) {
        stime = (tm[i][0] - 900) / 100 * 60 + tm[i][0] % 100;
        etime = (tm[i][1] - 900) / 100 * 60 + tm[i][1] % 100;
        seat = find_seat(n, stime);
        for (int j = stime; j < etime; j++) {
            lbr[j][seat] = i + 1;
        }
    }
    for (int i = 0; i < 720; i++) {
        if (!lbr[i][p]) r++;
    }
    /*
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 720; j += 10) {
            printf("%c", lbr[j][i] ? lbr[j][i] + 'A' - 1 : '.');
        }
        printf("\n");
    }
    */
    printf("%d", r);

    return 0;
}