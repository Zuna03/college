#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int *merge(int arr1[], int arr2[], int m, int n)
{
    int *mergedArr = (int *)malloc((m + n) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }

    return mergedArr;
}

void storeInInorder(struct node *node, int inorder[], int *idx)
{
    if (node == NULL)
        return;
    storeInInorder(node->left, inorder, idx);

    inorder[*idx] = node->data;
    (*idx)++;
    storeInInorder(node->right, inorder, idx);
}

struct node *conversion_sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct node *root = newNode(arr[mid]);

    root->left = conversion_sortedArrayToBST(arr, start, mid - 1);

    root->right = conversion_sortedArrayToBST(arr, mid + 1, end);

    return root;
}

struct node *mergeTrees(struct node *root1, struct node *root2, int m, int n)
{
    int *arr1 = (int *)malloc(m * sizeof(int));
    int i = 0;
    storeInInorder(root1, arr1, &i);

    int *arr2 = (int *)malloc(m * sizeof(int));
    int j = 0;
    storeInInorder(root2, arr2, &j);

    int *mergedArr = merge(arr1, arr2, m, n);

    return conversion_sortedArrayToBST(mergedArr, 0, m + n - 1);
}
void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    printf("%d ", node->data);

    printInorder(node->right);
}

int main()
{
    struct node *root1 = newNode(110);
    root1->left = newNode(90);
    root1->right = newNode(700);
    root1->left->left = newNode(5);

    struct node *root2 = newNode(70);
    root2->left = newNode(60);
    root2->right = newNode(220);

    struct node *mergedTree = mergeTrees(root1, root2, 4, 3);

    printf("First BST :\n");
    printInorder(root1);
    printf("\n");

    printf("Second BST :\n");
    printInorder(root2);
    printf("\n");

    printf("Following is Inorder traversal of the merged tree \n");
    printInorder(mergedTree);

    getchar();
    return 0;
}
