#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int n;                  
    int stock[101] = { 0 };   // = {0}�� ����ؾ� 0���� �ʱ�ȭ��
    int sales[101] = { 0 };   
    int id, total = 0;

    printf("��ǰ ���� ���� �Է� (1~100): ");   //��ǰ ���� �Է�
    (void)scanf("%d", &n);

    for (int i = 1; i <= n; i++) {           //�԰� ���� �Է�
        printf("��ǰ ID %d �԰� ����: ", i);
        (void)scanf("%d", &stock[i]);
    }

    for (int i = 1; i <= n; i++) {            //�Ǹ� ���� �Է�
        printf("��ǰ ID %d �Ǹ� ����: ", i);
        (void)scanf("%d", &sales[i]);

        stock[i] -= sales[i];
        if (stock[i] < 0) stock[i] = 0;
    }

    printf("��ȸ�� ��ǰ ID �Է��Ͻÿ�: ");      //��� ��ȸ
    (void)scanf("%d", &id);

    printf("��ǰ ID %d ���� ����Դϴ�.: %d\n", id, stock[100]);  //��� ���

    for (int i = 1; i <= n; i++) {           //��ü ��� ���� ���
        total += stock[i];
    }
    printf("��ü ��� �����Դϴ�.: %d\n", total);

    return 0;
}
