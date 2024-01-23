// codsoft_task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <windows.h>
using namespace std;

class Tasks
{
public:
	string task;
	int task_number;
	bool completed;

	Tasks()
	{
		completed = false;
	}

	Tasks(int t_n, string t, bool com)
	{
		task = t;
		task_number = t_n;
		completed = com;
		//cout << "COM = " << completed << endl;
	}

	void display()
	{
		cout << task_number << ". " << task;
		//cout << " DISPLAY com = " << completed << endl;
		if (completed == true)
			cout << "							(Completed)" << endl;
		else
			cout << "							(Pending)" << endl;
	}
};

class Node
{
public:
	Tasks t;
	Node* next;
	Node* prev;

	Node()
	{
		next = NULL;
		prev = NULL;
	}
};

class LinkedList
{
private:
	Node* head;
	Node* last;
public:
	int nodecount;
	LinkedList()
	{
		head = NULL;
		last = NULL;
		nodecount = 0;
		readFile();
	}

	void insert(Tasks& data)
	{
		Node* newnode = new Node();
		newnode->t.task_number = data.task_number;
		newnode->t.task = data.task;
		newnode->t.completed = data.completed;

		if (head == NULL)
		{
			head = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			newnode->prev = last;
			last = newnode;
		}
		nodecount++;
		//cout << "Node count== " << nodecount << endl;
		//cout << "INsert debug = " << newnode->t.completed << endl;
	}

	void display()
	{
		Node* temp = head;
		if (temp != NULL)
		{
			while (temp->next != NULL)
			{
				//cout << "Debug: Displaying task " << temp->t.task_number << " - completed: " << temp->t.completed << endl;

				temp->t.display();
				temp = temp->next;
			}
			//cout << "Debug: Displaying task " << temp->t.task_number << " - completed: " << temp->t.completed << endl;

			temp->t.display();
		}
		else
		{
			cout << "List is empty" << endl;
		}
	}

	void remove(int id)
	{
		Node* temp = head;
		if (head == NULL)
		{
			cout << "No tasks to remove" << endl;
			return;
		}
		if (temp->t.task_number == id)
		{
			head = head->next;
			if (head != NULL)
			{
				head->prev = NULL;
			}
			//delete temp;
			if (head == NULL)
			{
				last = NULL;
			}
			return;
		}

		while (temp->t.task_number != id)
		{
			temp = temp->next;
		}
		if (temp->next != NULL)
		{

			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			//delete temp;
		}
		else
		{
			temp->prev->next = NULL;
			last = temp->prev;
			//delete temp;
		}


		Node* current = temp->next;
		while (current != NULL)
		{
			current->t.task_number--;
			current = current->next;
		}

		/*if (temp->next == NULL && temp->prev != NULL)
		{
			last->t.task_number--;
		}*/

		/*if (head->next == NULL)
		{
			head->t.task_number--;
		}*/

		delete temp;
		nodecount--;

		cout << "Task " << id << " removed successfully." << endl;
	}

	void deleteList()
	{
		Node* temp = head;

		while (temp != NULL)
		{
			Node* nextNode = temp->next;
			delete temp;
			temp = nextNode;
		}
		head = NULL;
	}

	

	bool is_empty()
	{
		return head == NULL;
	}

	void task_completed(int id)
	{
		Node* temp = head;

		while (temp != NULL)
		{
			if (temp->t.task_number == id)
			{
				//cout << "Debug: Marking task " << id << " as completed." << endl;
				temp->t.completed = true;
				break;
			}
			temp = temp->next;
		}
		cout << endl;

		if (temp == NULL)
			cout << "No such task exists cannot delete" << endl;

		Node* newtemp = head;
		int count = 0;
		while (newtemp != NULL)
		{
			if (newtemp->t.completed == true)
			{
				count++;
			}
			newtemp = newtemp->next;
		}
		/*cout << "Debug count= " << count << endl;
		cout << "nodecount == " << nodecount << endl;*/
		if (count == nodecount)
			cout << "Congrats you have completed all your tasks" << endl;
		
	}

	void readFile()
	{
		ifstream inFile("tasks.txt");
		string line;
		int currentTaskNumber = 1;
		while (getline(inFile, line))
		{
			stringstream ss(line);
			string task;
			string task_number_str;
			string completed_str;
			int task_number;
			bool completed45;

			getline(ss, task_number_str, ',');
			getline(ss, task, ',');
			getline(ss, completed_str, ',');
			

			task_number = stoi(task_number_str);
			completed45 = (completed_str == "1");

			/*cout << "*****************************************************************************************************************************************" << endl;
			cout << "Debug: task_number=" << task_number << ", task=" << task << ", completed_str=" << completed_str << ", completed45=" << completed45 << endl;
			cout << "*****************************************************************************************************************************************" << endl;

			*/
			Tasks newTask(currentTaskNumber, task,completed45);
			//newTask.completed = completed45;
			//cout << "NEW TASK.completed = " << newTask.completed << endl;
			insert(newTask);
			currentTaskNumber++;
		}
		inFile.close();
	}



	void writeToFile()
	{
		ofstream outFile("tasks.txt"); 

		Node* temp = head;
		while (temp != NULL)
		{
			outFile << temp->t.task_number << "," << temp->t.task << "," << temp->t.completed << endl;
			temp = temp->next;
		}

		outFile.close();
	}

	~LinkedList()
	{
		//cout << "Debug: Destructor called" << endl;

		writeToFile();
		deleteList();
	}

	int getNodeCount()
	{
		return nodecount;
	}
};

int main()
{
	LinkedList l1;
	int choice = -1;
	int newtaskcount = l1.getNodeCount();

	while (choice != 0)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 590);
		cout << endl;
		cout << "--------------" << endl;
		cout << "| To Do List |" << endl;
		cout << "--------------" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "----------------------------" << endl;
		cout << "| 1. Add new task          |" << endl;
		cout << "| 2. Mark task as complete |" << endl;
		cout << "| 3. Remove task           |" << endl;
		cout << "| 4. Erase all tasks       |" << endl;
		cout << "| 5. Display Tasks         |" << endl;
		cout << "| 0. Close Program         |" << endl;
		cout << "----------------------------" << endl;
		cout << endl;
		cin >> choice;
		while (choice < 0 || choice >= 6)
		{
			cout << "In-Valid Input " << endl;
			cout << "Re-Enter : ";
			cin >> choice;
		}
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		if (choice == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			string newtask = " ";
			//newtaskcount++;
			cout << "Enter the task : ";
			cin.ignore();
			cin.clear();
			getline(cin, newtask);

			Tasks t1(l1.getNodeCount() + 1, newtask, false);
			l1.insert(t1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (choice == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			int newtasknumber = -1;
			cout << "Enter task number to mark as complete : ";
			cin >> newtasknumber;
			l1.task_completed(newtasknumber);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (choice == 3)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
			int newremovetask = -1;
			
			if (l1.getNodeCount() == 0)
			{
				cout << "There are no tasks to remove" << endl;
				Sleep(2000);
			}
			else
			{
				cout << "Enter task number to remove : ";
				cin >> newremovetask;
				while (newremovetask > l1.getNodeCount() || newremovetask < 1)
				{
					cout << "In-Valid input, no such tasks exist" << endl;
					cout << "Re-Enter : ";
					cin >> newremovetask;

				}
				l1.remove(newremovetask);
			}
			
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (choice == 4)
		{
			l1.deleteList();
		}
		else if (choice == 5)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			l1.display();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			//Sleep(2000);
			cout << "Press Enter to continue...";
			cin.ignore(); 
			cin.get();
		}
		else if (choice == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "Thank you for using my To-Do-List" << endl;
			cout << "Goodbye.................." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
	return 0;
}