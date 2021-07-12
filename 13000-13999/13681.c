#include <stdio.h>
#define SZ 131072

/*
���� : �� ���� �÷��̾ N(N <= 100000)���� 1 ~ N������ �ڿ����� �̷���� ������ �̿��� ������ �����Ѵ�.
�� �ϸ��� �÷��̾�� ������ �� �� ��� �� ���� �� ū �� ���� ������ �ٲ۴�. �̶� �̷��� ���� �������� ���
���� ������ ���� ����. �ٲ� �� �ִ� ���� ���ٸ� ����. �̶� �̱�� �÷��̾ ���Ѵ�.

�ذ� ��� : �÷��̾��� ���ÿ� ������� ó�� ������ ���� �ٲ� �� �ִ� Ƚ���� �������ִ�.
�� ���� ���� ��Ʈ���� ��ȯ ������ Ƚ���� ������, 1517���� Ǯ�̸� �״�� ������ ����, �� ���� Ȧ���� ���
������ �̱�� ¦���� ��� �İ��� �̱�ٰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��, ���� �̷�

��ó : Brasil 2008 E��
*/

int x[103000];
long long seg[SZ << 1];

void upd(int p, int n) {
    seg[SZ + p] = n;
    for (int i = ((SZ + p) >> 1); i > 0; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

long long find(int fs, int fe, int ss, int se, int p) {
    if (fs > se || fe < ss) return 0;
    else if (fs <= ss && se <= fe) return seg[p];
    else return find(fs, fe, ss, (ss + se) >> 1, p << 1) + find(fs, fe, ((ss + se) >> 1) + 1, se, (p << 1) + 1);
}

int main(void) {
    int n;
    long long r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\E.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x[i]);
            upd(x[i], 1);
            r += x[i] - find(0, x[i] - 1, 0, SZ - 1, 1) - 1;
        }

        for (int i = 1; i <= n; i++) {
            upd(i, 0);
        }
        if (r & 1) printf("Marcelo\n");
        else printf("Carlos\n");
    }
    return 0;
}