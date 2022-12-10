#include <iostream>

using namespace std;

class OneDirecionList
{
private:
	class Node
	{
	public:
		int value;
		Node* next_ptr;

		Node(int value = 0, Node* next_ptr = nullptr)
		{
			this->value = value;
			this->next_ptr = next_ptr;
		}
	};

	int currSize = 0;
	Node* head;

public:
	OneDirecionList()
	{
		head = new Node;
	}

	void erase(int index)
	{
		Node* temp = head;
		if (index == 0)
		{
			head = head->next_ptr;
			delete temp;
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next_ptr;
			}
			Node* left = temp;
			temp = temp->next_ptr;
			left->next_ptr = temp->next_ptr;
			delete temp;
		}
		currSize--;
	}

	void print()
	{
		Node* temp = head;
		while (temp->next_ptr != nullptr)
		{
			cout << temp->value << " ";
			temp = temp->next_ptr;
		}
		cout << endl;
	}

	void push(int index, int value)
	{
		Node* temp = head;
		if (index == 0)
		{
			head = new Node(value, temp);
		}
		else
		{
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next_ptr;
			}
			Node* left = temp;
			left->next_ptr = new Node(value, temp->next_ptr);
		}
		currSize++;
	}

	int& operator[](int index)
	{
		Node* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next_ptr;
		}
		return temp->value;
	}

	int size()
	{
		return currSize;
	}
};

bool doubleCheck(OneDirecionList& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		int countDouble = 1;
		for (int j = 0; j < list.size(); j++)
		{
			if (list[i] == list[j] && i != j) countDouble++;
			if (countDouble > 2) break;
		}
		if (countDouble == 2) return true;
	}
	return false;
}

void deleteMax(OneDirecionList& list)
{
	int indexMax = 0;
	int max = list[0];
	for (int i = 1; i < list.size(); i++)
	{
		if (list[i] > max)
		{
			indexMax = i;
			max = list[i];
		}
	}
	list.erase(indexMax);
}

void Insert(OneDirecionList& list, int num)
{
	for (int i = 1; i < list.size(); i += 3)
	{
		list.push(i, num);
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	OneDirecionList arr;
	int size;
	cout << "Размер списка >> ";
	cin >> size;
	int num;
	for (int i = 0; i < size; i++)
	{
		cin >> num;
		arr.push(0,num);
	}
	arr.print();

	//Задание #1
	cout << "Проверка на два одинаковых элемента - " << doubleCheck(arr) << endl << endl;

	//Задание #2
	deleteMax(arr);
	arr.print();

	//Задание #3
	cin >> num;
	Insert(arr, num);
	arr.print();
	return 0;
}
