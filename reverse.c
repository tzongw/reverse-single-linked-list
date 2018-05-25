//
//  main.c
//  reverse
//
//  Created by tzongw on 2018/5/26.
//  Copyright © 2018年 tzongw. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *build(int arr[], size_t len)
{
    struct node *head;
    struct node **pp = &head;
    while (len--)
    {
        struct node *p = malloc(sizeof(struct node));
        p->data = *arr++;
        *pp = p;
        pp = &p->next;
    }
    *pp = NULL;
    return head;
}

void print(struct node *head)
{
    printf("list: ");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[])
{
    int n = 9;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    struct node *list = build(arr, n);
    print(list);
    return 0;
}
