#include <stdio.h>
#include <string.h>

/*
���� : 25�ڸ� �̳��� �� N�� �־�����. �����ؼ� �� ���� ���� �� �ִ� ���� �ִ��� Ȯ���ϰ� �ִٸ� �ϳ��� ����Ѵ�.
��, ���⼭ ������ ��� �������� �ø��� ���� �ʴ´�. ���� ��� 765 * 765 = (92500 + 2600 + 505) = 94605�� �ȴ�.

�ذ� ��� : ���� N�� �ڸ����� ����. �ڸ����� ¦���� ��쿡�� �������� ���� �� ����.
N�� Ȧ���� ��쿡�� �������� �ڸ����� �� �� �ִµ�, (N + 1) / 2�� ����.
�������� ����� ����� ���캸�� �� ���ڸ����� �ش� �ڸ������� ���غ��� �� X��° �ڸ����� N�� X��° �ڸ����� ���� �������� ���� �ȴ�.
�װ��� ���������� ���� �ڸ������� 2���� �����ϹǷ� �ִ� 2^13���� ����� ���� Ȯ���غ��� �ǰ�,
�̴� ����� �ð� ���� Ǯ �� �ִ� ���̴�.

�ֿ� �˰����� : ����, ��Ʈ��ŷ

��ó : PacNW 2019 L��/Y�� // SEUSA 2019D1 A�� // SEUSA 2019D2 B��
*/

char n[32], root[16];
int ans = 0;

void track(int x, int y) {
    if (x == y) {
        //������ �����غ��� N�� ������ Ȯ���Ѵ�.
        int tmp[32] = { 0, };
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < y; j++) {
                tmp[i + j] = (tmp[i + j] + root[i] * root[j]) % 10;
            }
        }
        for (int i = 0; i < x * 2 - 1; i++) {
            if (tmp[i] != n[i]) return;
        }
        ans = 1;
        return;
    }
    int sum = 0;
    for (int i = 1; i < y; i++) {
        sum += root[i] * root[y - i];
    }
    for (int i = 0; i < 10; i++) {
        root[y] = i;
        if ((sum + (1 + !!y) * i * root[0]) % 10 != n[y]) continue; //Y��° ���ڸ� N�� ���� ���� �� �ִ��� Ȯ���غ���.
        track(x, y + 1);
        if (ans) return;
    }
}

int main(void) {
    scanf("%s", n);
    int len = strlen(n);
    if (!(len & 1)) {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < len; i++) n[i] -= '0';
    track((len >> 1) + 1, 0);
    if (!ans) {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < (len >> 1) + 1; i++) {
        printf("%c", root[i] + '0');
    }
    return 0;
}