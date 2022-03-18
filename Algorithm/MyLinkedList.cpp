#include <iostream>
using namespace std;

class Node
{
public:
	Node() : _next(nullptr), _data(0)
	{

	}

	Node(const int& value) : _next(nullptr), _data(value)
	{

	}

public:
	int		_data;
	Node*	_next;
};

class LinkedList
{
public:
	LinkedList(): _size(0)
	{
		_head = new Node;

		_head->_next = nullptr;
	}

	~LinkedList()
	{
		while (_size > 0)
		{
			remove();
		}
		delete _head;
	}

	void Insert(int value, int index = 0)
	{
		Node* newNode = new Node(value);

		Node* curNode = nullptr;
		Node* prevNode = nullptr;

		if (index == 0)
		{
			if(_head->_next == nullptr)
				_head->_next = newNode;
			else
			{
				curNode = _head->_next;
				_head->_next = newNode;
				newNode->_next = curNode;
			}
		}
		else
		{
			if (index > _size)
				return;

			int cnt = 0;
			prevNode = _head;
			curNode = _head;

			while (cnt <= index)
			{
				prevNode = curNode;
				curNode = curNode->_next;
				cnt++;
			}

			prevNode->_next = newNode;
			newNode->_next = curNode;
		}

		++_size;
	}

	void remove(int index = 0)
	{
		Node* delNode = nullptr;
		Node* nextNode = nullptr;

		if (index == 0)
		{
			delNode = _head->_next;
			nextNode = delNode->_next;

			_head->_next = nextNode;
			delete delNode;
		}

		--_size;
	}

	void printAll()
	{
		Node* curNode = _head;
		while (curNode->_next != nullptr)
		{
			curNode = curNode->_next;
			cout << curNode->_data << " ";
		}
	}

private:


public:
	int _size;
	Node* _head;
};

int main()
{
	LinkedList ll;

	ll.Insert(3);
	ll.Insert(2);
	ll.Insert(1);
	ll.Insert(5);
	ll.Insert(4);
	ll.Insert(0, 6);

	ll.printAll();
}