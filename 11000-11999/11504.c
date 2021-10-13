#include <stdio.h>

/*
���� : ���� N(N <= 100)���� ĭ���� ������ ����, �� ĭ�� 0���� 9 ������ ���ڸ� ��־���. �̶�, M(M <= 9)�ڸ� �ڿ���
X <= Y�� �־��� ��, �ð�������� �����ؼ� Mĭ�� ���� ���� X�� Y ������ ���� ������ ���Ѵ�.

�ذ� ��� : �� ĭ�� ���ؼ� Mĭ�� �����ؼ� ������ ������ ����Ѵ�. �׸���, �� �ڸ����� ���� �迭�� X, Y�� ���� ���Ѵ�.
�迭�� X �̻��̰� Y ������ ��� ������ �����ϴ� ���̹Ƿ� ���� �ȴ�. �ڸ����� �׻� �����Ƿ� ������ �ʿ䰡 ����.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : Daejeon 2015 L��
*/

int x[16], y[16], tmp[16], rot[128];

int cmp(int* a, int* b, int n) {
    //�迭 �� �Լ�
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) return -1;
        else if (a[i] > b[i]) return 1;
    }
    return 0;
}

int main(void) {
    int t, n, m, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &y[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &rot[i]);
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[j] = rot[(i + j) % n];
            }
            if (cmp(x, tmp, m) <= 0 && cmp(tmp, y, m) <= 0) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}