#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <vector>

using namespace std;
	vector < string > u;
	vector < bool* > used;
	int n = 0, m = 0;

void dfs (int x, int y){
	used[x][y] = false;
	if (x > 0 && u[x-1][y] == 'o' && used[x-1][y])
		dfs(x-1, y);
	if (y > 0 && u[x][y-1] == 'o' && used[x][y-1])
		dfs(x, y-1);
	if (x < n && u[x+1][y] == 'o' && used[x+1][y])
		dfs(x+1, y);
	if (y < m && u[x][y+1] == 'o' && used[x][y+1])
		dfs(x, y+1);
}

int main() {
	setlocale(LC_ALL, "Russian");
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	string s;
	int i, j;
	int ans = 0;
	while (true){
		getline(in, s);
		if (in.eof())
			break;
		if (n == 0)
			m = s.length();
		u.push_back(s);
		used.push_back(new bool [m]);
		n++;
	}
	n--;
	m--;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= m; j++)
			if (u[i][j] == 'o' && used[i][j]){
				ans++;
				dfs(i, j);
			}
	out << ans;
	in.close();
	out.close();
	return 0;
}