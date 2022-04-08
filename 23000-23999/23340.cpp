#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� : N(N <= 200000)���� �������� �̷���� Ʈ���� �ִ�. Ʈ���� �� ������ ��(<= 10^9)�� �־�����
���� �ö󰡴� ������� �̵��ϴ� ����� ������ ���Ѵ�. ��, ������ 1�� �̻� ������ �Ѵ�.
����, �����Ͽ� ���� ���Ƽ��� �� �ȴ�.

�ذ� ��� : �� �������� �ش� ������ ������� �ϴ� �������� ��ο� �������� �ϴ� �ö���� �����
������ �Ź� �����صд�. ��, �� ������ �� ���� �ö�� �� �ִ� ��θ� �����ؾ� �Ѵ�.
�� �������� �ö���� ��δ� ��� �Ʒ� ������ �ö���� ��� �� + 1�� �ȴ�. �� �������� �θ� ��������
�ö󰡴� ������ ������ ���� ������ �ö���� ��θ��� �̹� ������ ��ο� �߰��Ѵ�.
�������� ��ε� ����� ������� ���� �� �ִ�. ��� �θ� �������� ū ������ �������� ��θ��� �߰��Ѵ�.
����, �� �������� �ش� ������ ������ �������� ��ε鵵 ���Ѵ�.
�̴� �� �Ʒ� �����鸶�� �� ���� �������� �ö�ͼ� �� ū �������� �������� ������ ��� ���� ���� ����
���ϴ� ������� Ǯ �� �ִ�. �̴� ������ ���� ������������ ������ ���� ���� ���� �̿��ϴ� �������
����ϸ� O(N)�� ��� ������ ���� ���� �� �ִ�. ��, �� �������� ���� ���� ������ �����Ѵ�.

�ֿ� �˰��� : DP, Ʈ��DP, ����

��ó : TOPC 2021 G��
*/

int mem[204800][2];
vector<pair<int, int>> ed[204800], chd[204800];
pair<int, int> par[204800];
long long res = 0;

void mktree(int x, int p) {
    for (auto& i : ed[x]) {
        if (i.second == p) continue;
        chd[x].push_back(i);
        par[i.second] = { i.first, x };
        mktree(i.second, x);
    }
}

void dp(int x) {
    long long up = 0, down = 0, last = -1;
    for (auto& i : chd[x]) {
        dp(i.second);
        up += mem[i.second][0] + 1;
        if (x != 1 && i.first < par[x].first) mem[x][0] += mem[i.second][0] + 1;
        down += mem[i.second][1] + 1;
        if (x != 1 && i.first > par[x].first) mem[x][1] += mem[i.second][1] + 1;
    }
    res += up + down;
    up = 0;
    for (auto& i : chd[x]) {
        if (i.first != last) {
            res += up * down;
            up = 0;
        }
        up += mem[i.second][0] + 1;
        down -= mem[i.second][1] + 1;
        last = i.first;
    }
}

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back({ c, b });
        ed[b].push_back({ c, a });
    }
    mktree(1, -1);
    for (int i = 1; i <= n; i++) {
        sort(chd[i].begin(), chd[i].end());
    }

    dp(1);
    printf("%lld", res);
    return 0;
}