#include <stdio.h>
#include <stdlib.h>

struct list_item {
    int data;
    struct list_item *next;
};

void list_push(struct list_item **phead, int data)
{
    struct list_item *tmp;
    tmp = malloc(sizeof(struct list_item));
    tmp->data = data;
    tmp->next = *phead;
    *phead = tmp;
}

int list_pop(struct list_item **phead)
{
    struct list_item *tmp;
    int data;
    tmp = *phead;
    data = tmp->data;
    *phead = (*phead)->next;
    free(tmp);
    return data;
}

void list_print(struct list_item *cur)
{
    while(cur) {
        if (cur->next)
            printf("%d -> ", cur->data);
        else
            printf("%d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void list_free(struct list_item *head)
{
    struct list_item *tmp;
    while(head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void list_filter(struct list_item **pcur, int (*cond)(int))
{
    while(*pcur) {
        if(!(*cond)((*pcur)->data)) {
            struct list_item *tmp = *pcur;
            *pcur = (*pcur)->next;
            free(tmp);
        } else {
            pcur = &((*pcur)->next);
        }
    }
}

int is_odd(int x) { return x % 2; }
int is_even(int x) { return x % 2 == 0; }

int main()
{
    struct list_item *list = NULL;
    for(int i = 0; i < 10; ++i)
        list_push(&list, i);
    list_print(list);
    list_filter(&list, &is_odd);
    for(int i = 0; i < 10; ++i)
        list_push(&list, i);
    list_print(list);
    list_filter(&list, &is_even);
    list_print(list);
    return 0;
}
