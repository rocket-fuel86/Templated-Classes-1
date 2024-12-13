// Односвязный список

#include <iostream>
using namespace std;


template<typename T>

class MyInt
{
private:
	T value;
public:
	explicit MyInt(T value) : value(value) {}

	void SetData(T value)
	{
		this->value = value;
	}
	T GetData() const
	{
		return value;
	}
};


template<typename T>

class Node
{
private:
	MyInt<T> myInt;
	Node<T>* next /*= nullptr*/;
public:
	explicit Node(MyInt<T> myInt) : myInt(myInt), next(nullptr) {}

	MyInt<T> GetMyInt() const
	{
		return myInt;
	}

	void SetMyInt(MyInt<T> myInt)
	{
		this->myInt = myInt;
	}

	Node<T>* GetNext() const
	{
		return next;
	}

	void SetNext(Node<T>* next)
	{
		this->next = next;
	}
};

template<typename T>

class LinkedList
{
private:
	Node<T>* head;
	size_t size;
public:
	LinkedList() : head(nullptr), size(0) {}

	size_t GetSize() const
	{
		return size;
	}

	void InsertAtEnd(MyInt<T> value)
	{
		if (head == nullptr)
		{
			InsertAtBeginning(value);
			return;
		}
		Node<T>* newNode = new Node<T>(value);

		Node<T>* temp = head;
		while (temp->GetNext() != nullptr)
		{
			temp = temp->GetNext();
		}
		temp->SetNext(newNode);
		size++;
	}

	void InsertAtBeginning(MyInt<T> value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->SetNext(head);
		head = newNode;
		size++;
	}

	~LinkedList()
	{
		while (head != nullptr)
		{
			Node<T>* temp = head;
			head = head->GetNext();
			delete temp;
		}
	}
};

int main()
{
	LinkedList<double> test;

	test.InsertAtBeginning(MyInt<double>(7.7));
}