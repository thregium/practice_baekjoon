#include <stdio.h>
#include <string.h>

/*
���� : ���̰� �ִ� 80�� ������ ���ڿ� ���·� �־�����. �̶�, �� ������ �������� ������ ���� ����߷��� ��,
���� ���� �Ǵ� ���� ������ �������� Ȯ���� ������� ���Ѵ�.
������ ������ ���� �������� ���� �ٷ� ����������, ������ ���߸� ���� ���������� �ʰ� �����.
���Ż�� �������� �� �������� ���� �Ǵ� ���� �� �Ǵ� �ٸ� ���Ż�̳� ���� ���� �� ���� ��������.
���� �������� ���� 1/2�� Ȯ���� ���� �Ǵ� ���������� ��������.

�ذ� ��� : ��� ������ ���� �ش� ������ ���� �������� �� ���� ������������ ���ߴ����� Ȯ���غ���.
Ư�� ���� ������ ��� ����⿡ ���� Ȯ���غ��� �Ѵ�. �� ��������, �������� Ƚ���� ��ü ������ ũ��� ������
���������� ����� ����� ���� �� �ְ�, �̿� 100�� ���� ����� ���·� ���� �� �ִ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : MidC 2006 B��
*/

char pach[128];

int main(void) {
    int holes, len;
    double prob;
    while (1) {
        scanf("%s", pach);
        if (pach[0] == '#') break;
        len = strlen(pach);
        holes = 0;
        for (int i = 0; i < len; i++) {
            if (pach[i] == '.') holes += 2;
            else if (pach[i] == '_') continue;
            else if (pach[i] == '/') {
                for (int j = i - 1;; j--) {
                    if (j < 0 || pach[j] == '.') {
                        holes += 2;
                        break;
                    }
                    else if (pach[j] == '\\' || pach[j] == '|') break;
                }
            }
            else if (pach[i] == '\\') {
                for (int j = i + 1;; j++) {
                    if (j >= len || pach[j] == '.') {
                        holes += 2;
                        break;
                    }
                    else if (pach[j] == '\\' || pach[j] == '|') break;
                }
            }
            else if (pach[i] == '|') {
                for (int j = i - 1;; j--) {
                    if (j < 0 || pach[j] == '.') {
                        holes++;
                        break;
                    }
                    else if (pach[j] == '\\' || pach[j] == '|') break;
                }
                for (int j = i + 1;; j++) {
                    if (j >= len || pach[j] == '.') {
                        holes++;
                        break;
                    }
                    else if (pach[j] == '\\' || pach[j] == '|') break;
                }
            }
        }
        prob = holes * 100;
        prob /= len * 2;
        printf("%d\n", (int)prob);
    }
    return 0;
}