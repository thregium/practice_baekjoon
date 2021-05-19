#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MOD 102983

/*
���� : ������ ���� 3���� ���α׷��� ���������͸� �ۼ��Ѵ�. ���α׷� ��ü�� �� �ٿ� �־�����, �Ʒ��δ� �Էµ��� �־�����.
����� ������ ������ ���� �����ڵ�(����)�� �����ڿ� ���󼭴� ���� ���� �ִ� �߰� ������ �־�����.
��κ��� ��� ������ �̿��� ������ �ϸ�, �󺧷� ������ ���� ���� �����ϴ�.
�� ������ ������ ���� �ּҷ� ���� �޸� �����̴�.
����, (���� ����÷� / �����÷�, 0���� ������, �� ������, �� Ȯ�� �Ұ�, �ص� �Ұ� ��) ��Ÿ�� ������ �߻��ϴ� ���
�߰��� ���α׷��� �����Ѵ�.

�ذ� ��� : ����

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : GNY 2020 I��
*/

/*
��� ���� �� ���ٸ� ��� ſ..?
    
    
            
    
            
                
                    
    



*/

char program[10240], labels[2048][192], labeldump[10240][192], isheapin[103000];
int operation[10240][2], labelpos[2048], stack[1024], substack[1024], heap[103000], stacks[1024];
int op = 0, lp = 1, sp = 1, sttop = 0, len;

void parse(void);
int parsenum(int* p, int o);
char* parselabel(int* p);
int getoper(int);
int operate(int o, int par, int pos);
int push(int num);
int dup(void);
int swap(void);
int discard(void);
int compute(int o);
int hash(int);
int heapin(void);
int heapout(void);
int findlabel(char* label);
int subroutine(int lnum, char* label);
int jump(int lnum, char* label);
int jumpif(int mode, int lnum, char* label);
int endsubroutine(int lnum, char* label);
int printchar(void);
int printnum(void);
int readchar(void);
int readnum(void);

int main(void) {
    fgets(program, 10000, stdin);
    if (program[strlen(program) - 1] == '\n') program[strlen(program) - 1] = '\0';
    len = strlen(program);
    parse();
    for (substack[sp - 1] = 0; substack[sp - 1] < op; substack[sp - 1]++) {
        if (operation[substack[sp - 1]][0] == 36) return 0;
        if (operate(operation[substack[sp - 1]][0], operation[substack[sp - 1]][1], substack[sp - 1]) < 0) {
            printf("RUN-TIME ERROR"); //���� �ڵ尡 ��ȯ�� ���
            break;
        }
    }
    return 0;
}

void parse(void) {
    int p = 0, o;
    while (p < len) {
        o = getoper(p);
        operation[op][0] = o;

        if (o < 0) break;
        else if (o / 10 == 1 || o / 10 == 4) p += 4;
        else p += 3;
        if (o <= 2) operation[op][1] = parsenum(&p, o); //���ڸ� �Ľ��Ѵ�.
        else if (o >= 30 && o <= 34) {
            char* tmplbl = parselabel(&p); //���� �Ľ��Ѵ�.
            if (o == 30) {
                for (int i = 1; i < lp; i++) {
                    if (!strcmp(tmplbl, labels[i])) {
                        operation[op][0] = -1; //�̹� ���ǵ� ���� ���
                        break;
                    }
                }
                strcpy(labels[lp], tmplbl); //�� ��Ͽ� �߰��Ѵ�.
                operation[op][1] = lp;
                labelpos[lp] = op;
                lp++;
            }
            else {
                for (int i = 1; i < lp; i++) {
                    if (!strcmp(tmplbl, labels[i])) {
                        operation[op][1] = i;
                        break;
                    }
                }
                if (operation[op][1] == 0) {
                    //���� ã�� ���� ���
                    operation[op][1] = -1;
                    strcpy(labeldump[op], tmplbl); //��Ȯ�� �� �迭�� �־�д�.
                }
            }
            free(tmplbl);
        }
        op++;
    }
}

int parsenum(int* p, int o) {
    int r = 0;
    while (program[*p] != '2') {
        //2�� ������ �������� �� �Է�
        r *= 2;
        r += program[*p] - '0';
        (*p)++;
    }
    (*p)++;
    if (o == 2) return -r;
    else return r;
}

char* parselabel(int* p) {
    int i = 0;
    char* a = calloc(1, sizeof(char) * 192);
    while (program[*p] != '2') {
        //2�� ������ �������� �� �Է�
        a[i] = program[*p];
        i++;
        (*p)++;
    }
    (*p)++;
    return a;
}

int getoper(int p) {
    if (program[p] == '0' && program[p + 1] == '0' && program[p + 2] == '0') return 1; //���ÿ� ��� �߰�
    if (program[p] == '0' && program[p + 1] == '0' && program[p + 2] == '1') return 2; //���ÿ� ���� �߰�
    if (program[p] == '0' && program[p + 1] == '2' && program[p + 2] == '0') return 3; //�ֻ��� ���� ����
    if (program[p] == '0' && program[p + 1] == '2' && program[p + 2] == '1') return 4; //�ֻ��� 2���� ��ȯ
    if (program[p] == '0' && program[p + 1] == '2' && program[p + 2] == '2') return 5; //�ֻ��� ���� ����

    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '0' && program[p + 3] == '0') return 10; //+
    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '0' && program[p + 3] == '1') return 11; //-
    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '0' && program[p + 3] == '2') return 12; //*
    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '1' && program[p + 3] == '0') return 13; //(/)
    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '1' && program[p + 3] == '1') return 14; //%

    if (program[p] == '1' && program[p + 1] == '1' && program[p + 2] == '0') return 20; //�޸𸮿� ���� ����
    if (program[p] == '1' && program[p + 1] == '1' && program[p + 2] == '1') return 21; //�޸𸮿��� ���� ����

    if (program[p] == '2' && program[p + 1] == '0' && program[p + 2] == '0') return 30; //�� ����
    if (program[p] == '2' && program[p + 1] == '0' && program[p + 2] == '1') return 31; //�����ƾ ȣ��
    if (program[p] == '2' && program[p + 1] == '0' && program[p + 2] == '2') return 32; //�ش� �󺧷� ����
    if (program[p] == '2' && program[p + 1] == '1' && program[p + 2] == '0') return 33; //���� �ֻ��� ���Ұ� 0�� ��� ����
    if (program[p] == '2' && program[p + 1] == '1' && program[p + 2] == '1') return 34; //���� �ֻ��� ���Ұ� ������ ��� ����
    if (program[p] == '2' && program[p + 1] == '1' && program[p + 2] == '2') return 35; //�����ƾ ����
    if (program[p] == '2' && program[p + 1] == '2' && program[p + 2] == '2') return 36; //���α׷� ����

    if (program[p] == '1' && program[p + 1] == '2' && program[p + 2] == '0' && program[p + 3] == '0') return 40; //���� ���
    if (program[p] == '1' && program[p + 1] == '2' && program[p + 2] == '0' && program[p + 3] == '1') return 41; //�� ���
    if (program[p] == '1' && program[p + 1] == '2' && program[p + 2] == '1' && program[p + 3] == '0') return 42; //���� �Է�
    if (program[p] == '1' && program[p + 1] == '2' && program[p + 2] == '1' && program[p + 3] == '1') return 43; //�� �Է�

    return -1;
}

int operate(int o, int par, int pos) {
    int r = 0;
    if (o < 0) return -100; //���� ����
    else if (o <= 2) r = push(par);
    else if (o == 3) r = dup();
    else if (o == 4) r = swap();
    else if (o == 5) r = discard();
    else if (o < 20) r = compute(o - 10);
    else if (o == 20) r = heapin();
    else if (o == 21) r = heapout();
    else if (o == 30); //�� ����, ���α׷� �ʿ� X
    else if (o == 31) r = subroutine(par, labeldump[pos]);
    else if (o == 32) r = jump(par, labeldump[pos]);
    else if (o <= 34) r = jumpif(o - 32, par, labeldump[pos]);
    else if (o == 35) r = endsubroutine(par, labeldump[pos]);
    else if (o == 36); //���α׷� ����, �ܺο� ����
    else if (o == 40) r = printchar();
    else if (o == 41) r = printnum();
    else if (o == 42) r = readchar();
    else if (o == 43) r = readnum();

    if (r > 0) operation[pos][1] = r; //�� ����
    return r;
}

int push(int num) {
    if (sttop == 1024) return -1; //���� �����÷�
    else stack[sttop++] = num;
    return 0;
}

int dup(void) {
    if (sttop == 1024 || sttop == 0) return -3; //���� ����/����÷�
    else stack[sttop++] = stack[sttop - 1];
    return 0;
}

int swap(void) {
    if (sttop < 2) return -2; //���� ����÷�
    int temp = stack[sttop - 2];
    stack[sttop - 2] = stack[sttop - 1];
    stack[sttop - 1] = temp;
    return 0;
}

int discard(void) {
    if (sttop == 0) return -2; //���� ����÷�
    sttop--;
    return 0;
}

int compute(int o) {
    if (sttop < 2) return -2; //���� ����÷�
    int val = 0;
    switch (o) {
    case 0:
        val = stack[sttop - 2] + stack[sttop - 1];
        break;
    case 1:
        val = stack[sttop - 2] - stack[sttop - 1];
        break;
    case 2:
        val = stack[sttop - 2] * stack[sttop - 1];
        break;
    case 3:
        if (stack[sttop - 1] == 0) return -10; //��Ȧ ����
        val = stack[sttop - 2] / stack[sttop - 1];
        break;
    case 4:
        if (stack[sttop - 1] == 0) return -10; //��Ȧ ����
        val = stack[sttop - 2] % stack[sttop - 1];
        break;
    }
    discard();
    discard();
    push(val);
    return 0;
}

int hash(int a) {
    //������ ������ ���� ���� �����Ѵ�.
    if (a < 0) return (a % MOD + MOD) % MOD;
    return a % MOD;
}

int heapin(void) {
    if (sttop < 2) return -2;
    int address = hash(stack[sttop - 2]);
    heap[address] = stack[--sttop];
    isheapin[address] = 1;
    sttop--;
    return 0;
}

int heapout(void) {
    if (sttop == 0) return -2;
    int address = hash(stack[sttop - 1]);
    //if (!isheapin[address]) return -21; //�� �ּҿ� �޸� ���� - ���� �ƴ�
    stack[sttop - 1] = heap[address];
    return 0;
}

int findlabel(char* label) {
    for (int i = 1; i < lp; i++) {
        if (!strcmp(label, labels[i])) return i;
    }
    return -1; //�� Ȯ�� ����
}

int subroutine(int lnum, char* label) {
    if (sp == 1024) return -31; //�����ƾ ���� �����÷�
    if (lnum < 0) lnum = findlabel(label);
    if (lnum < 0) return -33; //�� �Ҹ�
    substack[sp++] = labelpos[lnum];
    return lnum;
}

int endsubroutine(int lnum, char* label) {
    if (sp == 1) return -32; //�����ƾ ���� ����÷�
    if (lnum < 0) lnum = findlabel(label);
    if (lnum < 0) return -33; //�� �Ҹ�
    sp--;
    return lnum;
}

int jump(int lnum, char* label) {
    if (lnum < 0) lnum = findlabel(label);
    if (lnum < 0) return -33; //�� �Ҹ�
    substack[sp - 1] = labelpos[lnum];
    return lnum;
}

int jumpif(int mode, int lnum, char* label) {
    if (lnum < 0) lnum = findlabel(label);
    if (lnum < 0) return -33; //�� �Ҹ�
    if ((mode == 1 && stack[sttop - 1] == 0) || (mode == 2 && stack[sttop - 1] < 0)) jump(lnum, label);
    sttop--;
    return lnum;
}

int printchar(void) {
    if (sttop == 0) return -2; //���� ����÷�
    if (stack[sttop - 1] > 127 || stack[sttop - 1] < 0) return -41; //�߸��� ����
    printf("%c", stack[--sttop]);
    return 0;
}

int printnum(void) {
    if (sttop == 0) return -2; //���� ����÷�
    printf("%d", stack[--sttop]);
    return 0;
}

int readchar(void) {
    if (sttop == 0 || sttop == 1024) return -3; //���� ����/����÷�
    int address = hash(stack[--sttop]);
    char c;
    int r = scanf("%c", &c);
    if (r == 0) return -42; //�Է� Ȯ�� ����
    heap[address] = c;
    isheapin[address] = 1;
    return 0;
}

int readnum(void) {
    if (sttop == 0 || sttop == 1024) return -3; //���� ����/����÷�
    int address = hash(stack[--sttop]);
    int n;
    int r = scanf("%d", &n);
    if (r == 0) return -42; //�Է� Ȯ�� ����
    heap[address] = n;
    isheapin[address] = 1;
    return 0;
}