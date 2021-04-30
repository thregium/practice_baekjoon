#include <stdio.h>
#include <math.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100)������ �ҵ��� ���� ���谡 �� X�� ���� Y �� / ���� Y ��� �־����ٰ� �� ��, Bessie�� Elsie�� ���� ���� ���Ѵ�.

�ذ� ��� : Bessie�� �������� �� �ҵ��� ���̸� ������ ���´�. �� ����� ���̸� ���� �� �� ���ٸ� ���� �ҷ� �Ѿ��.
N�� 100 �����̹Ƿ� N^2���ε� ����� ���ư��� ���� �����ϴ�. �츦 ���� ������ �� ����� ��� ���� ���̿��� 12�� ���� �������� �� ��ȣ�� �ǰ�,
ã�� ���� ��� ���Ʈ ������ Ȯ���غ��� �ȴ�. �� ���� ���� ���̴� �񱳹��� ���ų� ������ ������ ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ����

��ó : USACO 2020F B1��
*/

char* years[12] = { "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat" };
char rel[128][8][16];
int ages[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("C:\\1_����\\PS\\olympiad\\USA\\Bronze\\2021_02\\prob1_bronze_feb21\\10.in", "r");
        fo = fopen("C:\\1_����\\PS\\olympiad\\USA\\Bronze\\2021_02\\prob1_bronze_feb21\\10_p.out", "w");
    }
    int n, repeat = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%s", rel[i][j]);
        }
        ages[i] = 1000000; //���� �ʱ�ȭ
    }
    while (repeat) {
        //Ž���� ����� �ִ� ��� ��� �ݺ��Ѵ�.
        repeat = 0;
        for (int i = 0; i < n; i++) {
            if (ages[i] < 1000000) continue; //�̹� ������ ���
            if (!strcmp(rel[i][7], "Bessie")) {
                //Bessie�� �� ����� ���
                for (int j = 0; j < 12; j++) {
                    if (!strcmp(rel[i][4], years[j])) {
                        if (!strcmp(rel[i][3], "next")) {
                            ages[i] = (j + 11) % 12 + 1; //���� ��
                        }
                        else {
                            ages[i] = j - 12; //���� ��
                        }
                    }
                }
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!strcmp(rel[i][7], rel[j][0])) {
                    if (ages[j] >= 1000000) {
                        repeat = 1;
                        break;
                    }

                    for (int k = 0; k < 12; k++) {
                        if (!strcmp(rel[i][4], years[k])) {
                            if (!strcmp(rel[i][3], "next")) {
                                ages[i] = ages[j] + (k + (11 - (ages[j] + 2400) % 12)) % 12 + 1; //���� ��
                            }
                            else {
                                ages[i] = ages[j] + (k + (12 - (ages[j] + 2400) % 12)) % 12 - 12; //���� ��
                            }
                        }
                    }
                }
            }
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        printf("%s was born %d years %s Bessie.\n", rel[i][0], abs(ages[i]), ages[i] < 0 ? "before" : "after");
    }
    */
    for (int i = 0; i < n; i++) {
        if (!strcmp(rel[i][0], "Elsie")) {
            printf("%d", abs(ages[i])); //���� ���� ���밪 ���
            return 0;
        }
    }
    return 0;
}