#include <stdio.h>

/*
���� : 19 * 19 ũ���� �����ǿ��� ������ �޼��� ���� �ִ��� Ȯ���ϰ� �ִٸ� �� ���� ��ǥ�� ���Ѵ�.

�ذ� ��� : ��� ������ ���⿡ ���� ������ �޼��Ͽ����� Ȯ���Ѵ�. �밢���� �����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ���̽� ��ũ

��ó : ���� 2003 ��1�� // IIPC 2005 A��
*/

int omok[24][24];

int main(void) {
    int pl, cs;
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            scanf("%d", &omok[i][j]);
        }
    }
    //����, ����
    for (int i = 1; i <= 19; i++) {
        pl = -1, cs = 0;
        for (int j = 1; j <= 19; j++) {
            if (omok[i][j] == pl) cs++;
            else {
                if (cs == 5 && pl) {
                    printf("%d\n%d %d", pl, i, j - 5);
                    return 0;
                }
                else cs = 1;
                pl = omok[i][j];
            }
        }
        if (cs == 5 && pl) {
            printf("%d\n%d 15", pl, i);
            return 0;
        }
        pl = -1, cs = 0;
        for (int j = 1; j <= 19; j++) {
            if (omok[j][i] == pl) cs++;
            else {
                if (cs == 5 && pl) {
                    printf("%d\n%d %d", pl, j - 5, i);
                    return 0;
                }
                else cs = 1;
                pl = omok[j][i];
            }
        }
        if (cs == 5 && pl) {
            printf("%d\n15 %d", pl, i);
            return 0;
        }
    }
    
    // \ �밢��
    for (int i = 1; i <= 15; i++) {
        pl = -1, cs = 0;
        for (int j = 1; i + j <= 20; j++) {
            if (omok[i + j - 1][j] == pl) cs++;
            else {
                if (cs == 5 && pl) {
                    printf("%d\n%d %d", pl, i + j - 6, j - 5);
                    return 0;
                }
                else cs = 1;
                pl = omok[i + j - 1][j];
            }
        }
        if (cs == 5 && pl) {
            printf("%d\n15 %d", pl, 16 - i);
            return 0;
        }
        pl = -1, cs = 0;
        for (int j = 1; i + j <= 20; j++) {
            if (omok[j][i + j - 1] == pl) cs++;
            else {
                if (cs == 5 && pl) {
                    printf("%d\n%d %d", pl, j - 5, i + j - 6);
                    return 0;
                }
                else cs = 1;
                pl = omok[j][i + j - 1];
            }
        }
        if (cs == 5 && pl) {
            printf("%d\n%d 15", pl, 16 - i);
            return 0;
        }
    }

    // / �밢��
    for (int i = 5; i <= 19; i++) {
        pl = -1, cs = 0;
        for (int j = 1; j <= i; j++) {
            if (omok[i - j][j] == pl) cs++;
            else {
                if (cs == 5 && pl) {
                    printf("%d\n%d %d", pl, i - j + 5, j - 5);
                    return 0;
                }
                else cs = 1;
                pl = omok[i - j][j];
            }
        }
        if (cs == 5 && pl) {
            printf("%d\n5 %d", pl, i - 4);
            return 0;
        }
    }
    for (int i = 1; i <= 15; i++) {
        pl = -1, cs = 0;
        for (int j = 1; i + j <= 20; j++) {
            if (omok[20 - j][i + j - 1] == pl) cs++;
            else {
                if (cs == 5 && pl) {
                    printf("%d\n%d %d", pl, 25 - j, i + j - 6);
                    return 0;
                }
                else cs = 1;
                pl = omok[20 - j][i + j - 1];
            }
        }
        if (cs == 5 && pl) {
            printf("%d\n%d 15", pl, i + 4);
            return 0;
        }
    }
    printf("0");
    return 0;
}