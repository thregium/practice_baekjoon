#include <stdio.h>
#include <vector>
#include <algorithm>
#define ZERO 103000
using namespace std;

/*
���� : N(N <= 100000)���� ���� ��ǥ���� �ִ�. (0, 0)���� �����¿�� ���� ����� ���� ������ �̵��ϴ�
������ M(M <= 100000)ȸ �� ���� �����ϴ� ��ġ�� ����Ѵ�. ���� ��ǥ�� ���� 100000 ������ �����̸�,
���� ���� �ݵ�� �����Ѵ�.

�ذ� ��� : ��ǥ ������ �����Ƿ� ���Ϳ� �� ��ǥ�� �ְ� ������ ���� ���⿡ �°� �̺� Ž���ϸ� �ȴ�.

�ֿ� �˰��� : ����, �̺� Ž��, �ùķ��̼�

��ó : CHCI 2012J2 3��
*/

char op[103000];
vector<int> xpos[204800], ypos[204800];

int main(void) {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        x += ZERO;
        y += ZERO;
        xpos[x].push_back(y);
        ypos[y].push_back(x);
    }
    for (int i = 0; i < 204800; i++) {
        sort(xpos[i].begin(), xpos[i].end());
        sort(ypos[i].begin(), ypos[i].end());
    }
    scanf("%s", op);

    x = ZERO, y = ZERO;
    for (int i = 0; i < m; i++) {
        if (op[i] == 'L') x = ypos[y][lower_bound(ypos[y].begin(), ypos[y].end(), x) - ypos[y].begin() - 1];
        else if(op[i] == 'R') x = ypos[y][upper_bound(ypos[y].begin(), ypos[y].end(), x) - ypos[y].begin()];
        else if (op[i] == 'D') y = xpos[x][lower_bound(xpos[x].begin(), xpos[x].end(), y) - xpos[x].begin() - 1];
        else if (op[i] == 'U') y = xpos[x][upper_bound(xpos[x].begin(), xpos[x].end(), y) - xpos[x].begin()];
    }
    printf("%d %d", x - ZERO, y - ZERO);
    return 0;
}