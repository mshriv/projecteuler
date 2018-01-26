#include <stdio.h>
#include <queue>
using namespace std;
struct node
{
	unsigned long val;
	unsigned long long maxsum;
	node *l;
	node *r;

	node(unsigned long v) : val(v)
	{
		l = NULL;
		r = NULL;
		maxsum = 0;
	}
};

node *Populate(const char *f)
{
	FILE *fp = fopen(f, "r");
	if (fp == NULL)
		return NULL;

	char line[2048];
	node * root= NULL;
	queue<node *> vec;
	while (fscanf(fp, "%[^\n]", line) != -1)
	{
		char *tok = strtok(line, " \t");
		while (tok != NULL)
		{
			if (vec.empty())
			{
				root = new node(atol(tok));
				vec.push(root);
				vec.push(NULL);
			}
			else
			{
				node*tmp = vec.front();
				if (tmp->l == NULL) {
					tmp->l = new node(atol(tok));
					vec.push(tmp->l);
				}
				else if (tmp->r == NULL)
				{
					tmp->r = new node(atol(tok));
					vec.push(tmp->r);
					vec.pop();
					node *tmp1 = vec.front();
					if (tmp1 != NULL)
					{
						tmp1->l = tmp->r;
					}
					else
					{
						vec.pop();
						vec.push(NULL);
					}
				}
			}
			tok = strtok(NULL, " \t");
		}
		fgetc(fp);
	}

	return root;
}

unsigned long long max(node *root)
{
	if (root == NULL)
		return (unsigned long long) 0;

	if (root->maxsum != 0)
		return root->maxsum;

	unsigned long long left = max(root->l);
	unsigned long long right = max(root->r);

	if (left > right)
	{
		root->maxsum = (unsigned long long)root->val + left;
	}
	else
		root->maxsum = (unsigned long long)root->val + right;
	return root->maxsum;
}

void p18()
{
	const char *filename = "data1.txt";
	node *root = NULL;
	root = Populate(filename);

	unsigned long long sum = max(root);

	printf("%llu", sum);
	while (1);
}