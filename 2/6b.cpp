#include <iostream>
using namespace std;
#define MAX 100

void display(int mat[MAX][3]) {
    cout<<"Row Col Val\n";
    for(int i=0;i<=mat[0][2];i++)
        cout<<mat[i][0]<<"   "<<mat[i][1]<<"   "<<mat[i][2]<<endl;
}

void addSparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if(A[0][0]!=B[0][0] || A[0][1]!=B[0][1]) {
        cout<<"Addition not possible!\n"; return;
    }
    int i=1,j=1,k=1;
    while(i<=A[0][2] && j<=B[0][2]) {
        if(A[i][0]==B[j][0] && A[i][1]==B[j][1]) {
            C[k][0]=A[i][0]; C[k][1]=A[i][1];
            C[k][2]=A[i][2]+B[j][2];
            i++; j++; k++;
        }
        else if(A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
            C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++;
        }
        else {
            C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++;
        }
    }
    while(i<=A[0][2]) { C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++; }
    while(j<=B[0][2]) { C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++; }
    C[0][0]=A[0][0]; C[0][1]=A[0][1]; C[0][2]=k-1;
}

int main() {
    int A[MAX][3],B[MAX][3],C[MAX][3];
    int r,c,nz;
    cout<<"Enter rows, cols, non-zero count for A: ";
    cin>>r>>c>>nz;
    A[0][0]=r; A[0][1]=c; A[0][2]=nz;
    cout<<"Enter (row col val):\n";
    for(int i=1;i<=nz;i++) cin>>A[i][0]>>A[i][1]>>A[i][2];

    cout<<"Enter rows, cols, non-zero count for B: ";
    cin>>r>>c>>nz;
    B[0][0]=r; B[0][1]=c; B[0][2]=nz;
    cout<<"Enter (row col val):\n";
    for(int i=1;i<=nz;i++) cin>>B[i][0]>>B[i][1]>>B[i][2];

    addSparse(A,B,C);
    cout<<"\nA + B:\n"; display(C);
}
