#include <stdio.h>

/*
���� : N(N <= 1000)���� ������ �ִ� Tchoukaillon ���忡�� �̱� �� �ִ� ��츦 ����Ѵ�. �̷��� ���� �����ϴ�.

�ذ� ��� : 1�� �� ���� �������� �ö󰡸� ������ ���ƺ��� �ȴ�. ��� ������ ������ �����̸� �� ĭ�� �������� �������,
���� ĭ�� ������ 1���� �þ�� �ȴ�. ����, �̸� �������� �ϸ� �� ĭ�� ������ ���� �� ���� �������� 1���� ����� �ȴ�.
�̶�, �� ĭ������ ������ �� �� ���� ������ ���� ���� �� ĭ�� ������ ���ƾ� �Ѵ�. �̸� N�� �ݺ��ϸ� ���ϴ� ���¸� ���� �� �ִ�.

�ֿ� �˰��� : �ֵ� Ȥ?

��ó : GNY 2014 E��
*/

int res[128];

int main(void) {
    int t, tn, n, b;
    //freopen("E:\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2014\\e.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2014\\e_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &tn, &n);
        b = 0;
        for (int i = 0; i < 128; i++) res[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= b; j++) {
                if (res[j] == 0) {
                    res[j] = j + 1;
                    for (int k = 0; k < j; k++) res[k]--;
                    if (j == b) b++;
                    break;
                }
            }
        }
        printf("%d %d\n", tn, b);
        for (int i = 0; i < b; i++) {
            printf("%d", res[i]);
            if (i < b - 1) printf("%c", (i + 1) % 10 ? ' ' : '\n');
        }
        printf("\n");
    }
    return 0;
}