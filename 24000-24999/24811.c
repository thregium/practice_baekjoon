#include <stdio.h>

/*
���� : ���񿡼� �� ���� N(N <= 15)���� �����ӵ��� ��ġ�ٿ��̳� ������Ƽ�� �Ͼ�� �� Ȯ���Ѵ�.

�ذ� ��� : �ֱ� �۽�Ʈ�ٿ��� �Ͼ ���� 4ȸ���� 10 �ߵ� �̻� �������� ���ߴٸ� ���ݱ��� �Ҿ������
������ ������. ����, �׷��� ��찡 ����ٸ� Nothing�� ����Ѵ�. �� �ܿ��� ���� ��ġ�� 100�ߵ� �̻��̸�
��ġ�ٿ�, 0�ߵ� ���ϸ� ������Ƽ�� ����ϰ� ��ġ�� �ȴ�. ������ �ƹ� �ϵ� �Ͼ�� �ʾҴٸ�
Nothing�� ����Ѵ�.

�ֿ� �˰����� : ����

��ó : VTH 2018 G��
*/

int main(void) {
    int n, x, p = 20, q = 1, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        p += x, s += x;
        if (q == 4 && s < 10) {
            printf("Nothing");
            return 0;
        }
        if (x >= 10) {
            q = 0, s = 0;
        }
        q++;
        if (p >= 100) {
            printf("Touchdown");
            return 0;
        }
        else if (p <= 0) {
            printf("Safety");
            return 0;
        }
    }
    printf("Nothing");
    return 0;
}