#include <stdio.h>
#include <ctype.h>

/*
���� : �־��� 1���� 12������ ���� �̷���� ���׷��� ä��� ���� ���������� ���� ����� ���Ѵ�.
�ݵ�� ���� �ִ� ��츸 �־�����. �� ���� ���� 26�̾�� �Ѵ�.

�ذ� ��� : �� ���������� ���� ä���� ���� ����� ������ ä��������. ������ �������� ������
�ٸ� ���� �־��. �̸� �ݺ��ϴٰ� ������ �����ϵ��� ä��� ����� ������ �ϴ� ���� �����ϰ�
���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ʈ��ŷ

��ó : GCPC 2011 D��
*/

char star[8][16], used[12];
int line[6][4][2] = { {{0, 4}, {1, 3}, {2, 2}, {3, 1}}, {{3, 1}, {3, 3}, {3, 5}, {3, 7}},
    {{3, 7}, {2, 6}, {1, 5}, {0, 4}}, {{1, 1}, {1, 3}, {1, 5}, {1, 7}},
    {{1, 7}, {2, 6}, {3, 5}, {4, 4}}, {{4, 4}, {3, 3}, {2, 2}, {1, 1}} };
int fin = 0;

int nostar(void) {
    int t, cnt = 0;
    for (int i = 0; i < 6; i++) {
        t = 0;
        for (int j = 0; j < 4; j++) {
            if (isupper(star[line[i][j][0]][line[i][j][1]])) t++;
        }
        if (t < 4) continue;
        t = 0;
        for (int j = 0; j < 4; j++) t += star[line[i][j][0]][line[i][j][1]] - 'A' + 1;
        if (t != 26) return 1;
        else cnt++;
    }
    if (cnt == 6) return -1;
    else return 0;
}

void track(int cnt) {
    if (nostar() == 1) return;
    if (cnt == 12) {
        fin = 1;
        return;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (star[i][j] == 'x') {
                for (int k = 0; k < 12; k++) {
                    if (!used[k]) {
                        star[i][j] = 'A' + k;
                        used[k] = 1;
                        track(cnt + 1);
                        if (fin) return;
                        used[k] = 0;
                        star[i][j] = 'x';
                    }
                }
                return;
            }
        }
    }
}

int main(void) {
    int c = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%s", star[i]);
        for (int j = 0; j < 9; j++) {
            if (isupper(star[i][j])) {
                used[star[i][j] - 'A'] = 1;
                c++;
            }
        }
    }
    track(c);
    for (int i = 0; i < 5; i++) {
        printf("%s\n", star[i]);
    }
    return !fin;
}