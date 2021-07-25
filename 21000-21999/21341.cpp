#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;

/*
���� : N * N(N <= 100000) ũ���� ���忡�� �� ����� ���� ������ ��� ���� ��� ������ �Ѵ�.
�� ����� �� �Ͽ� N���� �̵� ��� �ϳ��� ��� �̵��ϴ� ���� 2ȸ �ϰų�, ��� ���� ���� ������ ������ �� �ִ�.
�Ǵ�, �� �ڸ��� �״�� �ִ� �͵� �����ϴ�. �̶�, ���� ���� ����� ���� �Ͽ� �̱����, ������, �� �� �ƴ϶��
��� �̵��ؾ� ���� �ʴ��� ���Ѵ�.
�� �̵��� Ư���� �������� Ư���� ĭ��ŭ �̵��ϴ� ���� ���ϸ�, ���� ������ �̵��ϴ� ���� �Ұ����ϴ�.

�ذ� ��� : ��� �̵��� ���캸�⿡�� N�� �ſ� ũ�� ������ �������� ���� ���� �� �ִ� ��ġ��
��� ���� �̵��� ���� ��ġ�� ���� ���� ���� �ߺ��Ǵ� ���� �ִ��� Ȯ���Ͽ� �� �� �ִ��� ���Ѵ�.
���� A���� B�� �̵� �����ϴٸ� �ش� �Ͽ� ��� ���� ���� �� �ִٴ� ���̹Ƿ� �̱��.
�ݴ��, B���� ��� ĭ���� �̵� �����ϴٸ� ��� �̵��ص� �����Ƿ� ���� �ȴ�.
�׷���, N�� 4 �̻��� ��� �׷��� ��Ȳ�� �Ͼ�� ���� �Ұ���������. ����, N�� Ŀ�� ���� B�� �ѹ��� �̵� ������ ĭ ����
N^2 / 2�� �����ϱ� ������ ��ü ĭ�� �� ���� ������ �̵� �����ϰ� �ȴ�.
����, N�� ���� ��쿡�� ���� �����ְ�, ū ��쿡�� �������� ������ ���� �� ���� �̵��ؼ� ������ �ʴ� ���� ��ġ�� ã���� �ȴ�.

�ֿ� �˰��� : �� �� �� �̵�, ������ȭ

��ó : NWERC 2020 E��
*/

int a[2], b[2], pos[103000][2], rpos[103000][2], board[1024][1024];
set<pair<int, int>> st;

int main(void) {
    int n, r = 0, rx = 0, ry = 0, t = 0;
    srand((unsigned)time(NULL));
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2020\\nwerc2020all\\endgame\\data\\secret\\60-random.in", "r", stdin);
    scanf("%d", &n);
    scanf("%d %d", &a[0], &a[1]);
    scanf("%d %d", &b[0], &b[1]);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        rpos[i][0] = -pos[i][0];
        rpos[i][1] = -pos[i][1];
    }
    if (n <= 1000) {
        for (int i = 0; i < n; i++) {
            if (b[0] + pos[i][0] < 1 || b[0] + pos[i][0] > n) continue;
            if (b[1] + pos[i][1] < 1 || b[1] + pos[i][1] > n) continue;
            board[b[0] + pos[i][0]][b[1] + pos[i][1]] = 1;
            for (int j = 0; j < n; j++) {
                if (b[0] + pos[i][0] + pos[j][0] < 1 || b[0] + pos[i][0] + pos[j][0] > n) continue;
                if (b[1] + pos[i][1] + pos[j][1] < 1 || b[1] + pos[i][1] + pos[j][1] > n) continue;
                board[b[0] + pos[i][0] + pos[j][0]][b[1] + pos[i][1] + pos[j][1]] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[0] + pos[i][0] < 1 || a[0] + pos[i][0] > n) continue;
            if (a[1] + pos[i][1] < 1 || a[1] + pos[i][1] > n) continue;
            for (int j = 0; j < n; j++) {
                if (a[0] + pos[i][0] + pos[j][0] < 1 || a[0] + pos[i][0] + pos[j][0] > n) continue;
                if (a[1] + pos[i][1] + pos[j][1] < 1 || a[1] + pos[i][1] + pos[j][1] > n) continue;
                if (b[0] == a[0] + pos[i][0] + pos[j][0] && b[1] == a[1] + pos[i][1] + pos[j][1]) {
                    printf("Alice wins");
                    return 0;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == b[0] && j == b[1]) continue;
                if (!board[i][j]) {
                    printf("tie %d %d", i, j);
                    return 0;
                }
            }
        }
        printf("Bob wins");
    }
    else {
        for (int i = 0; i < n; i++) {
            if (b[0] + rpos[i][0] < 1 || b[0] + rpos[i][0] > n) continue;
            if (b[1] + rpos[i][1] < 1 || b[1] + rpos[i][1] > n) continue;
            st.insert(pair<int, int>(b[0] + rpos[i][0], b[1] + rpos[i][1]));
        }
        for (int i = 0; i < n; i++) {
            if (a[0] + pos[i][0] < 1 || a[0] + pos[i][0] > n) continue;
            if (a[1] + pos[i][1] < 1 || a[1] + pos[i][1] > n) continue;
            if (st.find(pair<int, int>(a[0] + pos[i][0], a[1] + pos[i][1])) != st.end()) {
                printf("Alice wins");
                return 0;
            }
        }
        while (1) {
            srand(rand() * n + a[0]);
            a[0] = (rand() * 32768LL + rand()) % n + 1;
            a[1] = (rand() * 32768LL + rand()) % n + 1;
            if (a[0] == b[0] && a[1] == b[1]) continue;
            st.clear();
            t = 0;
            for (int i = 0; i < n; i++) {
                if (a[0] + rpos[i][0] < 1 || a[0] + rpos[i][0] > n) continue;
                if (a[1] + rpos[i][1] < 1 || a[1] + rpos[i][1] > n) continue;
                st.insert(pair<int, int>(a[0] + rpos[i][0], a[1] + rpos[i][1]));
            }
            for (int i = 0; i < n; i++) {
                if (b[0] + pos[i][0] < 1 || b[0] + pos[i][0] > n) continue;
                if (b[1] + pos[i][1] < 1 || b[1] + pos[i][1] > n) continue;
                if (st.find(pair<int, int>(b[0] + pos[i][0], b[1] + pos[i][1])) != st.end()) {
                    t = 1;
                    break;
                }
            }
            if (!t) {
                printf("tie %d %d", a[0], a[1]);
                break;
            }
        }
    }
    return 0;
}