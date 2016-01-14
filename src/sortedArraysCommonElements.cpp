/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common
to both statement (ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, 
                      { 20, "19-10-2004", "Second" }, 
                      { 30, "03-03-2005", "Third" } 
					};
             B[3] = { { 10, "09-10-2003", "First" }, 
			          { 220, "18-01-2010", "Sixth" }, 
			          { 320, "27-08-2015", "Seventh" } 
					};
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isEqual(struct transaction*, int, struct transaction*, int);
int strlen(char*);
int strcmp(char*, char*);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	if (isEqual(A, ALen, B, BLen))
		return A;
	int i = 0, j = 0, k = 0;
	struct transaction *C = (struct transaction*)malloc(sizeof(struct transaction) * 3);
	while (i < ALen && j < BLen) {
		if (A[i].amount < B[j].amount)
			i++;
		else if (B[j].amount < A[i].amount)
			j++;
		else {
			C[k++] = B[j++];
			i++;
		}
	}
	if (k == 0)
		return NULL;
	return C;
}
int isEqual(struct transaction *A, int Alen, struct transaction *B, int Blen) {
	if (Alen != Blen)
		return 0;
	for (int i = 0; i < Alen; i++) {
		if (A[i].amount != B[i].amount || !strcmp(A[i].date, B[i].date) || !strcmp(A[i].description, B[i].description))
			return 0;
	}
	return 1;
}
int strcmp(char *str1, char *str2) {
	if (strlen(str1) != strlen(str2))
		return 0;
	int i = 0;
	while (str1[i] != '\0') {
		if (str1[i] != str2[i])
			return 0;
		i++;
	}
	return 1;
}
int strlen(char *str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}