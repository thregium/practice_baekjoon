#include <stdio.h>
#include <ctype.h>

/*
���� : �־��� ���ڿ�(50�� ����, �빮�� + Ư������(���� ����, ����Ʈ ��� ���� ����))�� �־��� ��,
�� �հ����� ���ڿ��� ġ�� Ƚ���� ���Ѵ�.

�ذ� ��� : �� �հ��� ���� ġ�� ���ڿ����� �����ص� ����, �ش� ���ڰ� ������
�ش� ���ڿ� �����ϴ� �հ��� ��� Ƚ���� 1�� �ø���. ��� ���ڸ� Ȯ���� ���� �� �հ����� ��� Ƚ���� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : COCI 14/15#3 1��
*/

char s[64];
int cnt[8];
const char* key[] = { "`1qaz", "2wsx", "3edc", "45rtfgvb", "67yuhjnm", "8ik,", "9ol.", "0-=p[];'/" };

int main(void) {
    int t;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        t = 1;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; key[j][k]; k++) {
                if (key[j][k] == tolower(s[i])) {
                    t = 0;
                    cnt[j]++;
                }
            }
        }
        if (t) return 1;
    }
    for (int i = 0; i < 8; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}