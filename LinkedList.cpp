#include "LinkedList.h"
#include "ADTList.h"
#include "object.h"
#include "nodo.h"
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;

LinkedList::LinkedList(){
}

LinkedList::~LinkedList(){
	if(head){
		delete head;
	}
}

bool LinkedList::insert(object* e, int p){
	if(p < 0 || p > size){
		return false;
	}
	nodo* neo = new nodo(e);
	if(!head){
		head = neo;
	}else if(p==0){
		neo->next = head;
		head = neo;
	}else{
		nodo* temp = head;
		for (int i = 1; i < p; ++i){
			temp = temp -> next;

		}
		neo -> next = temp ->next;
		temp -> next = neo;
	}
	size++;
	return true;
}

object* LinkedList::remove(int p){
	if (p < 0 || p >= size){
        return 0;
	}
    nodo* temporal;
    if (p == 0){
    	temporal = head;
        head = temporal->next;
        object* retVal = temporal -> elemento;
       	//temporal ->elemento = 0;      
        delete temporal;
        temporal = 0;
        delete retVal;
        size--;
        return retVal;
    }else if (p == size-1){
        temporal = head;
        for (int i=1; i<p; i++){
           temporal = temporal->next;
        }
        object* retValDos = temporal ->next-> elemento;
        temporal -> next -> elemento = NULL;
        delete temporal ->next;
        temporal-> next = 0;
        size--;
        return retValDos;
    }else { 
        temporal = head;
        for (int i=1; i<p; i++){
           temporal = temporal -> next;
        }
        nodo* guardar = temporal->next->next;
        object* retValTres = temporal->next->elemento;
        temporal->next->elemento = 0;
        delete temporal ->next;
        temporal->next =0;
        temporal->next = guardar;
        size--;
        return retValTres;    
    }
}

object* LinkedList::first()const {
	if(head){
		return head -> elemento;
	}
	return 0;
}

object* LinkedList::last()const{
	if(head == 0){
		return 0;
	}
	nodo* temp = head;
	for (int i = 0; i < size; ++i){
		temp = temp->next;
	}
	return temp ->elemento;
	return 0;	
}



void LinkedList::clear(){
	if(head){
		delete head;
	}
	head = 0;
	size = 0;
}

int LinkedList::indexOf(object* e)const {
	nodo* temp = head;
    for (int i=0; i < size; i++){
        if (temp->elemento->equals(e)){
                return i;
        }
        temp = temp->next;
    }
	return -1;
}

object* LinkedList::get(int p){
	if (p < 0 || p >= size){
        return 0;
	}
    nodo* temp = head;
    for (int i=0; i < p; i++){
        temp = temp->next;
    }
    return temp->elemento;
}

int LinkedList::Capacity()const {
	return -1;
}

bool LinkedList::isEmpty()const {
	if (size == 0){
		return true;
	}
	return false;
}

bool LinkedList::isFull()const {
	return false;
}





