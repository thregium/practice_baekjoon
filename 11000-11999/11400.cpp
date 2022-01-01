#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� : V(V <= 100000)���� ������ E(E <= 10^6)���� �������� �̷���� ����� �׷������� �������� ��� ã�� �����Ͽ� ����Ѵ�.

�ذ� ��� : BCC�� ã�� �˰����� �ణ �����Ͽ� Ǯ �� �ִ�. ���� DFS Ʈ������ ���� ������ ���캻 ���
���� �������� �Ʒ������� �����̴� ��� ���� �������� ���� ���� �Ǵ� �� ���� ������ �ݵ�� ���� ������ ������ �ϱ� ������
���� ������ �������� �ȴ�. �̷� ������ �������� ��� ã�� �����Ͽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BCC, ������
*/

int dfsn[103000];
int dfsc = 0, sttp = 0;
pair<int, int> stack[1048576];
vector<int> ed[103000];
vector<vector<pair<int, int>>> bcc;
vector<pair<int, int>> artic;

int small(int x, int y) {
    return x < y ? x : y;
}
int big(int x, int y) {
    return x > y ? x : y;
}

int dfs(int cur, int prev) {
    //�ش� ������ dfsn �ο� �� ���� ������ �ְ� ���� ��ȯ
    dfsn[cur] = ++dfsc;
    int res = dfsc;
    int ndfsn;

    for (int next : ed[cur]) {
        if (next == prev) continue;

        if (dfsn[cur] > dfsn[next]) {
            stack[sttp++] = pair<int, int>(cur, next); //�湮���� ���� ������ ���ÿ� �߰�
        }
        if (dfsn[next] > 0) res = small(res, dfsn[next]); //������(�̹� �湮�� ���)
        else {
            ndfsn = dfs(next, cur); //���� ���� Ȯ��
            res = small(res, ndfsn);
            //�� ���� �� �� ���� ��� BCC �߰�
            if (ndfsn >= dfsn[cur]) {
                vector<pair<int, int>> cbcc;
                while (sttp > 0 && stack[sttp - 1] != pair<int, int>(cur, next)) {
                    cbcc.push_back(stack[sttp - 1]);
                    sttp--;
                }
                cbcc.push_back(stack[sttp - 1]);
                sttp--;
                bcc.push_back(cbcc);
            }
            if (ndfsn > dfsn[cur]) {
                artic.push_back(pair<int, int>(small(cur, next), big(cur, next))); 
                //������ �߰�(���� ���� �Ʒ��θ� ������ ���)
            }
        }
    }
    return res;
}

int main(void) {
    int v, e, a, b;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    for (int i = 1; i <= v; i++) {
        if (dfsn[i] == 0) dfs(i, -1);
    }
    printf("%d\n", artic.size());
    sort(artic.begin(), artic.end());
    for (int i = 0; i < artic.size(); i++) {
        printf("%d %d\n", artic[i].first, artic[i].second);
        if (i > 0 && artic[i].first == artic[i - 1].first && artic[i].second == artic[i - 1].second) return 1;
    }
    return 0;
}