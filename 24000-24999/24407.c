#include <stdio.h>

/*
���� : C(C <= 100000)���� ������ ��� N(N <= 1000)���� �߸��� ������ ����� �־�����,
�߸��� �����Ϳ� ��Ȯ�� �����͸� ������ ��� ���� ����Ѵ�.

�ذ� ��� : ������ ������ ���� �迭�� ������ �� �ִ� �����̹Ƿ� �����͵��� �迭�� �ű� ��,
������ �����͵��� ���� ������� �������� ������ ����, ���Ŀ� �°� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : NAQ 2021 G��
*/

int ec[103000], err[103000][2], corr[103000][2];

int main(void) {
    int c, n, x, stt = 1, ep = 0, cp = 0;
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        ec[x] = 1;
    }
    for (int i = 2; i <= c; i++) {
        if (ec[i] != ec[i - 1]) {
            if (!ec[i]) {
                err[ep][0] = stt;
                err[ep][1] = i - 1;
                ep++;
            }
            else {
                corr[cp][0] = stt;
                corr[cp][1] = i - 1;
                cp++;
            }
            stt = i;
        }
    }
    if (ec[c]) {
        err[ep][0] = stt;
        err[ep][1] = c;
        ep++;
    }
    else {
        corr[cp][0] = stt;
        corr[cp][1] = c;
        cp++;
    }
    printf("Errors: ");
    for (int i = 0; i < ep; i++) {
        if (err[i][0] == err[i][1]) printf("%d", err[i][0]);
        else printf("%d-%d", err[i][0], err[i][1]);
        if (i < ep - 2) printf(", ");
        else if (i == ep - 2) printf(" and ");
    }
    printf("\nCorrect: ");
    for (int i = 0; i < cp; i++) {
        if (corr[i][0] == corr[i][1]) printf("%d", corr[i][0]);
        else printf("%d-%d", corr[i][0], corr[i][1]);
        if (i < cp - 2) printf(", ");
        else if (i == cp - 2) printf(" and ");
    }
    return 0;
}