#include <stdio.h>

/*
���� : 3���� ���簢���� ���� ���� ����(<= 40)�� �־�����. �� ���簢���� �ٿ� �ϳ��� ���簢������
����� ����� �ݵ�� �ִٰ� �� ��, �� ����� ����Ѵ�.

�ذ� ��� : �ٿ��� �ϳ��� ���簢���� ����� ����� ũ�� 2�����̴�. �� ��츦 ��� ����� ���տ� ����
�õ��� ���鼭 ������ ��츦 ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ���̽� ��ũ, ������

��ó : IATI 2015 D2��
*/

char res[256][256];
int rect[3][2];

void printhor(int x) {
    for (int y = 0; y <= x * 2; y++) printf("%c", (~y & 1) ? '.' : ' ');
    printf("\n");
}

void printver1(int x, int y) {
    for (int i = 0; i < x; i++) {
        printf(".");
        for (int j = 1; j < y * 2; j++) printf(" ");
        printf(".\n");
    }
}

void printver2(int x, int y1, int y2) {
    for (int i = 0; i < x; i++) {
        printf(".");
        for (int j = 1; j < y1 * 2; j++) printf(" ");
        printf(".");
        for (int j = 1; j < y2 * 2; j++) printf(" ");
        printf(".\n");
    }
}

int main(void) {
    int r = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &rect[i][0], &rect[i][1]);
    }
    for (int i = 0; i < 8; i++) {
        if (rect[0][i & 1] + rect[1][(i >> 1) & 1] == rect[2][(i >> 2) & 1]) {
            if (rect[0][~i & 1] == rect[1][(~i >> 1) & 1]) {
                printhor(rect[2][(i >> 2) & 1]);
                printver1(rect[2][(~i >> 2) & 1] - 1, rect[2][(i >> 2) & 1]);
                printhor(rect[2][(i >> 2) & 1]);
                printver2(rect[0][(~i >> 0) & 1] - 1, rect[0][(i >> 0) & 1], rect[1][(i >> 1) & 1]);
                printhor(rect[2][(i >> 2) & 1]);
                return 0;
            }
        }

        if (rect[0][i & 1] + rect[2][(i >> 2) & 1] == rect[1][(i >> 1) & 1]) {
            if (rect[0][~i & 1] == rect[2][(~i >> 2) & 1]) {
                printhor(rect[1][(i >> 1) & 1]);
                printver1(rect[1][(~i >> 1) & 1] - 1, rect[1][(i >> 1) & 1]);
                printhor(rect[1][(i >> 1) & 1]);
                printver2(rect[0][(~i >> 0) & 1] - 1, rect[0][(i >> 0) & 1], rect[2][(i >> 2) & 1]);
                printhor(rect[1][(i >> 1) & 1]);
                return 0;
            }
        }

        if (rect[1][(i >> 1) & 1] + rect[2][(i >> 2) & 1] == rect[0][i & 1]) {
            if (rect[1][(~i >> 1) & 1] == rect[2][(~i >> 2) & 1]) {
                printhor(rect[0][(i >> 0) & 1]);
                printver1(rect[0][(~i >> 0) & 1] - 1, rect[0][(i >> 0) & 1]);
                printhor(rect[0][(i >> 0) & 1]);
                printver2(rect[1][(~i >> 1) & 1] - 1, rect[1][(i >> 1) & 1], rect[2][(i >> 2) & 1]);
                printhor(rect[0][(i >> 0) & 1]);
                return 0;
            }
        }

        if (rect[0][i & 1] == rect[1][(i >> 1) & 1] && rect[0][i & 1] == rect[2][(i >> 2) & 1]) {
            printhor(rect[0][(i >> 0) & 1]);
            printver1(rect[0][(~i >> 0) & 1] - 1, rect[0][(i >> 0) & 1]);
            printhor(rect[0][(i >> 0) & 1]);
            printver1(rect[1][(~i >> 1) & 1] - 1, rect[0][(i >> 0) & 1]);
            printhor(rect[0][(i >> 0) & 1]);
            printver1(rect[2][(~i >> 2) & 1] - 1, rect[0][(i >> 0) & 1]);
            printhor(rect[0][(i >> 0) & 1]);
            return 0;
        }
    }
    return 1;
}