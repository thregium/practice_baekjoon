#include <stdio.h>

/*
���� : H���� �ֵ��׿� B(H, B <= 100)���� �ܹ��Ű� �ְ�, ������ ���԰� �־��� �� �� ������ ���Ը� ��Ȯ�� ���� �ϱ� ���� �ʿ��� �ּ����� ���� ���� ���Ѵ�.

�ذ� ��� : ���� ������ ����� ������� Ǯ �� �ִ�. ��, �̶��� ������ ������ ���ο� �Բ� �ش� ���Կ� �ʿ��� �ּ� ������ ������ ���� �����ؾ� �Ѵ�.

�ֿ� �˰��� : ���̳��� ���α׷���, ����

��ó : NAQ 2016 H��
*/

int hi[128], bi[128], mem1[128][103000], mem2[128][103000];

int main(void) {
    int h, b, s, r = 666;
    scanf("%d", &h);
    for (int i = 1; i <= h; i++) {
        scanf("%d", &hi[i]);
    }
    scanf("%d", &b);
    for (int i = 1; i <= b; i++) {
        scanf("%d", &bi[i]);
    }
    mem1[0][0] = 1;
    mem2[0][0] = 1;
    s = 0;
    for (int i = 1; i <= h; i++) {
        s += hi[i];
        for (int j = 0; j <= s; j++) {
            if (mem1[i - 1][j]) mem1[i][j] = mem1[i - 1][j];
            if (j >= hi[i] && mem1[i - 1][j - hi[i]]) {
                if (mem1[i][j] && mem1[i][j] <= mem1[i - 1][j - hi[i]] + 1) continue;
                else mem1[i][j] = mem1[i - 1][j - hi[i]] + 1;
            }
        }
    }
    s = 0;
    for (int i = 1; i <= b; i++) {
        s += bi[i];
        for (int j = 0; j <= s; j++) {
            if (mem2[i - 1][j]) mem2[i][j] = mem2[i - 1][j];
            if (j >= bi[i] && mem2[i - 1][j - bi[i]]) {
                if (mem2[i][j] && mem2[i][j] <= mem2[i - 1][j - bi[i]] + 1) continue;
                else mem2[i][j] = mem2[i - 1][j - bi[i]] + 1;
            }
        }
    }

    for (int i = 1; i <= 100000; i++) {
        if (mem1[h][i] && mem2[b][i]) {
            if (mem1[h][i] + mem2[b][i] < r) r = mem1[h][i] + mem2[b][i];
        }
    }
    if (r == 666) printf("impossible");
    else printf("%d", r - 2);
    return 0;
}