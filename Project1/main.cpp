#include <iostream>
#include <stack>

using namespace std;

template <class T> 
class MyQueue
{
private:
	stack<T> firstStack;
	stack<T> secondStack;
public:
	void push(T elem)
	{
		firstStack.push(elem);
	}

	T pop()
	{
		T result;
		if (secondStack.empty())
			while (!firstStack.empty())
			{
				secondStack.push(firstStack.top());
				firstStack.pop();
			}

		result = secondStack.top();
		secondStack.pop();
		return result;
	}
};

template <class T>
class MyCycleQueue
{
private:
	T* data;
	T* top;
	T* tail;
	bool isFull;
public:
	MyCycleQueue(int size = 5)
	{
		data = new T[size];
		top = nullptr;
		tail = nullptr;
		isFull = false;
	}

	void push(T elem)
	{
		if (isFull)
		{
			cout << "Queue is full!";
			return;
		}
		if (top == nullptr)
		{
			top = &data[1];
			tail = &data[0];
			*top = elem;
		}
		if (top == tail)
			isFull = true;
	}

	T pop()
	{
		if (!isFull && tail == top)
		{
			cout << "Queue is empty!";
			throw("error");
		}
		T temp = *tail;
		tail--;
		isFull = false;
		return temp;
	}
};

int main()
{
	/*MyQueue<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	cout << test.pop();
	cout << test.pop();
	cout << test.pop();*/

	MyCycleQueue<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);
	//test.push(6);
	//cout << test.pop();
}