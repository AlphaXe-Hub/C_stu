#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_node {
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};
struct stud_node *head, *tail;

void input();

int main() {
    struct stud_node *p;

    head = tail = NULL;
    input();
    for (p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */
void input() {
    struct stud_node *s;
    while (1) {
        s = (struct stud_node *) malloc(sizeof(struct stud_node));
        scanf("%d", &s->num);
        if (s->num == 0) { break; }
        scanf("%s", s->name);
        scanf("%d", &s->score);

        if (head==NULL) {//若头节点为空 将这个节点放在头节点
            head=s;
            head->next = NULL;
        }
        if (tail!=NULL) {//若尾节点不为空，将这个节点接入尾节点
            tail->next = s;
        }
        tail = s;           //s当作尾节点
        tail->next = NULL;  //尾节点下一个为空
    }
}
