#include <stdio.h>

/*
���� : 3���� �ĺ��� ���� ��ǥ ����� �־��� ��, 1���� ���� ������ ���Ѵ�. ���� ���� ���� ���� ��� -> 3���� ���� ���� ���� ���
-> 2���� ���� ���� ���� ��� ������ �켱������ �ְ� ���� ���ٸ� 1���� ����.

�ذ� ��� : ������ ������ ���� �� ����� ���� ������ �ذ��Ѵ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : ���� 2011�� ��2/��1��
*/

int counts[4][4];

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        counts[1][a]++;
        counts[1][0] += a;
        counts[2][b]++;
        counts[2][0] += b;
        counts[3][c]++;
        counts[3][0] += c;
    }
    if (counts[1][0] > counts[2][0] && counts[1][0] > counts[3][0]) printf("1 %d", counts[1][0]);
    else if (counts[2][0] > counts[1][0] && counts[2][0] > counts[3][0]) printf("2 %d", counts[2][0]);
    else if (counts[3][0] > counts[1][0] && counts[3][0] > counts[2][0]) printf("3 %d", counts[3][0]);
    else if (counts[1][3] > counts[2][3] && counts[1][3] > counts[3][3] && counts[1][0] >= counts[2][0] && counts[1][0] >= counts[3][0]) printf("1 %d", counts[1][0]);
    else if (counts[2][3] > counts[1][3] && counts[2][3] > counts[3][3] && counts[2][0] >= counts[1][0] && counts[2][0] >= counts[3][0]) printf("2 %d", counts[2][0]);
    else if (counts[3][3] > counts[1][3] && counts[3][3] > counts[2][3] && counts[3][0] >= counts[1][0] && counts[3][0] >= counts[2][0]) printf("3 %d", counts[3][0]);
    else if (counts[1][2] > counts[2][2] && counts[1][2] > counts[3][2] && counts[1][3] >= counts[2][3] && counts[1][3] >= counts[3][3] && counts[1][0] >= counts[2][0] && counts[1][0] >= counts[3][0]) printf("1 %d", counts[1][0]);
    else if (counts[2][2] > counts[1][2] && counts[2][2] > counts[3][2] && counts[2][3] >= counts[1][3] && counts[2][3] >= counts[3][3] && counts[2][0] >= counts[1][0] && counts[2][0] >= counts[3][0]) printf("2 %d", counts[2][0]);
    else if (counts[3][2] > counts[1][2] && counts[3][2] > counts[2][2] && counts[3][3] >= counts[1][3] && counts[3][3] >= counts[2][3] && counts[3][0] >= counts[1][0] && counts[3][0] >= counts[2][0]) printf("3 %d", counts[3][0]);
    else printf("0 %d", counts[1][0] >= counts[2][0] ? counts[1][0] : counts[2][0]);
    return 0;
}