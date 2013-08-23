#include <stdio.h>

#define N 20
#define max(x, y) (x>y? x: y)


struct BinaryTreeNode // a node in the binary tree
{
	int id;
	BinaryTreeNode *m_pLeft; // left child of node
	BinaryTreeNode *m_pRight; // right child of node
};

int dist[N][N];
BinaryTreeNode tree[N];
int treeNodes;
int treeRoot;


void createTree(int nodeNumber, int (*array)[3], int n)
{
	treeNodes = nodeNumber;
	for (int i = 0; i < nodeNumber; ++i)
	{
		tree[i].id = i;
	 	tree[i].m_pLeft = 0;
	 	tree[i].m_pRight = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		if(array[i][1] >= 0) //left child
			tree[array[i][0]].m_pLeft = &tree[array[i][1]];
		if(array[i][2] >= 0)
			tree[array[i][0]].m_pRight = &tree[array[i][2]];
	}
}


void longestPath(int root, int father)
{
	if(father != -1)
	{
		printf("%d %d\n", root, father);
		dist[root][father] = dist[father][root] = 1;
		for (int i = 0; i < treeNodes; ++i)
		{
			if(i != root && dist[i][father] != -1)
			{
				dist[i][root] = dist[i][father] + 1;
				dist[root][i] = dist[i][root];
			}
		}
	}
	if (tree[root].m_pLeft)
		longestPath(tree[root].m_pLeft->id, root);
	if (tree[root].m_pRight)
		longestPath(tree[root].m_pRight->id, root);
}

void searchPath(int root)
{
	for (int i = 0; i < treeNodes; ++i)
	{
		for (int j = 0; j < treeNodes; ++j)
		{
			dist[i][j] = -1;
			dist[j][i] = -1;
		}
	}
	for (int i = 0; i < treeNodes; ++i)
		dist[i][i] = 0;
	longestPath(treeRoot, -1);
	for (int i = 0; i < treeNodes; ++i)
	{
		for (int j = 0; j < treeNodes; ++j)
			printf("%d ", dist[i][j]);
		printf("\n");
	}
}


int longestPath2(BinaryTreeNode* root, int& depth)
{
	if(root)
	{
		int leftPath, rightPath;
		int leftDepth, rightDepth;
		leftPath = longestPath2(root->m_pLeft, leftDepth);
		rightPath = longestPath2(root->m_pRight, rightDepth);

		depth = max(leftDepth, rightDepth) + 1;
		int maxPath = max(leftPath, rightPath);
		maxPath = max(maxPath, leftDepth + rightDepth);
		//printf("depth: %d, path: %d\n", depth, maxPath);
		return maxPath;
	}
	else
	{
		depth = 0;
		return 0;
	}	
}

int main()
{
	int relation[8][3] = {{0, 1, 2}, {1, 3, 4}, {3, 5, 6}, {4, 7, 8}, {5, 9, 10}, 
							{7, 11, -1}, {9, 12, 13}, {11, 14, -1}};
	createTree(15, relation, 8);
	int depth;
	int maxPath = longestPath2(&tree[treeRoot], depth);
	printf("%d\n", maxPath);
	//searchPath(treeRoot);
	return 0;
}