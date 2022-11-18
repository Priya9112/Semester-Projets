#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500

/* A binary tree node has data,
pointer to left child,mid child
and a pointer to right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
	struct node *mid;
};

/* function prototypes */
void printLevelOrder(struct node* root);
void printNodesAtLevel(struct node* root,int currentLevel, int level);
struct node** createqueue(int*, int*);
void Enqueue(struct node**, int*, struct node*);
struct node* Dequeue(struct node**, int*);
struct node* generateBTree();

/* Given a binary tree, print its nodes in level order
using array for implementing queue */
void printLevelOrder(struct node* root)
{
	int rear, front;
	struct node** queue = createqueue(&front, &rear);
	struct node* temp_node = root;

	while (temp_node)
	{
		printf(" %d ", temp_node->data);

		/*Enqueue left child */
		if (temp_node->left)
			Enqueue(queue, &rear, temp_node->left);
        /*Enqueue mid child */
        if (temp_node->mid)
			Enqueue(queue, &rear, temp_node->mid);
		/*Enqueue right child */
		if (temp_node->right)
			Enqueue(queue, &rear, temp_node->right);

		/*Dequeue node and make it temp_node*/
		temp_node = Dequeue(queue, &front);
    }
}
void printNodesAtLevel(struct node* root,int currentLevel, int level)
{
	if(root == NULL)
  {
      return;
  }
  if(currentLevel >= level)
  {
     printf("{ %d }\t", root->data);

     return;
  }
  printNodesAtLevel(root->left, currentLevel+1, level);
  printNodesAtLevel(root->mid, currentLevel+1, level);
  printNodesAtLevel(root->right, currentLevel+1, level);

}

/*UTILITY FUNCTIONS*/
struct node** createqueue(int* front, int* rear)
{
	struct node** queue = (struct node**)malloc(
		sizeof(struct node*) * MAX_Q_SIZE);

	*front = *rear = 0;
	return queue;
}

void Enqueue(struct node** queue, int* rear,struct node* new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

struct node* Dequeue(struct node** queue, int* front)
{
	(*front)++;
	return queue[*front - 1];
}

/* Helper function that allocates a new node with the
given data and NULL left,mid and right pointers. */
struct node* newNode(int data)
{
	struct node* node= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
    node->mid = NULL;
	return (node);
}
/*
This function returns below tree
            1
          / |  \
         2  9   3
       / \  / \  \
      4   5 10 11 6
    / \
   7   8
*/
struct node* generateBTree()
{
    // Root Node
    struct node* root =  newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
	root->mid = newNode(9);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    root->mid->left = newNode(10);
    root->mid->right = newNode(11);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);

    return root;
}

/* Driver program to test above functions*/
int main()
{
    int n=11;
        printf("Friend Suggestions System");
    printf("Level order traversal of a tree is Breadth First Traversal for the tree.\n\n\t\t");
    printf("            1\n\t\t");
    printf("        /   |   \\ \n\t\t");
    printf("       2    9    3\n\t\t");
    printf("     /  \\  /  \\   \\ \n\t\t");
    printf("    4   5  10 11   6 \n\t\t");
    printf("  /  \\ \n\t        ");
    printf(" 7    8 \n\n");

    printf("\nTotal number of Users used in Friend Suggestions System are : %d",n);
	struct node *root = generateBTree();
	printf("\n\nLevel Order traversal of binary tree is (BFS)  \n");
	printLevelOrder(root);
	printf("\n\n\nUser \t\t\t\t\t\t :\t");
    printNodesAtLevel(root, 0, 0);
    printf("\n");
    printf("\nConnected Friends \t\t\t\t :\t");
    printNodesAtLevel(root, 0, 1);
    printf("\n");
    printf("\nRecommended Friends (according to priority order) :\t");
    printNodesAtLevel(root, 0, 2);
    printNodesAtLevel(root, 0, 3);
    printf("\n\n");

	return 0;
}
