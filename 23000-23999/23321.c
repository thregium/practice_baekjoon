#include <stdio.h>
#include <string.h>

/*
���� : 5�ٿ� ���� ���� ���°� �־��� ��, ���� ���¸� ���Ѵ�. �� ���´� ���� �غ� / ���� �� / ���� ���·� �ְ�,
���� �غ�� ���� �� ���´� ������ ���� ��� ���·� �ٲ��. ������ ���� ���¿��� �״���̴�.

�ذ� ��� : �Ӹ��� ���̸� ���� �� ���¸� ã�Ƴ� ����, ���� ���¸� ã�Ƽ� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : ȫ�ʹ� 2021 B��
*/

char s[5][10240];
int cat[10240];
const char* nxt[3] = { ".omln", "owln.", "..oLn" };

int main(void) {
    int l;
    for (int i = 0; i < 5; i++) {
        scanf("%s", s[i]);
    }
    l = strlen(s[0]);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < 5; j++) {
            if (s[j][i] == 'o') cat[i] = j;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < l; j++) {
            printf("%c", nxt[cat[j]][i]);
        }
        printf("\n");
    }
    return 0;
}