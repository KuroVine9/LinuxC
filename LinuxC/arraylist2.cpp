#include <iostream>

template <typename T>
struct _Node {
	_Node(T data = NULL, _Node* next = nullptr) : data(data), next(next) {}
	T data;
	_Node* next;
};

template <typename T>
class ArrayList {
	typedef _Node<T> Node;
private:
	Node* start_point;
public:
	ArrayList() : start_point(nullptr) {}
	
	ArrayList& add(T val) {
		Node* search_point = start_point;
		if (search_point == nullptr) {
			search_point = new Node<T>;
			search_point->data = val;
			search_point->next = nullptr;
			start_point = search_point;
		}
		else {

		}
	}
};