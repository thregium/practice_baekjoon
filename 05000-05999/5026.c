#include <stdio.h>

/*
���� : �־��� ������ a + b �������� P=NP���� Ȯ���ϰ�, P=NP��� skipped, a + b��� �� ������ ���� ����Ѵ�.

�ذ� ��� : ������ ���ڿ� ���·� �Է¹��� ����, P=NP��� skipped�� ����ϸ� �ǰ�,
a + b��� sscanf�� ���� a, b�� ���� �˾Ƴ��� a + b�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : NCPC 2010 F��
*/

char prob[16];

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", prob);
        if (prob[0] == 'P') printf("skipped\n");
        else {
            sscanf(prob, "%d+%d", &a, &b);
            printf("%d\n", a + b);
        }
    }
    return 0;
}