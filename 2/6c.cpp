#include <iostream>
using namespace std;
#define MAX 100

void display(int M[MAX][3]) {
    cout<<"Row Col Val\n";
    for(int i=0;i<=M[0][2];i++)
        cout<<M[i][0]<<"   "<<M[i][1]<<"   "<<M[i][2]<<endl;
}

void transpose(int B[MAX][3], int T[MAX][3]) {
    T[0][0]=B[0][1]; T[0][1]=B[0][0]; T[0][2]=B[0][2];
    int k=1;
    for(int col=0; col<B[0][1]; col++)
        for(int i=1;i<=B[0][2]; i++)
            if(B[i][1]==col) {
                T[k][0]=B[i][1];
                T[k][1]=B[i][0];
                T[k][2]=B[i][2];
                k++;
            }
}

void multiplySparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if(A[0][1]!=B[0][0]) { cout<<"Multiplication not possible!\n"; return; }

    int BT[MAX][3]; transpose(B,BT);
    int k=1;

    for(int i=1;i<=A[0][2]; i++) {
        for(int j=1;j<=BT[0][2]; j++) {
             if(A[i][1]==BT[j][1]) {
                int r=A[i][0];        // row of result = row of A
                int c=BT[j][0];       // col of result = col of B
                int v=A[i][2]*BT[j][2]; // product value

                // Check if (r,c) already exists in C → accumulate
                int f=0;
                for(int x=1;x<k; x++) {
                    if(C[x][0]==r && C[x][1]==c) {
                        C[x][2]+=v; f=1; break;
                    }
                }
                // If not found, insert new entry
                if(!f) { 
                    C[k][0]=r; C[k][1]=c; C[k][2]=v; 
                    k++;  }
            }
        }
    }
    C[0][0]=A[0][0]; C[0][1]=B[0][1]; C[0][2]=k-1;
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

    multiplySparse(A,B,C);
    cout<<"\nA x B:\n"; display(C);
}
