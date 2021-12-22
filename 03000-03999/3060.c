#include <stdio.h>

/*
���� : 6������ ������ �������� �ְ�, ���� ������ ���귮�� �־�����. �� �������� ó�� �Դ� ������ ���� ���� �־�����,
���̰� ���ڶ�� �Ǵ� ù ���� ���Ѵ�. ���̴� �������� �ʴ´�. �� ���� �������� ���� ���� ������ �翡 ����
���� �� ���� �ݴ��ʿ� �ִ� ������ ������ �� �ո�ŭ �Դ´�.

�ذ� ��� : ������ �־������ �����Ѵ�. ���� ������ �̿��ϸ� ���� ���� �� �ִ�.

�ֿ� �˰����� : ����, �ùķ��̼�
*/

long long feed[1024][6];

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < 6; i++) {
            scanf("%lld", &feed[1][i]);
        }
        for (int i = 1;; i++) {
            if (i == 1024) return 1;
            if (feed[i][0] + feed[i][1] + feed[i][2] + feed[i][3] + feed[i][4] + feed[i][5] > n) {
                printf("%d\n", i);
                break;
            }
            for (int j = 0; j < 6; j++) {
                feed[i + 1][j] = feed[i][j] + feed[i][(j + 1) % 6] + feed[i][(j + 3) % 6] + feed[i][(j + 5) % 6];
            }
        }
    }
    return 0;
}