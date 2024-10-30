#pragma once
class Node
{
		int key;                       //����
		Node* prev, * next;     //������ ����������� � ���������� ����� 
	public:
		Node() 
		{ 
			key = 0;
			prev = nullptr;
			next = nullptr;
		} //����������� �� ���������
		Node(int k, Node* pr, Node* nxt)         //����������� � �����������
		{
			key = k; prev = pr; next = nxt;
		}
		int Key() { return key; }
		//��� �������� ������� prev � next
		friend class List;
};
class List
{
	Node* head, * tail;           //������ �� ���� ������� � ���� ������

public:
	//�� ��������� ������ �� ���� �����
	List();
	//������������ ������ �� n ��������� ��������� 
	List(int n);
	//������������ ������ �� n ����� � ������� � ���������� ������� � 
	List(int* a, int n);
	List(List& s);			//����������� �����������
   //����������; Clear � ������� ������
	~List();
	List& operator= (List& s);    //��������� ������
	void AddAfter(Node* p, int x);  //���������� ���� ����� ���������
	void AddToTail(int x);     //���������� �������� � �����
	void AddToHead(int x);	        //���������� �������� � ������
	void AddToTail(const List& other);	        //���������� ������ � �����
	void AddToHead(const List& other);        //���������� ������ � ������
	void Del(Node* p);       //�������� �������� �� ��������� p
	void DelTail();	        //�������� �������� � ������
	void DelHead();		                  //�������� ��������� ��������
	Node* FindKey(int key);		//����� � ������ �� �����
	Node* FindPos(int pos);		//����� � ������ �� �������
	bool Empty();			//�������� ������� ������
	void Clear();				//������� ������
	bool operator == (const List& other);	          //�������� ��������� �������
	Node* Max();				//���������� max ��-�� ������
	Node* Min();				//���������� min ��-�� ������
	void Scan(int n);			          //���� ������ �� n ���������
	void Print();				//������ ������
	friend ostream& operator << (ostream& r, List& X);
	friend istream& operator >> (istream& r, List& X);
};


