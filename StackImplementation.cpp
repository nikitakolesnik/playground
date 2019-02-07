#include <iostream>
#include <memory> //unique_ptr


struct Node {
	int nValue;
	Node *ptrNext;

	Node() { nValue = 0; ptrNext = 0; }
	Node(int n) { nValue = n; ptrNext = 0; }
};

class Stack {
public:
	Node * ptrHead;
	Stack() { ptrHead = 0; }

	void Insert(int);
	void Delete();
	void Clear();
	void Print();
};


int _main() { return 0;
//int main() {
	std::unique_ptr<Stack> S(new Stack());
	char cChoice;
	int  nInput;
	bool bRepeat = true;

	while (bRepeat)
	{
		std::cout
			<< "\r\n"
			<< "   1. Print\r\n"
			<< "   2. Insert\r\n"
			<< "   3. Delete end\r\n"
			<< "   4. Delete all\r\n"
			<< "   Q. Quit\r\n"
			<< "      Enter Selection: ";

		std::cin >> cChoice;
		std::cin.ignore(1000, 10);
		std::cout << "\r\n";

		switch (cChoice)
		{
		case '1':
			S->Print();
			break;
		case '2':
			std::cout << "      Enter value:";
			std::cin >> nInput;
			std::cin.ignore(1000, 10);
			S->Insert(nInput);
			break;
		case '3':
			S->Delete();
			break;
		case '4':
			S->Clear();
			break;
		case 'Q': case 'q':
			bRepeat = false;
			break;
		default:
			std::cout << "Invalid input\r\n";
			break;
		}
	}

	//std::cin.get();
}


void Stack::Insert(int n) 
{
	std::cout << "Inserting " << n << "\r\n";

	Node *ptrNode = new Node(n);

	ptrNode->ptrNext = ptrHead;
	ptrHead = ptrNode;
}

void Stack::Delete() {
	if (ptrHead == nullptr)               // 0 items
		std::cout << "Nothing to delete\r\n";
	else if (ptrHead->ptrNext == nullptr) // 1 item
	{
		std::cout << "Deleting " << ptrHead->nValue;
		
		delete ptrHead;
		ptrHead = 0;
		
		std::cout << ", list is now empty\r\n";
	}
	else                                  // 2+ items
	{
		std::cout << "Deleting " << ptrHead->nValue << "\r\n";

		Node *ptrTemp = ptrHead->ptrNext;
		delete ptrHead;
		ptrHead = ptrTemp;
	}
}

void Stack::Clear() 
{
	if (!ptrHead)
		std::cout << "Nothing to delete; list is already empty\r\n";
	else
	{
		std::cout << "Deleting list\r\n";

		if (ptrHead->ptrNext == nullptr)
		{
			delete ptrHead;
			ptrHead = 0;
		}
		else
		{
			Node *ptrTrav0 = ptrHead, *ptrTrav1 = ptrHead->ptrNext;

			while (true)
			{
				delete ptrTrav0;
				ptrTrav0 = ptrTrav1;

				if (ptrTrav1->ptrNext)
					ptrTrav1 = ptrTrav1->ptrNext;
				else
					break;
			}
		}
	}
	ptrHead = 0;
}

void Stack::Print() 
{
	if (ptrHead != nullptr)
	{
		Node* trav = ptrHead;
		std::cout << "List: ";

		while (trav) {
			std::cout << trav->nValue << ' ';

			if (trav->ptrNext)
				trav = trav->ptrNext;
			else
				break;
		}
		std::cout << "\r\n";
	}
	else
		std::cout << "List is empty\r\n";
}
