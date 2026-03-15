#include <iostream>


class Node {
public:
	int value;
	Node* next{ nullptr };
	Node* previous{ nullptr };

	Node(int val) : value(val) {}
};


class DoubleLinkedList {
private:
	Node* head;
	Node* tail;
	Node* defaultNode;
	int length;

public:
	DoubleLinkedList(int initialValue)
		: defaultNode(new Node(initialValue)), head(nullptr), tail(nullptr), length(1)
	{
		head = defaultNode;
		tail = defaultNode;
	}

	~DoubleLinkedList()
	{
		Node* temp;
		while (head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void append(int value)
	{
		Node* newNode{ new Node(value) };
		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		length++;
	}

	void deleteLast()
	{
		if (!length) { return; }
		Node* tempNode{ tail };
		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			tail = tail->previous;
			tail->next = nullptr;
		}
		delete tempNode;
		length--;
	}

	void prepend(int value)
	{
		//automatically increases length
		if (!length) { append(value); }
		else
		{
			Node* prependedNode{ new Node(value) };
			prependedNode->next = head;
			head->previous = prependedNode;
			head = prependedNode;
			length++;
		}
	}

	void deleteFirst()
	{
		if (!length) { return; }
		else if (length == 1)
		{
			//automatically decrements length
			deleteLast();
		}
		else
		{
			head = head->next;
			delete head->previous;
			head->previous = nullptr;
			length--;
		}
	}

	void printList()
	{
		Node* tempNode = head;
		while (tempNode)
		{
			std::cout << tempNode->value;
			tempNode = tempNode->next;
		}
		std::cout << '\n';
	}

	Node* getNode(int index)
	{
		if ((index >= 0) && (index < length))
		{
			if (index < length / 2)
			{
				Node* tempNode{ head };
				for (int i{ 0 }; i < index; i++)
				{
					tempNode = tempNode->next;
				}
				return tempNode;
			}
			else
			{
				Node* tempNode{ tail };
				for (int i{ 0 }; i < (length - index - 1); i++)
				{
					tempNode = tempNode->previous;
				}
				return tempNode;
			}
		}
	}

	bool setNode(int index, int val)
	{
		if (index >= 0 && index < length)
		{
			Node* tempNode{ head };
			// indexes from 0 up if index is closer to the head, from tail if not
			if (index < length / 2)
			{
				for (int i{ 0 }; i < index; i++)
				{
					tempNode = tempNode->next;
				}
				tempNode->value = val;
			}
			else
			{
				tempNode = tail;
				for (int i{ 0 }; i < (length - index - 1); i++)
				{
					tempNode = tempNode->previous;
				}
				tempNode->value = val;
			}
			
			return true;
		}
		else { return false; }
	}

	bool insertNode(int index, int val)
	{
		if ((index >= 0) && (index < length))
		{
			if (index == 0)
			{
				prepend(val);
			}
			else if (index == length)
			{
				append(val);
			}
			else
			{
				Node* tempNode{ head };
				if (index < length / 2)
				{
					for (int i{ 0 }; i < index; i++)
					{
						tempNode = tempNode->next;
					}
				}
				else
				{
					tempNode = tail;
					for (int i{ 0 }; i < (length - index - 1); i++)
					{
						tempNode = tempNode->previous;
					}
				}
				Node* newNode{ new Node(val) };
				newNode->next = tempNode->next;
				tempNode->next->previous = newNode;
				newNode->previous = newNode;
				tempNode->next = newNode;
				length++;
			}
			return true;
		}
		return false;
	}

	bool deleteNode(int index)
	{
		if (index == 0)
		{
			deleteFirst();
			return true;
		}
		else if (index == (length - 1))
		{
			deleteLast();
			return true;
		}
		else if ((index > 0) && (index < (length - 1)))
		{
			Node* tempNode{ head };
			if (index <= index / 2)
			{
				for (int i{ 0 }; i < index; i++)
				{
					tempNode = tempNode->next;
				}
			}
			else
			{
				tempNode = tail;
				for (int i{ 0 }; i < (length - index - 1); i++)
				{
					tempNode = tempNode->previous;
				}
			}
			tempNode->next->previous = tempNode->previous;
			tempNode->previous->next = tempNode->next;
			length--;
			delete tempNode;
			return true;
		}
		return false;
	}

	void partitionList(int x)
	{
		if (x > 0 && x < length && length > 1)
		{
			Node* smallStart{new Node(0)};
			Node* largeStart{ nullptr };
			Node* smallTemp{ nullptr };

			Node* tempNode{ head };
			Node* tempAfter{ nullptr };

			for (int i{ 0 }; i < length; i++)
			{
				tempAfter = tempNode->next;
				if (tempNode->value >= x)
				{
					if (!largeStart)
					{
						largeStart = tempNode;
					}
					tempNode = tempNode->next;
				}
				else
				{
					if (!tempNode->previous)
					{
						smallStart->next = tempNode;
						tempNode->previous = smallStart;
						tempNode->next->previous = nullptr;
						tempNode->next = nullptr;

						smallTemp = tempNode;
						head = tempNode;
						tempNode = tempAfter;
					}
					else if (tempNode->previous && tempNode->next)
					{
						if (!smallStart->next)
						{
							tempNode->previous->next = tempNode->next;
							tempNode->next->previous = tempNode->previous;

							smallStart->next = tempNode;
							tempNode->previous = smallStart;
							tempNode->next = nullptr;
							smallTemp = tempNode;

							head = tempNode;
							tempNode = tempAfter;
							continue;
						}
						tempNode->previous->next = tempNode->next;
						tempNode->next->previous = tempNode->previous;

						smallTemp->next = tempNode;
						tempNode->previous = smallTemp;
						tempNode->next = nullptr;

						smallTemp = tempNode;
						tempNode = tempAfter;
					}
					else if (!tempNode->next)
					{
						tempNode->previous->next = nullptr;
						smallTemp->next = tempNode;
						tempNode->previous = smallTemp;
						smallTemp = tempNode;
					}
				}
			}
			if (largeStart)
			{
				smallTemp->next = largeStart;
				largeStart->previous = smallTemp;
			}
			delete head->previous;
			head->previous = nullptr;
		}
	}

	void reverseBetween(int index1, int index2)
	{
		if ((index1 >= 0 && index1 < length) && (index2 >= 0 && index2 < length))
		{
			Node* temp{ head };
			Node* tempAfter{ head };

			Node* start{ nullptr };
			Node* end{ nullptr };
			Node* reverseStart{ nullptr };
			Node* reverseEnd{ nullptr };

			for (int i{ 0 }; i < index1; i++)
			{
				temp = temp->next;
			}

			start = temp->previous;
			reverseStart = temp;
			tempAfter = temp;

			for (int i{ 0 }; i < (index2 - index1 + 1 ); i++)
			{
				temp = tempAfter;
				tempAfter = temp->next;
				temp->next = temp->previous;
				temp->previous = tempAfter;
			}

			reverseEnd = temp;
			end = temp->previous;

			if (start && end)
			{
				reverseStart->next = end;
				end->previous = reverseStart;
				reverseEnd->previous = start;
				start->next = reverseEnd;
			}
			else if (!(start || end))
			{
				head = reverseEnd;
				tail = reverseStart;
			}
			else if (!start && end)
			{
				reverseStart->next = end;
				end->previous = reverseStart;
				reverseEnd->previous = nullptr;
				head = reverseEnd;
			}
			else if (start && !end)
			{
				reverseEnd->previous = start;
				start->next = reverseEnd;
				reverseStart->next = nullptr;
				tail = reverseStart;
			}
		}
	}

	void swapPairs()
	{
		if (length > 2)
		{
			Node* one{ head };
			Node* two{ one->next };
			Node* three{ two->next };
			Node* ghost{ nullptr };

			head = two;

			while (two)
			{
				two->previous = one->previous;
				two->next = one;
				one->previous = two;
				one->next = three;
				if (three) { three->previous = one; }
				one = one->previous;
				two = two->next;

				if (ghost)
				{
					ghost->next = one;
					one->previous = ghost;
				}
				
				ghost = two;

				if (three && three->next)
				{
					one = three;
					two = three->next;
					three = three->next->next;
				}
				else { break; }
			}
		}
	}
};

int main()
{

}