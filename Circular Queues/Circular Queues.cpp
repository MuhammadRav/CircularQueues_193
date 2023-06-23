#include <iostream>
using namespace std;

class Queues {
	int front, rear, n = 5;
	int queue_array[5];

public:
	Queues() {
		front = -1;
		rear = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		//cek apakah antrian kosong
		if (front == -1) {
			front = 0;
			rear = 0;
		}
		else {
			//jika rear berada di posisi terakhir array, kembali ke awal array
			if (rear == n - 1)
				rear = 0;
			else
				rear = rear + 1;
		}
		queue_array[rear] = num;	//step 4
	}

	void remove() {
		//cek apakah antrian kosong
		if (front == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nThe element deleted from the queue is: " << queue_array[front] << "\n";

		//cek jika antrian hanya memiliki satu elemen
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			// jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (front == n - 1)
				front = 0;
			else
				front = front + 1;
		}
	}

	void display() {
		int front_position = front;
		int rear_position = rear;

		//cek apakah antrian kosong
		if (front == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElements in the queue are...\n";

		//jika front_position <= rear_position, iterasi dari front hingga rear
		if (front_position <= rear_position) {
			while (front_position <= rear_position) {
				cout << queue_array[front_position] << "	";
				front_position++;
			}
			cout << endl;
		}
		else {
			//jika front_position > rear_position, iterasi dari front hingga akhir array
			while (front_position <= n - 1) {
				cout << queue_array[front_position] << "	";
				front_position++;
			}

			front_position = 0;

			//iterasi dari awal array hingga rear
			while (front_position <= rear_position) {
				cout << queue_array[front_position] << "	";
				front_position++;
			}
			cout << endl;
		}
	}
};

int main() {
	Queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. Implement insert operation" << endl;
			cout << "2. Implement delete operation" << endl;
			cout << "3. Display values" << endl;
			cout << "4. Exit" << endl;
		}
	}
}