#include "mySort.h"

void merge(int arr[],int a1, int b1, int a2, int b2){	//arr[] is the entire array itself, 
/*	a1 is the index of the FIRST element in the "left" half which is to be merged
	b1 is the index of the FIRST element in the "right" half which is to be merged
	a2 is the index of the LAST element in the "left" half which is to be merged
	b2  is the index of the LAST element in the "right" half which is to be merged
*/
	int tempArr[MAX_SIZE_N_TO_SORT]; //
	int a,b,c;
	a=a1;
	b=b1;
	c=0;

	while(a<=b1 && b<=b2){
		if( myCompare(arr[a],arr[b])<0 ){
			tempArr[c++] = arr[a++];
		}
		else{
			tempArr[c++] = arr[b++];
		}
	}

	while(a <= b1){
		myCopy(&arr[a++],&tempArr[c++]);
	}
	while(b <= b2){
		myCopy(&arr[b++],&tempArr[c++]);
	}

	for(a=a1,c=0; a<=b2; a++,c++){
		mySwap(&arr[a],&tempArr[c]);
	}
}		

void mySort(int array[], unsigned int first, unsigned int last)
{
	int halfway;
	
	if(first<last){
		halfway = (first + last)/2;
		mySort(array,first,halfway);
		mySort(array,halfway+1,last);
		merge(array,first,halfway,halfway+1,last);
	}
}
