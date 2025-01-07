struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *t=head;
    int l=0;
    while(t!=NULL)
    {
        l++;
        t=t->next;
    }
    t=head;
    for(int i=0;i<l/2;i++)
    {
        t=t->next;
    }

    return t;
}