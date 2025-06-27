#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

typedef char ElementType;

typedef struct Node {
    ElementType data;
    struct Node* prev;
    struct Node* next;
}Node;

typedef Node* pNode;

pNode create_Node(ElementType data) {
    pNode newnode = (pNode)malloc(sizeof(Node));
    if (newnode == NULL) {
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

void print_Node(pNode cursor) {
    while (cursor->prev != NULL) {
        cursor = cursor->prev;
    }

    while (cursor->data != 'T') {
        printf("%c", cursor->data);
        cursor = cursor->next;
    }
    printf("\n");
}

pNode input_data(pNode cursor) {
    char text[MAX];
    (void)scanf("%s", &text);

    pNode Tail = create_Node('T');
    cursor = Tail;

    pNode temp = create_Node(text[0]);
    temp->next = Tail;
    Tail->prev = temp;

    for (int i = 1; text[i] != '\0'; i++) {
        pNode temp = create_Node(text[i]);
            temp->next = Tail;
            temp->prev = Tail->prev;
            temp->next->prev = temp;
            temp->prev->next = temp;
    }

    return cursor;
}

pNode push(pNode cursor) {
    char text;
    (void)scanf(" %c", &text);

    pNode newNode = create_Node(text);

    newNode->next = cursor;
    newNode->prev = cursor->prev;

    newNode->next->prev = newNode;
    if (newNode->prev != NULL)
        newNode->prev->next = newNode;

    return cursor;
}

pNode left(pNode cursor) {
    if (cursor->prev != NULL)
        cursor = cursor->prev;
    return cursor;
}

pNode right(pNode cursor) {
    if (cursor->next != NULL)
        cursor = cursor->next;
    return cursor;
}

pNode del(pNode cursor) {
    if (cursor->prev == NULL)
        return cursor;
    
    pNode temp = cursor->prev;

    temp->next->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);

    return cursor;
}

typedef struct {
    const char name;
    pNode (*func)(pNode);
}Edit;

Edit edit_table[] = {
    { 'P', push},
    { 'L', left},
    { 'D', right},
    { 'B', del},
    { '\0', NULL},
};

void (*select_fun(const char c))(pNode) {
    for (int i = 0; edit_table[i].name != '\0'; i++) {
        if (c == edit_table[i].name) {
            return edit_table[i].func;
        }
    }
    return NULL;
}

int main() {
    pNode cursor = { 0 };
    cursor = input_data(cursor);

    int T;
    (void)scanf(" %d", &T);

    while (T--) {
        char edit;
        (void)scanf(" %c", &edit);

        pNode (*func)(pNode) = select_fun(edit);
        cursor = func(cursor);
        //print_Node(cursor);
    }
    print_Node(cursor);

}