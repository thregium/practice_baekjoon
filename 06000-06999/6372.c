#include <stdio.h>
#include <ctype.h>

/*
���� : 4��Ʈ ������ ������ ����ũ�� ���μ����� ���� �°� �����ϰ� �Է¿� ���� ��� ����� ���Ѵ�.

�ذ� ��� : ���� �°� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : GNY 2001 F��
*/

char memory[320], a, b;

int getdata(char c) {
    //���带 ���� ��ȯ�Ѵ�.
    if (isdigit(c)) return c - '0';
    else return c - 'A' + 10;
}

char makeword(int d) {
    //���� ����� ��ȯ�Ѵ�.
    if (d < 10) return d + '0';
    else return d + 'A' - 10;
}

int getaddress(int x) {
    //�ش��ϴ� ��ġ�� ������ �ּ�(��)�� ��ȯ�Ѵ�.
    return getdata(memory[x]) * 16 + getdata(memory[x + 1]);
}

void swapacc(void) {
    //A�� B�� ��ȯ�Ѵ�.
    char t = a;
    a = b;
    b = t;
}

void addacc(void) {
    //A�� B�� ���ϰ� ������ ���� �����Ѵ�.
    int t = getdata(a) + getdata(b);
    a = makeword(t % 16);
    b = makeword(t / 16);
}

int main(void) {
    while (scanf("%s", memory) != EOF) {
        if (memory[0] == '8') return 0;
        a = '0';
        b = '0';
        for (int p = 0; p < 256; p++) {
            if (memory[p] == '8') {
                //���α׷��� �����Ѵ�.
                break;
            }
            switch (memory[p]) {
            case '0':
                //�޸𸮿��� ���� �ҷ��� A�� �����Ѵ�.
                a = memory[getaddress(p + 1)];
                p += 2;
                break;
            case '1':
                //A�� �ִ� ���� �޸𸮿� �����Ѵ�.
                memory[getaddress(p + 1)] = a;
                p += 2;
                break;
            case '2':
                //A�� B�� ��ȯ�Ѵ�.
                swapacc();
                break;
            case '3':
                //A�� B�� ���ϰ� ���� ���� �����Ѵ�.
                addacc();
                break;
            case '4':
                //A�� 1�� ���Ѵ�. �����÷ΰ� ���� ��� 0���� �ٲ۴�.
                a = makeword((getdata(a) + 1) % 16);
                break;
            case '5':
                //A���� 1�� ����. �����÷ΰ� ���� ��� F�� �ٲ۴�.
                a = makeword((getdata(a) + 15) % 16);
                break;
            case '6':
                //A�� 0�� ��� �־��� �ּҷ� �̵��Ѵ�.
                if (a == '0') {
                    p = getaddress(p + 1) - 1;
                }
                else p += 2;
                break;
            case '7':
                //�־��� �ּҷ� �̵��Ѵ�.
                p = getaddress(p + 1) - 1;
            }
        }
        
        for (int i = 0; i < 256; i++) printf("%c", memory[i]);
        printf("\n");
    }
    return 0;
}