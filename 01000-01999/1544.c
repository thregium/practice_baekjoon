#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 50)���� �ҹ��ڷ� �̷���� ���� 50 ���� ���ڿ��� �־�����. �̶�, �ð�������� ����Ʈ�ؼ� �������� ���ڿ���
���� ���ڿ��̶�� �� ��, ���� �ٸ� ���ڿ��� ������ ���Ѵ�.

�ذ� ��� : �� ���ڿ��� �Է¹��� ����, ������ ���ڿ����� ���� ���ڿ��� ã�´�.
���� ���ڿ��� ���� ���̰� ���� ����� ���̴�. ���⼭ ���̰� �����Ƿ� ������ ���� ������ 1ĭ�� �о��
��ġ�ϴ��� Ȯ���� ����, ���� ���ڿ��� �ִٸ� Ž���� �����ϰ� ���� ���ڿ��� ã���� �ȴ�.
���� ���ڿ��� ���ٸ� �ᱣ���� 1�� ���ϰ� ���� ���ڿ��� ã�´�. ��� ���ڿ��� ���캻 ������ ������� ����ϸ� ���� �ȴ�.

�ֿ� �˰����� : ����, ���ڿ�, ���Ʈ ����
*/

char word[64][64];

int main(void) {
    int n, l, cy, ok, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);
    }
    for (int i = 0; i < n; i++) {
        cy = 0;
        for (int j = 0; j < i; j++) {
            if (strlen(word[i]) != strlen(word[j])) continue; //���̰� �ٸ��ٸ� ���� ���ڿ��� �ƴϴ�.
            //���̰� ���� ���� ������ ��� ���ڿ��� ���ɴ�.
            l = strlen(word[i]);
            for (int k = 0; k < l; k++) {
                ok = 1;
                //1ĭ�� �о��.
                for (int p = 0; p < l; p++) {
                    if (word[i][p] != word[j][(k + p) % l]) ok = 0; //�о��� �� �ٸ� ���ڰ� ������ �ٸ� ���ڿ��̴�.
                }
                if (ok) {
                    cy = 1;
                    break;
                }
            }
            if (cy) break;
        }
        r += (!cy); //���� ���ڿ��� �ƴ϶�� �ᱣ���� 1�� ���Ѵ�.
    }
    printf("%d", r);
    return 0;
}