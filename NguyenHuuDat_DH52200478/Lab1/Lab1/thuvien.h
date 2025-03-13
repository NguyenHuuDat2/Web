#include"iostream"
#include <cstdio>
using namespace std;
typedef int TYPEINFO;
struct NODE {
	TYPEINFO info;
	NODE* left;
	NODE* right;
};
typedef NODE* BST_TREE;
void InMenu(int& chon);

void PreOrder(BST_TREE r);

void InOrder(BST_TREE r);

void InIt(BST_TREE r);

BST_TREE CreateNode(TYPEINFO a);

void Remove(BST_TREE& r);

BST_TREE Find(BST_TREE& r, TYPEINFO a);

BST_TREE Insert(BST_TREE& r, TYPEINFO a);

void timMaxLeft(BST_TREE& r, BST_TREE& t);

int Delete(BST_TREE& r, TYPEINFO a);

int demspt(BST_TREE r);

void WriteNode(BST_TREE r, FILE* f);

int WriteFile(BST_TREE r, char* filename);

int ReadFile(BST_TREE& r, char* filename);

