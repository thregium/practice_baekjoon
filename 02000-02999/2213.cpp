#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� : N(N <= 10000)���� �������� �̷���� Ʈ������ �� ������ ����ġ(<= 10000, �ڿ���)�� �־��� ��,
�ִ� ���� ������ ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� ���� ������ �������� ���� �������� �ʾ��� ���� �ִ��� ������ �� ���� Ǯ�� �ȴ�.
�̸� �ٽ� �������Ͽ� �ִ� ���� ������ ���ؾ� �ϴµ�, �̴� �θ� ����� ���� ���θ� �̿��� ���س����� �ȴ�.
�θ� ��带 �����ߴٸ� �� �ڽ� ���� �ݵ�� �������� �ʾƾ� �Ѵ�. �������� ���� ��쿡�� �θ� ���� �ڽ� �����
�� ��� ��� �� ū ���� �������� ������ ���̴�. ����, �� ū ��츦 Ȯ���� �� ��찡
�����ϴ� ����� ���� ���� ���տ� �߰��ϸ� �ȴ�.

�ֿ� �˰��� : DP, Ʈ��DP, ������
*/

int w[10240], mem[10240][2];
vector<int> ed[10240], group;

int big(int a, int b) {
    return a > b ? a : b;
}

void dp(int x, int p) {
    mem[x][1] = w[x];
    for (int i : ed[x]) {
        if (i == p) continue;
        dp(i, x);
        mem[x][0] += big(mem[i][0], mem[i][1]);
        mem[x][1] += mem[i][0];
    }
}

void track(int x, int p, int s) {
    if (s) {
        for (int i : ed[x]) {
            if (i == p) continue;
            track(i, x, 0);
        }
    }
    else {
        int sum = 0;
        if (mem[x][1] > mem[x][0]) group.push_back(x);
        for (int i : ed[x]) {
            if (i == p) continue;
            track(i, x, mem[x][1] > mem[x][0]);
        }
    }
}

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dp(1, -1);
    track(1, -1, 0);
    printf("%d\n", big(mem[1][0], mem[1][1]));
    sort(group.begin(), group.end());
    for (int i : group) {
        printf("%d ", i);
    }
    return 0;
}