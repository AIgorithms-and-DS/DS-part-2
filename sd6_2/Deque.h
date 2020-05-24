#pragma once

//Для создания дека будим использовать цикличесий массив

template <typename T>
class Deque
{
private:
	int N;
	T* arr;
	int tailer = -1;
	int header;
	bool flag = true;

public:
	Deque(int N)
	{
		this->N = N;
		arr = new T[N];
		header = N;
	}

	void push(T d)
	{
		tailer++;
		arr[tailer] = d;	
	}

	void pushBack(T d)
	{
		header--;
		arr[header] = d;	
	}

	T pop()
	{
		if (tailer == -1 && flag)
		{
			tailer = N - 1;
			flag = false;
		}

		T temp = arr[tailer];
		tailer--;

		return temp;
	}

	T popBack()
	{
		if (header == N && flag)
		{
			header = 0;
			flag = false;
		}

		T temp = arr[header];
		header++;

		return temp;
	}
	
	~Deque()
	{
		delete[] arr;
	}
};