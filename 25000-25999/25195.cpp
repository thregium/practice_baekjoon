#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 100000)���� ������ M(M <= 100000)���� �������� �̷���� DAG�� 1�� ��������
S(S <= N)���� �־��� ���� ��� �ϳ��� ������ �ʰ� ���̻� �̵� �Ұ����� �� ����
�̵��ϴ� ����� �ִ� �� ���Ѵ�.

�ذ� ��� : �÷������� ���� 1�� �������� ����Ͽ� ����� Ȯ���ϵ�, ���̳��� ���α׷����� �̿��Ͽ�
�� �� �湮�� ������ ����� ������ �˾Ƴ����� �ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, DP

��ó : ������ 1ȸ E��
*/

int fan[103000], mem[103000];
vector<int> ed[103000];

int avoidable(int x) {
    if (fan[x]) return mem[x] = 0;
    if (ed[x].size() == 0) return mem[x] = 1;
    if (mem[x] >= 0) return mem[x];
    int r = 0;
    for (int i : ed[x]) {
        r |= avoidable(i);
    }
    return mem[x] = r;
}

int main(void) {
    int n, m, f, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) mem[i] = -1;
    scanf("%d", &f);
    for (int i = 0; i < f; i++) {
        scanf("%d", &a);
        fan[a] = 1;
    }
    for (int i = 1; i <= 1; i++) {
        r |= avoidable(i);
    }
    printf("%s", r ? "yes" : "Yes");
    return 0;
}