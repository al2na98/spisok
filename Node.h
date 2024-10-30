#pragma once
class Node
{
		int key;                       //ключ
		Node* prev, * next;     //адреса предыдущего и следующего узлов 
	public:
		Node() 
		{ 
			key = 0;
			prev = nullptr;
			next = nullptr;
		} //конструктор по умолчанию
		Node(int k, Node* pr, Node* nxt)         //конструктор с аргументами
		{
			key = k; prev = pr; next = nxt;
		}
		int Key() { return key; }
		//дл€ возврата адресов prev и next
		friend class List;
};
class List
{
	Node* head, * tail;           //ссылки на узел Ђголоваї и узел Ђхвостї

public:
	//по умолчанию список из двух узлов
	List();
	//формирование списка из n случайных элементов 
	List(int n);
	//формирование списка из n узлов с ключами Ц элементами массива а 
	List(int* a, int n);
	List(List& s);			//конструктор копировани€
   //деструктор; Clear Ц очистка списка
	~List();
	List& operator= (List& s);    //инициаци€ списка
	void AddAfter(Node* p, int x);  //добавление узла после заданного
	void AddToTail(int x);     //добавление элемента в хвост
	void AddToHead(int x);	        //добавление элемента в начало
	void AddToTail(const List& other);	        //добавление списка в хвост
	void AddToHead(const List& other);        //добавление списка в начало
	void Del(Node* p);       //удаление элемента по указателю p
	void DelTail();	        //удаление элемента с хвоста
	void DelHead();		                  //удаление головного элемента
	Node* FindKey(int key);		//поиск в списке по ключу
	Node* FindPos(int pos);		//поиск в списке по позиции
	bool Empty();			//проверка пустоты списка
	void Clear();				//очистка списка
	bool operator == (const List& other);	          //проверка равенства списков
	Node* Max();				//нахождение max эл-та списка
	Node* Min();				//нахождение min эл-та списка
	void Scan(int n);			          //ввод списка из n элементов
	void Print();				//печать списка
	friend ostream& operator << (ostream& r, List& X);
	friend istream& operator >> (istream& r, List& X);
};


