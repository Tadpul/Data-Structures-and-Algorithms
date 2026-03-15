#include <iostream>

class Node {
public:
	int value;
	Node* next;

	Node(int value)
	{
		this->value = value;
		next = nullptr;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int numOfNodes;

public:
	LinkedList(int value)
	{
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		numOfNodes = 1;
	}

	~LinkedList()
	{
		Node* temp = head;
		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}

	}

	void append(int value)
	{
		Node* node = new Node(value);
		if (numOfNodes == 0)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
		numOfNodes++;
	}

	void removeLastNode()
	{
		if (numOfNodes == 0)
		{
			return;
		}
		else if (numOfNodes == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			numOfNodes--;
		}
		else
		{
			tail = head;
			while (tail->next->next != nullptr)
			{
				tail = tail->next;
			}
			delete tail->next;
			tail->next = nullptr;
			numOfNodes--;
		}
	}

	Node* getNode(int index)
	{
		if (index >= 0 && index < numOfNodes)
		{
			Node* tempNode = head;
			for (int i{ 0 }; i < index; i++)
			{
				tempNode = tempNode->next;
			}
			return tempNode;
		}
		return nullptr;
	}

	void prependNode(int value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		numOfNodes++;

		if (numOfNodes == 1)
		{
			tail = newNode;
		}
	}

	bool setNode(int index, int val)
	{
		if (index >= 0 && index < numOfNodes)
		{
			Node* tempNode = getNode(index);
			tempNode->value = val;
			return true;
		}
		return false;
	}

	bool insertNode(int index, int val)
	{

		if (index >= 0 && index < numOfNodes)
		{
			if (index == numOfNodes)
			{
				append(val);
				return true;
			}
			else if (index == 0)
			{
				prependNode(val);
				return true;
			}

			Node* newNode = new Node(val);
			Node* tempNode = getNode(index - 1);
			newNode->next = tempNode->next;
			tempNode->next = newNode;
			numOfNodes++;
			return true;
		}
		return false;
	}

	bool deleteNode(int index)
	{
		if (index == (numOfNodes - 1))
		{
			removeLastNode();
			return true;
		}
		else if (index == 0)
		{
			if (numOfNodes == 1)
			{
				removeLastNode();
				return true;
			}

			Node* tempNode = head;
			head = head->next;
			delete tempNode;
			numOfNodes--;
			return true;
		}
		else if (index > 0 && index < numOfNodes - 1)
		{
			Node* tempNode = getNode(index - 1);
			Node* tempNode2 = tempNode->next;

			tempNode->next = tempNode2->next;
			delete tempNode2;
			
			numOfNodes--;
			return true;
		}
		return false;
	}

	void reverseList()
	{
		Node* tempNode{ head };
		head = tail;
		tail = tempNode;

		Node* before{ nullptr };
		Node* after{nullptr};
		for (int i{ 0 }; i < numOfNodes; i++)
		{	
			after = tempNode->next;
			tempNode->next = before;
			before = tempNode;
			tempNode = after;
		}
	}

	Node* getMiddle()
	{
		Node* slow{ head };
		Node* fast{ head };

		while (fast)
		{
			if (fast->next)
			{
				{
					fast = fast->next->next;
					slow = slow->next;
				}
			}
			else
			{
				break;
			}
		}
		return slow;
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

	int binaryToDecimal()
	{

		Node* temp{ head };
		while (temp)
		{
			if (temp->value == 0)
			{
				temp = temp->next;
				continue;
			}
			else
			{
				int decimal{ 0 };
				while (temp)
				{
					decimal *= 2;
					if (temp->value == 1)
					{
						decimal += 1;
					}
					
					temp = temp->next;
				}
				return decimal;
			}
			return 0;
		}
	}

	void partitionList(int x)
	{
		bool smallStartFound{ false };
		bool largeStartFound{ false };
		Node* largeHead{ nullptr };
		Node* smallHead{ nullptr };

		Node* tempLarge{ head }; 
		Node* tempSmall{ head };
		Node* temp{ head };

		while (temp)
		{
			if (temp->value < 3)
			{
				if (!smallStartFound)
				{
					smallHead = temp;
					tempSmall = temp;
					smallStartFound = true;
				}
				else
				{
					tempSmall->next = temp;
					tempSmall = temp;
				}
				
			}
			if (temp->value >= 3)
			{
				if (!largeStartFound)
				{
					tempLarge = temp;
					largeHead = temp;
					largeStartFound = true;
				}
				else
				{
					tempLarge->next = temp;
					tempLarge = temp;
				}
			}
			temp = temp->next;
		}
		if (!largeStartFound)
		{
			head = smallHead;
			tail = tempSmall;
			return;
		}
		else if (!smallStartFound)
		{
			head = largeHead;
			tail = tempLarge;
			return;
		}

		head = smallHead;
		tempSmall->next = largeHead;
		tempLarge->next = nullptr;
		tail = tempLarge;
	}

	void reverseBetween(int index1, int index2)
	{
		if ((index2 < numOfNodes) && head && (index1 != index2))
		{
			Node* start{ nullptr };
			Node* end{ nullptr };

			Node* startReverse{ nullptr };
			Node* endReverse{ nullptr };

			Node* current{ head };
			for (int i{ 0 }; i < index1; i++)
			{
				if (i == (index1 - 1))
				{
					start = current;
				}
				current = current->next;
			}
			startReverse = current;

			Node* before{ nullptr };
			Node* after{ current->next };

			for (int i{ 0 }; i < (index2 - index1 + 1); i++)
			{
				current->next = before;
				std::cout << current->value << " points to " << before << '\n';
				before = current;
				current = after;
				if (after)
				{
					after = after->next;
				}
			}
			endReverse = before;
			end = current;

			if ((index1 == 0) && (index2 == (numOfNodes - 1)))
			{
				head = endReverse;
			}
			else if (index1 == 0)
			{
				startReverse->next = end;
				head = endReverse;
			}
			else if (index2 == (numOfNodes - 1))
			{
				start->next = endReverse;
				startReverse = nullptr;
			}
			else
			{
				start->next = endReverse;
				startReverse->next = end;
			}
		}
	}

	void swapPairs()
	{
		if (numOfNodes == 2)
		{
			Node* temp{ head->next };
			head->next->next = head;
			head->next = nullptr;
			head = temp;
			tail = head->next;
		}
		else if (numOfNodes >= 3)
		{
			Node* first{ head };
			Node* second{ first->next };
			Node* third{ second->next };
			Node* ghost{ nullptr };

			bool firstIteration{ true };

			while (first && second)
			{
				if (firstIteration)
				{
					Node* temp{ head->next };
					head->next->next = head;
					head->next = third;
					head = temp;
					firstIteration = false;

					ghost = first;
					first = third;
					second = first->next;
					if (second) { third = second->next; }
				}
				else
				{
					ghost->next = second;
					second->next = first;
					first->next = third;

					ghost = first;
					first = third;
					if (first) { second = first->next; }
					if (second) { third = second->next; } 
				}
			}
			if (first) { tail = first; }
			else { tail = second; }
		}
	}

	void getHead() { std::cout << head->value << '\n'; }
	void getTail() { std::cout << tail->value << '\n'; }
	void getLength() { std::cout << numOfNodes << '\n'; }
};

int main()
{
	
}