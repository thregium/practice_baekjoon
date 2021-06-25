#include <stdio.h>
#include <math.h>
#define MAX 987654321

/*
���� : N * N(N <= 1000) ũ���� ������ ���� ���� ������ �Ʒ� �� ���� �ִ�. W(W <= 1000)���� ���� ���� �� �� �� �� ���� �̵�����
������� �湮�Ѵٰ� �� ��, �� ���� �̵��Ÿ��� ���� �۰� �ϴ� ����� �׶��� �̵� �Ÿ��� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �� ���� ������ ��ġ(�� ��ȣ)�� ���� �ּ� �̵��Ÿ��� �����Ѵ�.
���� �� ���� ������ ��ġ�� 2 �̻� ���� ���� ��쿡�� ������ �̵����� ������ ���� �� ��ġ ��ȣ�� ū ���� 1 �ڷ� �ű�� �� ���̴�.
���̰� 1�� ���ٸ�, ��ġ ��ȣ�� �� ū ��(�������� �� ���� ���̾���)�� �� ���� ������ �ڷ� �ű�� ���� �����ϴ�.
�� �ൿ�� �� ���� ������ ��ġ ��ȣ�� �۾Ҵ� ��� ���� ���� �����ϴ�. ���̰� 0�� ���� ���� �� ����.
������ ���� �ּ� �̵��Ÿ��� ã���� �ű⼭���� �ٽ� �������� ���� �̵� ����� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : DP, ������

��ó : ���� 2003 ��2��
*/

int pos[1024][2], mem[1024][1024], route[1024]; //pos: W���� ���� X, Y ��ǥ / mem: ù ��° ���� �� ��° ���� ��ġ
int n;

int small(int a, int b) {
    return a < b ? a : b;
}

int getdist(int a, int p) {
    if (p < 0) {
        //0�� ���� ���� ó��(-1�� ���� ��, -2�� ������ �Ʒ�)
        if (p == -1) return pos[a][0] + pos[a][1] - 2;
        else return n * 2 - pos[a][0] - pos[a][1];
    }
    else return (abs(pos[a][0] - pos[p][0]) + abs(pos[a][1] - pos[p][1]));
}

int main(void) {
    int w, best, x = 0, y = 0;
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= w; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    mem[0][1] = getdist(1, -1); //ù ��° ���� ���ؼ��� ���� �̸� ���صд�.
    mem[1][0] = getdist(1, -2);
    for (int i = 2; i <= w; i++) {
        for (int j = 0; j < i - 1; j++) {
            //���̰� 2 �̻� ���� ��쿡�� 1ĭ�� �ű� �� �ִ�.
            mem[j][i] = mem[j][i - 1] + getdist(i, i - 1);
            mem[i][j] = mem[i - 1][j] + getdist(i, i - 1);
        }
        best = MAX;
        for (int j = 0; j < i - 1; j++) {
            //�� ���� ������ ���� ��ġ���� �����ϴ� ��� ��쿡 ���� �ּڰ��� ���Ѵ�.
            best = small(best, mem[i - 1][j] + getdist(i, j == 0 ? -1 : j));
        }
        mem[i - 1][i] = best;
        best = MAX;
        for (int j = 0; j < i - 1; j++) {
            //�� ���� ������ ���� ��ġ���� �����ϴ� ��� ��쿡 ���� �ּڰ��� ���Ѵ�.
            best = small(best, mem[j][i - 1] + getdist(i, j == 0 ? -2 : j));
        }
        mem[i][i - 1] = best;
    }
    best = MAX;
    for (int i = 0; i < w; i++) {
        if (mem[i][w] < best) {
            best = mem[i][w];
            x = i;
            y = w;
        }
        if (mem[w][i] < best) {
            best = mem[w][i];
            x = w;
            y = i;
        }
    }
    printf("%d\n", best);

    while (x > 0 || y > 0) {
        //������
        if (x > y) {
            route[x] = 2;
            if (x > y + 1) x--;
            else {
                for (int i = 1; i < y; i++) {
                    if (mem[i][y] + getdist(i, x) == mem[x][y]) {
                        x = i;
                        break;
                    }
                }
                if (x == y + 1) x = 0;
            }
        }
        else {
            route[y] = 1;
            if (y > x + 1) y--;
            else {
                for (int i = 1; i < x; i++) {
                    if (mem[x][i] + getdist(i, y) == mem[x][y]) {
                        y = i;
                        break;
                    }
                }
                if (y == x + 1) y = 0;
            }
        }
    }
    for (int i = 1; i <= w; i++) {
        printf("%d\n", route[i]);
    }
    return 0;
}