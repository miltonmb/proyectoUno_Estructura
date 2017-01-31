#pragma once
#include "object.h"
class nodo{
	friend class LinkedList;
	private:
		object* elemento;
		nodo* next;

	public:
		nodo(object*);
		~nodo();
};