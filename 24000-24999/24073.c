#include <stdio.h>

/*
���� : 100�� ������ �빮�ڷ� �̷���� ���ڿ����� �κ� ���� "IOI"�� �ִ� �� ã�´�.

�ذ� ��� : ��� 3���� ���� �ֿ� ���� 'I', 'O', 'I'�� ������� ������ �� Ȯ���Ѵ�.
���´ٸ� �׷��� �κ� ������ �ִ� ���̰�, ������ �ʴ´ٸ� �׷��� �κ� ������ ���� ���̴�.

�ֿ� �˰����� : ���ڿ�, ���Ʈ ����

��ó : JOI 2021��1 2-2��
*/

char s[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (s[i] == 'I' && s[j] == 'O' && s[k] == 'I') r = 1;
            }
        }
    }
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}