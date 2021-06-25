#include <stdio.h>

/*
���� : 1������ 100������ 100���� �л�ȸ�� �ĺ��� �ְ�, M(M <= 1000)���� �л����� �̵� �� �ϳ��� �̴´�. ���� ����� �л�ȸ�� �ĺ��� ������.
���⼭ �ĺ��� ���� �ڸ��� N(N <= 20)�� ���ε�, �� �ڸ��� ���� ��쿡�� ���� �ڸ��� �ִ� ��� ��� ���� ��ǥ���� ���� ����� ������ ��� �ɴ´�.
�׷��� ����� ������ ��쿡�� ���� ���� ���� ����� ������. ������ ��쿡�� ��ǥ���� �ʱ�ȭ�ȴ�.
��� ����� ��ǥ�� ������ �� �ĺ��� ������ ����� ������� ���Ѵ�.

�ذ� ��� : ������� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ���� 2007 ��1��
*/

int picture[32][3], cnt[128];

int main(void) {
    int n, m, x, t, lowest;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        t = 0;
        lowest = 0;
        for (int j = 0; j < n; j++) {
            if (picture[j][0] == x || picture[j][0] == 0) {
                picture[j][0] = x;
                picture[j][1]++;
                if (picture[j][0] == 0) picture[j][2] = i;
                t = 1;
                break;
            }
            if ((picture[j][1] < picture[lowest][1]) || (picture[j][1] == picture[lowest][1] && picture[j][2] < picture[lowest][2])) {
                lowest = j;
            }
        }
        if (!t) {
            picture[lowest][0] = x;
            picture[lowest][1] = 1;
            picture[lowest][2] = i;
        }
    }
    for (int i = 0; i < n; i++) cnt[picture[i][0]]++;
    for (int i = 1; i <= 100; i++) {
        if (cnt[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}