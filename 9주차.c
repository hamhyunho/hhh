#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5

typedef struct {
    int id;
    char name[20];
    int stock;
    int price;
    int sales;
    int total;
} Product;

int main() {
    Product products[MAX_PRODUCTS] = { 0 };
    int count = 0;
    int menu;

    printf("[쇼핑몰 재고 관리 프로그램]\n");

    while (1) {
        printf("\n> 원하는 메뉴를 선택하세요.\n");
        printf("(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n> ");
        scanf("%d", &menu);

        
        if (menu == 1) {
            if (count >= MAX_PRODUCTS) {
                printf("상품 개수 초과! (최대 %d개까지 등록 가능)\n", MAX_PRODUCTS);
                continue;
            }

            int id, found = -1;
            printf("상품ID : ");
            scanf("%d", &id);

           
            for (int i = 0; i < count; i++) {
                if (products[i].id == id) {
                    found = i;
                    break;
                }
            }

            if (found == -1) { 
                products[count].id = id;
                printf("상품명 : ");
                scanf("%s", products[count].name);
                printf("입고량 : ");
                scanf("%d", &products[count].stock);
                printf("판매가격 : ");
                scanf("%d", &products[count].price);
                products[count].sales = 0;
                products[count].total = 0;
                printf("상품 등록 완료!\n");
                count++;
            } else { 
                int addStock;
                printf("[%s] 상품이 이미 존재합니다.\n", products[found].name);
                printf("입고량 추가 입력: ");
                scanf("%d", &addStock);
                products[found].stock += addStock;
                printf("재고가 업데이트되었습니다! (현재 재고: %d)\n", products[found].stock);
            }
        }

        
        else if (menu == 2) {
            int id, amount;
            printf("상품ID : ");
            scanf("%d", &id);

            int found = -1;
            for (int i = 0; i < count; i++) {
                if (products[i].id == id) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                printf("해당 상품이 존재하지 않습니다.\n");
                continue;
            }

            printf("판매량 : ");
            scanf("%d", &amount);

            
            if (products[found].stock < amount) {
                printf("재고가 부족합니다! (현재 재고: %d)\n", products[found].stock);
                continue;
            }

           
            products[found].stock -= amount;
            products[found].sales += amount;
            products[found].total += products[found].price * amount;

            printf("[%s] 상품 판매 완료 (남은 재고: %d)\n", products[found].name, products[found].stock);

            
            continue;
        }

       
        else if (menu == 3) {
            int id;
            printf("상품ID를 입력하세요: ");
            scanf("%d", &id);

            int found = -1;
            for (int i = 0; i < count; i++) {
                if (products[i].id == id) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                printf("해당 상품이 없습니다.\n");
                continue;
            }

            Product p = products[found];
            printf("\n[개별상품현황]\n");
            printf("ID\t상품명\t재고\t판매가\t판매량\t총판매금액\n");
            printf("-------------------------------------------\n");
            printf("%d\t%s\t%d\t%d\t%d\t%d\n", p.id, p.name, p.stock, p.price, p.sales, p.total);
        }


        else if (menu == 4) {
            printf("\n[전체상품현황]\n");
            printf("ID\t상품명\t재고\t판매가\t판매량\t총판매금액\n");
            printf("---------------------------------------------------\n");
            int sum = 0;
            for (int i = 0; i < count; i++) {
                printf("%d\t%s\t%d\t%d\t%d\t%d\n", 
                    products[i].id, products[i].name, products[i].stock, 
                    products[i].price, products[i].sales, products[i].total);
                sum += products[i].total;
            }
            printf("---------------------------------------------------\n");
            printf("총매출액: %d원\n", sum);
        }

        
        else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        else {
            printf("잘못된 메뉴 선택입니다.\n");
        }
    }

    return 0;
}
