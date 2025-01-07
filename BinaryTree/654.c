struct TreeNode* nodeCreate(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int findMax(int start, int end, int *nums)
{
    int i;
    int max_idx=start;
    for (i=start; i <=end; i++)
    {
        if (nums[i] > nums[max_idx])
        {
            max_idx = i;
        }
    }
    return max_idx;
}
struct TreeNode* func(int start, int end, int *nums)
{
    int maxIdx;
    struct TreeNode* node;
    if (start<=end)
    {
        maxIdx=findMax(start,end,nums);
        node=nodeCreate(nums[maxIdx]);
        node->left=func(start,maxIdx-1,nums);
        node->right=func(maxIdx+1,end,nums);
        return node;
    }
    else
    {
        return NULL;
    }
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){

    return func(0,numsSize-1,nums);
}