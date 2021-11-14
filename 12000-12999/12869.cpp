#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

/*
���� : A, B, C(A, B, C <= 60) �� N���� �־��� ��, (9, 3, 1)�� �ٲ� ������ �ּ� �� ȸ ���� ��� ���� 0 ���ϰ� �Ǵ��� ���Ѵ�.

�ذ� ��� : BFS�� ����Ѵ�. ���� ó���� �����ؾ� �Ѵ�. N = 1�� ���� ���������� �ذ� �����ϴ�.

�ֿ� �˰��� : BFS
*/

int vis2[64][64], dist2[64][64];
int vis3[64][64][64], dist3[64][64][64];

queue<tuple<int, int>> q2;
queue<tuple<int, int, int>> q3;

int bfs2(int a, int b) {
    //n == 2�� ��
    int d = 0, am, bm;
    vis2[a][b] = 1;
    q2.push(make_tuple(a, b));
    while (q2.size()) {
        a = get<0>(q2.front());
        b = get<1>(q2.front());
        q2.pop();
        d = dist2[a][b];
        if (a == 0 && b == 0) return d; //���� ����
        am = a < 9 ? 0 : a - 9;
        bm = b < 3 ? 0 : b - 3;
        if (!vis2[am][bm]) {
            vis2[am][bm] = 1;
            dist2[am][bm] = d + 1;
            q2.push(make_tuple(am, bm));
        }
        am = a < 3 ? 0 : a - 3;
        bm = b < 9 ? 0 : b - 9;
        if (!vis2[am][bm]) {
            vis2[am][bm] = 1;
            dist2[am][bm] = d + 1;
            q2.push(make_tuple(am, bm));
        }
    }
    return -1;
}

int bfs3(int a, int b, int c) {
    //n = 3�� ��
    int d = 0, am, bm, cm;
    vis3[a][b][c] = 1;
    q3.push(make_tuple(a, b, c));
    while (q3.size()) {
        a = get<0>(q3.front());
        b = get<1>(q3.front());
        c = get<2>(q3.front());
        q3.pop();
        d = dist3[a][b][c];
        if (a == 0 && b == 0 && c == 0) return d; //���� ����
        am = a < 9 ? 0 : a - 9;
        bm = b < 3 ? 0 : b - 3;
        cm = c < 1 ? 0 : c - 1;
        if (!vis3[am][bm][cm]) {
            vis3[am][bm][cm] = 1;
            dist3[am][bm][cm] = d + 1;
            q3.push(make_tuple(am, bm, cm));
        }
        am = a < 9 ? 0 : a - 9;
        bm = b < 1 ? 0 : b - 1;
        cm = c < 3 ? 0 : c - 3;
        if (!vis3[am][bm][cm]) {
            vis3[am][bm][cm] = 1;
            dist3[am][bm][cm] = d + 1;
            q3.push(make_tuple(am, bm, cm));
        }
        am = a < 3 ? 0 : a - 3;
        bm = b < 1 ? 0 : b - 1;
        cm = c < 9 ? 0 : c - 9;
        if (!vis3[am][bm][cm]) {
            vis3[am][bm][cm] = 1;
            dist3[am][bm][cm] = d + 1;
            q3.push(make_tuple(am, bm, cm));
        }
        am = a < 3 ? 0 : a - 3;
        bm = b < 9 ? 0 : b - 9;
        cm = c < 1 ? 0 : c - 1;
        if (!vis3[am][bm][cm]) {
            vis3[am][bm][cm] = 1;
            dist3[am][bm][cm] = d + 1;
            q3.push(make_tuple(am, bm, cm));
        }
        am = a < 1 ? 0 : a - 1;
        bm = b < 9 ? 0 : b - 9;
        cm = c < 3 ? 0 : c - 3;
        if (!vis3[am][bm][cm]) {
            vis3[am][bm][cm] = 1;
            dist3[am][bm][cm] = d + 1;
            q3.push(make_tuple(am, bm, cm));
        }
        am = a < 1 ? 0 : a - 1;
        bm = b < 3 ? 0 : b - 3;
        cm = c < 9 ? 0 : c - 9;
        if (!vis3[am][bm][cm]) {
            vis3[am][bm][cm] = 1;
            dist3[am][bm][cm] = d + 1;
            q3.push(make_tuple(am, bm, cm));
        }
    }
}

int main(void) {
    int n, a, b, c, r;
    scanf("%d", &n);
    if (n == 1) {
        scanf("%d", &a);
        printf("%d", (a + 8) / 9);
        return 0;
    }
    else if (n == 2) {
        scanf("%d %d", &a, &b);
        r = bfs2(a, b);
        if (r < 0) return 1;
        printf("%d", r);
    }
    else if (n == 3) {
        scanf("%d %d %d", &a, &b, &c);
        r = bfs3(a, b, c);
        while (r < 0);
        printf("%d", r);
    }
    else return 1;
    return 0;
}