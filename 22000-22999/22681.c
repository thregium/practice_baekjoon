#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10000)���� ���� ����/������ ����ϴ� ������ ������ ��:��:�� ������ �־�����.
�� �뼱�� ��ȯ���̱� ������ ������ ����� ������ �ٽ� ���� ������ �� �ְ� ������ 0�ʸ��� �ٽ� �����ϴ� �͵� �����ϴ�.
�̶�, �־��� �ð�ǥ�� ���߱� ���� �ʿ��� ������ �ּ� ����� ���Ѵ�. ��, ������ �Ѱ� ���� ���ִ� ������ ����.
(���ѽð� 8��)

�ذ� ��� : ���� ����� ������ ������ ���� ���� ������ �ٽ� ������ ������ �Ѵ�. �̷��� �Ǹ� �ش� ������ ���Ե� ������
���� ���� ��Ȱ���� �� ������, �̸� �ݺ��ϸ� ������ �ּ� ����� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : JAG 2007D B��
*/

int tm[10240][2], chk[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, h, m, s, r, end, arv;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2007D\\judge-data\\B\\B4", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2007D\\judge-data\\B\\B4_t.ans", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%d:%d:%d", &h, &m, &s);
                tm[i][j] = h * 3600 + m * 60 + s;
            }
        }
        qsort(tm, n, sizeof(int) * 2, cmp1);

        r = 0, arv = 0;
        while (arv < n) {
            end = 0;
            for (int i = 0; i < n; i++) {
                if (!chk[i] && tm[i][0] >= end) {
                    chk[i] = 1;
                    arv++;
                    end = tm[i][1];
                }
            }
            r++;
        }
        printf("%d\n", r);

        for (int i = 0; i < n; i++) chk[i] = 0;
    }
    return 0;
}