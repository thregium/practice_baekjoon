#include <stdio.h>
#include <string.h>
#define MOD 10000

/*
���� : ���� 500 ������ ���ڿ��� �־��� ��, �� ���ڿ��� �Ϻ� ���ڵ��� ����(�Ǵ� ������ �ʰ�)
���� �� �ִ� "welcome to code jam" ���ڿ��� �������� ���Ѵ�.

�ذ� ��� : �־��� ���ڿ��� "welcome to code jam" ���ڿ��� �� �������� �ش� ���ڿ��� �־��� ���ڿ���
������ ������ �Ǵ� ����� ���� �Ź� ���س�����. ���� ���ڰ� ��ġ���� �ʴ´ٸ� ���� 0�̰�,
��ġ�ϴ� ��� ���� �־��� ���ڿ��� �� ��� ���ڿ� ���� welcome... ���ڿ��� �ٷ� �� ������ ����� ����
�հ� ����. welcome... ���ڿ��� ������ m�� ���� ����� ���� ��� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : DP, ���ڿ�

��ó : GCJ 2009Q C2��
*/

char s[512];
int mem[512][24];
char* wtcj = "welcome to code jam";

int main(void) {
    int t, res;
    scanf("%d\n", &t);
    for (int tt = 1; tt <= t; tt++) {
        fgets(s, 503, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        if (s[0] == 'w') mem[0][1] = 1;
        mem[0][0] = 1;
        res = 0;
        for (int i = 1; s[i]; i++) {
            for (int j = 1; j <= 19; j++) {
                if (s[i] != wtcj[j - 1]) continue;
                for (int k = 0; k < i; k++) {
                    mem[i][j] = (mem[i][j] + mem[k][j - 1]) % MOD;
                }
            }
            res = (res + mem[i][19]) % MOD;
        }
        printf("Case #%d: %04d\n", tt, res);

        for (int i = 0; i < 512; i++) {
            for (int j = 0; j < 24; j++) mem[i][j] = 0;
        }
    }
    return 0;
}