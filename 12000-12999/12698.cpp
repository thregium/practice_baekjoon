#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <deque>
#include <map>
#include <assert.h>
using namespace std;

char grid[32][32];
pair<int, int> port[32][32][4]; //�� �������� �� �������� ��Ż�� ���� �����ϴ� ĭ
pair<int, int> stt = { 0, 0 }; //������ / ������
const int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //�� ������ �迭
deque<vector<int>> dq;
map<vector<int>, int> dist; //�Ÿ��� ������ ����
//�� ���� : [X��ǥ, Y��ǥ, ���� ��Ż(��)�� X��ǥ, ���� ��Ż(��)�� Y��ǥ]
int h, w;

int isvalid(vector<int> state, int tdist) {
    //�ش� ������ ���� Ž������ ���� ��������, �׷��ٸ� ��ĭ �Ǵ� ������ ���θ� ��ȯ
    if (state[0] < 0 || state[0] > h + 1 || state[1] < 0 || state[1] > w + 1) return 0;
    if (dist.find(state) != dist.end() && dist[state] <= tdist) return 0;
    if (grid[state[0]][state[1]] == '#') return -1;
    return 1;
}

int bfs(vector<int> state) {
    //0 - 1 BFS�� ���� �ִܰŸ� ��ȯ
    while (dq.size()) dq.pop_back();
    dist.clear();
    dist.insert({ state, 0 });
    dq.push_back(state);

    vector<int> tstate;
    int sdist, pt;

    while (dq.size()) {
        state = dq.front();
        dq.pop_front();
        tstate = state;
        sdist = dist[state];
        if (grid[state[0]][state[1]] == 'X') return sdist; //���Ϳ� ������ ���
        assert(grid[state[0]][state[1]] != '#');
        if (state[0] == 2 && state[1] == 4) {
            state[0] = state[0];
        }

        for (int i = 0; i < 4; i++) {
            //�����ϴ� ��Ż�� �ش� �������� ������� �߻�
            tstate[2] = port[state[0]][state[1]][i].first;
            tstate[3] = port[state[0]][state[1]][i].second;
            if (isvalid(tstate, sdist) > 0) {
                //������ ��� ���� ���ʿ� �߰�
                dq.push_front(tstate);
                dist.erase(tstate);
                dist.insert({ tstate, sdist });
            }
        }
        tstate = state;

        for (int i = 0; i < 4; i++) {
            //������� �̵�
            tstate[0] = state[0] + dxy[i][0];
            tstate[1] = state[1] + dxy[i][1];
            pt = isvalid(tstate, sdist + 1);
            if (pt > 0) {
                //�� ĭ�� ��� ���� ���ʿ� �߰�
                dq.push_back(tstate);
                dist.erase(tstate);
                dist.insert({ tstate, sdist + 1 });
            }
            else if (pt < 0) {
                //�� ĭ�� �ƴ϶�� �װ��� ��� ��Ż�� ����� ���� ��Ż�� �̵�
                tstate[0] = state[2];
                tstate[1] = state[3];
                if (isvalid(tstate, sdist + 1) > 0) {
                    //�װ��� �� ĭ�� ��� ���� ���ʿ� �߰�
                    dq.push_back(tstate);
                    dist.erase(tstate);
                    dist.insert({ tstate, sdist + 1 });
                }
            }
        }
    }
    return -1; //���Ϳ� �������� ���� ���
}

int main(void) {
    int t, res, x, y;
    /*
    srand(time(NULL));
    printf("200\n");
    for (int tt = 0; tt < 200; tt++) {
        do {
            h = 8;
            w = 8;
        } while (h * w < 2);
        printf("%d %d\n", h, w);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                grid[i][j] = ((rand() & 1) ? '#' : '.');
            }
            grid[i][w + 1] = '\0';
        }
        x = rand() % h + 1;
        y = rand() % w + 1;
        grid[x][y] = 'O';
        do {
            x = rand() % h + 1;
            y = rand() % w + 1;
        } while (grid[x][y] == 'O');
        grid[x][y] = 'X';
        for (int i = 1; i <= h; i++) {
            printf("%s\n", grid[i] + 1);
        }
    }
    return 0;
    */
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        //�Է�
        scanf("%d %d", &h, &w);
        for (int i = 0; i <= h + 1; i++) {
            for (int j = 0; j <= w + 1; j++) grid[i][j] = '#';
        }
        stt.first = -1, stt.second = -1;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == 'O') {
                    stt.first = i;
                    stt.second = j;
                }
            }
        }
        if (stt.first < 0) return 1;

        //�� �������� ������� ��Ż���� ��Ƽ� �����ϴ� ���� ����.
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                for (int d = 0; d < 4; d++) {
                    port[i][j][d].first = i;
                    port[i][j][d].second = j;
                    while (grid[port[i][j][d].first][port[i][j][d].second] != '#') {
                        port[i][j][d].first += dxy[d][0];
                        port[i][j][d].second += dxy[d][1];
                    }
                    port[i][j][d].first -= dxy[d][0];
                    port[i][j][d].second -= dxy[d][1];
                }
            }
        }

        res = bfs(vector<int>{stt.first, stt.second, 0, 0}); //�������� �������� BFS ����

        //BFS ����� ���� ���
        if (res < 0) printf("Case #%d: THE CAKE IS A LIE\n", tt);
        else printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}