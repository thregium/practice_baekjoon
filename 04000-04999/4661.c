#include <stdio.h>
#include <string.h>

/*
���� : Ű������ �빮�� ���ĺ��� ������ ���� Ž�� Ʈ������ ���� ������ ���ʷ� ��� ����� �־�����.
�̶�, ���� ���� Ž�� Ʈ���� ���� ��ȸ�� ����� ����Ѵ�.

�ذ� ��� : ���� ��带 ��� ���� �������� �������� ��Ʈ �������� ������ �� �� �ִ�.
����, �������� ���� Ž�� Ʈ���� ����� ������ ���� Ž�� Ʈ���� �ǹǷ� �̸� �ٽ� ���� ��ȸ�ؼ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, Ʈ��

��ó : MidC 2000 D��
*/

char s[32][32], child[32][2];

void printtree(char c) {
    printf("%c", c);
    if (child[c - 'A'][0]) printtree(child[c - 'A'][0]);
    if (child[c - 'A'][1]) printtree(child[c - 'A'][1]);
}

int main(void) {
    int line = 0, e = 0;
    char root;
    while (1) {
        line = 0;
        while (1) {
            scanf("%s", s[line++]);
            if (!strcmp(s[line - 1], "*")) break;
            else if (!strcmp(s[line - 1], "$")) {
                e = 1;
                break;
            }
        }
        line--;
        root = s[line - 1][0];
        for (int i = line - 2; i >= 0; i--) {
            for (int j = 0; s[i][j]; j++) {
                for (char k = root;;) {
                    if (s[i][j] < k) {
                        if (child[k - 'A'][0]) k = child[k - 'A'][0];
                        else {
                            child[k - 'A'][0] = s[i][j];
                            break;
                        }
                    }
                    else if (s[i][j] > k) {
                        if (child[k - 'A'][1]) k = child[k - 'A'][1];
                        else {
                            child[k - 'A'][1] = s[i][j];
                            break;
                        }
                    }
                    else return 1;
                }
            }
        }
        printtree(root);
        printf("\n");
        for (int i = 0; i < 32; i++) {
            child[i][0] = '\0';
            child[i][1] = '\0';
        }
        if (e) break;
    }
    return 0;
}