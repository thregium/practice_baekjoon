#include <stdio.h>
#include <math.h>
#define INF 1E39

/*
���� : ��ǥ������ N(N <= 20)���� ����(|| <= 10000, ����)�� �ִ�. 1��° �������� ����Ͽ�
�Ÿ� R(R <= 10000)���ϰ�, �� ȸ���� theta(< 180) ���Ϸ� ���ư��� ���� ���� ������ ������ �����
������ ���� ������ ���Ѵ�. �������� �����Ѵ�.

�ذ� ��� : �켱 �Ÿ��� ���� ��ó���� ����, �� �̵� Ƚ��, �ֱ� 2���� ������ ���� �ִ� �Ÿ��� ���Ѵ�.
�ִ� �Ÿ��� R ������ ���� ���� �̵� Ƚ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : DP, ������

��ó : JAG 2010S3 B��
*/

int pos[32][2];
double angle[24][24][24], dist[24][24], mem[10240][24][24];

double todeg(double x) {
    return x / acos(-1) * 180;
}

int getdist(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(void) {
    int n, res = 0;
    double xdist, th, angle1, angle2;
    scanf("%d%lf %lf", &n, &xdist, &th);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            angle1 = todeg(atan2(pos[j][1] - pos[i][1], pos[j][0] - pos[i][0]));
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                angle2 = todeg(atan2(pos[k][1] - pos[j][1], pos[k][0] - pos[j][0]));
                angle[i][j][k] = fabs(angle2 - angle1);
                angle[i][j][k] = 180 - fabs(angle[i][j][k] - 180);
            }
            dist[i][j] = sqrt(getdist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]));
        }
    }
    for (int i = 0; i < 10240; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) mem[i][j][k] = INF;
        }
    }

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            mem[1][i][j] = dist[i][j];
        }
    }
    for (int i = 1; i <= 10000; i++) {
        for (int p1 = 0; p1 < n; p1++) {
            for (int p2 = 0; p2 < n; p2++) {
                if (p1 == p2) continue;
                if (mem[i][p1][p2] > xdist) continue;
                else res = i;
                for (int p3 = 0; p3 < n; p3++) {
                    if (p2 == p3) continue;
                    if (angle[p1][p2][p3] < th && mem[i][p1][p2] + dist[p2][p3] < mem[i + 1][p2][p3]) {
                        mem[i + 1][p2][p3] = dist[p2][p3] + mem[i][p1][p2];
                    }
                }
            }
        }
        if (res < i) break;
    }
    printf("%d\n", res);
    return 0;
}