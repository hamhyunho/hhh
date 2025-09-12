#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int n;                  
    int stock[101] = { 0 };   // = {0}을 사용해야 0으로 초기화됨
    int sales[101] = { 0 };   
    int id, total = 0;

    printf("상품 종류 개수 입력 (1~100): ");   //상품 종류 입력
    (void)scanf("%d", &n);

    for (int i = 1; i <= n; i++) {           //입고 수량 입력
        printf("상품 ID %d 입고 수량: ", i);
        (void)scanf("%d", &stock[i]);
    }

    for (int i = 1; i <= n; i++) {            //판매 수량 입력
        printf("상품 ID %d 판매 수량: ", i);
        (void)scanf("%d", &sales[i]);

        stock[i] -= sales[i];
        if (stock[i] < 0) stock[i] = 0;
    }

    printf("조회할 상품 ID 입력하시오: ");      //재고 조회
    (void)scanf("%d", &id);

    printf("상품 ID %d 남은 재고입니다.: %d\n", id, stock[100]);  //재고 출력

    for (int i = 1; i <= n; i++) {           //전체 재고 수량 계산
        total += stock[i];
    }
    printf("전체 재고 수량입니다.: %d\n", total);

    return 0;
}
