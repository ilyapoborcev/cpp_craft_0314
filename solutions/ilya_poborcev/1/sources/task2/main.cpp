#include <iostream>
#include <fstream>
#include <algorithm> 
#include <set>
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	set <long long> code;
	set <long long> :: iterator j;
	double d;
	int n;
	int i;
	in >> n;
	for (i = 0; i < n; i++){
		in >> d;
		code.insert(long long(d*10000));
	}
	while (true){
		in >> d;
		if (in.eof())
			break;
		if (code.find(long long(d*10000)) != code.end())
			out << "YES";
		else 
			out << "NO";
		out << '\n';
	}
	in.close();
	out.close();
	return 0;
}