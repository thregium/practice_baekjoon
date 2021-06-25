#include <stdio.h>

/*
���� : R1����� R2(|R1|, |R2| <= 5000), (0 <= R2 - R1 <= 49)�����, C1������ C2(|C1|, |C2| <= 5000), (0 <= C2 - C1 <= 4)��������
�ҿ뵹�̸� ���� ���� ���߾� ����Ѵ�.

�ذ� ��� : �ҿ뵹�̸� ���� ���� �ʰ� ��ǥ�� ���� ���� ã�´�. ���� �� ��° �������� Ȯ�� ��, ���⿡ ���� ���� ����� �ȴ�.
�� �������δ� �ش� ������ �ҿ뵹�̿��� ���� ū ���� ã��, �� ���� �ڸ����� ã�Ƴ� ����, ��� ���� ���� ū ���� �ش��ϴ�
ĭ �� ������ ���߾� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����
*/

int a[64][8];

int big(int a, int b) {
    return a > b ? a : b;
}

int getlen(int x) {
    //�ڿ��� x�� �ش��ϴ� ���� �ڸ����� ���Ѵ�.
    if (x >= 1000000000) return 10;
    else if (x >= 100000000) return 9;
    else if (x >= 10000000) return 8;
    else if (x >= 1000000) return 7;
    else if (x >= 100000) return 6;
    else if (x >= 10000) return 5;
    else if (x >= 1000) return 4;
    else if (x >= 100) return 3;
    else if (x >= 10) return 2;
    else return 1;
}

int getnum(int x, int y) {
    if (x == 0 && y == 0) return 1;
    int level = big((x < 0 ? -x : x), (y < 0 ? -y : y)); //���� ��
    int num = (level * 2 - 1) * (level * 2 - 1);
    if (y == level && x != level) {
        num += level - x; //������
    }
    else if (x == -level) {
        num += (level * 3) - y; //����
    }
    else if (y == -level) {
        num += (level * 5) + x; //����
    }
    else {
        num += (level * 7) + y; //�Ʒ���
    }
    return num;
}

int main(void) {
    int r1, r2, c1, c2, biggest = 0, space = 0;;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            a[i - r1][j - c1] = getnum(i, j);
            if (a[i - r1][j - c1] > biggest) biggest = a[i - r1][j - c1]; //���� ū ���� ã�´�.
        }
    }
    space = getlen(biggest) + 1;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            for (int k = 0; k < space - getlen(a[i - r1][j - c1]) - (j == c1); k++) {
                //�� ������ �ƴ϶�� ���� ĭ �� + 1��, �� �� ���̶�� ���� ĭ �� ��ŭ�� ���⸦ �Ѵ�.
                printf(" ");
            }
            printf("%d", a[i - r1][j - c1]);
        }
        printf("\n");
    }
    return 0;
}