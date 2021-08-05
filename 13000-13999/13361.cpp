#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 250000)���� ���簢���� ������ ȸ���ϸ鼭 ������, ��� ���簢���� ������� �ʺ� �����ϵ��� �� ��
���� �� �ִ� ���簢�� ������ �ִ��� ���Ѵ�. �׻� �׷��� ���� �� �ִ� ��츸 �־�����.

�ذ� ��� : �� ���簢���� ���̰� ���� �ٸ��ٸ� ū�ͺ��� �׻� �����Ͽ� �ʺ� �����ϵ��� ���� �� �ִ�.
����, ���簢���� ���̰� ��ġ�� ��쿡 ���ؼ��� �Ű澲�� �Ǵµ�, �̴� �׷��� �̷��� �̿��� �ذ� �����ϴ�.
�� ���簢���� �� ���� ���̰� ������ �ǰ�, �� ���簢���� �̷�� �� ���� ���̸� ���� ���� ������ �ȴ�.
�� �������� ��ǥ������ ���� ������ �ٿ��ش�.

���� �� �������� ������ ���Ѵ�. �����ϴ� ������ ���η� �дٸ�, ��� ������ ���� ������ 2�� ���ϰ� �Ǿ�� �Ѵ�.
(�ʺ� ���� ���簢���� �־�� �ȵȴ�.) �׷���, �׷��� ���� �� �ִ� ��츸 �־����µ� �̷��� �׷����� 2���� ���̴�.
�ϳ��� Ʈ���̰�, �ٸ� �ϳ��� Ʈ���� �ϳ��� ������ �� ���� �����̴�.

Ʈ���� ������ �߰��� ������ ��쿡�� ��� �������� �ѹ��� �����ؾ� �ϹǷ� ��� ������ �������� 1�� �� ����
���̷� ���ָ� �ǰ�,
Ʈ���� ��쿡�� �ϳ��� �������� �������� �ʾƵ� �ǹǷ� Ʈ��+1�� ��쿡�� ���� ���� ������ ���̸� �����ָ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, DFS

��ó : NCPC 2016 H��
*/

int irons[262144][2], weights[524288][3], ntw[524288], vis[524288];
vector<int> ed[524288];
long long r = 0, edc = 0, vtc = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void dfs1(int x) {
    //�������� �������� ���� ���� ���� Ʈ��/�׷��� ���� Ȯ��
    vis[x]++;
    vtc++;
    edc += ed[x].size();
    for (int y : ed[x]) {
        if (vis[y] == 0) {
            dfs1(y);
        }
    }
}

void dfs2(int x) {
    //Ʈ���� ���(���� �����Ϳ��� ���)
    vis[x]++;
    for (int y : ed[x]) {
        if (vis[y] == 1) {
            r += weights[ntw[x]][1];
            dfs2(y);
        }
    }
}

void dfs3(int x) {
    //Ʈ���� �ƴ� ���(��� ������ ���� �������� - 1���� ������)
    vis[x]++;
    r += weights[ntw[x]][1] * (ed[x].size() - 1);
    for (int y : ed[x]) {
        if (vis[y] == 1) {
            dfs3(y);
        }
    }
}

int main(void) {
    int n, mw = 1;
    //freopen("E:\\PS\\ICPC\\Europe\\NCPC\\2016\\ncpc2016-packages\\tower\\data\\secret\\25.cycle.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &irons[i][0], &irons[i][1]);
        weights[i << 1][0] = (i << 1);
        weights[i << 1][1] = irons[i][0];
        weights[(i << 1) + 1][0] = (i << 1) + 1;
        weights[(i << 1) + 1][1] = irons[i][1];
    }
    qsort(weights, n * 2LL, sizeof(int) * 3, cmp2);
    weights[0][2] = 1;
    ntw[1] = weights[0][0];
    for (int i = 1; i < (n << 1); i++) {
        if (weights[i][1] == weights[i - 1][1]) weights[i][2] = weights[i - 1][2];
        else {
            weights[i][2] = weights[i - 1][2] + 1;
            ntw[weights[i][2]] = weights[i][0];
            mw++;
        }
    }
    qsort(weights, n * 2LL, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        ed[weights[i << 1][2]].push_back(weights[(i << 1) + 1][2]);
        ed[weights[(i << 1) + 1][2]].push_back(weights[i << 1][2]);
    }
    for (int i = mw; i > 0; i--) {
        if (vis[i] == 2) continue;
        edc = 0, vtc = 0;
        dfs1(i);
        if (edc < vtc * 2) {
            dfs2(i);
        }
        else {
            dfs3(i);
        }
    }
    printf("%lld", r);
    return 0;
}