#include "thuvien.h"
int main() {
	int chon;
	BST_TREE tree = NULL;
	TYPEINFO a;
	char output_filename[] = "output.txt";
	char input_filename[] = "input.txt";
	do {
		InMenu(chon);
		switch (chon)
		{
		case 1:
			break;
		case 2:
			cout << "them node cho cay";
			cin >> a;
			tree = Insert(tree, a);

			break;
		case 3:

			cout << "xoa node cho cay";
			cin >> a;
			if (Delete(tree, a)) {
				cout << "Xoa node thanh cong!\n";
			}
			else {
				cout << "Gia tri khong ton tai trong cay!\n";
			}
			break;
		case 4:
			cout << "tim Node ";
			cin >> a;
			if (Find(tree, a) != NULL) {
				cout << "Gia tri ton tai trong cay!\n";
			}
			else {
				cout << "Gia tri khong ton tai trong cay!\n";
			}
			break;
		case 5:
			cout << "Duyet NLR";
			PreOrder(tree);
			break;
		case 6:
			cout << "Duyet LNR";
			InOrder(tree);
			break;
		case 7:
			cout << "Duyet LRN";
			InIt(tree);
			break;
		case 8:
			cout << "Ghi file ";
			if (WriteFile(tree, output_filename))
				cout << "Ghi file thanh cong!\n";
			break;
		case 9:
			if (ReadFile(tree, input_filename))
				cout << "Doc file thanh cong!\n";
			cout << "Doc file";
			break;
		default:
			cout << "\n chua co chuc nang nay, vui long chon lai";
			break;
		}
	} while (chon != 1);
	return 0;
}