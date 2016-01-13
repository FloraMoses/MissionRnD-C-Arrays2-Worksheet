/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number
of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int convertToInt(char*);
int subString(char*, int, int);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int cmpYear = subString(date, 7, 4);
	int cmpMonth = subString(date, 4, 2);
	int cmpDay = subString(date, 1, 2);
	int year, month, day, i, count = 0;
	for (i = 0; i < len; i++) {
		year = subString(Arr[i].date, 7, 4);
		if (cmpYear < year)
			break;
		else if (cmpYear > year)
			continue;
		else {
			month = subString(Arr[i].date, 4, 2);
			if (cmpMonth < month)
				break;
			else if (cmpMonth > month)
				continue;
			else {
				day = subString(Arr[i].date, 1, 2);
				if (cmpDay < day)
					break;
				else if (cmpDay > day)
					continue;
			}
		}
	}
	return len - i;
}
int subString(char str[], int pos, int length) {
	int i = 0;
	char subs[5];
	while (i < length) {
		subs[i] = str[pos + i - 1];
		i++;
	}
	subs[i] = '\0';
	return convertToInt(subs);
}
int convertToInt(char* str) {
	int number = 0;
	for (int c = 0; str[c] != '\0'; c++) {
		number = number * 10 + str[c] - '0';
	}
	return number;
}