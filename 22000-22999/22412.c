#include <stdio.h>
#include <string.h>

/*
���� : 5000�� ������ 'A', 'B', 'C'�� �̷���� ���ڿ��� �־�����. �̶�, "ABC"���� ���� ������ �ݺ��Ͽ�
�־��� ���ڿ��� ���� �� �ִ� �� ���Ѵ�. 'A', 'B', 'C' �� �� ���ڸ� ������ ��� "ABC"�� �ٲٴ� �����̴�.
�ݵ�� ��� ���� ���ڸ� "ABC"�� �ٲپ�� �ϸ�, �� �ܰ迡�� �ٲٴ� ���ڴ� ���ϴ� ��� ���� �����ϴ�.

�ذ� ��� : ������ �ٲپ� �־��� ���ڿ����� "ABC"�� �������� ����ٸ� ����� ���� �پ��� ������
���� �ð� ���� ã�� �� �ִ�. ��� �κ� ���ڿ� "ABC"�� ���� 'A', 'B', 'C' �� �� ���ڷ� �ٲٴ� ������
�ϸ� �ȴ�. ��, ���� ������ �ٲ� ���ڰ� �ִٸ� ��� ���ڸ� �ٲ� ���� �ƴϹǷ� �� �� ���� �����̴�.
�� ��쿡�� "ABC"�� �Ǵ� ��찡 ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : JAG 2015S2 C��
*/

char buff[5120];
int r = 0;

void track(char* s) {
    int pos, cnt, cnt2;
    char orig[5120] = { 0, };
    strcpy(orig, s);
    if (!strcmp(orig, "ABC")) {
        r = 1;
    }
    for (char i = 'A'; i <= 'C'; i++) {
        pos = 0, cnt = 0, cnt2 = 0;
        for (int j = 0; orig[j]; j++) {
            if (orig[j] == 'A' && orig[j + 1] == 'B' && orig[j + 2] == 'C') {
                j += 2;
                cnt++;
                buff[pos++] = i;
            }
            else {
                if (orig[j] == i) cnt2++;
                buff[pos++] = orig[j];
            }
        }
        buff[pos] = '\0';
        if (cnt > 0 && cnt2 == 0) track(buff);
    }
    return;
}

int main(void) {
    scanf("%s", buff);
    track(buff);
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}