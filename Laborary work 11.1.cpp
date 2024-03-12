#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List {
public:
	void pop_front();
	T& GetValue(const int index);
	void push_front(T data);
	void insert(T data, int index);
	void removeIndex(int index);
private:
	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};


int main() {
	setlocale(LC_ALL, "ru");
	system("chcp 1251>NULL");
	List<string> list;
	cout << "Введите размер списка: ";
	int size;
	cin >> size;
	string input;
	for (int i = 0; i <= size; i++) {
		getline(cin, input);
		list.push_front(input);
	}
	cout << endl;
	cout << "Изначальное содержимое списка: " << endl;
	for (int i = 0; i < size; i++) {
		cout << list.GetValue(i) << endl;
	}
	cout << "Введите ключ, для удаления элемента: " << endl;
	getline(cin, input);
	for (int i = 0; i < size; i++) {
		if (list.GetValue(i) == input) {
			list.removeIndex(i);
		}
	}
	cout << "Содержимое списка после удаления элемента с ключом \"" << input << "\":" << endl;
	for (int i = 0; i < size; i++) {
		cout << list.GetValue(i) << endl;
	}
	cout << "Введите номер элемента, перед которым будем вставлять новые элементы: " << endl;
	int number;
	cin >> number;
	cout << "Введите сколько элементов нужно добовить: " << endl;
	int count;
	cin >> count;
	for (int i = 0; i <= count; i++) {
		getline(cin, input);
		list.insert(input, number++);
	}
	cout << "Список после вставки новых элементов: " << endl;
	for (int i = 0; i < size; i++) {
		if (list.GetValue(i) != "")
			cout << list.GetValue(i) << endl;
	}
	return 0;
}



template<typename T>
T& List<T>::GetValue(const int index) {
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	Size++;
}


template<typename T>
void List<T>::insert(T data, int index) {
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<typename T>
void List<T>::pop_front() {
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::removeIndex(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}