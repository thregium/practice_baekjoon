#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� : NV(NV <= 20)���� �������� �̷���� ������ ����ġ �׷����� �ִ�. �̶�, SV �������� DV�������� ���ϴ�
����ġ���� MAXDIST(MAXDIST <= 9999) ������ ��θ� ���� ã��, �Ÿ� �� -> ��� ���� ������ ������ ����Ѵ�.

�ذ� ��� : ��Ʈ��ŷ�� ���� SV���� ����ϴ� ��θ� ���� ã�ƺ���. �̶�, �߰��� ����� �Ÿ��� MAXDIST�� �Ѿ�� ���
�߰��� Ž���� ������ �ð��� �����Ѵ�. DV�� �����ϸ� �ش� ���������� ��θ� �����ϰ� �ٸ� ��θ� Ž���غ���.
��θ� ���� Ž���ߴٸ� ���ݱ����� ��� ��ε��� �Ÿ� ���� ��� ���� ������ ������ �д�.
���� �����ص� ��ε��� ���� ����صθ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ��Ʈ��ŷ, ����

��ó : PacNW 2004 G��
*/

int chk[32];
vector<pair<int, int>> ed[32];
vector<int> path;
pair<int, vector<int>> res[1024];
int rp = 0;

void track(int sv, int dv, int dist, int maxdist) {
    chk[sv] = 1;
    path.push_back(sv);
    if (sv == dv) {
        res[rp].second = path;
        res[rp++].first = dist;
        chk[sv] = 0;
        path.pop_back();
        return;
    }
    for (auto i : ed[sv]) {
        if (chk[i.first]) continue;
        if (dist + i.second > maxdist) continue;
        track(i.first, dv, dist + i.second, maxdist);
    }
    chk[sv] = 0;
    path.pop_back();
}

int main(void) {
    int nv, nr, c1, c2, dist, sv, dv, maxdist;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\g.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\g_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d", &nv);
        if (nv < 0) break;
        scanf("%d", &nr);
        for (int i = 0; i < nr; i++) {
            scanf("%d %d %d", &c1, &c2, &dist);
            ed[c1].push_back(pair<int, int>(c2, dist));
            ed[c2].push_back(pair<int, int>(c1, dist));
        }
        scanf("%d %d", &sv, &dv);
        scanf("%d", &maxdist);

        rp = 0;
        track(sv, dv, 0, maxdist);
        sort(res, res + rp);
        
        if (tt > 1) printf("\n");
        printf("Case %d:\n", tt);
        for (int i = 0; i < rp; i++) {
            printf(" %d: ", res[i].first);
            for (int j = 0; j < res[i].second.size(); j++) {
                printf("%d", (res[i].second)[j]);
                printf(" ");
            }
            printf("\n");
        }
        if (rp == 0) printf(" NO ACCEPTABLE TOURS\n");
        for (int i = 1; i <= nv; i++) {
            ed[i].clear();
        }
    }
    return 0;
}