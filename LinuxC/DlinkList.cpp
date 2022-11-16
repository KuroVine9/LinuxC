#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
struct _Node {
	_Node(T data = NULL) : data(data), prev(nullptr), next(nullptr) {}
	T data;
	struct _Node* prev, *next;
};

template <typename T>
class DlinkList {
	typedef struct _Node<T> Node;
private:
	Node* start_point;
	int list_size;
public:
	DlinkList() : start_point(nullptr), list_size(0) {}
	class iterator {
	public:
		Node* search_point;
	public:
		iterator(Node* search_point = nullptr) : search_point(search_point) {}
		iterator& operator++() {
			search_point = search_point->next;
			return *this;
		}
		iterator& operator--() {
			search_point = search_point->prev;
			return *this;
		}
		iterator& operator+(int index) {
			for (; index > 0; index--) search_point = search_point->next;
			return *this;
		}
		iterator& operator-(int index) {
			for (; index > 0; index--) search_point = search_point->prev;
			return *this;
		}
		T& operator*() {
			return search_point->data;
		}
		bool operator==(const iterator& iter) {
			return search_point == iter.search_point;
		}
		bool operator!=(const iterator& iter) {
			return search_point != iter.search_point;
		}
	};
	class reverse_iterator {
	private:
		Node* search_point;
	public:
		reverse_iterator(Node* search_point = nullptr) : search_point(search_point) {}
		reverse_iterator& operator++() {
			search_point = search_point->prev;
			return *this;
		}
		reverse_iterator& operator--() {
			search_point = search_point->next;
			return *this;
		}
		reverse_iterator& operator+(int index) {
			for (; index > 0; index--) search_point = search_point->prev;
			return *this;
		}
		reverse_iterator& operator-(int index) {
			for (; index > 0; index--) search_point = search_point->next;
			return *this;
		}
		T& operator*() {
			return search_point->data;
		}
		bool operator==(const reverse_iterator& riter) {
			return search_point == riter.search_point;
		}
		bool operator!=(const reverse_iterator& riter) {
			return search_point != riter.search_point;
		}
	};
	
	T& operator[] (int index) {
		Node* search;
		for (search = start_point; index > 0; index--) {
			search = search->next;
		}
		return search->data;
	}
	T& front() {
		return start_point->data;
	}
	T& back() {
		Node* search = start_point;
		for (; search->next != nullptr; search = search->next);
		return search->data;
	}
	DlinkList& push_back(T val) {
		Node* newNode = new Node(val);
		if (start_point == nullptr) {
			start_point = newNode;
		}
		else {
			Node* search;
			for (search = start_point; search->next != nullptr; search = search->next);
			search->next = newNode;
			newNode->prev = search;
		}
		list_size++;
		return *this;
	}
	DlinkList& push_front(T val) {
		Node* newNode = new Node(val);
		newNode->next = start_point;
		start_point->prev = newNode;
		start_point = newNode;
		list_size++;
		return *this;
	}
	DlinkList& pop_back() {
		Node* search;
		for (search = start_point; search->next != nullptr; search = search->next);
		if (search == start_point) { start_point = nullptr; }
		else { search->prev->next = nullptr; }
		delete search;
		list_size--;
		return *this;
	}
	DlinkList& pop_front() {
		if (start_point->next == nullptr) {
			delete start_point;
			start_point = nullptr;
		}
		else {
			Node* search = start_point->next;
			start_point->next->prev = nullptr;
			delete start_point;
			start_point = search;
		}
		list_size--;
		return *this;
	}
	iterator erase(iterator iter) {
		Node* search = iter.search_point;
		if (iter.search_point == start_point) {
			search->next->prev = nullptr;
			start_point = search->next;
		}
		else {
			search->prev->next = search->next;
			if (search->next != nullptr) search->next->prev = search->prev;
		}
		search = search->next;
		delete(iter.search_point);
		list_size--;
		return iterator(search);
	}


	iterator begin() { return iterator(start_point); }
	iterator end() { return iterator(); }
	reverse_iterator rbegin() {
		Node* search;
		for (search = start_point; search->next != nullptr; search = search->next);
		return reverse_iterator(search);
	}
	reverse_iterator rend() { return reverse_iterator(); }
};

int main() {
	using namespace std;
	DlinkList<int> d;
	d.push_back(0);
	d.push_back(1);
	d.push_back(2);
	d.push_back(-100);
	d.push_front(200);

	for (auto a : d) {
		cout << a << endl;
	}
	DlinkList<int>::iterator iter;
	for (iter = d.begin(); iter != d.end();) {
		if (*iter == -100) iter = d.erase(iter);
		else ++iter;
	}
	cout << endl;
	for (auto a : d) {
		cout << a << endl;
	}

	cout << "=====" << endl << endl;
	d.pop_back().pop_back().pop_back().pop_back();
	d.push_back(5050);
	d.pop_front();
	d.push_back(123);
	cout << d.front()<<d.back()<<*(d.begin()) << endl;
	//copy(d.begin(), d.end(), ostream_iterator<int>(cout, "\n"));
	
	
	return 0;
}