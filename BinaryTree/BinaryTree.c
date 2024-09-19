#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

// Function to create a new node
node *createNode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to build the tree
node *BuildTree(int nodes[], int *index)
{
    (*index)++;
    if (nodes[*index] == -1)
    {
        return NULL;
    }
    node *newnode = createNode(nodes[*index]);
    newnode->left = BuildTree(nodes, index);
    newnode->right = BuildTree(nodes, index);
    return newnode;
}

// Inorder traversal: left, root, right
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal: root, left, right
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: left, right, root
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Level-order traversal (BFS)
void levelorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    queue[rear++] = NULL;
    while (front < rear)
    {
        node *currentnode = queue[front++];
        if (currentnode == NULL)
        {
            printf("\n");
            if (front < rear)
            {
                queue[rear++] = NULL;
            }
        }
        else
        {
            printf("%d ", currentnode->data);
            if (currentnode->left != NULL)
            {
                queue[rear++] = currentnode->left;
            }
            if (currentnode->right != NULL)
            {
                queue[rear++] = currentnode->right;
            }
        }
    }
}

// Count the number of nodes in the tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    return leftNodes + rightNodes + 1;
}

// Sum of all node values in the tree
int sumNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);
    return leftSum + rightSum + root->data;
}

// Height of the tree
int height(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Diameter of the tree
int diameter(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int diam1 = diameter(root->left);
    int diam2 = diameter(root->right);
    int diam3 = height(root->left) + height(root->right) + 1;
    return (diam3 > diam1 ? (diam3 > diam2 ? diam3 : diam2) : (diam1 > diam2 ? diam1 : diam2));
}

int main()
{
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    int index = -1;
    node *root = BuildTree(nodes, &index);
    printf("Preorder traversal\n");
    preorder(root);
    printf("\n");

    printf("Inorder traversal\n");
    inorder(root);
    printf("\n");

    printf("Postorder traversal\n");
    postorder(root);
    printf("\n");

    printf("LevelOrder traversal\n");
    levelorder(root);

    printf("Number of Nodes: %d\n", countNodes(root));
    printf("Sum of Nodes: %d\n", sumNodes(root));
    printf("Height of the tree: %d\n", height(root));
    printf("Diameter of the tree: %d\n", diameter(root));

    return 0;
}

/*
      1
     / \
    2   3
   / \   \
  4   5   6

*/
