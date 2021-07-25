#include <stdio.h>

/*
���� : M * N ũ�� ���ڿ��� ĥ���� ĭ���� 2���� ��ġ�� �ʴ� ���簢������ ���� �� �ִ��� ���ϰ�,
�����ϴٸ� ������ ����� ����Ѵ�.

�ذ� ��� : ���� ���� �������� �ִ��� �а� �� ���� ���� �������� �а� �ϴ� ������� ���簢���� ������ ����.
Ž�� ������ ����->���� ������ �ؾ� �Ѵ�. ���� ���簢���� ���ų� 1ĭ�� �ִ� ��쿡�� ���� �� ����.
���簢�� �ϳ����� 2ĭ �̻��̶�� ���ε� ���ε� 2ĭ �̻��� ������ ������ �ȴ�.
���簢�� 2���� ��쿡�� ���� ��� ����ϸ� �ǰ�, 3�� �̻��̶�� �ٽ� ����->���� ������ �������.
Ž�� ������ ����->���η� �ٲپ�� �Ѵ�. ���⼭ ���簢�� 2���� ���������ٸ� ������ ���� �����ϰ�,
���⼭�� 3�� �̻��̶�� ������ ���� �Ұ����ϴ�.

�ֿ� �˰��� : �׸��� �˰���, ���̽� ��ũ, ������

��ó : ROI 2004H H��
*/

char pict[256][256];
int rect[256][256];

void printrect(int m, int n) {
    //���簢�� ���
    printf("YES\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rect[i][j] == 0) printf(".");
            else printf("%c", rect[i][j] + 'a' - 1);
        }
        printf("\n");
    }
}

int main(void) {
    int m, n, cnt = 0, startx = 0, starty = 0, sizex = 0, sizey = 0, tmp;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", pict[i]);
    }
    //���� -> ����
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pict[i][j] != '#') continue;
            if (rect[i][j]) continue;
            sizex = 0, sizey = 0, cnt++;
            startx = i, starty = j;
            for (int ii = i; ii < m && pict[ii][j] == '#' && rect[ii][j] == 0; ii++) {
                sizex++; //���� Ȯ��
            }
            for (int jj = j; jj < n; jj++) {
                tmp = 0;
                for (int ii = i; ii < i + sizex; ii++) {
                    if (pict[ii][jj] != '#' || rect[ii][jj] != 0) tmp = 1;
                }
                if (tmp) break;
                sizey++; //�ʺ� Ȯ��
            }
            for (int ii = i; ii < i + sizex; ii++) {
                for (int jj = j; jj < j + sizey; jj++) {
                    rect[ii][jj] = cnt;
                }
            }
        }
    }
    if (cnt == 0) {
        printf("NO"); //���簢���� ���� ��
        return 0;
    }
    else if (cnt == 1) {
        //1���� ���
        if (sizex > 1) {
            for (int i = starty; i < starty + sizey; i++) rect[startx][i] = 2;
            printrect(m, n);
        }
        else if (sizey > 1) {
            for (int i = startx; i < startx + sizex; i++) rect[i][starty] = 2;
            printrect(m, n);
        }
        else printf("NO");
        return 0;
    }
    else if (cnt == 2) {
        printrect(m, n); //2����� �״�� ���
        return 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) rect[i][j] = 0; //���簢�� �ʱ�ȭ
    }
    cnt = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            //���� -> ����
            if (pict[i][j] != '#') continue;
            if (rect[i][j]) continue;
            sizex = 0, sizey = 0, cnt++;
            for (int jj = j; jj < n && pict[i][jj] == '#' && rect[i][jj] == 0; jj++) {
                sizey++; //�ʺ� Ȯ��
            }
            for (int ii = i; ii < n; ii++) {
                tmp = 0;
                for (int jj = j; jj < j + sizey; jj++) {
                    if (pict[ii][jj] != '#' || rect[ii][jj] != 0) tmp = 1;
                }
                if (tmp) break;
                sizex++; //���� Ȯ��
            }
            for (int ii = i; ii < i + sizex; ii++) {
                for (int jj = j; jj < j + sizey; jj++) {
                    rect[ii][jj] = cnt;
                }
            }
        }
    }
    if (cnt > 2) printf("NO");
    else printrect(m, n);
    return 0;
}