#include <stdio.h>

/*
���� : N(N <= 100)���� ���簢���� �ִ�. �̶�, �� ���簢���� ���̿� �ʺ� ���� �����ϴ� ������ ���� ��,
���� �� �ִ� ���簢���� �ִ� ������ ���Ѵ�. ���簢���� ���̿� �ʺ�� 1000 ���ϸ� ���̿� �ʺ� ��� ���� ���(�Ǵ� 90�� ������ ���� ���)�� ����.
����, ���簢���� 90�� ������ �״� �͵� �����ϴ�.

�ذ� ��� : ��� ���簢���� �ֿ� ���� ������ ���̿� �ʺ� ��� �ٸ� �� ������ ��� ���� ������ ���ϴ� ������ �߰��Ѵ�.
���̿� �ʺ� ���� ��찡 ���� ������ �� �׷����� �׻� DAG�� �ȴ�. ����, ���� ������ ���� ���� ���� ���� �� �ִ� ���� ������ ����
�Ź� ���ذ��� ���� ���� ���� �� �ִ� ��츦 ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���� ����

��ó : ���� 1999 ��3��
*/

int papers[128][2], revs[128][128], eds[128][128], best[128], ins[128], vis[128];

int main(void) {
    int n, r = 0, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &papers[i][0], &papers[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        best[i] = 1;
        for (int j = i + 1; j <= n; j++) {
            if ((papers[i][0] == papers[j][0] && papers[i][1] == papers[j][1]) || (papers[i][1] == papers[j][0] && papers[i][0] == papers[j][1])) {
                best[i]++;
            }
            else if ((papers[i][0] <= papers[j][0] && papers[i][1] <= papers[j][1]) || (papers[i][1] <= papers[j][0] && papers[i][0] <= papers[j][1])) {
                eds[j][++eds[j][0]] = i;
                revs[i][++revs[i][0]] = j;
                ins[i]++;
            }
            else if ((papers[i][0] >= papers[j][0] && papers[i][1] >= papers[j][1]) || (papers[i][1] >= papers[j][0] && papers[i][0] >= papers[j][1])) {
                eds[i][++eds[i][0]] = j;
                revs[j][++revs[j][0]] = i;
                ins[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[j] || ins[j]) continue;
            vis[j] = 1;
            t = 0;
            for (int k = 1; k <= revs[j][0]; k++) {
                if (best[revs[j][k]] > t) t = best[revs[j][k]];
            }
            best[j] += t;
            for (int k = 1; k <= eds[j][0]; k++) {
                ins[eds[j][k]]--;
            }
            if (best[j] > r) r = best[j];
            break;
        }
    }
    printf("%d", r);
    return 0;
}