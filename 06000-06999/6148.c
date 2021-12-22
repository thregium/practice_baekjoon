#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 20)������ �ҵ��� Ű�� ���� �־��� ��(<= 10^6), �ҵ��� Ű ���� B���� ũ�� �ϸ鼭 B���� ���̰�
���� ���� ����� ���̸� ���Ѵ�. �׻� B���� ū ������ �ϳ��� �ֵ��� �־�����.

�ذ� ��� : 2^N������ ��츦 ��Ʈ����ŷ�� ���� ���� �õ��� ���� �ּڰ��� ���ϸ� �ȴ�.

�ֿ� �˰����� : ���Ʈ ����, ��Ʈ����ŷ

��ó : USACO 2007D B2��
*/

int h[32];

int main(void) {
    int n, b, s, r = INF;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) s += h[j];
        }
        if (s >= b && s - b < r) r = s - b;
    }
    printf("%d", r);
    return 0;
}