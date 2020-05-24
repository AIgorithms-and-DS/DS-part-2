#pragma once

template <typename T>
class Stack
{
private:
	int N;
	T *arr;
	int top = 0;

public:
	Stack(int N)
	{
		this->N = N;
		arr = new T[N];
	}

	void push(T d)
	{
		if (top != N - 1)
		{
			arr[top] = d;
			top++;
		}
		else
		{
			arr[top] = d;
		}
	}

	T pop()
	{
		T temp = arr[top];
		top--;

		return temp;
	}

	~Stack()
	{
		delete[] arr;
	}
};