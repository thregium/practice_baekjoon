#include <stdio.h>

/*
���� : 1000�� ������ �ҹ��ڷ� �̷���� ���� ������ �� ���ڿ��� �־�����. �̶�, �� ���ڿ��� �Ʒ� ���ڿ���
������׷� �̾�ٿ��� �� �� ���ڿ��� ���� �� �ִ� �� ���Ѵ�. ���� ���ڿ��� 1ĭ�� ����
���ο� ���ڿ��� �߰��ϰ� �Ʒ� ���ڿ��� �� ���̸� �޿��. �Ʒ� ���ڿ��� �������� ��ġ�� �������
�ص� ������ ������ �����ؾ� �Ѵ�.

�ذ� ��� : �� ���ڿ��� �켱 Ȧ����°�� ¦����° ���ڵ�� ������. �׸��� �Ʒ� ���ڿ��� �ϳ��� ���캸��
�� ���ڿ��� Ȧ����°�� ¦����° ���� ��� ���� ���� �ִٸ� �� ���ڿ����� ���� ��ġ�� 1ĭ�� �ű��.
�� �� �� ���ڿ��̶� ������ �̵� �����ϴٸ� �� ���ڿ��� ���� �� �ִ� ���̰�,
�� �ܿ��� �� ���ڿ��� ���� �� ���� ���̴�.

�ֿ� �˰����� : ���ڿ�, �� ������

��ó : JAG 2015P A��
*/

char s[1024], t[1024], odd[512], even[512];

int main(void) {
	int p1 = 0, p2 = 0;
	scanf("%s%s", s, t);
	for (int i = 0; s[i]; i += 2) {
		odd[i >> 1] = s[i];
		even[i >> 1] = s[i + 1];
	}
	for (int i = 0; t[i]; i++) {
		if (t[i] == odd[p1]) p1++;
		if (t[i] == even[p2]) p2++;
	}
	if (odd[p1] && even[p2]) printf("No");
	else printf("Yes");
	return 0;
}