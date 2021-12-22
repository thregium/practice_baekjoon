#include <stdio.h>

/*
���� : ǳ���� ���� H(H <= 100)�� �ִ� �ð� M(M <= 100)�� �־��� ��, ǳ���� ��� �� ���� ������ �� ���� �ɸ��� �ð��� ���Ѵ�.
�� �ð��� -6t^4 + ht^3 + 2t^2 + t��� ������ ���� �� �ִ�. M ���� ���� ������ �ʴ´ٸ� ������ �ʴ´ٰ� ����Ѵ�.

�ذ� ��� : ������ �־��� ���� t�� ���� 1���� M���� �÷����� ����Ѵ�. ���� ���� 0 ���ϰ� �Ǵ� ���� ���´ٸ�
�� ���� ���� ����Ѵ�. M���� ������ �ʾҴٸ� ������ �ʴ� ���̴�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : CCC 2011J 2��
*/

int main(void) {
    int h, m;
    scanf("%d%d", &h, &m);
    for (int i = 1; i <= m; i++) {
        if (-6 * i * i * i * i + h * i * i * i + 2 * i * i + i <= 0) {
            printf("The balloon first touches ground at hour: %d", i);
            return 0;
        }
    }
    printf("The balloon does not touch ground in the given time.");
    return 0;
}