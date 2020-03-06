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
pubclic:
	MyCycleQueue(int size = 0)
	{
		data = new T[size];
		top = nullptr;
		tail = nullptr;
	}

	void push(T elem)
	{

	}

};

int main()
{
	MyQueue<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	cout << test.pop();
	cout << test.pop();
	cout << test.pop();
	//test.push(4);
	//cout << test.pop();
}