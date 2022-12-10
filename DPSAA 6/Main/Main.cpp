#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pnext;

    Node(int value = 0, Node* next = nullptr)
    {
        pnext = next;
        data = value;
    }
};

int searchMax(int arr[], const int SIZE, int index = 0)
{
    if (index + 1 == SIZE)
    {
        return arr[index];
    }
    if (arr[index] < searchMax(arr, SIZE, index + 1)) return searchMax(arr, SIZE, index + 1);
    else return arr[index];
}

void push_back(Node* head, const int VALUE)
{
    if (head->pnext != nullptr) push_back(head->pnext, VALUE);
    else head->pnext = new Node(VALUE);
}

int pop_front(Node*& head)
{
    int value = head->data;
    if (head->pnext != nullptr)
    {
        Node* temp = head;
        head = head->pnext;
        delete temp;
        return value;
    }
    else
    {
        
        delete head;
        return value;
    }
}

void print(Node* head)
{
    cout << head->data << " ";
    if (head->pnext != nullptr)
    {
        print(head->pnext);
    }
}

int main()
{
   int num;
   Node* head = new Node;
   cout << "Количество элементов >> ";
   int size;
    cin >> size;
   cout << "Ввод очереди >> ";
   for (int i = 0; i < size; i++)
   {
       cin >> num;
       push_back(head, num);
   }
  
   print(head);
   cout << "\n" << pop_front(head) << endl;
   print(head);
   
}