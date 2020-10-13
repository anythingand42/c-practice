#include <stdio.h>
#include <stdlib.h>

struct list_item {
    int data;
    struct list_item *next;
};

void list_push(struct list_item **head_ptr, int data)
{
    struct list_item *tmp;
    tmp = malloc(sizeof(struct list_item));
    tmp->data = data;
    tmp->next = *head_ptr;
    *head_ptr = tmp;
}

void list_print(struct list_item *list)
{
    struct list_item *current;
    current = list;
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
    return 0;
}
