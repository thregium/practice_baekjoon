#include <stdio.h>

/*
���� : 20���� ������ �ü��� ������ �־��� ��, ��� ������ ���Ѵ�. ������ P�� ��� �� ���Ǵ�
��꿡�� �����Ѵ�. P�� �ƴ� ���Ǵ� ��� �ϳ� �̻� �־�����.

�ذ� ��� : ������ ������ P��� �� ���Ǵ� �Ѿ�� �� �� ��� ��� ������ �ð� �� * ������ ����
���� ���� �Ͱ� �ð� ���� ���� ������ ������. �� ���� �ð� ������ ������ ������ ���� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : ���ϴ� 2022U B��
*/

char dump[64], buff[4];

int main(void) {
    int np = 0;
    double time, score, total = 0;
    for (int i = 0; i < 20; i++) {
        scanf("%s %lf %s", dump, &time, buff);
        if (buff[0] == 'P') continue;
        score = 'D' - buff[0] + 1;
        if (buff[1] == '+') score += 0.5;
        if (buff[0] == 'F') score = 0;
        np += time;
        total += time * score;
    }
    printf("%.9f", total / np);
    return 0;
}