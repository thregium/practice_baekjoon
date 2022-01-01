#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : R * C(R, C <= 100) ũ���� '.'�� 'x'�� �̷���� �������� �ִ�. �̶�, N(N <= 100)������ ������ ���̷�
����, ������ �����ư��� �־��� ���̵� X_i�� ���븦 ������ �� ���������� ������ ����� ����Ѵ�.
���븦 ���� �� ���� ������ �ִ� 'x'�� ������� �� �� �����¿�� �پ����� ���� 'x'�� ������ �Ʒ��� �������� �ȴ�.

�ذ� ��� : �켱 �Ź� ���븦 ���� �� ���� ���밡 �����ϴ� 'x'�� ã�´�. ã�� �������� �� 'x'�� ���� ��
�����¿� �� ���ῡ ���� �پ��ִ� 'x'�� ������ ���� ���ϰ� �����ǿ��� �����ش�.
�� ������ ���� �������� �� �������� ��� ���� �� ���� ��ĭ�� ���������� �ȴ�.
�� �������� ���߾����� ���δ� ������ ���ҵ� ��� �Ʒ� ĭ�� 'x'�̰ų� �ٴ��� ��츦 ã���� �� �� �ִ�.
���߾��ٸ� �� ��ġ�� ������ 'x'�� ���´�. �̶�, �� �������� ���������� ���ߴ� ��찡 ���� �� �ֱ� ������
4���� �̸� ���캸�ƾ� �Ѵ�. ������ ���� �������� 1ĭ�� ���� ���� �� ������ ��� ���߱� ������ �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, BFS, �ùķ��̼�, ť, ...

��ó : CHCI 2009CR 5�� / 2009RJ 4��
*/

char mine[128][128], vis[128][128];
int store[4][10240][2], fin[4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int r, c;
queue<pair<int, int>> q[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (mine[x][y] == '.' || vis[x][y]) return 0;
    return 1;
}

void dfs(int x, int y, int d) {
    vis[x][y] = 1;
    mine[x][y] = '.';
    store[d][++store[d][0][0]][0] = x;
    store[d][store[d][0][0]][1] = y;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1], d);
    }
}

int main(void) {
    int n, x, y;
    //freopen("E:\\PS\\Olympiad\\Croatia\\2009\\regional_testdata\\official_test_data\\reljef\\reljef.in.5", "r", stdin);
    //freopen("E:\\PS\\Olympiad\\Croatia\\2009\\regional_testdata\\official_test_data\\reljef\\reljef.out_t.5", "w", stdout);
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", mine[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        x = r - x;
        y = -1;
        if (i & 1) {
            for (int j = c - 1; j >= 0; j--) {
                if (mine[x][j] == 'x') {
                    y = j;
                    break;
                }
            }
        }
        else {
            for (int j = 0; j < c; j++) {
                if (mine[x][j] == 'x') {
                    y = j;
                    break;
                }
            }
        }
        //���밡 'x'�� ��� ��ġ�� ���Ѵ�. ���� �ʴ´ٸ� ���� ���븦 ������.
        if (y < 0) continue;

        mine[x][y] = '.';
        for (int j = 0; j < 4; j++) {
            //�����¿� �� ���⿡ ���� �ش� ������ �������� ���صд�. �׸��� �������� ����������.
            if (isvalid(x + dxy[j][0], y + dxy[j][1])) dfs(x + dxy[j][0], y + dxy[j][1], j);
            qsort(&store[j][1], store[j][0][0], sizeof(int) * 2, cmp1);
            for (int k = 1; k <= store[j][0][0]; k++) {
                q[j].push(pair<int, int>(store[j][k][0], store[j][k][1]));
                if (mine[store[j][k][0] + 1][store[j][k][1]] == 'x' || store[j][k][0] + 1 == r) fin[j] = 1;
                //���� �̹� ���߾��ִ� ������ ��� ���߾����� ǥ���صд�.
            }
            store[j][0][0] = 0;
        }
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) vis[j][k] = 0; //�湮 ���θ� �ʱ�ȭ�Ѵ�.
        }
        
        while (1) {
            //�� �������� ����������.
            if (fin[0] + fin[1] + fin[2] + fin[3] == 8) break;
            for (int k = 0; k < 5; k++) {
                for (int j = 0; j < 4; j++) {
                    //���������� ���� ���߾����� ���θ� üũ�Ѵ�. �������� ���㿡 ����� ���� �� ������ �Ѵ�.
                    if (q[j].size() == 0) fin[j] = 1;
                    for (int p = 0; p < q[j].size(); p++) {
                        x = q[j].front().first;
                        y = q[j].front().second;
                        q[j].pop();
                        if (mine[x + 1][y] == 'x' || x + 1 == r) fin[j] = 1;
                        q[j].push(pair<int, int>(x, y));
                    }
                    if (fin[j]) {
                        while (q[j].size()) {
                            //���� ��� ������ �ٽ� ǥ���Ѵ�.
                            x = q[j].front().first;
                            y = q[j].front().second;
                            q[j].pop();
                            mine[x][y] = 'x';
                        }
                        fin[j] = 2;
                    }
                }
            }
            for (int j = 0; j < 4; j++) {
                //������ �ʾҴٸ� ������ �� ���Ҹ� �� ĭ ������.
                if (fin[j] == 0) {
                    for (int k = 0; k < q[j].size(); k++) {
                        x = q[j].front().first;
                        y = q[j].front().second;
                        q[j].pop();
                        q[j].push(pair<int, int>(x + 1, y));
                    }
                }
                
            }
        }
        for (int i = 0; i < 4; i++) fin[i] = 0;
    }

    for (int i = 0; i < r; i++) {
        printf("%s\n", mine[i]);
    }
    return 0;
}