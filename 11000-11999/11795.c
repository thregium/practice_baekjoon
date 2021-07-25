#include <stdio.h>

/*
���� : A, B, C �� ���� ��ǰ�� ���� ���´�. ��� ��ǰ�� 30�� �̻� ���� ������ ���� ��ǰ�� �ִ��� ����, ��� ��ǰ�� ���� �縸ŭ
�����ٰ� �ϸ�, �� ������ ������ ��ǰ�� ���� ���� ���Ѵ�. ������ �ʴ� ���� NO��� ����Ѵ�.

�ذ� ��� : ���� ����� ���� Ȯ���ϰ� ��ǰ�� ���� ���� �� �� �ּڰ��� Ȯ���ؼ� ���� ���� ���� 30 �̸��� ��� NO�� ����� ����
���� ���� �Ѿ��, 30 �̻��̸� �ּڰ���ŭ�� ����ϰ� ���� ����� ������ �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : Phuket 2015 L��
*/

int small3(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int main(void) {
    int t, a = 0, b = 0, c = 0, xa, xb, xc, dtb;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &xa, &xb, &xc);
        a += xa, b += xb, c += xc;
        dtb = small3(a, b, c);
        if (dtb < 30) {
            printf("NO\n");
            continue;
        }
        printf("%d\n", dtb);
        a -= dtb, b -= dtb, c -= dtb;
    }
    return 0;
}