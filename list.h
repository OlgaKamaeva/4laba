#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	Node * pNext;
	T data;
//	Node<T> *temp;
	Node(T data = T(), Node *pNext = NULL)
	{
		this->data = data;
		this->pNext = pNext;
	}
};

template<typename T>
class List
{
    int Size;
	Node<T> *head;

public:
	List();
	~List();

	//удаление первого элемента в списке
	void deleteFirst();

	//добавление элемента в конец списка
	void insertLast(T data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	//добавление элемента в начало списка
	void insertFirst(T data);

	//добавление элемента в список по указанному индексу
	void insertAtPos(T data, int index);

	//удаление элемента в списке по указанному индексу
	void deleteAtPos (int index);

	//удаление последнего элемента в списке
	void deleteLast();

	// получить последний элемент в списке
	T getLast();

	// получить первый элемент в списке
	T getFirst();

	bool isContains (T value);

	bool isEmpty();

	void print();
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = NULL;
}
template<typename T>
List<T>::~List()
{
	clear();
}
template<typename T>
void List<T>::deleteFirst()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
template<typename T>
void List<T>::insertLast(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}
template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		deleteFirst();
	}
}

template<typename T>
void List<T>::insertFirst(T data)
{
	head = new Node<T>(data, head);
	Size++;
}
template<typename T>
void List<T>::insertAtPos(T data, int index)
{
	if (index == 0)
	{
		insertFirstv(data);
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T> *newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}
template<typename T>
void List<T>::deleteAtPos (int index)
{
	if (index == 0)
	{
		deleteFirst();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}
template<typename T>
void List<T>::deleteLast()
{
	deleteAtPos (Size - 1);
}
template<typename T>
T List<T>:: getFirst()
{
    if(head!=NULL)
        {
       return head->data;
        }

}
template<typename T>
T List<T>:: getLast()
{
    while(head!=NULL)
   	{
		Node<T> *current = this->head;
		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>;
	}
	return head->data;
}

template<typename T>
bool List<T>:: isContains (T value)
{
Node<T> *pt;
pt = head;
while (pt != NULL)
{
if (value == pt->data)
{
return true;
}
else
pt = pt->pNext;
}
return false;
}


template<typename T>
bool List<T>:: isEmpty()
{
if (head ==NULL)
{
    return true;
}
else
    return false;
}

template<typename T>
void  List<T>:: print()
{
if(Size != 0)
{
Node<T> * temp = head;
while(temp->pNext != 0)
{
cout << temp->data << ", ";
temp = temp->pNext;
}

cout << temp->data<<endl;
}
}
#endif // LIST_H_INCLUDED
