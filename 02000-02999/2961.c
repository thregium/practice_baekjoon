#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 10)���� �ڿ��� ���� �־��� ��, ������ �ֵ��� ù��° ���� ���� �ι�° ���� ���� ���� ���� ����� ���̸� ���Ѵ�.
��, �ּ� �� ���� �����ؾ� �Ѵ�.

�ذ� ��� : ������ �� �ִ� ��� �ֿ� ���� �����غ��� ���� ���̰� ���� ��츦 ���Ѵ�. ��Ʈ����ŷ�� ���� ���ϴ� ���� ����.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ����ŷ

��ó : COCI 08/09#2 3��
*/

int taste[16][2];

int main(void) {
    int n, s, b, r = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &taste[i][0], &taste[i][1]);
    }
    for (int i = 1; i < (1 << n); i++) {
        s = 1, b = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                s *= taste[j][0];
                b += taste[j][1];
            }
        }
        if (abs(s - b) < r) r = abs(s - b);
    }
    printf("%d", r);
    return 0;
}