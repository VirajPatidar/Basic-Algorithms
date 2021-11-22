#include <stdio.h>
#include <stdlib.h>

typedef struct bst {
  int key;
  struct bst *left, *right;
}bst;

bst* createBST() {
  bst *r = NULL;
  return r;
}

bst* createNode(int item) {
  bst *temp = (bst *)malloc(sizeof(bst));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(bst *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}

void search(bst* root, int key, bst* parent)
{
	if (root == NULL)
	{
		printf("Key Not found \n");
		return;
	}
	if (root->key == key)
	{
		if (parent == NULL)
			printf("The node with key %d is root node \n", &key);

		else if (key < parent->key)
			printf("Given key is left of node with key %d \n" ,parent->key);

		else
            printf("Given key is right of node with key %d \n" ,parent->key);

		return;
	}
	if (key < root->key)
		return search(root->left, key, root);

	return search(root->right, key, root);
}

bst* insert(bst *bst, int key) {
  if (bst == NULL)
    return createNode(key);
  if (key < bst->key)
    bst->left = insert(bst->left, key);
  else
    bst->right = insert(bst->right, key);
  return bst;
}

bst* minimumKey(bst* curr)
{
	while (curr->left != NULL)
		curr = curr->left;
	return curr;
}
void deleteNode(bst* root, int key)
{
	bst* parent = NULL;
	bst* curr = root;
	while (curr != NULL && curr->key != key)
	{
		parent = curr;
		if (key < curr->key)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (curr == NULL)
		return;
	if (curr->left == NULL && curr->right == NULL)
	{
		if (curr != root)
		{
			if (parent->left == curr)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			root = NULL;
		free(curr);
	}
	else if (curr->left && curr->right)
	{
		bst* successor  = minimumKey(curr->right);
		int val = successor->key;
		deleteNode(root, successor->key);
		curr->key = val;
	}
	else
	{
		bst* child = (curr->left)? curr->left: curr->right;
		if (curr != root)
		{
			if (curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}
		else
			root = child;
		free(curr);
	}
}

int main()
{
    int e, opt;
    bst* root;
    bst *parent = createBST();
    while(1)
    {
        printf("\n1. Create BST");
        printf("\n2. Insert an element");
        printf("\n3. Search an element");
        printf("\n4. Display elements");
        printf("\n5. delete an element");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1: root = createBST();
                    break;

            case 2: printf("Enter the value: ");
                    scanf("%d", &e);
                    root = insert(root,e);
                    break;

            case 3: printf("Enter the key of the desired node ");
                    scanf("%d", &e);
                    search(root,e,parent);
                    break;

            case 4: inorder(root);
                    break;

            case 5: printf("Enter the key of the node to be deleted");
                    scanf("%d", &e);
                    deleteNode(root, e);
                    break;

            case 6: return 0;

            default:printf("\nINVALID INPUT :(");
        }
    }
}
