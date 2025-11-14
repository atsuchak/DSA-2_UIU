#include <bits/stdc++.h>
using namespace std;

int pow_sum(int n) {
	if(n == 0) return 0;

	return pow_sum(n-1) + pow(n, 4);
}

int fact(int n) {
	if(n == 0) return 1;

	return n*fact(n-1);
}

int find_max(vector<int> a, int n) {
	if(n == 1) return a[0];

	return max(find_max(a, n-1), a[n-1]);
}

int count_even(vector<int> a, int n) {
	if(n == 1) return a[n-1]%2 == 0? 1 : 0;

	return count_even(a, n-1) + (a[n-1]%2 == 0? 1 : 0);
}

bool check_palindrome(string s, int st, int fn) {
	if(st == fn || st > fn) return 1;

	return (s[st] == s[fn]) && check_palindrome(s, st+1, fn-1);
}

double find_sqrt(double n, double low, double hi) {
	double mid = (low+hi)/2;

	if(abs(pow(mid, 2) - n) < .00000001) return mid;

	if(pow(mid, 2) > n) return find_sqrt(n, low, mid);

	return find_sqrt(n, mid, hi);
}

int fibonacci(int n) {
	if(n <= 2) return 1;

	return fibonacci(n-1) + fibonacci(n-2);
}


int main() {

	freopen("D:/progamming/Varsity/DSA 2/input.txt", "r", stdin);
	freopen("D:/progamming/Varsity/DSA 2/output.txt", "w", stdout);

	int n; cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	string st; cin >> st;

	double db; cin >> db;

	cout << "Series sum: " << pow_sum(n) << endl;
	cout << "Factorial: " << fact(n) << endl;
	cout << "Find max: " << find_max(a, n) << endl;
	cout << "Even count: " << count_even(a, n) << endl;

	cout << st << ": ";
	if(check_palindrome(st, 0, st.size()-1)) cout << "Palindrome" << endl;
	else cout << "Non Palindrome" << endl;

	cout << "Find square: " << find_sqrt(db, 0, db) << endl;
	cout << "fibonacci: " << fibonacci(n) << endl;

	return 0;
}


/*
Example input: 
5 
4 2 6 1 3
aibohphobia
64
*/