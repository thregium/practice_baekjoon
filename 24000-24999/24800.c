#include <stdio.h>

/*
���� : N(N <= 100)���� ����� S(S <= 100)���� ���ڳ� ������ �Ѵ�. ó������ �� ����� 1������ �����ϰ�,
S��° ����� ó������ ���� 2���� �ٲٰ�, �� �ķ� �� ���� 2�� �� �Ҹ��� �� ���� ���´�.
���������� ���� ����� ��ȣ�� ���Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. �� ��ġ�� ��ȭ�� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : VTH 2017 H��
*/

int hand[256];

int main(void) {
    int s, n, rem, x = -1, last = -1, end = 0;
    scanf("%d %d", &s, &n);
    for (int i = 0; i < n; i++) hand[i * 2] = 1;
    while (end < n * 2) {
        rem = s;
        while (rem) {
            x = (x + 1) % (n * 2);
            if (hand[x] == 0) continue;
            rem--;
        }
        last = x;
        if (hand[x] == 1) {
            hand[x] = 2, hand[x + 1] = 2;
            x--;
        }
        else if (hand[x] == 2) hand[x] = 3;
        else if (hand[x] == 3) {
            end++;
            hand[x] = 0;
        }
    }
    printf("%d", (last >> 1) + 1);
    return 0;
}