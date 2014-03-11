#include <fstream>
#include <algorithm> 
#include <string>
using namespace std;

bool pred(char c) {
	return (c == ' ' || c == '-' || c == '\\');
}

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	string s;
	string subs;
	getline(in, s);
	s.erase(remove_if(s.begin(), s.end(), pred), s.end());
	transform(s.begin(), s.end(), s.begin(), tolower);
	while (true){
		getline(in, subs);
		if (in.eof()) 
			break;
		subs.erase(remove_if(subs.begin(), subs.end(), pred), subs.end());
	    transform(subs.begin(), subs.end(), subs.begin(), tolower);
		reverse(subs.begin(), subs.end());
		if (s.find(subs, 0) != string::npos)
			out << "YES";
		else
			out << "NO";
		out << '\n';
	}
	in.close();
	out.close();
	return 0;
}