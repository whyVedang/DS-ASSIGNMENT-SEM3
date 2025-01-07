void insert(struct ListNode** head, int num) {
    struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
    new->val = num;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
    } else {
        struct ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            insert(&head, list1->val);
            list1 = list1->next;
        } else {
            insert(&head, list2->val);
            list2 = list2->next;
        }
    }
    while (list1 != NULL) {
        insert(&head, list1->val);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        insert(&head, list2->val);
        list2 = list2->next;
    }

    return head;
}