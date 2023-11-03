#include<iostream>
#include<fstream>
using namespace std;

void Allocate2d(int*** arr, int n);  //additional function
void Deallocate2d(int*** arr, int n); //additional function
void AllocateTriangularMatrix(int*** arr, int n);
void DeallocateTriangularMatrix(int*** arr, int n);
bool input(int*** arr, int& n);
bool inputFile(int*** arr1, int*** arr2, int& n1, int& n2);
void print( int **const arr, int n);
bool Add(int** arr1, int** arr2, int*** arr_added, int n1,int n2);
bool Multiply(int** arr1, int** arr2, int*** arr_multiplied, int n1, int n2);
void delete_row(int**& arr, int row,int &size);
void Swap(int**& arr, int size, int row1, int row2);
void menu2();
//-------------------------Description-------------------------
// We will initiallize a 3d array out side of the function and then pass it in the functions to allocate and manipulate a 2d array.

// menu2() function will show menus depending on the input of user. you can also go back to the previous menu.

// As the program only manipulates upper traingular matrices which are square the only condition 
//for addition and multiplication is that both matrices should be of the same order.
//--------------------------------------------------------------
int main()
{
	menu2();
}

void Allocate2d(int*** arr, int n)
{
	
	
	*arr = new int* [n];
	for (int i = 0; i < n; i++)
		(*arr)[i] = new int[n];
}

void Deallocate2d(int*** arr, int n)
{
	for (int i = 0; i < n; i++)
		delete[] (*arr)[i];
	delete[] *arr;
	arr = nullptr;
}


void AllocateTriangularMatrix(int*** arr, int n)
{
	*arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		(*arr)[i] = new int[n-i];
	}

}

void DeallocateTriangularMatrix(int*** arr, int n)
{
	for (int i = 0; i < n; i++)
		delete[]arr[n - i];
	delete[] *arr;
	arr = nullptr;
}

bool input(int*** arr, int& n)
{
	cout << "Enter the length of square matrix: ";
	cin >> n;

	int*** ArrForCheck = new int**;
	Allocate2d(ArrForCheck, n);        

	
	AllocateTriangularMatrix(arr, n);     
	//input
	cout << "Enter the whole matrix: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			cin >> (*ArrForCheck)[i][j];
		}
	}
	// check whether the input is uppertriangular matrix or not.

	bool status = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j)
			{
				if ((*ArrForCheck)[i][j] != 0)
					status = 0;
			}
			else if ((*ArrForCheck)[i][j] == 0)
				status = 0;

		}
	}
	if (status == 0)
	{
		
		return status;
	}
	
	
	
	//copy the data to Arr
	for(int i=0;i<n;i++)
	{
		int j = 0, k = 0;
		while (j < n - i)
		{
			if ((*ArrForCheck)[i][k] == 0)
				k++;
			else
			{
				(*arr)[i][j] = (*ArrForCheck)[i][k];
				j++;
				k++;
			}
		}
	}
	
	Deallocate2d(ArrForCheck, n);           
	
	return status;
}

bool inputFile(int*** arr1, int*** arr2, int& n1, int& n2)
{
	char name[50];
	int*** arr1_check = new int**;
	int*** arr2_check = new int**;
	cout << "eneter the name of the file: ";
	cin.ignore();
	cin.getline(name, 50);
	ifstream fin;
	fin.open(name);
	//input
	if (fin)
	{
		fin >> n1;
		Allocate2d(arr1_check, n1);
		for (int i = 0; i < n1; i++)
		{
			for (int j = 0; j < n1; j++)
			{
				fin >> (*arr1_check)[i][j];
			}
		}
		fin >> n2;
		Allocate2d(arr2_check, n2);
		for (int i = 0; i < n2; i++)
		{
			for (int j = 0; j < n2; j++)
			{
				fin >> (*arr2_check)[i][j];
			}
		}
		fin.close();
	}
	else
	{
		cout << "Error: reading the file";
	}
	
	//checks for both matrices
	bool status = 1;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			if (i > j)
			{
				if ((*arr1_check)[i][j] != 0)
					status = 0;
			}
			else if ((*arr1_check)[i][j] == 0)
				status = 0;

		}
	}

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (i > j)
			{
				if ((*arr2_check)[i][j] != 0)
					status = 0;
			}
			else if ((*arr2_check)[i][j] == 0)
				status = 0;

		}
	}
	if (status == 0)
	{
		cout << "Error: choose a file in which both matices are upper triangular matrices" << endl;
		return status;
	}

	// copying both matrices to arr1, arr2
	AllocateTriangularMatrix(arr1, n1);
	AllocateTriangularMatrix(arr2, n2);
	for (int i = 0; i < n1; i++)
	{
		int j = 0, k = 0;
		while (j < n1 - i)
		{
			if ((*arr1_check)[i][k] == 0)
				k++;
			else
			{
				(*arr1)[i][j] = (*arr1_check)[i][k];
				j++;
				k++;
			}
		}
	}
	Deallocate2d(arr1_check, n1);
	
	for (int i = 0; i < n2; i++)
	{
		int j = 0, k = 0;
		while (j < n2 - i)
		{
			if ((*arr2_check)[i][k] == 0)
				k++;
			else
			{
				(*arr2)[i][j] = (*arr2_check)[i][k];
				j++;
				k++;
			}
		}
	}
	Deallocate2d(arr2_check, n2);
	return status;

}

void print( int **const arr, int  n)
{
	cout << "---------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int k = n; k > n - i; k--)
			cout << "0 ";
		for (int j = 0; j < n - i; j++)
			cout << arr[i][j] << " ";
		cout << endl;
			
	}
	cout << "---------------------" << endl;
}

bool Add(int** arr1, int** arr2, int*** arr_added, int n1, int n2)
{
	if (n1 != n2)
	{
		
		return 0;
	}
	AllocateTriangularMatrix(arr_added, n1);
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1 - i; j++)
		{
			(*arr_added)[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	return 1;

}

bool Multiply(int** arr1, int** arr2, int*** arr_multiplied, int n1, int n2)
{
	if (n1 != n2)
	{
		cout << "error" << endl;
		return 0;
	}
	AllocateTriangularMatrix(arr_multiplied, n1);
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1 - i; j++)
			(*arr_multiplied)[i][j] = 0;
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1 - i; j++)
		{
			int k = i, l = j,m=0;
			while (k < n1 && l >= 0 && m<n1-i)
			{
				(*arr_multiplied)[i][j] = (*arr_multiplied)[i][j] + (arr1[i][m] * arr2[k][l]);
				m++;
				k++;
				l--;
			}
		}
	}
	return 1;
}

void delete_row(int**& arr, int row, int& size)
{
	for (int i = 0; i < size - row; i++)
		arr[row][i] = 0;
	// using a code blcok so we can destroy i and j as soon as we dont need them
	{
		int i = 0, j = row;
		while (j > 0 && i < size)
		{
			arr[i][j] = 0;
			i++;
			j--;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[i][j] == 0 && arr[i][j + 1] != 0)
			{
				for (int k = j; k < size - i - 1; k++)
				{
					arr[i][k] = arr[i][k + 1];
				}
			}
		}
	}
	int k = row;
	for (int i = 0; i < size - row - 1; i++)
	{
		int j = 0;
		while (j < size - row - 1)
		{
			arr[k][j] = arr[k + 1][j];
			j++;
		}
		k++;
	}

	//shrinking the array
	size--;
	int** arr_new = new int* [size];
	for (int i = 0; i < size; i++)
		arr_new[i] = new int[size - i];
	//copy
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			arr_new[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < size + 1; i++)
		delete[] arr[i];
	delete arr;
	arr = arr_new;
	arr_new = nullptr;
    

}

void Swap(int** &arr, int size, int row1, int row2)
{
	int* swap1 = new int[size - row1];
	int* swap2 = new int[size - row2];
	
	for (int j = 0; j < size - row1; j++)
		swap1[j] = arr[row1][j];
	for (int j = 0; j < size - row2; j++)
		swap2[j] = arr[row2][j];
 
	delete[] arr[row1];
	delete[]arr[row2];

	arr[row1] = new int[size - row2];
	arr[row2] = new int[size - row1];

	for (int j = 0; j < size - row2; j++)
		arr[row1][j] = swap2[j];
	for (int j = 0; j < size - row1; j++)
		arr[row2][j] = swap1[j];

	delete[]swap1;
	delete[]swap2;
	swap1 = nullptr;
	swap2 = nullptr;
	
	//printing
	
	for (int i = 0; i < size; i++)
	{
		if (i == row1)
		{
			for (int k1 = 0; k1 < row2; k1++)
				cout << "0 ";
			for (int j1 = 0; j1 < size - row2; j1++)
				cout << arr[i][j1] << " ";
			cout << endl;
		}
		else if (i == row2)
		{
			for (int k1 = 0; k1 < row1; k1++)
				cout << "0 ";
			for (int j1 = 0; j1 < size - row1; j1++)
				cout << arr[i][j1] << " ";
			cout << endl;
		}
		else
        {
			for (int k = 0; k < i; k++)
				cout << "0 ";
			for (int j = 0; j < size - i; j++)
				cout << arr[i][j] << " ";
			cout << endl;
		}

	}
}





void menu2()
{
	int choice = -1;
	int*** arr1 = new int**;
	int n1 = 0;
	while (choice != 0)
	{
		
		cout << "Choose an input method: " << endl;
		cout << "0. Exit" << endl;
		cout << "1. Input one matrix form console." << endl;
		cout << "2. Input two matirces from a file." << endl;
		cin >> choice;
		if (choice == 1)
		{
			int choice2 = -1;
			while (!input(arr1, n1)) {
				cout << "Error the matrix is not upper tiangular. Enter again." << endl;
			}
			while (choice2 != 0)
			{
				
				cout << "choose one of the following: " << endl;
				cout << "0. Back" << endl;
				cout << "1. Print the matirx." << endl;
				cout << "2. Swap 2 rows.(After using swap you will need to enter a new matrix for further operation.)" << endl;
				cout << "3. Delete a Row from the matrix." << endl;
				cout << "4. Input another matrix from console." << endl;
				cin >> choice2;
				if (choice2 == 1)
				{
					
					print(*arr1, n1);
					
				}
				else if (choice2 == 2)
				{
					int row1 = -1, row2 = -1;
			        bool status = false;
					while (!status)
					{
					     cout << "Enter the rows you want to swap. (first row is 0): ";
						 cin >> row1 >> row2;
						 if (row1 > n1 || row2 > n1)
						 {
							cout << "Invalid rows." << endl;
							status = false;
						 }
						else
							status = true;
					
					}
					Swap(*arr1, n1, row1, row2);
					choice2 = 0;

				}
				else if (choice2 == 3)
				{
				    int row = -1;
				    bool status = false;
				    while (!status)
				    {
				        cout << "enter the row:" << endl;
						cin >> row;
				        if (row > n1)
				        {
				            cout << "invalid row" << endl;
					        status = false;
				        }
					    else
					        status = true;
					
					}
		      	    delete_row(*arr1, row, n1);
					print(*arr1, n1);

				}
				else if (choice2 == 4)
				{
					int*** arr12 = new int**;
					int n2 = 0;
					while (!input(arr12, n2)) {
						cout << "Error the matrix is not upper tiangular. Enter again." << endl;
					}
					int choice3 = -1;
					while (choice3 != 0)
					{
						cout << "0. Back." << endl;
						cout << "1.Add both matrices." << endl;
						cout << "2.Multiply both matrices." << endl;
						cin >> choice3;
						if (choice3 == 1)
						{
							int*** added = new int**;
							if (!(Add(*arr1, *arr12, added, n1, n2)))
								cout << "Error cannot add thsese matircse." << endl;
							else
								print(*added, n1);

						}
						else if (choice3 == 2)
						{
							int*** multiplied = new int**;
							if (!Multiply(*arr1, *arr12, multiplied, n1, n2))
								cout << "Error cannot multiply thsese matircse." << endl;
							else
								print(*multiplied, n1);

						}
						else if(choice3>2 || choice3<0)
						{
							cout << "invalid operation" << endl;

						}

					}
					DeallocateTriangularMatrix(arr12, n1);
					arr12 = nullptr;

				}
				else if (choice2 > 2 || choice2 < 0)
				{
					cout << "invalid input" << endl;

				}

			}
		}
		else if (choice == 2)
		{
			int*** arr2 = new int**;
			int n2 = 0;
			while (!(inputFile(arr1, arr2, n1, n2)))
			{
				cout << "Both matrices must be upper triangular" << endl;
			}
			int choice3 = -1;
			while (choice3 != 0)
			{
				
				cout << "0. Back." << endl;
				cout << "1.Add both matrices." << endl;
				cout << "2.Multiply both matrices." << endl;
				cin >> choice3;
				if (choice3 == 1)
				{
					int*** added = new int**;
					if (!(Add(*arr1, *arr2, added, n1, n2)))
						cout << "Error cannot add thsese matircse." << endl;
					else
						print(*added, n1);
					DeallocateTriangularMatrix(added, n1);
					added = nullptr;
				}
				else if (choice3 == 2)
				{
					int*** multiplied = new int**;
					if (!Multiply(*arr1, *arr2, multiplied, n1, n2))
						cout << "Error cannot multiply thsese matircse." << endl;
					else
						print(*multiplied, n1);
					DeallocateTriangularMatrix(multiplied, n1);
					multiplied = nullptr;
				}
				else if (choice3 > 2 || choice3 < 0)
				{
					cout << "invalid operation" << endl;

				}

			}
			
			

        }
		else if (choice > 2 || choice < 0)
		{
		      cout << "invalid input" << endl;
		   
        }

	}
	DeallocateTriangularMatrix(arr1, n1);
	arr1 = nullptr;

	

}