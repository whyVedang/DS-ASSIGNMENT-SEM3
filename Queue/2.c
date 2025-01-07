
struct node{
    int val;
    struct node* next;
};
typedef struct node node;

struct NestedIterator {
    node* head;
    node* cur;
};
typedef struct NestedInteger NestedInteger;
void helper(node** phead, node** ptail, NestedInteger* nest){
    node* head = *phead;
    node* tail = *ptail;
    if(NestedIntegerIsInteger(nest)){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->val = NestedIntegerGetInteger(nest);
        if(tail){
            tail->next = newNode;
            newNode->next = NULL;
            *ptail = newNode;
        }
        else{
            newNode->next = NULL;
            *ptail = newNode;
            *phead = newNode;
        }
        return;
    }

    int size = NestedIntegerGetListSize(nest);
    NestedInteger** nestList = NestedIntegerGetList(nest);
    for(int i = 0;i<size;i++){
        NestedInteger* cur = nestList[i];
        helper(phead,ptail,cur);
    }
}

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    struct NestedIterator* obj = (struct NestedIterator*)malloc(sizeof(struct NestedIterator));
    node** phead = (node**)calloc(1,sizeof(node*));
    node** ptail = (node**)calloc(1,sizeof(node*));
    for(int i = 0;i<nestedListSize;i++){
        helper(phead,ptail,nestedList[i]);
    }
    obj->head = *phead;
    obj->cur = *phead;
    return obj;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->cur != NULL;
}

int nestedIterNext(struct NestedIterator *iter) {
    int val = iter->cur->val;
    iter->cur = iter->cur->next;
    return val;
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
    node* head = iter->head;
    for(node* cur = iter->head;cur!=NULL;){
        node* temp = cur;
        cur=cur->next;
        free(temp);
    }
    return;
}