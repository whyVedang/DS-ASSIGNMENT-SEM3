struct Node {
    int val;            
    struct Node* right; 
    struct Node* down;  
};

typedef struct Node Node;

struct Skiplist {
    Node* head; 
    };

typedef struct Skiplist Skiplist;


Node* createNode(int val, Node* right, Node* down) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->right = right;
    newNode->down = down;
    return newNode;
}


Skiplist* skiplistCreate() {
    Skiplist* obj = (Skiplist*)malloc(sizeof(Skiplist));
    obj->head = createNode(-1, NULL, NULL);
    return obj;
}

bool skiplistSearch(Skiplist* obj, int target) {
    Node* node = obj->head;
    while (node) {
        while (node->right && node->right->val < target) {
            node = node->right;
        }
        if (node->right && node->right->val == target) {
            return true;
        }
        node = node->down;
    }
    return false;
}
void skiplistAdd(Skiplist* obj, int num) {
    Node* nodes[100];     Node* node = obj->head;
    int top = 0;

    while (node) {
        while (node->right && node->right->val < num) {
            node = node->right;
        }
        nodes[top++] = node;
        node = node->down;
    }

    bool insert = true;
    Node* down = NULL;
    while (insert && top > 0) {
        node = nodes[--top];
        node->right = createNode(num, node->right, down);
        down = node->right;
        insert = (rand() & 1) == 0;
    }

    if (insert) {
        obj->head = createNode(-1, NULL, obj->head);
    }
}

bool skiplistErase(Skiplist* obj, int num) {
    Node* node = obj->head;
    bool found = false;
    while (node) {
        while (node->right && node->right->val < num) {
            node = node->right;
        }
        if (node->right && node->right->val == num) {
            Node* temp = node->right;
            node->right = node->right->right;
            free(temp);
            found = true;
        }
        node = node->down;
    }
    return found;
}

void skiplistFree(Skiplist* obj) {
    Node* node = obj->head;
    while (node) {
        Node* temp = node;
        node = node->down;
        Node* rightNode = temp->right;
        while (rightNode) {
            Node* rightTemp = rightNode;
            rightNode = rightNode->right;
            free(rightTemp);
        }
        free(temp);
    }
    free(obj);
}