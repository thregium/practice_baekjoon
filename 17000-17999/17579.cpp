#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#define INF 0x7A35090F
using namespace std;

/*
���� : ���� N(N <= 100)���� ����(<= 10^9, �ڿ���)�� �� N(N <= 10)�� �� �Ϻ� �Ǵ� ���θ� ����Ͽ�
�� �� �ִ� �� ���Ѵ�. �� ���� ���Դ� 10^8 ������ �ڿ����̸�, ���� ������ �߰� ���� �� �ִ�.
�׷��� ����� �ִٸ� 0��, �� 1���� �߰��� �� �� �ִ� ����� �ִٸ� ���� ������ �� ���� ���Ը� ����Ѵ�.
�׷��� ����� ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : �� �߸� ���ʰ� �����ʿ� �÷��� �� �� �� �ִ� ��� ���Ե��� (������ �����ؼ�) �ؽü¿� ��´�.
�׸��� �� �� ������ ���Ը��� �ؽü¿��� ã�� �� �ִٸ� �Ѿ�� �ƴ϶�� �ش� ������ ���Կ�
�ؽü¿� �ִ� �� ���� ���� ���ο� �ؽü¿� ��´�. �̸� �ݺ��� ����, ��� ���� ã�� �� �־��� �� Ȯ���Ѵ�.
�׷��ٸ� 0�� ����ϰ�, �׷��� �ʴٸ� ��� ���ο� �ؽü¿� ������ ���� �ִ� �� Ȯ���Ѵ�.
�ִٸ� �� �� �� ���� ���� ���� ����ϸ� �ȴ�. �� �� ��� ��쿡�� -1�� ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, �ؽü�

��ó : JDC 2019 C��
*/

int meas[16], weight[128];
const int b3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
unordered_set<int> scale, cand, ncand;

int main(void) {
    int n, m, w, r;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2019\\judgedata\\C\\C4", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2019\\judgedata\\C\\C4_t.out", "w", stdout);
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &weight[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &meas[i]);
        }
        for (int i = 0; i < b3[m]; i++) {
            w = 0;
            for (int j = i, k = 0; k < m; j /= 3, k++) w += meas[k] * (j % 3 - 1);
            scale.insert(w);
        }
        w = 0;
        for (int i = 0; i < n; i++) {
            if (scale.find(weight[i]) != scale.end()) continue;
            if (w == 0) {
                for (int j : scale) cand.insert(abs(weight[i] - j));
                w = 1;
            }
            else {
                for (int j : scale) {
                    if (cand.find(abs(weight[i] - j)) != cand.end()) ncand.insert(abs(weight[i] - j));
                }
                cand.clear();
                for (int j : ncand) cand.insert(j);
                ncand.clear();
            }
        }
        if (w == 0) printf("0\n");
        else if (cand.empty()) printf("-1\n");
        else {
            r = INF;
            for (int i : cand) {
                if (i < r) r = i;
            }
            printf("%d\n", r);
        }
        cand.clear();
        scale.clear();
    }
    return 0;
}