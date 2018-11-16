#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int grid[9][9];

int boxCheck(int n,int a,int b) {
	for (int a1 = a * 3; a1 < a * 3 + 3; a1++) {
		for (int b1 = b * 3; b1 < b * 3 + 3; b1++) {
			if (grid[b1][a1] == n) {
				return 0;
			}
		}
	}
	return 1;
}

int rowCheck(int n,int b) {
	for (int a1 = 0; a1 < 9; a1++) {
		if (grid[a1][b] == n) {
			return 0;
		}
	}
	return 1;
}

int coloumnCheck(int n,int b) {
	for (int a1 = 0; a1 < 9; a1++) {
		if (grid[b][a1] == n) {
			return 0;
		}
	}
	return 1;
}


int main() {
	int x, y, i, j, o, p;
	string temp;
	int looper, lc = 0;
	int n;
	int checker = 0;
	int completion = 0;
	n = 0;
	string puzzle;
	cout << "Welcome! Enter your puzzle in a continuous line (Row by Row)! No Spaces\nUse 0s instead of spaces. \nExample: 003020600900305001001806400008102900700000008006708200002609500800203009005010300\n\nEnter your puzzle:";
	cin >> puzzle;
	for (y = 0; y < 9; y++) {
		for (x = 0; x < 9; x++) {
			temp = puzzle[n];
			grid[x][y] = std::stoi(temp);
			n += 1;
			cout << " | " << grid[x][y];
		}
		cout << endl;
	}
	while (completion == 0) {
		for (y = 0; y < 3; y++) {
			for (x = 0; x < 3; x++) {
				for (i = y * 3; i < (y * 3) + 3; i++) {
					for (j = x * 3; j < (x * 3) + 3; j++) {
						if (grid[j][i] == 0) {
							checker = 0;
							looper = 0;
							for (n = 1; n < 10; n++) {
								if (boxCheck(n, y, x) == 1 && rowCheck(n, i) == 1 && coloumnCheck(n, j) == 1) {
									checker++;
								}
								if (checker == 1) {
									looper++;
								}
							}
							if (checker == 1) {
								cout << j << i;
								cout << checker;
								cout << looper << endl;
								grid[j][i] = 10 - looper;
								lc = 0;
								for (o = 0; o < 9; o++) {
									for (p = 0; p < 9; p++) {
										cout << " | " << grid[p][o];
									}
									cout << endl;
								}
								cout << endl;
							}
						}
					}
				}
			}
		}
		lc++;
		if (lc > 1) {
			//boxes
			for (y = 0; y < 3; y++) {
				for (x = 0; x < 3; x++) {
					for (n = 1; n < 10; n++) {
						checker = 0;
						for (i = y * 3; i < (y * 3) + 3; i++) {
							for (j = x * 3; j < (x * 3) + 3; j++) {
								if (boxCheck(n, y, x) == 0 || rowCheck(n, i) == 0 || coloumnCheck(n, j) == 0 || grid[j][i] != 0) {
									checker++;
								}
								else {
									o = j;
									p = i;
								}
							}
						}
						if (checker == 8) {
							grid[o][p] = n;
							lc = 0;
							cout << checker;
						}
					}
				}
			}

			//rows
			for (n = 1; n < 10; n++) {
				for (i = 0; i < 9; i++) {
					checker = 0;
					for (j = 0; j < 9; j++) {
						x = j / 3;
						y = i / 3;
						if (boxCheck(n, y, x) == 0 || rowCheck(n, i) == 0 || coloumnCheck(n, j) == 0 || grid[j][i] != 0) {
							checker++;
						}
						else {
							o = j;
							p = i;
						}
					}
					if (checker == 8) {
						grid[o][p] = n;
						for (o = 0; o < 9; o++) {
							for (p = 0; p < 9; p++) {
								cout << " | " << grid[p][o];
							}
							cout << endl;
						}
						cout << endl;
					}
				}
			}

			//coloumns
			for (n = 1; n < 10; n++) {
				for (j = 0; j < 9; j++) {
					checker = 0;
					for (i = 0; i < 9; i++) {
						x = j / 3;
						y = i / 3;
						if (boxCheck(n, y, x) == 0 || rowCheck(n, i) == 0 || coloumnCheck(n, j) == 0 || grid[j][i] != 0) {
							checker++;
						}
						else {
							o = j;
							p = i;
						}
					}
					if (checker == 8) {
						grid[o][p] = n;
						for (o = 0; o < 9; o++) {
							for (p = 0; p < 9; p++) {
								cout << " | " << grid[p][o];
							}
							cout << endl;
						}
						cout << endl;
					}
				}
			}
			lc = 0;
		}
		completion = 1;
		for (o = 0; o < 9; o++) {
			for (p = 0; p < 9; p++) {
				if (grid[p][o] == 0) {
					completion = 0;
				}
			}
		}

	}
	for (y = 0; y < 9; y++) {
		for (x = 0; x < 9; x++) {
			cout << " | " << grid[x][y] ;
		}
		cout << endl;
	}
	
	
	return 0;
}
