#pragma once
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

struct Tableware			//посуда
{
	bool dirty = true;		//(грязная)
	bool error = false;		//доказательство работы алгоритма
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

class WashMashine		//посудомойка
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

	void loadFirst(Tableware& t)		//первая очередь
	{
		queue1->push(t);
	}

	void loadSecond(Tableware& t)		//вторая очередь
	{
		queue2->push(t);
	}

	void wash(Tableware& t)
	{
		t.dirty = false;
	}

	Tableware takeFirst()		//взять с первой очереди
	{
		return queue1->pop();
	}

	Tableware takeSecond()		//взять со второй очереди
	{
		return queue2->pop();
	}
};

class Shelf			//полка
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