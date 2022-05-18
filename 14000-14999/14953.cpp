#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 100000)���� ������ M(M <= 300000)���� �������� �̷���� ���� �׷����� �־�����.
�̶�, �ֺ� ������ ������ ������������ �����ϴ� ��� ��� ���� �� ���� ���̸� ���Ѵ�.

�ذ� ��� : �� ������ �ֺ� ������ ������ ���� ������� ������ ����, ������� �ֺ� ���� ���
���� ����� ���̰� �� ���� + 1�� ����� ������. �� �� ���� ���̰� �� ������ ��� ���̸� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, DP, ����

��ó : Daejeon 2017 C��
*/

int vsize[103000], nsort[103000], mem[103000];
vector<int> ed[103000];

int cmp1(const void* a, const void* b) {
    int ai = vsize[*(int*)a];
    int bi = vsize[*(int*)b];
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, a, b, r = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
        vsize[a]++;
        vsize[b]++;
    }
    for (int i = 0; i < n; i++) nsort[i] = i;
    qsort(nsort, n, sizeof(int), cmp1);

    for (int i = 0; i < n; i++) {
        a = nsort[i];
        mem[a] = 1;
        for (int j : ed[a]) {
            if (vsize[j] < vsize[a] && mem[j] + 1 > mem[a]) mem[a] = mem[j] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mem[i] > r) r = mem[i];
    }
    if (r <= 0) return 1;
    printf("%d", r);
    return 0;
}