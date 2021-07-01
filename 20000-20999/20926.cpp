#include <stdio.h>
#include <queue>
#include <vector>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
���� : W * H(W, H <= 500) ũ���� ���� �̷ΰ� �ִ�. �� ���� �̷ο��� �����¿�� �̲������� ��ֹ��� ������ ������ �̵� �����ϴٸ�,
���� ���� �ⱸ�� �����ϴ� �ð��� ������ ���Ѵ�. ��, �̵� �ð��� ��ο� �ִ� ������ ���� ���̰�,
�̵� �߰��� �����̳� �̷��� ���� �����ٸ� ���ķδ� ������ �� ���ٰ� �Ѵ�.

�ذ� ��� : ����, �����¿�� ��ֹ��� ���� �� ���� �̵����� ���� ��ġ�� �װ������� �Ÿ��� ��� ĭ�� ���� �߰����ش�.
�� �������δ� ���ͽ�Ʈ�� �˰����� ���� �ⱸ���� ���� ���� �ð��� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ����

��ó : ����C 2021WB G��
*/

char maze[512][512];
int mindist[512][512];
vector<tuple<int, int, int>> ed[512][512];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int main(void) {
    int w, h, x = -1, y = -1, last = 0, dist = 0;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        scanf("%s", maze[i]);
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'T') {
                x = i;
                y = j;
                maze[i][j] = '0';
            }
            mindist[i][j] = INF;
        }
    }
    if (x < 0) return 1;

    //�� ���⿡ ���� ���� ����
    for (int i = 0; i < h; i++) {
        last = -1;
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'R') {
                last = j + 1;
                dist = 0;
            }
            else if (maze[i][j] == 'H' || maze[i][j] == 'E') {
                last = j;
                dist = 0;
            }
            else if (last >= 0) {
                if (j > last) ed[i][j].push_back(make_tuple(i, last, dist));
                dist += maze[i][j] - '0';
            }
        }
        last = w;
        for (int j = w - 1; j >= 0; j--) {
            if (maze[i][j] == 'R') {
                last = j - 1;
                dist = 0;
            }
            else if (maze[i][j] == 'H' || maze[i][j] == 'E') {
                last = j;
                dist = 0;
            }
            else if (last < w) {
                if (j < last) ed[i][j].push_back(make_tuple(i, last, dist));
                dist += maze[i][j] - '0';
            }
        }
    }
    for (int i = 0; i < w; i++) {
        last = -1;
        for (int j = 0; j < h; j++) {
            if (maze[j][i] == 'R') {
                last = j + 1;
                dist = 0;
            }
            else if (maze[j][i] == 'H' || maze[j][i] == 'E') {
                last = j;
                dist = 0;
            }
            else if (last >= 0) {
                if (j > last) ed[j][i].push_back(make_tuple(last, i, dist));
                dist += maze[j][i] - '0';
            }
        }
        last = h;
        for (int j = h - 1; j >= 0; j--) {
            if (maze[j][i] == 'R') {
                last = j - 1;
                dist = 0;
            }
            else if (maze[j][i] == 'H' || maze[j][i] == 'E') {
                last = j;
                dist = 0;
            }
            else if (last < h) {
                if (j < last) ed[j][i].push_back(make_tuple(last, i, dist));
                dist += maze[j][i] - '0';
            }
        }
    }

    //���ͽ�Ʈ��
    pq.push(pair<int, pair<int, int>>(0, pair<int, int>(x, y)));
    while (pq.size()) {
        x = pq.top().second.first;
        y = pq.top().second.second;
        dist = pq.top().first;
        pq.pop();
        if (dist >= mindist[x][y]) continue;
        mindist[x][y] = dist;
        for (auto t : ed[x][y]) {
            pq.push(pair<int, pair<int, int>>(dist + get<2>(t), pair<int, int>(get<0>(t), get<1>(t))));
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'E') {
                printf("%d", mindist[i][j] == INF ? -1 : mindist[i][j]);
            }
        }
    }
    return 0;
}