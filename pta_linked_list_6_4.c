#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();

struct ListNode *getodd(struct ListNode **L);

void printlist(struct ListNode *L) {
    struct ListNode *p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *readlist() {
    struct ListNode *head = NULL, *tail = NULL, *s;
    int num = 0;
    while (num >= 0) {
        scanf("%d", &num);
        if (num == -1) { break; }
        s = (struct ListNode *) malloc(sizeof(struct ListNode));
        s->data = num;
        if (head == NULL) {//初始化头部
            head = s;
            tail = s;
            s->next = NULL;

        } else {
            tail->next = s;
            s->next = NULL;
            tail = s;
        }
    }
    return head;
}

struct ListNode *getodd(struct ListNode **L) {
    struct ListNode *head = NULL, *tail = NULL, *s = NULL, *l = NULL, *head1 = NULL, *tail1 = NULL;
    for (*L; *L != NULL; *L = (*L)->next) {
        if (((*L)->data) % 2 == 1) {
            s = (struct ListNode *) malloc(sizeof(struct ListNode));
            s->data = ((*L)->data);
            if (head == NULL) {//初始化头部
                head = s;
                tail = s;
                s->next = NULL;

            } else {
                tail->next = s;
                s->next = NULL;
                tail = s;
            }

        } else {
            l = (struct ListNode *) malloc(sizeof(struct ListNode));
            l->data = ((*L)->data);
            if (head1 == NULL) {//初始化头部
                head1 = l;
                tail1 = l;
                l->next = NULL;

            } else {
                tail1->next = l;
                l->next = NULL;
                tail1 = l;
            }
        }

    }
    *L = head1;
    return head;
}



