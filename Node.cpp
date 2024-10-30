#include "Node.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
List::List()
{
	head = new Node;
	tail = new Node(-1, head, 0);
	head->next = tail;
    head->prev = nullptr;
 }
List::List(int n)
{
	head = new Node;
	tail = new Node(-1, head, 0);
	head->next = tail;
    head->prev = nullptr;
	for (int i = 0; i <= n; i++)
	{
		int x = rand() % 100;
		AddToTail(x);
	}
}
List::List(int* a, int n)
{
	head = new  Node;
	tail = new  Node(-1, head, 0);
	head->next = tail;
	for (int i = 0; i < n; i++)
	{
		AddToTail(a[i]);
	}
}
List::~List()
{
	Clear();
	delete head;
	delete tail;
}
List::List(List& s)
{
	head = new  Node;
	tail = new  Node(-1, head, 0);
	head->next = tail;
    head->prev = nullptr;
	Node* q = s.head->next;
	while (q != s.tail)
	{
		AddToTail(q->key);
		q = q->next;
	}
}
List& List::operator= (List& s)
{
	if (this != &s)
	{
		Clear();
		Node* q = s.head->next;
		while (q != s.tail) 
		{
			AddToTail(q->key); 
			q = q->next;
		}
	}
	return *this;
}

// ����� ������� ������
void List::Clear() {
    while (!Empty()) {
        DelHead(); // ������� �������� � ������
    }
}

// �������� ������� ������
bool List::Empty() {
    return head == nullptr; // ���� ������ ����� nullptr, ������ ����
}

// ���������� ���� � �����
void List::AddToTail(int x) {
    Node* newNode = new Node(x, tail->prev, tail); // ������� ����� ����
    if (tail->prev != nullptr) { // ���������, ��� ������ �� ����
        tail->prev->next = newNode; // ��������� ���������� ���� � �����
    }
    tail->prev = newNode; // ��������� prev ��� tail
    newNode->next = tail; // ��������� next ��� ������ ����
}

// ���������� ���� � ������
void List::AddToHead(int x) {
    Node* newNode = new Node(x, nullptr, head); // ������� ����� ����
    if (head) {
        head->prev = newNode; // ��������� ����� ���� � �������
    }
    else {
        tail = newNode; // ���� ������ ����, ����� ���� ���������� �������
    }
    head = newNode; // ��������� ������
}
void List::AddAfter(Node* p, int x) {
    if (p == nullptr || p == tail) return; // ���� ���� ���� ��� ��� tail, ������ �� ������
    Node* newNode = new Node(x, p, p->next); // ������� ����� ����
    p->next->prev = newNode; // ��������� ��������� ���� � �����
    p->next = newNode; // ��������� next ��� ���� p
}

void List::AddToTail(const List& other) {
    Node* current = other.head->next; // �������� � ������� ���� ������� ������
    while (current != other.tail) {
        AddToTail(current->key); // ��������� ������ ������� � �����
        current = current->next;
    }
}

void List::AddToHead(const List& other) {
    Node* current = other.tail->prev; // �������� � ���������� ���� ������� ������
    while (current != other.head) {
        AddToHead(current->key); // ��������� ������ ������� � ������
        current = current->prev;
    }
}

// �������� ���� �� ���������
void List::Del(Node* p) {
    if (p == nullptr) return; // ���� ���� ����, ������ �� ������
    if (p->prev) {
        p->prev->next = p->next; // ��������� ���������� ���� � ���������
    }
    else {
        head = p->next; // ���� ������� ������, ��������� ������
    }
    if (p->next) {
        p->next->prev = p->prev; // ��������� ��������� ���� � ����������
    }
    else {
        tail = p->prev; // ���� ������� �����, ��������� �����
    }
    delete p; // ������� ����
}

// �������� �������� � ������
void List::DelTail() {
    if (tail) {
        Del(tail); // ������� �����
    }
}

// �������� �������� � ������
void List::DelHead() {
    if (head) {
        Del(head); // ������� ������
    }
}

// ����� ���� �� �����
Node* List::FindKey(int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->Key() == key) {
            return current; // ���������� ����, ���� ������
        }
        current = current->next;
    }
    return nullptr; // ���� �� ������, ���������� nullptr
}

// ����� ���� �� �������
Node* List::FindPos(int pos) {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (index == pos) {
            return current; // ���������� ���� �� �������
        }
        current = current->next;
        index++;
    }
    return nullptr; // ���� ������� ��� ���������, ���������� nullptr
}

// ���������� ������������� �������� ������
Node* List::Max() {
    if (Empty()) return nullptr; // ���� ������ ����, ���������� nullptr
    Node* current = head;
    Node* maxNode = head;
    while (current != nullptr) {
        if (current->Key() > maxNode->Key()) {
            maxNode = current; // ��������� ������������ ����
        }
        current = current->next;
    }
    return maxNode; // ���������� ���� � ������������ ���������
}

// ���������� ������������ �������� ������
Node* List::Min() {
    if (Empty()) return nullptr; // ���� ������ ����, ���������� nullptr
    Node* current = head;
    Node* minNode = head;
    while (current != nullptr) {
        if (current->Key() < minNode->Key()) {
            minNode = current; // ��������� ����������� ����
        }
        current = current->next;
    }
    return minNode; // ���������� ���� � ����������� ���������
}
bool List::operator==(const List& other)
{
    Node* current1 = head->next;
    Node* current2 = other.head->next;

    while (current1 != tail && current2 != other.tail) {
        if (current1->key != current2->key) {
            return false; // ���� ����� �� �����, ������ �� �����
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1 == tail && current2 == other.tail; // ���������, ��� ��� ������ �������� �����
}

// ���� ������ �� n ���������
void List::Scan(int n) {
    Clear(); // ������� ������� ������
    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "������� ������� " << i + 1 << ": ";
        std::cin >> value; // ���� ��������
        AddToTail(value); // ��������� ������� � �����
    }
}

// ������ ������
void List::Print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->Key() << " "; // ����� ����� ����
        current = current->next; // ������� � ���������� ����
    }
    std::cout << std::endl; // ������� �� ����� ������
}
 //�������� ������
std::ostream& operator<<(std::ostream& r, List& X) {
    X.Print(); // ���������� ����� Print ��� ������
    return r;
}

// �������� �����
std::istream& operator>>(std::istream& r, List& X) {
    int n;
    std::cout << "������� ���������� ���������: ";
    r >> n; // ���� ���������� ���������
    X.Scan(n); // ���������� ����� Scan ��� �����
    return r;
}



