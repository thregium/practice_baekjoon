#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

/*
���� : N(N <= 6000)���� ������ �ִ�. �� ������ ������, �ʷϻ�, �Ķ��� �� �ϳ��̰�,
���̴� 100000 ������ �ڿ����̴�. �̶�, ������ ������ ��� �� ���� ���� ��� �ٸ�
�ﰢ���� ����� ����� ���� ���Ѵ�.

�ذ� ��� : �� ���е��� ���󺰷� �з��� ���� ���̺��� �����Ѵ�.
�׷� ����, �������� �ʷϻ��� ��� ��츦 �ϳ��� Ȯ���ϸ鼭 �Ķ��� ������ ������ ���� ������ ����
���� �� �ִ� �ﰢ���� �������� ��� ���س����� �ȴ�. ������ ������ �� ������ ���� ������ ũ��
���� �պ��� ���� �����̴�.

�ֿ� �˰��� : ������, �̺� Ž��

��ó : IATI 2016C 3��
*/

int red[6144], green[6144], blue[6144];

int main(void) {
    int n, rn = 0, gn = 0, bn = 0, x;
    long long res = 0;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &x);
        if (c == 'r') red[rn++] = x;
        else if (c == 'g') green[gn++] = x;
        else if (c == 'b') blue[bn++] = x;
        else return 1;
    }
    sort(blue, blue + bn);
    for (int i = 0; i < rn; i++) {
        for (int j = 0; j < gn; j++) {
            if (abs(red[i] - green[j]) > red[i] + green[j]) continue;
            res += upper_bound(blue, blue + bn, red[i] + green[j] - 1) -
                lower_bound(blue, blue + bn, abs(red[i] - green[j]) + 1);
        }
    }
    printf("%lld", res);
    return 0;
}