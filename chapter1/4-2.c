/*
    연결리스트의 노드 구조
    ● 노드  데이터부 -> 링크
        malloc/free
    ● 데니터 필드들(data fields)
        - 원소의 값을 저장
        - 다양한 자료형의 여러 개 항목가능.
    ●  링크 필드(link field)
        - 다음 노드의 주소를 저장(자신과 같은 구조체의 주소 값)
        - '자기참조구조체' 활용
    지기참조 구조체 만들기
    자기참조 구조체 : 멈버로서 자신과 같은 타입에 대한 주소를 가지는 구조체
    typedef struct _Node {
        int id;             pList -> data1 | *next -> data2 | *next -> data3 | NULL
        char name[20];
        struct _Node *next;
    } Node;
       연결리스트 사용 예제
     오름차순 문구목록 만들기
     문구 이름에 따른 오름차순으로 목록을 유지하려 한다
     1. insert "볼펜", "화이트보드", "연필깍기"
     List = (볼펜, 연필깍기, 화이트보드)
     2. Search "화이트보드"
     "화이트보드"를 [2번째에셔 찾았습니다.]
     3. Delete "볼펜"
     List = (연필깍기, 화이티보트)
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Node {
    char name[20];
    struct _Node *link;
} Node;

Node* InsertNode(Node* pList, char* newname) {
    Node *newNode, *trace = pList, *prevNode;

    newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, newname);
    newNode->link = NULL;
    
    if (pList == NULL || strcmp(pList->name, newname) > 0) {
        newNode->link = pList;
        pList = newNode;
    }
    else {
        while (trace != NULL && strcmp(trace->name, newname) < 0) {
            prevNode = trace;
            trace = trace->link;
        }
        newNode->link = prevNode->link;
        prevNode->link = newNode;
    }
    return pList;
}
Node* DeleteNode(Node* pList, char* newname) {
    Node *trace = pList, *prevNode = NULL;

    while (trace != NULL && strcmp(trace->name, newname) != 0) {
        prevNode = trace;
        trace = trace->link;
    }

    if (trace != NULL) {
        if (prevNode == NULL)
            pList = pList->link;
        else
            prevNode->link = trace->link;
        free(trace);
    }
    return pList;
}
Node* SearchNode(Node* pList, char* newname, int *pIndex) {
    Node *trace = pList;
    *pIndex = 0;
    while (trace != NULL) {
        if (strcmp(trace->name, newname) == 0)
            break;
        trace = trace->link;
        *pIndex = *pIndex + 1;
    }
    return trace;
}
void PrintList(Node* pList) {
    Node *trace = pList;
    printf("List = (");
    while (trace != NULL) {
        printf("%s", trace->name);
        trace = trace->link;
        if (trace != NULL)
            printf(", ");
    }
    printf(")\n\n");
}
Node* FreeList(Node* pList) {
    Node *savelink;
    while (pList != NULL) {
        savelink = pList->link;
        free(pList);
        pList = savelink;
    }
    return NULL;
}

void main() {
    Node * pList = NULL, *ptr;
    int index;
    printf("(1) insert \"볼펜\", \"화이트보드\", \"연필깍기\"\n") ;
    pList = InsertNode(pList, "볼펜");
    pList = InsertNode(pList, "화이트보드");
    pList = InsertNode(pList, "연필깍기");
    PrintList(pList);

    printf("(2) Search \"화이트보드\"\n");
    ptr = SearchNode(pList, "화이트보드", &index);
    printf("\"%s\"를 [%d]번째에서 찾았습니다.\n", ptr -> name, index);
    
    printf("(3) Delete \"볼펜\"\n");
    ptr = DeleteNode(pList, "볼펜");
    PrintList(pList);
    
    pList = FreeList(pList);
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _Node {
    char name[20];
    struct _Node *link;
} Node;


/* 노드 삽입 (오름차순 정렬) */
Node* InsertNode(Node* pList, char* newname) {
    Node *newNode, *trace = pList, *prevNode = NULL;

    newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("메모리 할당 실패\n");
        return pList;
    }

    strcpy(newNode->name, newname);
    newNode->link = NULL;

    /* 맨 앞 삽입 */
    if (pList == NULL || strcmp(pList->name, newname) > 0) {

        newNode->link = pList;
        pList = newNode;
    }
    else {

        while (trace != NULL &&
               strcmp(trace->name, newname) < 0) {

            prevNode = trace;
            trace = trace->link;
        }

        newNode->link = trace;
        prevNode->link = newNode;
    }

    return pList;
}


/* 노드 삭제 */
Node* DeleteNode(Node* pList, char* newname) {

    Node *trace = pList, *prevNode = NULL;

    while (trace != NULL &&
           strcmp(trace->name, newname) != 0) {

        prevNode = trace;
        trace = trace->link;
    }

    /* 찾은 경우 */
    if (trace != NULL) {

        /* 첫 노드 삭제 */
        if (prevNode == NULL)
            pList = trace->link;

        else
            prevNode->link = trace->link;

        free(trace);
    }

    return pList;
}


/* 노드 검색 */
Node* SearchNode(Node* pList,
                 char* newname,
                 int *pIndex) {

    Node *trace = pList;

    *pIndex = 0;

    while (trace != NULL) {

        if (strcmp(trace->name, newname) == 0)
            break;

        trace = trace->link;
        (*pIndex)++;
    }

    return trace;
}


/* 리스트 출력 */
void PrintList(Node* pList) {

    Node *trace = pList;

    printf("List = (");

    while (trace != NULL) {

        printf("%s", trace->name);

        trace = trace->link;

        if (trace != NULL)
            printf(", ");
    }

    printf(")\n\n");
}


/* 전체 메모리 해제 */
Node* FreeList(Node* pList) {

    Node *savelink;

    while (pList != NULL) {

        savelink = pList->link;

        free(pList);

        pList = savelink;
    }

    return NULL;
}


int main(void) {

    setlocale(LC_ALL, "");

    Node *pList = NULL;
    Node *ptr;

    int index;

    printf("(1) insert \"볼펜\", \"화이트보드\", \"연필깍기\"\n");

    pList = InsertNode(pList, "볼펜");
    pList = InsertNode(pList, "화이트보드");
    pList = InsertNode(pList, "연필깍기");

    PrintList(pList);

    printf("(2) Search \"화이트보드\"\n");

    ptr = SearchNode(pList, "화이트보드", &index);

    if (ptr != NULL)
        printf("\"%s\"를 [%d]번째에서 찾았습니다.\n\n",
               ptr->name,
               index);
    else
        printf("찾지 못했습니다.\n\n");


    printf("(3) Delete \"볼펜\"\n");

    pList = DeleteNode(pList, "볼펜");

    PrintList(pList);

    pList = FreeList(pList);

    return 0;
}