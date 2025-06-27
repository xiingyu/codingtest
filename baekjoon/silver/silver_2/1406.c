#include <stdio.h>
#include <stdlib.h>

int n_command;
char command, addedChar;
char strarr[100000];



void inputAll(void) {
    (void)scanf("%s", &strarr);
    (void)scanf("%d", &n_command);
}

typedef struct _nodeD {
    struct _nodeD* prev;
    struct _nodeD* next;
    char data;
}nodeD;
typedef nodeD* pnodeD;
typedef nodeD** ppnodeD;

pnodeD DLL_CreateNode(char data) {
    pnodeD ptemp = (pnodeD)malloc(sizeof(nodeD));
    if (ptemp == NULL) exit(1);
    *ptemp = (nodeD){NULL,NULL,data};
    return ptemp;
}

void removeNode(pnodeD targetNode, pnodeD Head, pnodeD Tail) {
    if (targetNode == Head || targetNode == Tail) return ;
    targetNode->prev->next = targetNode->next;
    targetNode->next->prev = targetNode->prev;
    free(targetNode);
}

void appendLeft(pnodeD fnode, pnodeD newnode) {
    newnode->next = fnode;
    newnode->prev = fnode->prev;
    fnode->prev->next = newnode;
    fnode->prev = newnode;
}

// void Lshift(pnodeD Cursor, pnodeD Head, pnodeD Tail){
//     if (Cursor->prev == Head) {
//         return ;
//     }
// }

void Lshift(ppnodeD pCursor, pnodeD Head, pnodeD Tail){
    //커서 주소 조지기
    pnodeD Cursor = *pCursor;
    if (Cursor->prev == Head) return ;

    pnodeD left = Cursor->prev;
    pnodeD right = Cursor->next;
    pnodeD left_prev = left->prev;

    // 커서 왕따만들기
    right->prev = left;
    left->next = right;

    // left앞에 커서 놓기
    Cursor->prev = left_prev;
    Cursor->next = left;
    left_prev->next = Cursor;
    left->prev = Cursor;
    *pCursor = Cursor;
    
}

void Rshift(ppnodeD pCursor, pnodeD Head, pnodeD Tail){
    pnodeD Cursor = *pCursor;
    if (Cursor->next == Tail) return;

    pnodeD right = Cursor->next;
    pnodeD left = Cursor->prev;
    pnodeD right_next = right->next;

    left->next = right;
    right->prev = left;

    Cursor->prev = right;
    Cursor->next = right_next;
    right->next = Cursor;
    right_next->prev = Cursor;

    *pCursor = Cursor;
}

void insertChar(char newChar, pnodeD Cursor) {
    pnodeD temp = DLL_CreateNode(newChar);
    appendLeft(Cursor, temp);
}

void printAnswer(pnodeD Head, pnodeD Tail) {
    int i;
    pnodeD cur = Head->next;
    while(cur != Tail) {
        printf("%c", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    int i=0;
    inputAll();

    pnodeD Head = DLL_CreateNode(0x00);
    pnodeD Tail = DLL_CreateNode(0x00);
    pnodeD Cursor = DLL_CreateNode(0x00);
    Head->prev = NULL;
    Head->next = Cursor;
    Cursor->prev = Head;
    Cursor->next = Tail;
    Tail->prev = Cursor;
    Tail->next = NULL;

    while(strarr[i]!=0) {
        appendLeft(Cursor, DLL_CreateNode(strarr[i++]));
    }

    for(i = 0; i < n_command; ++i) {
        // printf("circulated");
        (void)scanf(" %c", &command);
        if (command == 'P') {
            (void)scanf(" %c", &addedChar);
            insertChar(addedChar, Cursor);
        }
        else if (command == 'L') {
            Lshift(&Cursor, Head, Tail);
        }
        else if (command == 'D') {
            Rshift(&Cursor, Head, Tail);
        }
        else if (command == 'B') {
            removeNode(Cursor->prev, Head, Tail);
        }
        else exit(1);
    }
    printAnswer(Head,Tail);
    return 0;
}