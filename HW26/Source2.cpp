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
	T GetData()
	{
		return value;
	}
};

template<typename T>

class Node
{
private:
	MyInt<T> myInt;
	Node<T>* next /* nullptr */;
public:
	explicit Node(MyInt<T> myInt) : myInt(myInt), next(nullptr) {}

	MyInt<T>& GetMyInt()
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
	void SetNext(Node* next)
	{
		this->next = next;
	}
};


template<typename T>

class Queue
{
private:
	Node<T>* first;
	Node<T>* last;
	size_t size;
public:
	Queue() : first(nullptr), last(nullptr), size(0) {}

	size_t Size() const
	{
		return size;
	}

	void Enqueue(MyInt<T> myInt) // додавання елемента в в кінець черги 
	{
		Node<T>* newNode = new Node<T>(myInt);

		if (last == nullptr)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->SetNext(newNode);
			last = newNode;
		}

		size++;
	}

	MyInt<T>& Front()
	{
		if (first == nullptr)
		{
			throw runtime_error("Error");
		}
		return first->GetMyInt();
	}

	const MyInt<T> Front() const
	{
		return Front();
	}

	void Dequeue() // видалення з кінця черги
	{
		if (first == nullptr)
		{
			return;
		}

		Node<T>* temp = first;
		first = first->GetNext();

		if (first == nullptr)
		{
			last = nullptr;
		}

		delete temp;
		size--;
	}

	~Queue()
	{
		while (first != nullptr)
		{
			Node<T>* temp = first;
			first = first->GetNext();

			delete temp;
		}
	}
};

int main()
{
	Queue<double> queue;

	queue.Enqueue(MyInt<double>(9.9));

	for (size_t i = queue.Size(); i > 0; i--)
	{
		cout << queue.Front().GetData() << endl;
		queue.Dequeue();
	}
}