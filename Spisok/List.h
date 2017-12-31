#pragma once

#include <iostream>
#include <string>
#include <set>
#include "Struct.h"


using namespace std;

template< typename T >
class List;

template< typename T >
bool operator==(const List< T > &, const List< T > &);
template< typename T >
bool operator!=(const List< T > &, const List< T > &);

bool operator<(const Struct  &left, const  Struct  &right);

template< typename T >
class List
{
	struct Node
	{
		Node(const T &data) :
			m_data(data),
			m_next(),
			m_prev()
		{
		}

		T m_data;
		Node *m_next;
		Node *m_prev;
	};

public:
	List() :
		m_head(),
		m_tail(),
		m_size()
	{
	}

	List(const List &source) :
		m_head(),
		m_tail(),
		m_size()
	{
		Node *i = source.m_head;

		while (i != 0)
		{
			push_back(i->m_data);

			i = i->m_next;
		}
	}

	~List()
	{
		clear();
	}

	//Количество элементов
	size_t size() const
	{
		return m_size;
	}
	//Пустой ли список?
	bool is_empty() const
	{
		return m_size == 0;
	}
	//Очистка списка
	void clear()
	{
		while (m_size != 0)
			pop_back();
	}

	//Добавление в конец списка
	void push_back(const T &data)
	{
		Node *add_elem = new Node(data);

		if (m_size == 0)
		{
			m_head = add_elem;
		}
		else
		{
			m_tail->m_next = add_elem;
			add_elem->m_prev = m_tail;
		}

		m_tail = add_elem;

		++m_size;
	}
	//Удаление последнего элемента
	T pop_back()
	{
		if (m_size == 0)
			return T();

		T ret_elem = m_tail->m_data;
		Node *new_tail = m_head == m_tail ? 0 : m_tail->m_prev;
		if(new_tail != NULL)
		new_tail->m_next = NULL;

		delete m_tail;

		if (m_head == m_tail)
			m_head = 0;

		m_tail = new_tail;

		--m_size;

		return ret_elem;
	}


	//Добавление в начало списка
	void push_front(const T &data)
	{
		Node *add_elem = new Node(data);

		if (m_size == 0)
		{
			m_tail = add_elem;
		}
		else
		{
			m_head->m_prev = add_elem;
			add_elem->m_next = m_head;
		}

		m_head = add_elem;

		++m_size;
	}
	//Удаление первого элемента списка
	T pop_front()
	{
		if (m_size == 0)
			return T();

		T ret_elem = m_head->m_data;
		Node *new_head = m_head == m_tail ? 0 : m_head->m_next;

		delete m_head;

		if (m_head == m_tail)
			m_tail = 0;

		m_head = new_head;

		--m_size;

		return ret_elem;
	}

	//Вывод на экран
	void print()
	{
		Node *m_head2  = m_head;

		if (m_size == 0) {
			cout << "Spisok empty\n";
		}else {
			do {
				T ret_elem = m_head2->m_data;
				cout << ret_elem << ' ';
				m_head2 = m_head2->m_next; // переход к следующему узлу
			} while (m_head2 != NULL); // условие окончания обхода
		}
		cout << endl;
	}

	

	//Сортировка списка
	void sort()
	{

		Node *t;
		T x;
		//cout<<"h="<<h;
		t = m_head->m_next;
		while (t) {
			x = t->m_data;
			//cout << "x=" <<x<<endl;
			Node *b = t->m_prev;
			while (b != NULL && x < b->m_data)
			{
				b->m_next->m_data = b->m_data;
				b = b->m_prev;
			}
			if (b == NULL) m_head->m_data = x;
			else b->m_next->m_data = x;
			t = t->m_next;

		}
	}

	// Вывести количество различных значений в списке
	int getSizeIcluzive()
	{

		set<T> mySet; // объявили пустое множество

		Node *m_head2 = m_head;


		do {
			T ret_elem = m_head2->m_data;
			mySet.insert(ret_elem);
			m_head2 = m_head2->m_next; // переход к следующему узлу
		} while (m_head2 != NULL); // условие окончания обхода



		return mySet.size();
	}


	//реверс списка
	void reverse() {
		Node*t, *p = m_head, *h = NULL;
		while (p != NULL) {
			t = p;
			p = p->m_next;

			t->m_next = h;
			h = t;
		}
		m_head = h;
	}


	//Удаление из списка тех элементов, значение которых уже встречалось
	void deletSpicokPovtor()
	{
		set<T> mySet; // объявили пустое множество
		set<T>::iterator si;
		Node *m_head2 = m_head;

		m_head = NULL;
		m_tail = NULL;
		m_size = 0;


		do {
			T ret_elem = m_head2->m_data;
			if (mySet.count(ret_elem));
			else
			{
				mySet.insert(ret_elem);
				push_back(ret_elem);
			}
		
			m_head2 = m_head2->m_next; // переход к следующему узлу
		} while (m_head2 != NULL); // условие окончания обхода
	}

	
	bool proverka_Semmitria()
	{
		Node *m_head2 = m_head, *m_tail2 = m_tail;

		if (m_size == 1)
			return true;
		else {
			int n = m_size / 2;
			//int m = m_size % 2; // получение остатка

			for (int i = 0; i < n; i++)
			{
				T ret_elem = m_head2->m_data;
				T ret_elem2 = m_tail2->m_data;
				if (ret_elem != ret_elem2)
					return false;

				m_head2->m_next;
				m_tail2->m_prev;
			}

			return true;
		}
	 }

	bool proverka_Yporyad()
	{
		Node *m_head2 = m_head;

		int n = 0;
		T chislo = m_head2->m_data;

		do {
			T ret_elem = m_head2->m_data;
			if (chislo > ret_elem)
				n++;
			else
				chislo = ret_elem;

			m_head2 = m_head2->m_next; // переход к следующему узлу
		} while (m_head2 != NULL); // условие окончания обхода

		if (n > 2)
			return false;
		return true;
	}





	friend bool operator==< >(const List< T > &left, const List< T > &right);
	friend bool operator!=< >(const List< T > &left, const List< T > &right);

	List &operator=(const List &source)
	{
		if (this != &source)
		{
			clear();

			Node *i = source->m_head;

			while (i != source->m_tail)
			{
				push_back(i->m_data);

				i = i->m_next;
			}
		}

		return *this;
	}

private:
	Node *m_head;
	Node *m_tail;
	size_t m_size;
};


//Явная специализация шаблона Struct
template<>
class List<Struct>
{
	struct Node
	{
		Node(const Struct &data) :
			m_data(data),
			m_next(),
			m_prev()
		{
		}

		Struct m_data;
		Node *m_next;
		Node *m_prev;
	};

public:
	List() :
		m_head(),
		m_tail(),
		m_size()
	{
	}

	List(const List &source) :
		m_head(),
		m_tail(),
		m_size()
	{
		Node *i = source.m_head;

		while (i != 0)
		{
			push_back(i->m_data);

			i = i->m_next;
		}
	}

	~List()
	{
		clear();
	}

	//Количество элементов
	size_t size() const
	{
		return m_size;
	}
	//Пустой ли список?
	bool is_empty() const
	{
		return m_size == 0;
	}
	//Очистка списка
	void clear()
	{
		while (m_size != 0)
			pop_back();
	}

	//Добавление в конец списка
	void push_back(const Struct &data)
	{
		Node *add_elem = new Node(data);

		if (m_size == 0)
		{
			m_head = add_elem;
		}
		else
		{
			m_tail->m_next = add_elem;
			add_elem->m_prev = m_tail;
		}

		m_tail = add_elem;

		++m_size;
	}
	//Удаление последнего элемента
	Struct pop_back()
	{
		if (m_size == 0)
			return Struct();

		Struct ret_elem = m_tail->m_data;
		Node *new_tail = m_head == m_tail ? 0 : m_tail->m_prev;
		if (new_tail != NULL)
			new_tail->m_next = NULL;

		delete m_tail;

		if (m_head == m_tail)
			m_head = 0;

		m_tail = new_tail;

		--m_size;

		return ret_elem;
	}


	//Добавление в начало списка
	void push_front(const Struct &data)
	{
		Node *add_elem = new Node(data);

		if (m_size == 0)
		{
			m_tail = add_elem;
		}
		else
		{
			m_head->m_prev = add_elem;
			add_elem->m_next = m_head;
		}

		m_head = add_elem;

		++m_size;
	}
	//Удаление первого элемента списка
	Struct pop_front()
	{
		if (m_size == 0)
			return Struct();

		Struct ret_elem = m_head->m_data;
		Node *new_head = m_head == m_tail ? 0 : m_head->m_next;

		delete m_head;

		if (m_head == m_tail)
			m_tail = 0;

		m_head = new_head;

		--m_size;

		return ret_elem;
	}

	//Вывод на экран
	void print()
	{
		Node *m_head2 = m_head;
		if (m_size == 0)
			cout << "Spisok empty\n";
		else {
			cout << "LIST\n";
			do {
				Struct ret_elem = m_head2->m_data;
				cout << ret_elem.chislo << ' ' << ret_elem.date << "\n";
				m_head2 = m_head2->m_next; // переход к следующему узлу
			} while (m_head2 != NULL); // условие окончания обхода

			cout << "\n";
		}
		cout << endl;
	}



	//Сортировка списка
	void sort()
	{

		Node *t;
		int x;
		//cout<<"h="<<h;
		t = m_head->m_next;
		while (t) {
			x = t->m_data.chislo;
			//cout << "x=" <<x<<endl;
			Node *b = t->m_prev;
			while (b != NULL && x < b->m_data.chislo)
			{
				b->m_next->m_data = b->m_data;
				b = b->m_prev;
			}
			if (b == NULL) m_head->m_data.chislo = x;
			else b->m_next->m_data.chislo = x;
			t = t->m_next;

		}
	}

	// Вывести количество различных значений в списке
	int getSizeIcluzive()
	{

		set<Struct> mySet; // объявили пустое множество

		Node *m_head2 = m_head;


		do {
			Struct ret_elem = m_head2->m_data;
			mySet.insert(ret_elem);
			m_head2 = m_head2->m_next; // переход к следующему узлу
		} while (m_head2 != NULL); // условие окончания обхода



		return mySet.size();
	}


	//реверс списка
	void reverse() {
		Node*t, *p = m_head, *h = NULL;
		while (p != NULL) {
			t = p;
			p = p->m_next;

			t->m_next = h;
			h = t;
		}
		m_head = h;
	}


	//Удаление из списка тех элементов, значение которых уже встречалось
	void deletSpicokPovtor()
	{
		set<Struct> mySet; // объявили пустое множество
		set<Struct>::iterator si;
		Node *m_head2 = m_head;

		m_head = NULL;
		m_tail = NULL;
		m_size = 0;


		do {
			Struct ret_elem = m_head2->m_data;
			if (mySet.count(ret_elem));
			else
			{
				mySet.insert(ret_elem);
				push_back(ret_elem);
			}

			m_head2 = m_head2->m_next; // переход к следующему узлу
		} while (m_head2 != NULL); // условие окончания обхода
	}


	bool proverka_Semmitria()
	{
		Node *m_head2 = m_head, *m_tail2 = m_tail;

		if (m_size == 1)
			return true;
		else {
			int n = m_size / 2;
			//int m = m_size % 2; // получение остатка

			for (int i = 0; i < n; i++)
			{
				Struct ret_elem = m_head2->m_data;
				Struct ret_elem2 = m_tail2->m_data;
				if (ret_elem.chislo != ret_elem2.chislo)
					return false;

				m_head2->m_next;
				m_tail2->m_prev;
			}

			return true;
		}
	}

	bool proverka_Yporyad()
	{
		Node *m_head2 = m_head;

		int n = 0;
		Struct chislo = m_head2->m_data;

		do {
			Struct ret_elem = m_head2->m_data;
			if (chislo.chislo > ret_elem.chislo)
				n++;
			else
				chislo = ret_elem;

			m_head2 = m_head2->m_next; // переход к следующему узлу
		} while (m_head2 != NULL); // условие окончания обхода

		if (n > 2)
			return false;
		return true;
	}

	friend bool operator==< >(const List< Struct > &left, const List< Struct > &right);
	friend bool operator!=< >(const List< Struct > &left, const List< Struct > &right);
	friend bool operator<(const Struct  &left, const Struct &right) 
	{
		if (left.chislo < right.chislo) return true;
		else return false;
	}

	List &operator=(const List *source)
	{
		if (this != source)
		{
			clear();

			Node *i = source->m_head;

			while (i != source->m_tail)
			{
				push_back(i->m_data);

				i = i->m_next;
			}
		}

		return *this;
	}

private:
	Node *m_head;
	Node *m_tail;
	size_t m_size;
};





template< typename T >
bool operator==(const List< T > &left, const List< T > &right)
{
	if (left.m_size != right.m_size)
		return false;

	List< T >::Node *p_left = left.m_head;
	List< T >::Node *p_right = right.m_head;

	while (p_left != left.m_tail)
	{
		if (p_left->m_data != p_right->m_data)
			return false;

		p_left = p_left->m_next;
		p_right = p_right->m_next;
	}

	return true;
}

template< typename T >
bool operator!=(const List< T > &left, const List< T > &right)
{
	return !(left == right);
}


