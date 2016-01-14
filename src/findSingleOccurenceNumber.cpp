/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>
void sort(int*, int);
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	if (A[0] > A[1])
		sort(A, len);
	for (int i = 0; i < len; i++) {
		if (i == 0) {
			if (A[i] != A[i + 1]) {
				return A[i];
			}
		}
		else if (i == (len - 1)) {
			if (A[i] != A[i - 1]) {
				return A[i];
			}
		}
		else if (A[i - 1] != A[i] && A[i] != A[i + 1]) {
			return A[i];
		}
	}
}
void sort(int *arr, int n) {
	int temp;
	for (int i = 0; i < (n - 1); i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
