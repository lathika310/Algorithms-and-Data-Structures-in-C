#include <stdio.h>

void mySort(int d[], unsigned int n){
for (int i=1; i<n; i++) {
	int temp = d[i];
	int j=i-1;

	while (temp<d[j] && j >=0){
		d[j+1] = d[j];
		--j;
		}
	d[j+1] = temp;
	}
}

