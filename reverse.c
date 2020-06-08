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

// 整个列表反序
struct node *reverse_all(struct node *head)
{
    struct node *done = NULL;
    while (head)
    {
        struct node *remain = head->next;
        head->next = done;
        done = head;
        head = remain;
    }
    return done;
}

// 奇数和偶数对反序
struct node *reverse_pair(struct node *head)
{
    struct node **pp = &head;
    struct node *p1, *p2;
    while ((p1 = *pp) && (p2 = p1->next))
    {
        p1->next = p2->next;
        p2->next = p1;
        *pp = p2;
        pp = &p1->next;
    }
    return head;
}

struct node *reverse_k(struct node *head, int k)
{
    struct node **pp = &head;
    while (*pp)
    {
        int c = 0;
        struct node *p1, *p, *q = NULL;
        for (p1 = p = *pp; p && c < k; c++)
        {
            q = p->next;
            p->next = *pp;
            *pp = p;
            p = q;
        }
        p1->next = q;
        if (c < k)
        {
            *pp = reverse_k(*pp, c);
            break;
        }
        else
            pp = &p1->next;
    }
    return head;
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
    printf("-----reverse all-----\n");
    list = build(arr, n);
    list = reverse_all(list);
    print(list);
    printf("-----reverse pair-----\n");
    list = build(arr, n);
    list = reverse_pair(list);
    print(list);
    list = build(arr, n);
    printf("-----reverse k-----\n");
    list = reverse_k(list, 4);
    print(list);
    return 0;
}
