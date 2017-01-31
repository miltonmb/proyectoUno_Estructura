#pragma once
#include "ADTList.h"
#include "object.h"
#include "nodo.h"
using namespace std;
class LinkedList:public ADTList{
	protected:
		nodo* head;
	public:
		LinkedList();
		virtual ~LinkedList();
		virtual bool insert(object*, int);
		virtual object* remove(int);
		virtual object* first()const;
		virtual object* last()const;
		virtual void clear();
		virtual int indexOf(object*)const;
		virtual object* get(int);
		virtual int Capacity()const;
		virtual bool isEmpty()const;
		virtual bool isFull()const;
};