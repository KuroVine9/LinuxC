#include <iostream>

template <class T>

class ArrayList {
	typedef struct Node {
		Node(T data = NULL, Node* next = nullptr) : data{ data }, next{ next } {}
		T data;
		Node* next;
	} Node;
private:
	int list_size;
	Node start;
public:
	ArrayList() : start(), list_size(0) {}

	ArrayList& add(T val) {
		if (list_size == 0) {
			start.data = val;
			list_size = 1;
		}
		else {
			Node* last;
			last = &start;
			Node* temp = new Node;
			temp->data = val;

			while (last->next != nullptr) last = last->next;
			last->next = temp;
			list_size++;
		}
		return *this;
	}

	ArrayList& add(int index, T val) {
		Node* last = &start;
		Node* temp = new Node;
		temp->data = val;

		for (; index > 1; index--) last = last->next;
		if (last->next->next != nullptr) temp->next = last->next;
		last->next = temp;
		list_size++;

		return *this;
	}

	ArrayList& addAll(ArrayList& list) {
		if (list_size == 0) {
			this->start.data = list.start.data;
			this->start.next = list.start.next;
			this->list_size = list.list_size;
		}
		else {
			Node* last = &start;
			Node* start = new Node(list.start.data, list.start.next);

			while (last->next != nullptr) last = last->next;
			last->next = start;	// 시작 주소뿐만 아닌 모든 노드를 "복사"해야함

			this->list_size += list.list_size;
		}
		return *this;
	}

	ArrayList operator+(ArrayList& list) {
		ArrayList output;
		output.addAll(*this).addAll(list);
		return output;
	}

	ArrayList& operator+=(ArrayList& list) {
		return addAll(list);
	}

	ArrayList& operator=(ArrayList& list) {
		this->start.data = list.start.data;
		this->start.next = list.start.next;
		this->list_size = list.list_size;
		return *this;
	}

	T remove(int index) {
		Node* last = &start;
		Node* temp = new Node;
		Node* temp_start = temp;
		T temp_data = NULL;

		temp->next = last;
		if (index == 0) {
			temp_data = start.data;
			last = last->next;
			start.data = last->data;
			start.next = last->next;
			delete(last);
			delete(temp_start);
			list_size--;
		}
		else {
			for (; index > 0; index--) {
				last = last->next;
				temp = temp->next;
			}
			temp->next = last->next;
			temp_data = last->data;
			delete(last);
			delete(temp_start);
			list_size--;
		}
		return temp_data;
	}

	bool remove(T val) {	// 오버로딩?
		Node* last = &start;
		Node* temp = new Node;
		Node* temp_start = temp;

		temp->next = last;
		do {
			if (last->data == val) break;
			last = last->next;
			temp = temp->next;
		} while (last->next != nullptr);

		if (last->data == val && last == &start) {
			if(list_size != 1) last = last->next;
			start.data = last->data;
			start.next = last->next;
			delete(temp_start);
			list_size--;
			return true;
		}
		else if (last->data == val) {
			temp->next = last->next;
			delete(last);
			delete(temp_start);
			list_size--;
			return true;
		}
		else
			return false;
	}

	void clear() {
		Node* temp = &start;
		Node* last = temp;

		if (start.next != nullptr) {
			last = last->next;
			temp = last;
			while (last->next != nullptr) {
				last = last->next;
				delete(temp);
				temp = last;
			}
			delete(last);
		}
		start.data = NULL;
		start.next = nullptr;
		list_size = 0;
	}

	bool contains(T val) {
		if (list_size == 0) return false;
		Node* last = &start;
		do {
			if (last->data == val) return true;
			last = last->next;
		} while (last->next != nullptr);
		return (last->data == val);
	}

	T& get(int index) {
		Node* last = &start;
		for (; index > 0; index--) last = last->next;
		return last->data;
	}

	ArrayList& set(int index, T val) {
		get(index) = val;
		return *this;
	}

	int indexOf(T val) {
		Node* last = &start;
		for (int i = 0; i < list_size; i++) {
			if (last->data == val) return i;
			last = last->next;
		}
		return -1;
	}

	int size() {
		return list_size;
	}

	bool isEmpty() {
		return (start.next == nullptr ? true : false);
	}

	T* toArray() {
		Node* last = &start;
		T* output = new T[list_size];	//memory?
		for (int i = 0; i < list_size; i++) {
			output[i] = last->data;
			last = last->next;
		}
		return output;
	}

	void testfunc(int x);
};

template <class T> void ArrayList<T>::testfunc(int x) {
	std::cout << 1;
}

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	ArrayList<char> a;
	int count;
	int temp;

	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> temp;
		a.add(temp);
	}

	while (a.size()!=0) {
		int min = a.get(0);
		for (int i = 0; i < a.size(); i++) {
			if (min > a.get(i)) min = a.get(i);
		}
		a.remove(min);
		cout << min << endl;
	}

	return 0;
}