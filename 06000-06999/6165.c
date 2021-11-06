#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 200)���� ���� �ٸ� ����(|��ǥ ����| <= 1000)�� �־�����. �̶�, �� ������ �̾ ���� �� �ִ�
�������� ���� ���� ������ ���Ѵ�.

�ذ� ��� : �� ������ �ֿ� ���� ��ǥ�� ���̸� �����ϰ� X��ǥ�� �þ�� �������� ���� �ٲ�д�.
X��ǥ�� 0�� ��� Y��ǥ�� �þ�� �������� �ٲ۴�. �� ��, �� �ֵ��� ������ ���� �����ص� ����,
��� �ֿ� ���� ������ ���� ���� �ֵ��� ���� �ȴ�.

�ֿ� �˰��� : ����, ����, ���Ʈ ����

��ó : USACO 2008F S1��
*/

int point[256][2], line[32768][2];

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int ay = *((int*)a + 1);
    int bx = *(int*)b;
    int by = *((int*)b + 1);
    return ax * by > bx * ay ? 1 : ax * by == bx * ay ? 0 : -1;
}

int main(void) {
    int n, lp = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            line[lp][0] = point[i][0] - point[j][0];
            line[lp][1] = point[i][1] - point[j][1];
            if (line[lp][0] < 0) {
                line[lp][0] *= -1;
                line[lp][1] *= -1;
            }
            else if (line[lp][0] == 0) line[lp][1] = 1;
            lp++;
        }
    }
    qsort(line, lp, sizeof(int) * 2, cmp1);

    for (int i = 0; i < lp; i++) {
        if (i > 0 && line[i][0] * line[i - 1][1] == line[i][1] * line[i - 1][0]) continue;
        r++;
    }
    printf("%d", r);
    return 0;
}