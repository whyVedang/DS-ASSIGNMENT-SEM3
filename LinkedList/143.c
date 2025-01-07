/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode** arr = (struct ListNode**)malloc(50000 * sizeof(struct ListNode*));

	struct ListNode* traverse = head;
	int size = 0;
	while (traverse != NULL)
	{
		arr[size] = (traverse);
		size++;
		traverse = traverse->next;
	}

	int last = size - 1;
	int start = 0;
	for (int i = 0; i < (size/2) ; i = i +1 )
	{
		arr[i]->next = arr[last];
		arr[last]->next = arr[start + 1];
		if (arr[last]->next != NULL)
			arr[last]->next->next = NULL;
		last--;
		start++;
	}
    if (head == NULL)
		return;

	if (NULL)
		printf("%s\t ",NULL);

	printf("%d\n", head->val);
        (head->next,NULL);
}