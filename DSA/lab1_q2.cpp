#include <iostream>
using namespace std;

int row, col, matrix[25][25];

void create() {
	cout<<"Enter matrix dimensions(rows col): ";
	cin>>row>>col;

	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cout<<"Enter element ("<<i+1<<","<<j+1<<"): ";
			cin>>matrix[i][j];
		}
	}
	cout<<"SUCCESSFULLY CREATED MATRIX!"<<endl;
}


void transpose() {

	if (row == 0 || col == 0) {
		cout << "Create matrix first.\n";
		return;
	}

	if (row != col) {

		int trans[25][25];

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				trans[j][i] = matrix[i][j];
			}
		}

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				matrix[i][j] = trans[i][j];
			}
		}

		int t = row;
		row = col;
		col = t;

		return;
	}

	for (int i = 0; i < row; i++) {
		for (int j = i + 1; j < col; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}



void multiply() {

	if(row==0 && col==0) {
		cout<<"Create matrix first.\n";
		return;
	}

	int r,c,m[25][25];
	if(r==0 && c==0) {
		cout<<"Create matrix first.\n";
		return;
	}
	cout<<"Enter a 2nd matrix! \nDimensions(rows col): ";
	cin>>r>>c;


	if (col != r) {
		cout << "Matrix multiplication not possible.\n";
		return;
	}

	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cout<<"Enter element ("<<i+1<<","<<j+1<<"): ";
			cin>>m[i][j];
		}
	}
	cout<<"SUCCESSFULLY CREATED MATRIX!\nMultiplying...."<<endl;


	int result[25][25];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < c; j++) {
			result[i][j] = 0;
			for (int k = 0; k < col; k++) {
				result[i][j] += matrix[i][k] * m[k][j];
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < c; j++) {
			matrix[i][j] = result[i][j];
		}
	}
	col = c;
	cout << "Matrices multiplied successfully.\n";
}


void display() {

	if(row==0 && col==0) {
		cout<<"Create matrix first.\n";
		return;
	}

	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}


int main() {
	int option;

	do {
		cout<<"----------MENU---------\n"<<"1. CREATE\n2. TRANSPOSE \n3. MULTIPLY\n4. DISPLAY \n5. EXIT"<<endl;

		cin>>option;

		switch(option) {
		case 1:
			create();
			break;
		case 2:
			transpose();
			break;
		case 3:
			multiply();
			break;
		case 4:
			display();
			break;
		}
	} while(option!=5);

}