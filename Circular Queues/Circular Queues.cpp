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

	}

};