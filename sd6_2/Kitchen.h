#pragma once
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

struct Tableware			//������
{
	bool dirty = true;		//(�������)
	bool error = false;		//�������������� ������ ���������
};

class Table
{
private:
	Stack<Tableware> *stack;

public:
	Table(int N)
	{
		stack = new Stack<Tableware>(N);
	}

	void put(Tableware& t)
	{
		stack->push(t);
	}

	Tableware take()
	{
		return stack->pop();
	}
};

class WashMashine		//�����������
{
private:
	Queue<Tableware>* queue1;
	Queue<Tableware>* queue2;

public:
	WashMashine(int N)
	{
		queue1 = new Queue<Tableware>(N);
		queue2 = new Queue<Tableware>(N);
	}

	void loadFirst(Tableware& t)		//������ �������
	{
		queue1->push(t);
	}

	void loadSecond(Tableware& t)		//������ �������
	{
		queue2->push(t);
	}

	void wash(Tableware& t)
	{
		t.dirty = false;
	}

	Tableware takeFirst()		//����� � ������ �������
	{
		return queue1->pop();
	}

	Tableware takeSecond()		//����� �� ������ �������
	{
		return queue2->pop();
	}
};

class Shelf			//�����
{
private:
	Deque<Tableware>* deque;

public:
	Shelf(int N)
	{
		deque = new Deque<Tableware>(N);
	}

	void putFront(Tableware& t)
	{
		deque->push(t);
	}

	void putBack(Tableware& t)
	{
		deque->pushBack(t);
	}

	Tableware takeFront()
	{
		return deque->pop();
	}

	Tableware takeBack()
	{
		return deque->popBack();
	}
};