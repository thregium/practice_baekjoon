#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

/*
���� : N(N <= 50000)������ �Ұ� �� ��ǥ(|| <= 10^9)�� �ִ�. �� ���� Ű(<= 10^9)�� �־��� ��,
�Ÿ� D(D <= 10^9) ������ �� ���� �ڽ��� Ű * 2 �̻��� �Ұ� �ִ� ���� �������� ���Ѵ�.

�ذ� ��� : �� ���� ���ʰ� ������ ������ �޴� ������ ���� �� �ҵ��� Ű�� ��Ƽ�¿� ������ ��,
�� ��Ƽ���� �ִ��� �� ���� Ű * 2 �̻��� ���� �������� ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��Ƽ��, �� ������

��ó : USACO 2013N S2��
*/

int cow[51200][2];
multiset<int> lt, rt;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, d, ls = 0, le = -1, rs = 0, re = -1, res = 0;
    //freopen("crowded.in", "r", stdin);
    //freopen("crowded.out", "w", stdout);
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cow[i][0], &cow[i][1]);
    }
    qsort(cow, n, sizeof(int) * 2, cmp1);

    for (int i = 0; i < n; i++) {
        while (re < n - 1 && cow[re + 1][0] <= cow[i][0] + d) {
            re++;
            rt.insert(cow[re][1]);
        }
        while (rs <= re && cow[rs][0] <= cow[i][0]) {
            rt.erase(rt.find(cow[rs][1]));
            rs++;
        }
        while (le < i - 1 && cow[le + 1][0] < cow[i][0]) {
            le++;
            lt.insert(cow[le][1]);
        }
        while (ls <= le && cow[ls][0] < cow[i][0] - d) {
            lt.erase(lt.find(cow[ls][1]));
            ls++;
        }

        if (lt.size() >= 1 && rt.size() >= 1 &&
            *lt.rbegin() >= cow[i][1] * 2 && *rt.rbegin() >= cow[i][1] * 2) {
            res++;
        }
    }
    printf("%d", res);
    return 0;
}