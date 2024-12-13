// Двухсвязный список

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
	Node<T>* next;
	Node<T>* prev; // new
public:
	explicit Node(MyInt<T> myInt) : myInt(myInt), next(nullptr), prev(nullptr) /*new*/ {}
	
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

	// new
	Node<T>* GetPrev() const
	{
		return prev;
	}

	void SetPrev(Node<T>* prev)
	{
		this->prev = prev;
	}
};


template<typename T>

class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;//new
	size_t size;
public:
	LinkedList() : head(nullptr), tail(nullptr)/*new*/, size(0) {}

	size_t GetSize() const
	{
		return size;
	}

	// edit!
	void InsertAtEnd(MyInt<T> value)
	{
		Node<T>* newNode = new Node<T>(value);

		if (tail == nullptr)
		{
			tail = newNode;
			head = newNode;
		}
		else
		{
			newNode->SetPrev(tail);
			tail->SetNext(newNode);
			tail = newNode;
		}
		size++;
	}

	// edit!
	void InsertAtBeginning(MyInt<T> value)
	{
		Node<T>* newNode = new Node<T>(value);

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->SetNext(head);
			head->SetPrev(newNode);
			head = newNode;
		}
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