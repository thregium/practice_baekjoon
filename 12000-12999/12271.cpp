#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <tuple>
#define INF 1012345678
#define INNER ((i * 128 + j) * 2)
#define OUTER ((i * 128 + j) * 2 + 1)
using namespace std;

/*
���� : N * N(N <= 100) ũ���� �ǿ��� �� ����� �־��� ��Ģ��� ���� ���´�.
���� ���°� �־��� ��, ��Ģ��� ���Ƽ� ������ ����� ��, �����ϴٸ� ���� �̱� ������ �� ���Ѵ�.

�ذ� ��� : �� ĭ�� 2���� ������ ĭ ������ ���Ϸ� �帣�� ������ �¿�� �帣�� ������ ���� ã�Ƽ� ���Ѵ�.
�� ������ ���� 2 �̻��� ��� ������ �� ����. ���� 1�� ��� ���Ϸ� ������ �帥�ٸ� ����, �¿�� �帥�ٸ�
����� �¸��̴�. ���� 0�� ���� ������ �¸��� �ƴϴ�. ��, ���� 1�� �� ��밡 �� ����
�� ���� ��� ������ �� ����, ���� �� ���� ���̰� 2 �̻��� ��쵵 ������ �� ����.

�ֿ� �˰��� : �׷��� �̷�, �÷ο�

��ó : GKS 2013B E2��
*/

char game[128][128];
int level[32768], see[32768];
vector<pair<tuple<int, int, int>, int>> ed[32768]; // (nxt / usg / cap) / revi
queue<int> q;
const int dxy[6][2] = { {0, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, 0}, {-1, 1} };

int small(int a, int b) {
    return a < b ? a : b;
}

void set_level(int x) {
    while (q.size()) q.pop();
    q.push(x);
    level[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (auto &i : ed[x]) {
            if (get<1>(i.first) == get<2>(i.first) || level[get<0>(i.first)]) continue;
            q.push(get<0>(i.first));
            level[get<0>(i.first)] = level[x] + 1;
        }
    }
}

int dinic(int x, int e, int f) {
    if (x == e) return f;
    int ff;

    for (int i = see[x]; i < ed[x].size(); i++) {
        if (level[get<0>(ed[x][i].first)] != level[x] + 1 || get<1>(ed[x][i].first) == get<2>(ed[x][i].first)) continue;
        ff = dinic(get<0>(ed[x][i].first), e, small(f, get<2>(ed[x][i].first) - get<1>(ed[x][i].first)));
        if (ff) {
            get<1>(ed[x][i].first) += ff;
            get<1>(ed[get<0>(ed[x][i].first)][ed[x][i].second]) -= ff;
            return ff;
        }
        see[x] = i;
    }

    return 0;
}

int main(void) {
    int t, n, xn, yn, blues = 0, reds = 0, bluef = 0, redf = 0, tmpf;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        blues = 0, reds = 0, bluef = 0, redf = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", game[i]);
            for (int j = 0; j < n; j++) {
                if (game[i][j] == 'R') reds++;
                else if (game[i][j] == 'B') blues++;
            }
        }
        if (abs(reds - blues) > 1) {
            printf("Case #%d: Impossible\n", tt);
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (game[i][j] != 'R') continue;
                ed[INNER].push_back({ {OUTER, 0, 1}, (int)ed[OUTER].size() });
                ed[OUTER].push_back({ {INNER, 0, 0}, (int)ed[INNER].size() - 1 });
                for (int d = 0; d < 6; d++) {
                    xn = i + dxy[d][0];
                    yn = j + dxy[d][1];
                    if (xn < 0) {
                        if (yn < 0) continue;
                        ed[OUTER].push_back({ {32760, 0, INF}, (int)ed[32760].size() });
                        ed[32760].push_back({ {OUTER, 0, 0}, (int)ed[OUTER].size() - 1 });
                        ed[32760].push_back({ {INNER, 0, INF}, (int)ed[INNER].size() });
                        ed[INNER].push_back({ {32760, 0, 0}, (int)ed[32760].size() - 1 });
                    }
                    else if (xn >= n) {
                        if (yn >= n) continue;
                        ed[OUTER].push_back({ {32762, 0, INF}, (int)ed[32762].size() });
                        ed[32762].push_back({ {OUTER, 0, 0}, (int)ed[OUTER].size() - 1 });
                        ed[32762].push_back({ {INNER, 0, INF}, (int)ed[INNER].size() });
                        ed[INNER].push_back({ {32762, 0, 0}, (int)ed[32762].size() - 1 });
                    }
                    else if (yn >= n || yn < 0) continue;
                    else {
                        if (game[xn][yn] != 'R') continue;
                        ed[OUTER].push_back({ {(xn * 128 + yn) * 2, 0, INF}, (int)ed[(xn * 128 + yn) * 2].size() });
                        ed[(xn * 128 + yn) * 2].push_back({ {OUTER, 0, 0}, (int)ed[OUTER].size() - 1 });
                        ed[(xn * 128 + yn) * 2 + 1].push_back({ {INNER, 0, INF}, (int)ed[INNER].size() });
                        ed[INNER].push_back({ {(xn * 128 + yn) * 2 + 1, 0, 0}, (int)ed[(xn * 128 + yn) * 2 + 1].size() - 1 });
                    }
                }
            }
        }
        while (1) {
            for (int i = 0; i < 32768; i++) {
                level[i] = 0;
                see[i] = 0;
            }
            set_level(32760);
            if (!level[32762]) break;
            while (1) {
                tmpf = dinic(32760, 32762, INF);
                if (!tmpf) break;
                redf += tmpf;
                if (redf > 1) break;
            }
            if (redf > 1) break;
        }
        for (int i = 0; i < 32768; i++) ed[i].clear();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (game[i][j] != 'B') continue;
                ed[INNER].push_back({ {OUTER, 0, 1}, (int)ed[OUTER].size() });
                ed[OUTER].push_back({ {INNER, 0, 0}, (int)ed[INNER].size() - 1 });
                for (int d = 0; d < 6; d++) {
                    xn = i + dxy[d][0];
                    yn = j + dxy[d][1];
                    if (yn < 0) {
                        if (xn >= n) continue;
                        ed[OUTER].push_back({ {32761, 0, INF}, (int)ed[32761].size() });
                        ed[32761].push_back({ {OUTER, 0, 0}, (int)ed[OUTER].size() - 1 });
                        ed[32761].push_back({ {INNER, 0, INF}, (int)ed[INNER].size() });
                        ed[INNER].push_back({ {32761, 0, 0}, (int)ed[32761].size() - 1 });
                    }
                    else if (yn >= n) {
                        if (xn < 0) continue;
                        ed[OUTER].push_back({ {32763, 0, INF}, (int)ed[32763].size() });
                        ed[32763].push_back({ {OUTER, 0, 0}, (int)ed[OUTER].size() - 1 });
                        ed[32763].push_back({ {INNER, 0, INF}, (int)ed[INNER].size() });
                        ed[INNER].push_back({ {32763, 0, 0}, (int)ed[32763].size() - 1 });
                    }
                    else if (xn >= n || xn < 0) continue;
                    else {
                        if (game[xn][yn] != 'B') continue;
                        ed[OUTER].push_back({ {(xn * 128 + yn) * 2, 0, INF}, (int)ed[(xn * 128 + yn) * 2].size() });
                        ed[(xn * 128 + yn) * 2].push_back({ {OUTER, 0, 0}, (int)ed[OUTER].size() - 1 });
                        ed[(xn * 128 + yn) * 2 + 1].push_back({ {INNER, 0, INF}, (int)ed[INNER].size() });
                        ed[INNER].push_back({ {(xn * 128 + yn) * 2 + 1, 0, 0}, (int)ed[(xn * 128 + yn) * 2 + 1].size() - 1 });
                    }
                }
            }
        }
        while (1) {
            for (int i = 0; i < 32768; i++) {
                level[i] = 0;
                see[i] = 0;
            }
            set_level(32761);
            if (!level[32763]) break;
            while (1) {
                tmpf = dinic(32761, 32763, INF);
                if (!tmpf) break;
                bluef += tmpf;
                if (bluef > 1) break;
            }
            if (bluef > 1) break;
        }
        for (int i = 0; i < 32768; i++) ed[i].clear();

        printf("Case #%d: ", tt);
        if (redf + bluef > 1) printf("Impossible\n");
        else if (redf) {
            if (blues > reds) printf("Impossible\n");
            else printf("Red wins\n");
        }
        else if (bluef) {
            if (reds > blues) printf("Impossible\n");
            else printf("Blue wins\n");
        }
        else printf("Nobody wins\n");
    }
    return 0;
}