#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 10000)���� �������� �̷���� Ʈ���� �־��� ��, �� Ʈ������ ������ �����Ͽ� ���صǴ� Ʈ�� ���
���� ū ���� ũ�Ⱑ N / 2 ���ϰ� �Ǵ� ������ ������������ ����Ѵ�. ������ NONE�� ����Ѵ�.

�ذ� ��� : ���� DFS�� �� Ʈ���� ��Ʈ�� 1�� Ʈ���� ���� ����, Ʈ�� DP�� ���� �� ������ ����Ʈ���� �ִ�
������ ���� ���Ѵ�. �� �������� �ش� ������ �ڽ��� ����Ʈ�� ��� ���� ū �Ͱ� �ش� ������ ����Ʈ���� ������
������ ���� �� �� ū ���� ũ�Ⱑ N / 2 ���ϰ� �Ǵ� ������ ����� �����Ѵ�.
�� �������� ������ ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : DP, Ʈ�� DP

��ó : USACO 2004D S3��
*/

int mem[10240], vis[10240], res[10240];
int rcnt = 0;
vector<int> ed[10240], child[10240];

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void dfs(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (vis[i]) continue;
        child[x].push_back(i);
        dfs(i);
    }
}

void dp(int n, int x) {
    int best = -1;
    mem[x] = 1;
    for (int i : child[x]) {
        dp(n, i);
        mem[x] += mem[i];
        best = big(best, mem[i]);
    }
    best = big(best, n - mem[x]);
    if (best * 2 <= n) res[rcnt++] = x;
}

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    dfs(1);
    dp(n, 1);
    qsort(res, rcnt, sizeof(int), cmp1);
    if (rcnt == 0) printf("NONE");
    else {
        for (int i = 0; i < rcnt; i++) {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}