//Program 1
/*Group Member List
Member Name 1: CHU CHENG QING
Matric Number:A23CS0218
Section:9

Member Name 2: CHEN WEI JAY NICKOLAS
Matric Number:A23CS5028
Section:9

Member Name 3: LIM XIN ROU
Matric Number:A23CS0240
Section:9
*/

#include <iostream>
#include <iomanip>
using namespace std;
class ItemNode{
    public:
    string name;
    float price;
    ItemNode* aft = NULL;
    ItemNode* bef = NULL;

    ItemNode(string n, float p): name(n), price(p){}
};

class List{
    private:
    ItemNode* head = NULL;
    ItemNode* tail = NULL;
    public:
    void task1(ItemNode*);
    void task2(ItemNode*);
    void task3(void);
    void task4(ItemNode*,int);
    void task5(int);
    void task6();
};

void List:: task1(ItemNode* item)
{
    if(head == NULL && tail == NULL)
    {
        head = tail = item;
        head->aft = head->bef = NULL;
        tail->aft = tail->bef = NULL;
    }
    
}

void List:: task2(ItemNode* item)
{
    item->aft = head;
    head->bef = item;
    head = item;
    
}
void List:: task3()
{
    ItemNode* Temp;    
    cout<<"Print backward:"<<endl;
    Temp = tail;
    while (Temp!=NULL)
    {
        cout<<'['<<Temp->name<<'\t'<<Temp->price<<"]\t";
        Temp = Temp->bef;
    }
    cout<<endl<<endl;
    
}
void List::task4(ItemNode* item, int index) {
    if (index < 1) {
        cout << "Invalid index. Index must be 1 or greater." << endl;
        return;
    }

    if (head == NULL && index == 1) {
        task1(item);
        return;
    }

    ItemNode* prevNode = NULL;
    ItemNode* currNode = head;
    int currIndex = 1;

    while (currNode && currIndex < index) {
        prevNode = currNode;
        currNode = currNode->aft;
        currIndex++;
    }

    if (currIndex == index) {
        item->aft = currNode;
        item->bef = prevNode;

        if (prevNode) {
            prevNode->aft = item;
        } else {
            head = item;
        }

        if (currNode) {
            currNode->bef = item;
        }
    } else if (currNode == NULL) {
        item->bef = tail;
        tail->aft = item;
        tail = item;
    } else {
        cout << "Index out of bounds. Cannot insert." << endl;
    }
}

void List:: task5(int x){
	if (x < 1)
	{
		cout << "Invalid index. Index must be 1 or greater." << endl;
	}
	
	ItemNode* prevNode = NULL;
    ItemNode* currNode = head;
    int currIndex = 1;

    while (currNode && currIndex < x) {
        prevNode = currNode;
        currNode = currNode->aft;
        currIndex++;
    }
	
	if (currIndex == x)
	{
		prevNode->aft = currNode->aft;
		if(currNode->aft)
			currNode->aft->bef = prevNode;
		delete currNode;
	}
	else if(currIndex == 1)
	{
		head = currNode->aft;
		if(head)
			head->bef = NULL;
		delete currNode;
	}
		

}
void List:: task6()
{
	if(tail->aft == NULL)
	{
		tail = tail->bef;
		delete tail;
	}
}
int main()
{
List ItemList;
ItemNode *n1 = new ItemNode("Book", 9.59);
ItemNode *n2 = new ItemNode("Ruler", 3.45);
ItemNode *n3 = new ItemNode("Pen", 5.69);
ItemNode *n4 = new ItemNode("Eraser", 2.25);
cout << fixed << setprecision(2) << left;
ItemList.task1(n1);
ItemList.task2(n2);
ItemList.task3();
ItemList.task4(n3, 2);
ItemList.task4(n4, 2);
ItemList.task3();
ItemList.task5(3);
ItemList.task3();
ItemList.task6();
ItemList.task3();
return 0;
}