#include <stdio.h>
#include <string.h>

/*
���� : ���� 18 ���Ϸ� ���� ������ �� ���ڿ��� �־��� ��, ù ��° ���ڿ��� ���� ���� Ƚ���� �߶�ٿ���
�� ��° ���ڿ��� ����ٸ� �ּ� �� ȸ �߶�� �ϴ��� ���Ѵ�.

�ذ� ��� : ��Ʈ����ŷ DP�� �̿��ϸ� N * 2^N �ð��� Ǯ �� �ִ�. ���������� �� ������ ��ġ�� ������� �� ���ڵ鿡 ����
���� ���� �ڸ� Ƚ���� �����صΰ� ����Ѵ�.

�ֿ� �˰��� : DP, ��ƮDP

��ó : PacNW 2018 O��
*/

char a[32], b[32];
int mem[20][262144];
int len;

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int pos, int prev, int bit) {
    //b�� pos��° ���ڸ� Ȯ������ �� ���� �� �ִ� ������ Ƚ���� ã�´�.
    //pos - 1��° ���ڴ� a���� prev������ ���� a���� �� ���ڴ� bit�����̴�.
    if (pos == len) return -1; //������ ĭ�� ������ ��� -1(����ĭ ���� 0)
    if (mem[prev][bit] >= 0) return mem[prev][bit]; //�̹� ��ϵ� ��� �ش� �� �ҷ�����
    int r = len, t;
    for (int i = 0; i < len; i++) {
        if ((bit >> i) & 1) continue; //�̹� ����� ����
        if (a[i] != b[pos]) continue; //���� �ٸ� ����

        t = dp(pos + 1, i, bit | (1 << i)); //���� ���·� �̵�
        if (i == prev + 1 && bit != 0) r = small(r, t); //���� ���ڿ��� ���
        else r = small(r, t + 1); //���ο� ���ڿ��� ����
    }
    return mem[prev][bit] = r;
}

int main(void) {
    scanf("%s%s", a, b);
    len = strlen(a);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 262144; j++) mem[i][j] = -1;
    }
    printf("%d", dp(0, 0, 0));
    return 0;
}