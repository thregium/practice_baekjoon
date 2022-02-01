#include <stdio.h>

/*
���� : 8 * 8 ũ���� �ǿ� 2 �̻� 2^30 ������ 2�� �ŵ����� �Ǵ� 0�� �ִ�.
�̶�, 2048�� ���� ����ȴٸ� ���� �־��� �������� ��￴�� �� ���� ���� ���¸� ����Ѵ�.
���ο� ���� �߰����� �ʴ´�.

�ذ� ��� : ���� ����̴� �ݴ� �������� Ȯ���� ������ ������ �ؿ������� �׾Ƴ�����.
���� ���� ���� ���������� Ȯ���� ���� ���ٸ� ���� ��ģ �� Ȯ���� ���� ���ְ�, �ٸ��ٸ� ���������� Ȯ����
���� ���� ���� ���� ���� ���������� Ȯ���� ���� �ٲ۴�. Ȯ���� ���� ���ٸ� ���� ���� ���������� Ȯ����
���� �ӽ� �����صд�. ���� ���� ���� ���� Ȯ���� ���� �׾Ƶ� ���� ������ ĭ���� 0���� ä���.
�̸� �� ���⸶�� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �� ������

��ó : ���հ��� 2021 B��
*/

long long area[8][8];

int main(void) {
    long long cnt, l, ln;
    char d;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%lld", &area[i][j]);
        }
    }
    scanf(" %c", &d);
    if (d == 'U') {
        for (int i = 0; i < 8; i++) {
            l = 0, ln = 0;
            for (int j = 0; j < 8; j++) {
                if (area[j][i] && ln == 0) ln = area[j][i];
                else if (ln > 0 && area[j][i] == ln) {
                    area[l++][i] = ln * 2;
                    ln = 0;
                }
                else if (area[j][i]) {
                    area[l++][i] = ln;
                    ln = area[j][i];
                }
            }
            area[l++][i] = ln;
            while (l < 8) area[l++][i] = 0;
        }
    }
    else if (d == 'L') {
        for (int i = 0; i < 8; i++) {
            l = 0, ln = 0;
            for (int j = 0; j < 8; j++) {
                if (area[i][j] && ln == 0) ln = area[i][j];
                else if (ln > 0 && area[i][j] == ln) {
                    area[i][l++] = ln * 2;
                    ln = 0;
                }
                else if (area[i][j]) {
                    area[i][l++] = ln;
                    ln = area[i][j];
                }
            }
            area[i][l++] = ln;
            while (l < 8) area[i][l++] = 0;
        }
    }
    else if (d == 'D') {
        for (int i = 0; i < 8; i++) {
            l = 7, ln = 0;
            for (int j = 7; j >= 0; j--) {
                if (area[j][i] && ln == 0) ln = area[j][i];
                else if (ln > 0 && area[j][i] == ln) {
                    area[l--][i] = ln * 2;
                    ln = 0;
                }
                else if (area[j][i]) {
                    area[l--][i] = ln;
                    ln = area[j][i];
                }
            }
            area[l--][i] = ln;
            while (l >= 0) area[l--][i] = 0;
        }
    }
    else {
        for (int i = 0; i < 8; i++) {
            l = 7, ln = 0;
            for (int j = 7; j >= 0; j--) {
                if (area[i][j] && ln == 0) ln = area[i][j];
                else if (ln > 0 && area[i][j] == ln) {
                    area[i][l--] = ln * 2;
                    ln = 0;
                }
                else if (area[i][j]) {
                    area[i][l--] = ln;
                    ln = area[i][j];
                }
            }
            area[i][l--] = ln;
            while (l >= 0) area[i][l--] = 0;
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%lld ", area[i][j]);
        }
        printf("\n");
    }
    return 0;
}