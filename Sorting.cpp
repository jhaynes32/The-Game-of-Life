#include <iostream>


void printArray(int [], int);
void bubbleSort(int [], int);
void selectionSort(int [], int);
void insertionSort(int [], int);
int linearSearch(int [], int, int);
int binarySearch(int [], int, int);

using namespace std;

int main() {

	int x[10];


	cout <<"-------------------------------------"<< endl;
	//Test bubble sort
	for (int i = 0; i < 10; i++)
	{
		x[i] = rand();
	}
	// Test Bubble sort
	cout << "Before Bubble sorting" << endl;
	printArray(x, 10);
	bubbleSort(x, 10);
	cout << "After Bubble sorting" << endl;
	printArray(x, 10);
	

	cout <<"-------------------------------------"<< endl;
	// Test selection sort
	for (int i = 0; i < 10; i++)
	{
		x[i] = rand();
	}
	cout << "Before Selection sorting" << endl;
	printArray(x, 10);
	selectionSort(x, 10);
	cout << "After Selection sorting" << endl;
	printArray(x, 10);

	cout <<"-------------------------------------"<< endl;
	// Test insertion sort
	for (int i = 0; i < 10; i++)
	{
		x[i] = rand();
	}
	cout << "Before Insertion sorting" << endl;
	printArray(x, 10);
	insertionSort(x, 10);
	cout << "After Selection sorting" << endl;
	printArray(x, 10);

	cout <<"-------------------------------------"<< endl;
	// Test Linear search
	for (int i = 0; i < 10; i++)
	{
		x[i] = rand();
	}
	cout << "Linear search" << endl;
	printArray(x, 10);
	int y = x[7];
	int z = linearSearch(x, 10, y);
	cout << "Linear Search " << y << " found at index: : " << z  << endl;
	z = linearSearch(x, 10, y+1);
	cout << "Linear Search " << (y + 1) << " found at index: : " << z  << endl;

	cout <<"-------------------------------------"<< endl;
	// Test binary search
	for (int i = 0; i < 10; i++)
	{
		x[i] = 3 * i;
	}
	cout << "binary search" << endl;
	printArray(x, 10);
	y = 18;
	z = binarySearch(x, 10, y);
	cout << "Binary Search " << y << " found at index: : " << z  << endl;
	z = binarySearch(x, 10, y+1);
	cout << "Binary Search " << (y + 1) << " found at index: : " << z  << endl;

}


void printArray(int x[], int size){

	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << "  ";
	}
	cout << endl;
}

void bubbleSort(int x[], int size) {

	bool sorted;

	for (int n = 0; n < size - 1 ; n++) {

		sorted = true;
		for (int i = 0; i < size - 1 - n; i++)
		{
			if (x[i] > x[i+1]){
				int temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
				sorted = false;
			}
		}
		if (sorted)
			return;
	}
}


void selectionSort(int x[], int size) {

	for(int i = 0; i < (size - 1) ; i++) {
		
		int minIndex = i;

		for (int j = i + 1; j < size; j++) {
			if (x[j] < x[minIndex])
				minIndex = j;
		}
		int temp = x[i];
		x[i] = x[minIndex];
		x[minIndex] = temp;
	}
}


void insertionSort(int x[], int size) {

	for (int i = 0; i < (size -1); i++) {

		/*  
		The old way -- can be deleted
		for (int j = i + 1; j > 0; j--) {

			if (x[j] < x[j-1]){
				int temp = x[j];
				x[j] = x[j -1];
				x[j-1] = temp;
			}
			else
				break;
		}
		*/

		int j = i + 1;
		while ((j > 0) && (x[j] < x[j-1])) {
			int temp = x[j];
			x[j] = x[j -1];
			x[j-1] = temp;
			j--;
		}
	}
}


int linearSearch(int x[], int size, int val){

	for (int i = 0; i < size; i++){
		if (x[i] == val){
			return i;
		}
	}
	return -1;
}

int binarySearch(int x[], int size, int val){

	int start = 0;
	int end = size - 1;
	while ( start <= end) {
		int mid = (start + end) / 2;
		if(x[mid] == val)
			return mid;
		else if (x[mid] > val)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;

	}