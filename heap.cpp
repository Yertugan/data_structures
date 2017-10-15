#include <iostream>

using namespace std;



void heapify(int a[], int N, int v){
	while(true){
		if(2*v+1 >= N){
			return;
		}
		int maxi = a[2*v+1];
		int pos = 2*v+1;
		if(2*v+2 < N && maxi<a[2*v+2]){
			maxi = a[2*v+2];
			pos = 2*v+2;
		}
		if(maxi > a[v]){
			swap(a[v], a[pos]);
			v=pos;
		}else{
			return;
		}
	}
}

void heapsort(int a[], int N){
	for (int i = N / 2 - 1; i >= 0; i--){
        heapify(a, N, i);
	}
 
    for (int i=N-1; i>=0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main(){
	int a[] = {10, 21, 17, 4, 3, 7};
    int n = sizeof(a)/sizeof(a[0]);
 
    heapsort(a, n);
 	for (int i=0; i<n; ++i){
        cout << a[i] << " ";
 	}
    cout << endl;
 
}
