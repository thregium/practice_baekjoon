#include <stdio.h>
#include <string.h>

/*
���� : K(K <= 100)���� �ܾ� ��� ���� �ٸ�(������ ������ �ٸ� ��ġ��� �ٸ� ���̴�) �� �ܾ ���ļ�
���� �� �ִ� �Ӹ���� ��� �ƹ��ų� �ϳ��� ����Ѵ�. ���ٸ� 0�� ����Ѵ�. �ܾ��� ���� �� ���� 10000 ���ϴ�.

�ذ� ��� : �ܾ��� ���� �� ���� ũ�� �ʱ� ������ ��� �ܾ ���� ���ĺ��� ���� �Ӹ���� ���θ� Ȯ���غ��� �ȴ�.
�Ӹ������ ���ڿ��� ������ �ٷ� �ݺ����� �������� �� ���ڿ��� ����ϰ�, ������ ������ �ʴ� ��� 0�� ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ���ڿ�

��ó : Daejeon 2012 E��
*/

char word[128][10240], buff[20480];

int main(void) {
    int t, k, l, r, tmp;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%s", word[i]);
        }
        r = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                sprintf(buff, "%s%s", word[i], word[j]);
                l = strlen(buff);
                tmp = 1;
                for (int ii = 0, jj = l - 1; ii <= jj; ii++, jj--) {
                    if (buff[ii] != buff[jj]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp) {
                    r = 1;
                    break;
                }
            }
            if (r) break;
        }
        printf("%s\n", r ? buff : "0");
    }
    return 0;
}