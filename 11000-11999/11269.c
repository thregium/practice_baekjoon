#include <stdio.h>

/*
���� : ���̰� 300 ���ϰ� 3�� ����̸� �빮�ڷθ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ��� PERPERPER...PER�� �ٲٷ��� �Ѵ�.
�� ���ڿ��� �Ϸ翡 �� ���ھ� �ٲ� �� �ִٸ� �ּ� �� ���� �ɸ����� ���Ѵ�.

�ذ� ��� : �� ������ ��ȣ�� 3���� ���� ������� � ���ڰ� ���;� ���� Ȯ���Ѵ�. 0�� ��� P, 1�� ��� E, 2�� ��� R�̴�.
���� ���;� �� ���ڰ� ���Դٸ� �Ѿ��, �׷��� �ʴٸ� �ٲ�� �ϹǷ� 1���� �߰��Ѵ�. �������� ���� ������ ���� �ȴ�.

�ֿ� �˰����� : ����, ���ڿ�

��ó : NCPC 2015 C��
*/

char s[384];

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (i % 3 == 0 && s[i] != 'P') r++;
        else if (i % 3 == 1 && s[i] != 'E') r++;
        else if (i % 3 == 2 && s[i] != 'R') r++;
    }
    printf("%d", r);
    return 0;
}