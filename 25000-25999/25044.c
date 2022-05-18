#include <stdio.h>

/*
���� : 15��, 18��, 21�ÿ� ������ �� ��° ���� �� ���� K(K < 60)�е��� �����Ǵ� �������� �ִ�.
N(N <= 1000)��°�� ������ �ð��� ��� ����Ѵ�.

�ذ� ��� : �ð��� �帧�� �ùķ��̼��ϸ鼭 ���� �ȿ� �������� ���� Ƚ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : DGIST 2022 A��
*/

int res[16];

int inrange(int tm, int n) {
    if (tm < n * 1440 || (n + 1) * 1440 <= tm) return 0;
    else return 1;
}

int main(void) {
    int n, k, tm = 0, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; tm < (n + 1) * 1440; i++) {
        if (i == 0) tm += 15 * 60;
        else tm += 18 * 60 + k;
        if (inrange(tm, n)) res[r++] = tm % 1440;
        tm += 3 * 60;
        if (inrange(tm, n)) res[r++] = tm % 1440;
        tm += 3 * 60;
        if (inrange(tm, n)) res[r++] = tm % 1440;
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%02d:%02d\n", res[i] / 60, res[i] % 60);
    }
    return 0;
}