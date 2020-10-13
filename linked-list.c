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

void list_print(struct list_item *list)
{
    struct list_item *current = list;
    while(current) {
        if (current->next)
            printf("%d -> ", current->data);
        else
            printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct list_item *list = NULL;
    list_push(&list, 1);
    list_push(&list, 2);
    list_push(&list, 3);
    list_print(list);
    printf("pop %d\n", list_pop(&list));
    printf("pop %d\n", list_pop(&list));
    list_print(list);
    return 0;
}
