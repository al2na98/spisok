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

// Метод очистки списка
void List::Clear() {
    while (!Empty()) {
        DelHead(); // Удаляем элементы с головы
    }
}

// Проверка пустоты списка
bool List::Empty() {
    return head == nullptr; // Если голова равна nullptr, список пуст
}

// Добавление узла в хвост
void List::AddToTail(int x) {
    Node* newNode = new Node(x, tail->prev, tail); // Создаем новый узел
    if (tail->prev != nullptr) { // Проверяем, что список не пуст
        tail->prev->next = newNode; // Связываем предыдущий узел с новым
    }
    tail->prev = newNode; // Обновляем prev для tail
    newNode->next = tail; // Обновляем next для нового узла
}

// Добавление узла в голову
void List::AddToHead(int x) {
    Node* newNode = new Node(x, nullptr, head); // Создаем новый узел
    if (head) {
        head->prev = newNode; // Связываем новый узел с головой
    }
    else {
        tail = newNode; // Если список пуст, новый узел становится хвостом
    }
    head = newNode; // Обновляем голову
}
void List::AddAfter(Node* p, int x) {
    if (p == nullptr || p == tail) return; // Если узел пуст или это tail, ничего не делаем
    Node* newNode = new Node(x, p, p->next); // Создаем новый узел
    p->next->prev = newNode; // Связываем следующий узел с новым
    p->next = newNode; // Обновляем next для узла p
}

void List::AddToTail(const List& other) {
    Node* current = other.head->next; // Начинаем с первого узла другого списка
    while (current != other.tail) {
        AddToTail(current->key); // Добавляем каждый элемент в хвост
        current = current->next;
    }
}

void List::AddToHead(const List& other) {
    Node* current = other.tail->prev; // Начинаем с последнего узла другого списка
    while (current != other.head) {
        AddToHead(current->key); // Добавляем каждый элемент в голову
        current = current->prev;
    }
}

// Удаление узла по указателю
void List::Del(Node* p) {
    if (p == nullptr) return; // Если узел пуст, ничего не делаем
    if (p->prev) {
        p->prev->next = p->next; // Связываем предыдущий узел с следующим
    }
    else {
        head = p->next; // Если удаляем голову, обновляем голову
    }
    if (p->next) {
        p->next->prev = p->prev; // Связываем следующий узел с предыдущим
    }
    else {
        tail = p->prev; // Если удаляем хвост, обновляем хвост
    }
    delete p; // Удаляем узел
}

// Удаление элемента с хвоста
void List::DelTail() {
    if (tail) {
        Del(tail); // Удаляем хвост
    }
}

// Удаление элемента с головы
void List::DelHead() {
    if (head) {
        Del(head); // Удаляем голову
    }
}

// Поиск узла по ключу
Node* List::FindKey(int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->Key() == key) {
            return current; // Возвращаем узел, если найден
        }
        current = current->next;
    }
    return nullptr; // Если не найден, возвращаем nullptr
}

// Поиск узла по позиции
Node* List::FindPos(int pos) {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (index == pos) {
            return current; // Возвращаем узел по позиции
        }
        current = current->next;
        index++;
    }
    return nullptr; // Если позиция вне диапазона, возвращаем nullptr
}

// Нахождение максимального элемента списка
Node* List::Max() {
    if (Empty()) return nullptr; // Если список пуст, возвращаем nullptr
    Node* current = head;
    Node* maxNode = head;
    while (current != nullptr) {
        if (current->Key() > maxNode->Key()) {
            maxNode = current; // Обновляем максимальный узел
        }
        current = current->next;
    }
    return maxNode; // Возвращаем узел с максимальным значением
}

// Нахождение минимального элемента списка
Node* List::Min() {
    if (Empty()) return nullptr; // Если список пуст, возвращаем nullptr
    Node* current = head;
    Node* minNode = head;
    while (current != nullptr) {
        if (current->Key() < minNode->Key()) {
            minNode = current; // Обновляем минимальный узел
        }
        current = current->next;
    }
    return minNode; // Возвращаем узел с минимальным значением
}
bool List::operator==(const List& other)
{
    Node* current1 = head->next;
    Node* current2 = other.head->next;

    while (current1 != tail && current2 != other.tail) {
        if (current1->key != current2->key) {
            return false; // Если ключи не равны, списки не равны
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1 == tail && current2 == other.tail; // Проверяем, что оба списка достигли конца
}

// Ввод списка из n элементов
void List::Scan(int n) {
    Clear(); // Очищаем текущий список
    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Введите элемент " << i + 1 << ": ";
        std::cin >> value; // Ввод значений
        AddToTail(value); // Добавляем элемент в хвост
    }
}

// Печать списка
void List::Print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->Key() << " "; // Вывод ключа узла
        current = current->next; // Переход к следующему узлу
    }
    std::cout << std::endl; // Переход на новую строку
}
 //Оператор вывода
std::ostream& operator<<(std::ostream& r, List& X) {
    X.Print(); // Используем метод Print для вывода
    return r;
}

// Оператор ввода
std::istream& operator>>(std::istream& r, List& X) {
    int n;
    std::cout << "Введите количество элементов: ";
    r >> n; // Ввод количества элементов
    X.Scan(n); // Используем метод Scan для ввода
    return r;
}



