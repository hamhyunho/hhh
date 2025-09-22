#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    int stock[101] = { 0 };   
    int sales[101] = { 0 };   
    int total_stock = 0;      
    int total_sales = 0;      
    int total_in = 0;         


    printf("��ǰ ���� ���� �Է� (1~100): ");
    scanf("%d", &n);

   
    for (int i = 1; i <= n; i++) {
        printf("��ǰ ID %d �԰� ����: ", i);
        scanf("%d", &stock[i]);
    }

    
    for (int i = 1; i <= n; i++) {
        printf("��ǰ ID %d �Ǹ� ����: ", i);
        scanf("%d", &sales[i]);
        stock[i] -= sales[i];   
        if (stock[i] < 0) stock[i] = 0; 
    }

    
    printf("������: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", stock[i]);
        total_stock += stock[i];       
        total_sales += sales[i];       
        total_in += stock[i] + sales[i];
    }
    printf("\n");
    double total_rate = ((double)total_sales / total_in) * 100.0;
    printf("�� �Ǹŷ�: %d (�Ǹ��� %.2f%%)\n", total_sales, total_rate);

   
    int max_id = 1, min_id = 1;
    for (int i = 2; i <= n; i++) {
        if (sales[i] > sales[max_id]) max_id = i;
        if (sales[i] < sales[min_id]) min_id = i;
    }
    printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", max_id, sales[max_id]);
    printf("���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", min_id, sales[min_id]);

   
    for (int i = 1; i <= n; i++) {
        if (stock[i] <= 2) {
            printf("��ǰ ID %d : ������(%d)\n", i, stock[i]);
        }
    }

    return 0;
}
