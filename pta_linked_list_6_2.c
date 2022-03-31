#include <stdio.h>
#include <stdlib.h>

struct stud_node {
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};

struct stud_node *createlist();

struct stud_node *deletelist(struct stud_node *head, int min_score);

int main() {
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for (p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */

struct stud_node *createlist() {
    int a;
    struct stud_node *head = NULL, *p1, *p2 = NULL;
    while (1) {
        scanf("%d", &a);
        if (a == 0)
            break;
        else {
            p1 = (struct stud_node *) malloc(sizeof(struct stud_node));
            p1->num = a;
            scanf("%s%d", p1->name, &p1->score);
            if (head == NULL)
                head = p1;
            else
                p2->next = p1;
            p2 = p1;
        }
    }
    if (p2 != NULL)
        p2->next = NULL;
    return head;
}

struct stud_node *deletelist(struct stud_node *head, int min_score) {
    struct stud_node *p1 = head, *p2 = NULL;
    while (p1) {
        if (p1->score < min_score) {
            if (p1 == head) {
                head = p1->next;
                free(p1);
                p1 = head;
            } else {
                p2->next = p1->next;
                free(p1);
                p1 = p2->next;
            }
        } else {
            p2 = p1;
            p1 = p1->next;
        }

    }
    if (p2 != NULL)
        p2->next = NULL;
    return head;
}