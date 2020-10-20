#include<bits/stdc++.h>
using namespace std;

bool ratinMaze(char maze[10][10], int sol[][10], int i, int j, int m, int n) {
	if (i == m && j == n) {
		sol[m][n] = 1;
		//print on hold
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		return true;
	}

	//Rat should not go outside
	if (i > m || j > n) {
		return false;
	}
	if (maze[i][j] == 'X') {
		return false;
	}

	sol[i][j] = 1;

	bool rightSuccess = ratinMaze(maze, sol, i, j + 1, m, n);
	bool downSuccess = ratinMaze(maze, sol, i + 1, j, m, n);

	//Backtracking
	sol[i][j] = 0;

	if (rightSuccess || downSuccess) {
		return true;
	}
	return false;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00",
	};

	int sol[10][10] = {0};

	int n = 4, m = 4;

	bool ans = ratinMaze(maze, sol, 0, 0, m - 1, n - 1);

	if (ans == false)
	{
		cout << "Path does not exist" << endl;
	}

	return 0;
}
