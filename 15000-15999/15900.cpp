#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : ������ ���� N(N <= 500000)���� ��Ʈ�� 1�� Ʈ������ ��� �� ������ ������ ���� �ִ�.
�� �ϸ��� ������ ���� ��� 1ĭ ���� �ø��� ���� �� ���� �ݺ��ϰ�, ���̻� ���� ������ �� ���� ����� ���ٸ�
������ �̱� �� �ִ� �� ���Ѵ�.

�ذ� ��� : �׻� 1�ܰ� ���� �������θ� �̵��ϱ� ������ �̵��� �� ���� �� ���� ���� ����
��� �� ������ ����(�Ѹ� ������ ������ 0�� ��)�� ����.
����, �� ���� �÷������� ���� ���� ����, Ȧ���� ��� �̱�� ¦���� ��� ���ٰ� �ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, Ʈ��, �÷�����, ���� �̷�?

��ó : UCPC 2018�� D��
*/

vector<int> ed[524288];

long long dfs(int x, int d, int p) {
    int c = 0;
    long long r = 0;
    for (int i : ed[x]) {
        if (i == p) continue;
        r += dfs(i, d + 1, x);
        c++;
    }
    if (c == 0) return d;
    else return r;
}

int main(void) {
    int n, a, b;
    long long r;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    r = dfs(1, 0, -1);
    if (r & 1) printf("Yes");
    else printf("No");
    return 0;
}