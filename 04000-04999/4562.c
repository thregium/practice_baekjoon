#include <stdio.h>

/*
���� : X�� Y�� �־��� ��, X�� Y �̻��̸� "MMM BRAINS"�� ����ϰ�, �� �ܿ��� "NO BRAINS"�� ����Ѵ�. �̸� Nȸ �ݺ��Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�.

�ֿ� �˰��� : ����

��ó : SCNA 2004 8��
*/

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x >= y) printf("MMM BRAINS\n");
        else printf("NO BRAINS\n");
    }
    return 0;
}