#include<iostream>
#include<fstream>
using namespace std;

//simple scheduling program to schedule instructions of different
//procesess evenly using the (QUEUE) data structure....


template<class T>
class Queue{

private:
	class Node{
	public:
		T data;
		Node* next;

		Node(){
			next = nullptr;
		}
		Node(T d, Node* n){
			data = d;
			next = n;
		}
		Node(T d){
			data = d;
			next = nullptr;
		}
		Node(const Node& rhs) {
			data = rhs.data;
			next = rhs.next;
		}
		const Node& operator=(const Node& rhs) {
			if (this!=&rhs) {
				data = rhs.data;
				next = rhs.next;
			}
			return *this;
		}
	};
	//we can also use fornt=head and back=tail for semantics..
	Node* front;
	Node* back;
	int count;


public:
	Queue(){
		front = back = nullptr;
		count = 0;
	}
	Queue(const Queue& rhs) {
		front = rhs.front;
		back = rhs.back;
		count = rhs.count;
	}
	const Queue& operator=(const Queue& rhs) {
		if (this != &rhs) {
			front = rhs.front;
			back = rhs.back;
			count = rhs.count;
		}
		return *this;
	}

	bool IsEmpty() {
		return (front == nullptr);
	}

	void EnQueue(T d){
		Node* newNode = new Node(d, nullptr);

		if (front == NULL){
			front = newNode;
			back = newNode;
			count++;
		}
		else{
			
			newNode->next = back->next;
			back->next = newNode;
			back = newNode;
			count++;
		}
	}

	void DeQueue() {

		if (front == NULL) {
			cout << "queue is empty!\n";
		}
		else {
			Node* h = front;
			front = h->next;
			delete h;
			count--;
		}
	}

	T* peek() //will return the pointer to the address of the data obj ( process obj in our case)
	{
		if (front != nullptr) {
			return &(front->data);
		}
		else {
			cout << "the queue is empty!\n";
			return NULL;
		}
	}

	void updateFrontAndCycleThrough()  
	{
		//basically we are shifting the front ptr to its next node and
       //we will join that old head node at the last of the queue or enqueue that node...
		if (front->next == NULL) 
		{
			//do nothing because we have only one node and we donot need to shift front and make cycle
		}
		else
		{
			Node* temp = front;
			front = front->next;
			temp->next = back->next;
			back->next = temp;
			back = temp;
		}
	}

	void display()
	{

		if (front != NULL)
		{
		Node* current = front;

		while (current != NULL)
		{
		cout << current->data << " ";
		current = current->next;
		}
	    }
		else
		{
		cout << "the queue is empty!\n";
       }

	}

	~Queue(){
		if (front != nullptr){

			while (front){
				Node* h = front;
				front = h->next;
				delete h;
			}
		}
	}
};


class Process
{
	int id;
	int instructionCount;
public:
	Process(int i = 0, int j = 0)
	{
		id = i;
		instructionCount = j;
	}
	friend class Scheduler;
};


class Scheduler {
private:
	Queue<Process> processes;
	int noOfIntructionsExecutedOnce;
	int processCount;

public:
	Scheduler()
	{
		noOfIntructionsExecutedOnce = 0;
	    processCount = 0;
   }

	void readFile(const char* filename) 
	{
		ifstream fin(filename);

		if (fin) 
		{
			cout << "file opened successfully!\n---------------------------------\n\n";
			
			fin >> noOfIntructionsExecutedOnce;
			fin >> processCount;
				
			int id = 1;
			int noOfInstruc = 0;

			while (id <= processCount)
			{
				
				cout << "\nenter process P" << id << " total instructions : ";
				while (1) {
					cin >> noOfInstruc;
					if (noOfInstruc < 1) {
						cout << "\nERROR - invalid input!\nenter again: ";
					}
					else {
						break;
					}
				}
				Process p(id, noOfInstruc);
				processes.EnQueue(p);
				id++;
			}
		}
		else {
			cout << "the file was not found!\n";
		}
	}


	void scheduleAllProcesses()
	{
		while (!processes.IsEmpty())
		{
			Process* updatingPtr = processes.peek();
			
			if (updatingPtr->instructionCount > noOfIntructionsExecutedOnce) {
				cout << "\n" << noOfIntructionsExecutedOnce << " instructions of Process p" << updatingPtr->id << " executed!\n";
				updatingPtr->instructionCount = updatingPtr->instructionCount - noOfIntructionsExecutedOnce;
			}
			else
			{
				cout << "\n" << updatingPtr->instructionCount << " instructions of Process p" << updatingPtr->id << " executed!\n";
				updatingPtr->instructionCount = updatingPtr->instructionCount - noOfIntructionsExecutedOnce;
			}

			//--------------

			if (updatingPtr->instructionCount <= 0) {
				cout << "Process p" << updatingPtr->id << " finished!\n";
				processes.DeQueue();
			}
			else {
				processes.updateFrontAndCycleThrough();
			}

		}
	}

};


int main()
{
	Scheduler S;
	S.readFile("processesInfo.txt");
	S.scheduleAllProcesses();
	
	cout << endl << endl;
	system("pause");
	return 0;
}