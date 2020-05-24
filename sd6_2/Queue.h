#pragma once

template <typename T>
class Queue
{
private:
	int N;
	T* arr;
	int head = 0;
	int tail = 0;

public:
	
	Queue(int N)
	{
		this->N = N;
		arr = new T[N];
	}

	void push(T d)
	{
		arr[tail] = d;
		tail++;
	}

	T pop()
	{
		T temp = arr[head];
		head++;

		return temp;
	}

	~Queue()
	{
		delete[] arr;
	}
};