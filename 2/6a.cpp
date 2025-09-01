#include <iostream>
using namespace std;
#define MAX 100

void display(int mat[MAX][3]) {
    cout << "Row Col Val\n";
    for (int i=0;i<=mat[0][2];i++)
        cout<<mat[i][0]<<"   "<<mat[i][1]<<"   "<<mat[i][2]<<endl;
}

void transposeSparse(int A[MAX][3], int T[MAX][3]) {
    T[0][0]=A[0][1]; T[0][1]=A[0][0]; T[0][2]=A[0][2];
    for (int i=1;i<=A[0][2];i++) {
        T[i][0]=A[i][1];
        T[i][1]=A[i][0];
        T[i][2]=A[i][2];
    }
}

int main() {
    int A[MAX][3], T[MAX][3], rows, cols, nz;
    cout<<"Enter rows, cols, non-zero count: ";
    cin>>rows>>cols>>nz;
    A[0][0]=rows; A[0][1]=cols; A[0][2]=nz;
    cout<<"Enter (row col val):\n";
    for(int i=1;i<=nz;i++) cin>>A[i][0]>>A[i][1]>>A[i][2];
    cout<<"\nMatrix A:\n"; display(A);
    transposeSparse(A,T);
    cout<<"\nTranspose of A:\n"; display(T);
}
