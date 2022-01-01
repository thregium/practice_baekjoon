#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 50)������ ������ �ɷ�ġ�� �־�����. �� ���� �� �ɷ�ġ�� ��� ����� �ɷ�ġ �̻��� ���
�� ��븦 ��Ƹ��� �� �ִ�. �� ���� �ִ� 2�������� ��Ƹ��� �� �ְ�, ���� ���ʷ� �ٸ� �� ��Ƹ԰� �ȴ�.
���� ���� ���� �ٸ� �� ���� �� ����. �̶�, ���� ����� �ּ� �������� ���Ѵ�.

�ذ� ��� : ���� ������ �Դ� ���(*2), ������ ������ ������ ���� �ΰ� �̺� ��Ī�� �ϸ� �ȴ�.
� ��Ī�� ���� ������ �� ���� �� �Ե��� �ϸ� �Ǳ� ������ �̺� ��Ī�� �����ȴ�.
��, ���� �ɷ�ġ�� ������ ���� ������ ���� �԰� ������ �ʵ��� ������ ������ ���ؼ� �Ϲ������� �԰� �������� �ؾ� �Ѵ�.

�ֿ� �˰��� : �̺� ��Ī 

��ó : SRM 358D1 1��
*/

int shark[64][3], left[128], right[64], vis[128];
vector<int> ed[128];

int match(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (right[i] == 0 || (!vis[right[i]] && match(right[i]))) {
            left[x] = i;
            right[i] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &shark[i][0], &shark[i][1], &shark[i][2]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (shark[i][0] == shark[j][0] && shark[i][1] == shark[j][1] && shark[i][2] == shark[j][2]) {
                if (j > i) {
                    ed[i * 2].push_back(j);
                    ed[i * 2 - 1].push_back(j);
                }
            }
            else if (shark[i][0] >= shark[j][0] && shark[i][1] >= shark[j][1] && shark[i][2] >= shark[j][2]) {
                ed[i * 2].push_back(j);
                ed[i * 2 - 1].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n * 2; i++) {
        r += match(i);
        for (int j = 1; j <= n * 2; j++) vis[j] = 0;
    }
    printf("%d", n - r);
    return 0;
}