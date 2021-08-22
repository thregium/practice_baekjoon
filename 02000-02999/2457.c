#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)������ ��/�� ������ �� ������ �־��� ��, �� �������� ���ؼ� 3�� 1�Ϻ��� 11�� 30�ϱ���
���� ���� ������ ���� �� �ִ��� Ȯ���ϰ� �����ϴٸ� ���� ���� ���� ������ ���� �� ���� ������ ���� ���Ѵ�.

�ذ� ��� : �� �������� �����Ѵ�. �� �������δ� 3�� 1�� ������ �����ϴ� �������� ���� �ʰ� ������ ������ ������ ã�´�.
�������δ� 3�� 1�� ���ĺ��� �� �� �� �������� �����ϴ� �������� ���� �ʰ� ������ ������ ������ ã�´�.
�̸� �ݺ��� ������ 11�� 30�� ���İ� �Ǵ� ù ������ ������ ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : ���� 2011�� ��3/��2��
*/

int flowers[103000][2];
int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m1, d1, m2, d2, lday = 60, next = -1, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
        flowers[i][0] = days[m1] + d1;
        flowers[i][1] = days[m2] + d2;
    }
    qsort(flowers, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (flowers[i][0] > lday) {
            if (next < 0) {
                printf("0");
                return 0;
            }
            lday = next;
            next = -1;
            if (lday >= 335) break;
            r++;
        }
        if (flowers[i][1] > next) next = flowers[i][1];
    }
    if (next < 335 && lday < 335) printf("0");
    else printf("%d", r);
    return 0;
}