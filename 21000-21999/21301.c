#include <stdio.h>

/*
���� : �� 10���� �־��� �� ǥ�������� 1 �������� ���Ѵ�.

�ذ� ��� : ǥ�������� ����ؼ� 1 �������� Ȯ���ϸ� �ȴ�. ��Ʈ 1�� 1�̹Ƿ� �������� ����� �ʿ� ����.

�ֿ� �˰��� : ����

��ó : GNY 2020 B��
*/

double a[10];

int main(void) {
    double average = 0, error = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &a[i]);
        average += a[i];
    }
    average /= 10;
    for (int i = 0; i < 10; i++) {
        error += (average - a[i]) * (average - a[i]);
    }
    //printf("error: %.4f\n", error);
    if (error > 9) printf("NOT ");
    printf("COMFY");
    return 0;
}