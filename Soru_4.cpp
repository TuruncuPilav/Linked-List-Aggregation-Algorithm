/*
  Negatif olmayan iki tam sayıyı temsil eden iki bağlantılı liste verilmiştir. 
  Basamaklar ters sırada saklanır ve her düğüm tek bir basamak içerir. 
  İki sayıyı toplayın ve yeni bir bağlantılı liste olarak geri dönün.

  Two linked lists are given that represent two non-negative integers. 
  The digits are stored in reverse order and each node contains a single digit. 
  Sum the two numbers and return as a new linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
};

Node* add(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void yazdir(Node* list) {
    printf("{ ");
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("}");
}

Node* toplama(Node* list1, Node* list2) {
    Node* root = NULL;
    Node* temp = NULL;
    int h = 0, toplam;
 
    while (list1 != NULL) {
        toplam = h + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
        h = toplam / 10;
        toplam = toplam % 10;

        Node* bellek = (Node*)malloc(sizeof(Node));
        bellek->data = toplam;
        bellek->next = NULL;

        if (root == NULL) {
            root = bellek;
            temp = bellek;
        }
        else {
            temp->next = bellek;
            temp = temp->next;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    //Eğer sonuç 4 basamaklı olursa
    if (h == 1) {
        Node* bellek = (Node*)malloc(sizeof(Node));
        bellek->data = 1;
        bellek->next = NULL;

        if (root == NULL) {
            root = bellek;
            temp = bellek;
        }
        else {
            temp->next = bellek;
            temp = temp->next;
        }
    }

    return root;
}

int main() {
    Node* list1 = add(2);
    list1->next = add(6);
    list1->next->next = add(9);

    Node* list2 = add(5);
    list2->next = add(6);
    list2->next->next = add(4);

    printf("Giris: ");
    yazdir(list1);
    yazdir(list2);

    printf("\nSonuc: ");
    yazdir(toplama(list1, list2));

    return 0;
}
