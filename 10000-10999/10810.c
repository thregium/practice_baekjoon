#include <stdio.h>

/*
���� : N(N <= 100)���� �ٱ��ϰ� �ִ�. �� �ٱ��Ͽ� ������ �ִ� M(M <= 100)���� ���� ��
�� �ٱ��Ͽ� �ִ� ���� ������ ���� ����Ѵ�. ���� ���� ��� 0�� ����Ѵ�.
�� ����ÿ��� I�� �ٱ��Ϻ��� J�� �ٱ��ϱ����� K(K <= N)�� ���� �ִ´�. ���� �̹� �ִٸ� �ִ� ���� ���� �� ���� �ִ´�.

�ذ� ��� : N�� M�� �۱� ������ �� �ٱ����� ���� �� ������ �ٲٴ� �۾��� ������ �� �� �ְ�,
����, I���� J���� ���� ���찡�� ���� �ٲٴ��� ����� �ð� ���� ��� �۾��� ó���� �� �ִ�.

�ֿ� �˰����� : ����, �ùķ��̼�
*/

int ball[128];

int main(void) {
    int n, m, x, y, z;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        for (int j = x; j <= y; j++) {
            ball[j] = z;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ball[i]);
    }
    return 0;
}