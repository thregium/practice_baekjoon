#include <stdio.h>

/*
���� : N(N <= 1000)���� ��¥�� ��ħ���� ���� ������� �־�����. �̶� ������ ���� ���� ������ �� ���� ������
��ħ���� ���� ���� ���Ѵ�.

�ذ� ��� : ��, ���� ���� ��¥�� ���ӵǾ�����, �Ǵ� ���� ���� ���� �� ���̸� ���� ���ӵǾ�����(���⿡ �����Ѵ�.)
�ƴϸ� ���� ���� ��, ���� �� ������ Ȯ���Ѵ�. �� 3������ ���Եȴٸ� ������ ���̴�.

�ֿ� �˰��� : ����

��ó : Latin 2008 E��
*/

int d[1024], m[1024], y[1024], c[1024];
int lday[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int lday2[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isleap(int y) {
    if (y & 3) return 0;
    else if (y % 100) return 1;
    else if (y % 400) return 0;
    else return 1;
}

int main(void) {
    int n, r1, r2;
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2008\\testset_2008\\electricity.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &d[i], &m[i], &y[i], &c[i]);
            if (i == 0) continue;
            if (d[i] == d[i - 1] + 1 && m[i] == m[i - 1] && y[i] == y[i - 1]) {
                r1++;
                r2 += c[i] - c[i - 1];
            }
            else if (!isleap(y[i]) && y[i] == y[i - 1] && m[i] == m[i - 1] + 1 && d[i] == 1 && d[i - 1] == lday[m[i - 1]]) {
                r1++;
                r2 += c[i] - c[i - 1];
            }
            else if (isleap(y[i]) && y[i] == y[i - 1] && m[i] == m[i - 1] + 1 && d[i] == 1 && d[i - 1] == lday2[m[i - 1]]) {
                r1++;
                r2 += c[i] - c[i - 1];
            }
            else if (y[i] == y[i - 1] + 1 && m[i] == 1 && m[i - 1] == 12 && d[i] == 1 && d[i - 1] == 31) {
                r1++;
                r2 += c[i] - c[i - 1];
            }
        }
        printf("%d %d\n", r1, r2);
    }
    return 0;
}