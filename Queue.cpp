#include<iostream>
#include<string>
using namespace std;
struct customer {
	string customerName;
	int arrivalTime;
	int serviceTime;
	int finishTime;
};
struct FCFSQueue {
	customer customerList[100];
	int length;
};
bool isEmpty(FCFSQueue);
int GetLength(FCFSQueue);
void Enqueue(FCFSQueue&, customer);
void Dequeue(FCFSQueue&);

int main() {

	FCFSQueue queue;
	queue.length = 0;
	customer newCus[2];
	for (int i = 0; i < 2; ++i) {
		cout << "Enter customer name: ";
		cin >> newCus[i].customerName;
		cout << "Enter arrival time :  ";
		cin >> newCus[i].arrivalTime;
		cout << "Enter service time :  ";
		cin >> newCus[i].serviceTime;
		newCus[i].finishTime = newCus[i].arrivalTime + newCus[i].serviceTime;

		Enqueue(queue, newCus[i]);
	}
	for (int i = 0; i < 2; i++) {
		cout << "Queue: " << i + 1 << endl;
		cout << "Name: " << newCus[i].customerName << endl;
		cout << "Arrival Time: " << newCus[i].arrivalTime << endl;
		cout << "Service Time: " << newCus[i].serviceTime << endl;
		cout << "Finish Time: " << newCus[i].finishTime << endl;
	}
	Dequeue(queue);
	Dequeue(queue);
	Dequeue(queue);
	system("PAUSE");
	return 0;
}
bool IsEmpty(FCFSQueue queue) {
	if (queue.length == 0)
		return true;
	else return false;
}
int GetLength(FCFSQueue queue) {
	return queue.length;
}
void Enqueue(FCFSQueue& queue, customer cus) {
	if (queue.length >= 100) {
		cout << "Queue is full!" << endl;
		return;
	}
	queue.customerList[queue.length] = cus;
	++queue.length;
	cout << "Customer: " << cus.customerName << " has been added to the queue." << endl;
}
void Dequeue(FCFSQueue& queue) {
	if (IsEmpty(queue)) {
		cout << "No customers in queue!" << endl;
		return;
	}
	customer cus = queue.customerList[0];
	cout << cus.customerName << " is leaving the queue!" << endl;
	for (int i = 0; i < GetLength(queue); i++) {
		queue.customerList[i] = queue.customerList[i + 1];
	}
	--queue.length;
}
