#include "thuvien.h"
void InMenu(int& chon) {
	cout << "\nCAY NHI PHAN TIM KIEM";
	cout << "\n1. Ket thuc";
	cout << "\n2. Them BST";
	cout << "\n3. Xoa BST";
	cout << "\n4. tim BST";
	cout << "\n5. Duyet PreOder";
	cout << "\n6. Duyet InOrder";
	cout << "\n7. Duyet PostOrder";
	cout << "\n8. Ghi file cay BST";
	cout << "\n9. Doc file cay BST";
	cout << "\nBan hay lua chon [0,1,2,3,4,5,6,7,8,9]:";
	cin >> chon;
}
void PreOrder(BST_TREE r) {
	if (r != NULL) {
		cout << r->info << "\t";
		PreOrder(r->left);
		PreOrder(r->right);
	}
}
void InOrder(BST_TREE r) {
	if (r != NULL) {
		
		PreOrder(r->left);
		cout << r->info << "\t";
		PreOrder(r->right);
	}
}
void InIt(BST_TREE r) {
	if (r != NULL) {

		PreOrder(r->left);
		
		PreOrder(r->right);
		cout << r->info << "\t";
	}
}
BST_TREE CreateNode(TYPEINFO a) {
	BST_TREE r = new NODE;
	r->info = a;
	r->left = NULL;
	r->right = NULL;
	return r;
}
void Remove(BST_TREE& r) {
	if (r != NULL) {
		Remove(r->left);
		Remove(r->right);
		delete r;
		r = NULL;
	}
}
BST_TREE Find(BST_TREE& r, TYPEINFO a) {
	if (r == NULL)
		return NULL;
	if (a > r->info) {
		return Find(r->right, a);
	}
	if (a < r->info) {
		return Find(r->left, a);
	}
	return r;
}
BST_TREE Insert(BST_TREE& r, TYPEINFO a)
{
	if (r == NULL)
		return CreateNode(a);
	if (a > r->info)
		r->right=Insert(r->right, a);
	if (a < r->info)
		r->left=Insert(r->left, a);
	return r;
}
void timMaxLeft(BST_TREE& r, BST_TREE & t) {
	if (r->left)
		//timMaxLeft(t, r->left);
		timMaxLeft(r, t->left);
	else {
		r->info = t->info;
		r = t;
		t= t->right;
	}
}

int Delete(BST_TREE& r, TYPEINFO a)
{
	if (r == NULL)
		return 0;
	else if (a < r->info) return Delete(r->left, a);
	else if (a > r->info) return Delete(r->right, a);
	else {
		if (r->left == NULL) r = r->right;
		else if (r->right == NULL) r = r->left;
		else {
			//c1  .ham khong can tim maxleft va minright
			/*NODE* t = r->left;
			while (r->right != NULL) {
				t = t->right;
			}
			r->info = t->info;
			Delete(r->left, t->info);*/
			

			//c2.  ham maxleft
			timMaxLeft(r, r->left);
		}
	}
	return 1;
}
int demspt(BST_TREE r) {
	if (r == NULL) return 0;
	else
	{
		return 1 + demspt(r->left) + demspt(r->right);
	}
}
void WriteNode(BST_TREE r, FILE* f) {
	if (r != NULL) {
		fprintf_s(f, "%d\t", r->info);
		WriteNode(r->left, f);
		WriteNode(r->right, f);
	}
}
int WriteFile(BST_TREE r, char* filename) {
	FILE* f;
	fopen_s(&f, filename, "wt");
	if (f == NULL)
		return 0;
	else {
		int spt = demspt(r);
		fprintf_s(f, "%d\n", spt);
		WriteNode(r, f);
		fclose(f);
		return 1;
	}
}
int ReadFile(BST_TREE& r, char* filename)
{
		FILE* file;
		fopen_s(&file, filename, "r"); 
		if (file == NULL) {
			fprintf(stderr, "Khong the mo file: %s\n", filename);
			return 0;
		}

		TYPEINFO value;
		while (fscanf_s(file, "%d", &value) != EOF) { //cuoi tap tin
			Insert(r, value); 
		}

		fclose(file); 
		return 1; 
	}


