#include <stdio.h>

#define N 10

struct BinaryTreeNode // a node in the binary tree
{
	int m_nValue; // value of node
	BinaryTreeNode *m_pLeft; // left child of node
	BinaryTreeNode *m_pRight; // right child of node
};


BinaryTreeNode tree[N];
int treeNodes;
int treeRoot;


void createTree(int* nodes, int (*array)[3], int n)
{
	treeNodes = n;
	for (int i = 0; i < n; ++i)
	{
		tree[i].m_nValue = nodes[i];
	 	tree[i].m_pLeft = 0;
	 	tree[i].m_pRight = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if(array[i][1] < 0)
		{
			treeRoot = array[i][2];
		}
		else
		{
			if(array[i][0] == 'l') //left child
				tree[array[i][1]].m_pLeft = &tree[array[i][2]];
			else
				tree[array[i][1]].m_pRight = &tree[array[i][2]];
		}
	}
}


void destroyTree(BinaryTreeNode* root)
{
	if(root)
	{
		destroyTree(root->m_pLeft);
		destroyTree(root->m_pRight);
		delete root;
		root = 0;
	}
}

void findPath(BinaryTreeNode* root, int s, int octave, char* path)
{
	if(root)
	{
		//printf("%d\n", root->m_nValue);
		path[octave] = root->m_nValue;
		int subs = s - root->m_nValue;
		if(root->m_pLeft == 0 && root->m_pRight == 0)
		{
			if(subs == 0)
			{
				for (int i = 0; i <= octave; ++i)
					printf("%d ", path[i]);
				printf("\n");
			}
		}
		else
		{
			if(subs < 0)
				return;
			findPath(root->m_pLeft, subs, octave+1, path);
			findPath(root->m_pRight, subs, octave+1, path);
		}
	}
}

int main()
{
	int nodes[5] = {10, 5, 12, 4, 7};
	int relation[5][3] = {{'l', -1, 0}, {'l', 0, 1}, {'r', 0, 2}, {'l', 1, 3}, {'r', 1, 4}};
	createTree(nodes, relation, 5);
	char path[256];
	findPath(tree, 22, 0, path);
	//printf("tag\n");
	//destroyTree(&tree[treeRoot]);
	//printf("tag\n");
	return 0;
}