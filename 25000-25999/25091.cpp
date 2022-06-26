#include <stdio.h>
#include <vector>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� Ʈ���� �ִ�. Ʈ���� �� ������ ���� �θ� ������
�� �������� ��ȣ�� �۴�. �̶� �� �������� ����Ͽ� ���� �湮���� ���� ������ ��� �������� �̵��ϴ�
�������� ���� �ִ��� ���� �ִ��� ���Ѵ�.

�ذ� ��� : ���ʺ��� ���Ǹ鼭 �� ������ �ִ��� ������ ������. �� ������ ���� ���� ���
���� �ִ��� ���� ���� �����ϰ� �������� ���� ���� ������ ��� �ᱣ���� ���Ѵ�.
�θ� ������ ���� ������ ��� �״�� ���Ѵ�.

�ֿ� �˰��� : DP, Ʈ��DP, �׸��� �˰���?

��ó : GCJ 2022Q D��
*/

int f[103000], p[103000], mem[103000];
vector<int> c[103000];

int main(void) {
    int t, n, best;
    long long res = 0, sum;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &f[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            c[p[i]].push_back(i);
        }

        res = 0;
        for (int i = n; i >= 1; i--) {
            mem[i] = f[i];
            if (c[i].size() == 0) continue;
            best = INF, sum = 0;
            for (int j : c[i]) {
                if (mem[j] < best) best = mem[j];
                sum += mem[j];
            }
            res += sum - best;
            if (best > mem[i]) mem[i] = best;
        }
        for (int i : c[0]) res += mem[i];

        printf("Case #%d: %lld\n", tt, res);
        for (int i = 0; i <= n; i++) c[i].clear();
    }
    return 0;
}