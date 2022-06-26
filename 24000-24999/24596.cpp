#include <stdio.h>
#include <vector>
#define INF 1234567890987654321
using namespace std;

/*
���� : N * N(N <= 500) ũ���� ���ڿ� K(K <= N * N) ������ �ڿ������� ���� �ִ�.
1���� K���� ���ʷ� �� �ڿ����� �ִ� ĭ���� �Ű� ���� ����� �ִ� �� Ȯ���ϰ� �ִٸ�
�� ��� ���� �Ÿ��� ª�� ���� ���Ѵ�. ���� ��� -1�� ����Ѵ�.
�Ÿ��� X��ǥ�� Y��ǥ�� ���� ��� ���� ���̴�.

�ذ� ��� : �� ������ �ش��ϴ� ��ǥ�� ����� ������ ����, 1���� ���ʴ�� �� ��ġ�� �Ÿ��� ������ ������
���̳��� ���α׷����� �Ѵ�. �� ���� ������ �� ���� ������ ���� N * N���� �۴ٸ�
���� ��� ��쿡 ���� �Ÿ��� ���ϸ鼭 ���� ª�� ���� ã�Ƴ�����,
N * N���� ū ��� �� ��� �������� �ִ� �Ÿ��� ���� �� �� ���� ���� �ִ� �Ÿ��� ����Ͽ�
���ϴ� ����� ����Ѵ�.

���������� K�� ���� ĭ ��� ���� �Ÿ��� ���� ���� �Ÿ��� ���� �ȴ�.
�� ���� ���Ѵ��� ��� �׷��� ����� ���� ���̹Ƿ� -1�� ����Ѵ�.

�ֿ� �˰��� : DP, �� �� �� �̵�?

��ó : PacNW 2021 G�� // SCUSA 2021D1 F�� // NENA 2021 J��
*/

long long a[512][512], lowh[512], lowv[512], disth[512], distv[512], mem[512][512];
vector<pair<int, int>> pos[262144];

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long getdist(pair<int, int> a, pair<int, int> b) {
    return small((a.first - b.first) * (a.first - b.first), (a.second - b.second) * (a.second - b.second));
}

int main(void) {
    int n, k;
    long long res = INF;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
            pos[a[i][j]].push_back({ i, j });
            if (a[i][j] == 1) mem[i][j] = 0;
            else mem[i][j] = INF;
        }
    }
    for (int i = 2; i <= k; i++) {
        if ((long long)pos[i].size() * pos[i - 1].size() >= (long long)n * n) {
            for (int j = 0; j < n; j++) {
                lowh[j] = INF; lowv[j] = INF;
                disth[j] = INF; distv[j] = INF;
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (a[j][k] != i - 1) continue;
                    if (mem[j][k] < lowh[j]) lowh[j] = mem[j][k];
                    if (mem[j][k] < lowv[k]) lowv[k] = mem[j][k];
                }
            }
            for (long long j = 0; j < n; j++) {
                for (long long k = 0; k < n; k++) {
                    if (lowh[j] + (j - k) * (j - k) < disth[k]) disth[k] = lowh[j] + (j - k) * (j - k);
                    if (lowv[j] + (j - k) * (j - k) < distv[k]) distv[k] = lowv[j] + (j - k) * (j - k);
                }
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (a[j][k] == i) mem[j][k] = small(disth[j], distv[k]);
                }
            }
        }
        else {
            for (auto& j : pos[i]) {
                for (auto& k : pos[i - 1]) {
                    if (getdist(j, k) + mem[k.first][k.second] < mem[j.first][j.second]) {
                        mem[j.first][j.second] = getdist(j, k) + mem[k.first][k.second];
                    }
                }
            }
        }
    }

    for (auto& j : pos[k]) {
        if (mem[j.first][j.second] < res) res = mem[j.first][j.second];
    }
    if (res == INF) printf("-1");
    else printf("%lld", res);
    return 0;
}