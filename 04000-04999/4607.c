#include <stdio.h>
#define INF 1012345678

/*
���� : R * C(R, C <= 20) ũ���� slitherlink ������ ������ �־��� ������� Ǭ��.
������ �־��� �������� Ǯ �� �ִ� ��츸 �־�����.

�ذ� ��� : ������ �־��� ������ �״�� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : MidC 2007 C��
*/

char res[128][128];
int dxy1[4][2] = { {2, 0}, {0, 0}, {0, 4}, {2, 4} };
int dxy2[4][2] = { {2, -4}, {-2, -4}, {-2, 4}, {2, 4} };

void drawline(int x, int y, int d, char c) {
    //(x, y)�� �־��� ���� �������� ���� �ߴ´�. d = 0: ��, 1: ������, 2: �Ʒ�, 3: ����. c: ���� ���� ����
    if (d & 1) {
        if (c == '-') {
            for (int i = -1; i <= 1; i++) res[x][y - d * 2 + 4 + i] = c;
        }
        else res[x][y - d * 2 + 4] = c;
    }
    else if (c == '-') {
        for (int i = -1; i <= 1; i++) res[x + d - 1][y + i] = c;
    }
    else res[x + d - 1][y] = c;
}

int findline(int x, int y, int h, int w, int d, char c) {
    //(x, y)�� d������ ���� c���� �˻��Ѵ�. d = 0: ��, 1: ������, 2: �Ʒ�, 3: ����.
    if (d & 1) {
        if (x >= h || y - d * 2 + 4 >= w || x <= 1 || y - d * 2 + 4 <= 1) return (c == 'x');
        return (res[x][y - d * 2 + 4] == c);
    }
    else {
        if (x + d - 1 >= h || y >= w || x + d - 1 <= 1 || y <= 1) return (c == 'x');
        return (res[x + d - 1][y] == c);
    }
}

int finished(int r, int c) {
    //��� ���� ���¸� Ȯ���Ͽ����� ���Ѵ�.
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < 4; k++) {
                if (findline(i * 2 + 3, j * 4 + 4, r * 2 + 3, c * 4 + 3, k, ' ')) return 0;
            }
        }
    }
    return 1;
}

void checkasell(int x, int y) {
    //�� ĭ���� üũ�� �� �ִ� �͵��� üũ�Ѵ�.
    int checked = 0, elimed = 0;
    if (res[x][y] == '0') {
        for (int i = 0; i < 4; i++) drawline(x, y, i, 'x');
    }
    for (int i = 0; i < 4; i++) {
        checked += findline(x, y, INF, INF, i, i & 1 ? '|' : '-');
        elimed += findline(x, y, INF, INF, i, 'x');
    }
    if (checked + elimed == 4) return; //�̹� �� �� �ִ� �͵��� ������ ���
    if (res[x][y] - '0' == checked) {
        //üũ ������ �͵��� ��� üũ�ߴٸ� �������� ���� ����
        for (int i = 0; i < 4; i++) {
            if (!findline(x, y, INF, INF, i, i & 1 ? '|' : '-')) drawline(x, y, i, 'x');
        }
    }
    if ('4' - res[x][y] == elimed) {
        //���� �� �ִ� �͵��� ��� �����ٸ� �������� ���� üũ��
        for (int i = 0; i < 4; i++) {
            if (!findline(x, y, INF, INF, i, 'x')) drawline(x, y, i, i & 1 ? '|' : '-');
        }
    }
}

void checktwothree(int x, int y, int d) {
    //������ 2���� 3�� üũ�Ѵ�.
    if (d == 0) {
        if (res[x][y] != '3' || res[x][y + 4] != '3') return;
        drawline(x, y, 3, '|');
        drawline(x, y, 1, '|');
        drawline(x, y + 4, 1, '|');
    }
    else {
        if (res[x][y] != '3' || res[x + 2][y] != '3') return;
        drawline(x, y, 0, '-');
        drawline(x, y, 2, '-');
        drawline(x + 2, y, 2, '-');
    }
}

void checktwobytwo(int x, int y, int h, int w) {
    //2 * 2 �������� Ȯ�� ������ �͵��� �߰��Ѵ�.
    //3�� �밢������ ������ ���
    if (res[x][y] == '3' && res[x + 2][y + 4] == '3') {
        drawline(x, y, 0, '-');
        drawline(x, y, 3, '|');
        drawline(x + 2, y + 4, 1, '|');
        drawline(x + 2, y + 4, 2, '-');
    }
    else if (res[x][y + 4] == '3' && res[x + 2][y] == '3') {
        drawline(x, y + 4, 0, '-');
        drawline(x, y + 4, 1, '|');
        drawline(x + 2, y, 2, '-');
        drawline(x + 2, y, 3, '|');
    }

    int edgechecked = 0, edgeelimed = 0; //�� ������((X, Y)�� ������ �밢�� �Ʒ�)�� �������� �����¿� ���� ���� üũ/���� ����
    for (int i = 0; i < 4; i++) {
        edgechecked += findline(x + 1, y + 2, h, w, i, i & 1 ? '-' : '|');
        edgeelimed += findline(x + 1, y + 2, h, w, i, 'x');
    }
    if (edgeelimed == 3) {
        //3���� ���ŵ� ��� ������ 1���� ����
        for (int i = 0; i < 4; i++) {
            if(!findline(x + 1, y + 2, h, w, i, 'x')) drawline(x + 1, y + 2, i, 'x');
        }
    }
    else if (edgechecked == 1 && edgeelimed == 2) {
        //1���� üũ�ǰ� ������ �� 2���� ���ŵ� ��� ������ 1���� üũ
        for (int i = 0; i < 4; i++) {
            if (findline(x + 1, y + 2, h, w, i, ' ')) drawline(x + 1, y + 2, i, i & 1 ? '-' : '|');
        }
    }
    else if (edgechecked == 2) {
        //2���� üũ�� ��� �������� ����
        for (int i = 0; i < 4; i++) {
            if (findline(x + 1, y + 2, h, w, i, ' ')) drawline(x + 1, y + 2, i, 'x');
        }
    }

    for (int i = 0; i < 4; i++) {
        //��� �� 2���� �����Ͽ� üũ/���ŵ� ��� �밢���� 3 �Ǵ� 1�� �ִٸ� ���� ���� �߰ų� �����Ѵ�.
        edgechecked = 0, edgeelimed = 0;
        for (int j = 0; j < 2; j++) {
            edgechecked += findline(x + 1, y + 2, h, w, (i + j) & 3, ((i + j) & 1) ? '-' : '|');
            edgeelimed += findline(x + 1, y + 2, h, w, (i + j) & 3, 'x');
        }
        if (edgeelimed == 2 || (edgechecked == 1 && edgeelimed == 1)) {
            if (res[x + dxy1[i][0]][y + dxy1[i][1]] == '3' ||
                res[x + dxy1[i][0]][y + dxy1[i][1]] == '1') {
                drawline(x + dxy1[i][0], y + dxy1[i][1], edgeelimed == 2 ? i : ((i + 2) & 3),
                    res[x + dxy1[i][0]][y + dxy1[i][1]] == '3' ? ((i & 1) ? '|' : '-') : 'x');
                drawline(x + dxy1[i][0], y + dxy1[i][1], edgeelimed == 2 ? (i + 1) & 3 : ((i + 3) & 3),
                    res[x + dxy1[i][0]][y + dxy1[i][1]] == '3' ? ((i & 1) ? '-' : '|') : 'x');
            }
        }
    }
}

void checkthreebythree(int x, int y, int h, int w) {
    //(X, Y)�� �߽����� ���� 3 * 3 ������ ���캻��.
    int checked = 0, elimed = 0;
    for (int i = 0; i < 4; i++) {
        checked = 0, elimed = 0;
        for (int j = 0; j < 2; j++) {
            checked += findline(x + dxy2[i][0], y + dxy2[i][1], h, w, (i + j) & 3, ((i + j) & 1) ? '|' : '-');
            elimed += findline(x + dxy2[i][0], y + dxy2[i][1], h, w, (i + j) & 3, 'x');
        }
        if (elimed == 2) {
            if (res[x][y] == '3' && res[x + dxy2[(i + 2) & 3][0]][y + dxy2[(i + 2) & 3][1]] == '1') {
                //3�� 1�� �밢������ ���ֺ� ���
                drawline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], i, 'x');
                drawline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], (i + 1) & 3, 'x');
            }
            //2�� �밢�� �������� 2ĭ�� ��������, �� �� �밢�� �� 1���� ������ ��� �ٸ� �� ���� �ߴ´�.
            if (res[x][y] == '2' && findline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], h, w, (i + 1) & 3, 'x')
                && findline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], h, w, (i + 2) & 3, ' '))
                drawline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], (i + 2) & 3, (i & 1) ? '|' : '-');
            if (res[x][y] == '2' && findline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], h, w, (i + 2) & 3, 'x')
                && findline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], h, w, (i + 1) & 3, ' '))
                drawline(x + dxy2[(i + 1) & 3][0], y + dxy2[(i + 1) & 3][1], (i + 1) & 3, (i & 1) ? '-' : '|');
            if (res[x][y] == '2' && findline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], h, w, (i + 3) & 3, 'x')
                && findline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], h, w, i, ' '))
                drawline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], i, (i & 1) ? '|' : '-');
            if (res[x][y] == '2' && findline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], h, w, i, 'x')
                && findline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], h, w, (i + 3) & 3, ' '))
                drawline(x + dxy2[(i + 3) & 3][0], y + dxy2[(i + 3) & 3][1], (i + 3) & 3, (i & 1) ? '-' : '|');
        }
        
        else if (checked == 1 && elimed == 1) {
            //2�� �밢�� �������� 1ĭ�� ä������ 1ĭ�� ������ ���¿��� �� �� �밢�� �� 1���� ������ ��� �ٸ� �� ���� �ߴ´�.
            if (res[x][y] == '2' && findline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], h, w, (i + 2) & 3, 'x')
                && findline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], h, w, (i + 1) & 3, ' '))
                drawline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], (i + 3) & 3, (i & 1) ? '-' : '|');
            if (res[x][y] == '2' && findline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], h, w, (i + 3) & 3, 'x')
                && findline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], h, w, (i + 2) & 3, ' '))
                drawline(x + dxy2[(i + 2) & 3][0], y + dxy2[(i + 2) & 3][1], (i + 2) & 3, (i & 1) ? '|' : '-');
        }
        
    }
}

int main(void) {
    int r, c, x, cnt;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2007\\mcpc2007\\slink\\slink.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2007\\mcpc2007\\slink\\slink_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d %d", &r, &c);
        if (r == 0) break;
        cnt = 0;
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                if (i >= r * 2 + 5 || j >= c * 4 + 5) res[i][j] = '\0';
                else if (i == 0 || j == 0 || i == r * 2 + 4 || j == c * 4 + 4) res[i][j] = '#';
                else res[i][j] = ' ';
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &x);
                res[i * 2 + 3][j * 4 + 4] = '0' + x;
            }
        }

        cnt = 0;
        while (!finished(r, c)) {
            //����ñ��� �ݺ�
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    checkasell(i * 2 + 3, j * 4 + 4);
                    if (j < c - 1) checktwothree(i * 2 + 3, j * 4 + 4, 0);
                    if (i < r - 1) checktwothree(i * 2 + 3, j * 4 + 4, 1);
                    checkthreebythree(i * 2 + 3, j * 4 + 4, r * 2 + 3, c * 4 + 3);
                }
            }
            for (int i = 0; i <= r; i++) {
                for (int j = 0; j <= c; j++) {
                    //2 * 2�� �ٱ��ʱ��� Ȯ���ؾ� ��
                    checktwobytwo(i * 2 + 1, j * 4, r * 2 + 3, c * 4 + 3);
                }
            }
            cnt++;
            //if (cnt == 100) break;
        }
        for (int i = 1; i <= r * 2 + 3; i++) {
            for (int j = 1; j <= c * 4 + 3; j++) {
                //���� ������ �����ϰ� ������ ������ �̾��ش�.
                if (res[i][j] == 'x') res[i][j] = ' ';
                else if (res[i][j - 1] == '-' && res[i][j + 1] == '-') res[i][j] = '-';
                else if (res[i - 1][j] == '|' && res[i + 1][j] == '|') res[i][j] = '|';
                else if (res[i][j] == ' ' && (res[i][j - 1] == '-' || res[i][j + 1] == '-'
                    || res[i - 1][j] == '|' && res[i + 1][j] == '|')) res[i][j] = '+';
            }
        }

        printf("%d\n", tt);
        for (int i = 0; i < r * 2 + 5; i++) {
            printf("%s\n", res[i]);
        }
    }
    return 0;
}