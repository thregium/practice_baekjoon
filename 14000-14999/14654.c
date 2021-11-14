#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 300)���� ������������ �� ���� �Ѵ�. �� ���� ��� ��� ���� ���� ������ Ƚ���� ���Ѵ�.
ù ���� �ݵ�� �ºΰ� ������, ���ķδ� ���ºν� �������̴� ���� ���� ������ �����Ѵ�.

�ذ� ��� : ������������ �ºθ� �Լ��� ���� ����, �� ��⸦ Ȯ���ϸ� �ºθ� Ȯ���Ѵ�. �������̴� ���� �̱��
���� Ƚ���� �ø���, ���� ���ο� ���� ���� Ƚ���� 1�� �ٲپ� �ٽ� Ȯ���Ѵ�.
�� ��� ���� Ƚ���� ���� ū ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ���� 1ȸ E��
*/

int a[384], b[384];

int game(int a, int b) {
    if (a == b) return 0;
    else if (a == b + 1 || (a == 1 && b == 3)) return 1;
    else return -1;
}

int main(void) {
    int n, w = 0, r = 0, g;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    for (int i = 0; i < n; i++) {
        g = game(a[i], b[i]);
        if (g > 0) {
            if (w > 0) w++;
            else w = 1;
        }
        else if (g < 0) {
            if (w < 0) w--;
            else w = -1;
        }
        else {
            if (w > 0) w = -1;
            else if (w < 0) w = 1;
            else return 1;
        }
        if (r < abs(w)) r = abs(w);
    }
    printf("%d", r);
    return 0;
}