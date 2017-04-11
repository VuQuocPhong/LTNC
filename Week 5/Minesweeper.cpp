#include <iostream>
#include <ctime>
#include <cstdlib>

#define NUM_OF_MINES 9

void initBoard (int *board, const int SIZE);
void generateMines (int *board, const int SIZE);
void generateBoard (int *board, const int SIZE);
void displayBoard (int *board, int *board_show, const int SIZE);
void generateHints (int *board, const int SIZE);

void playAGame (int *board, const int SIZE);
void getUserChoice (int &x, int &y, int *board_show, const int SIZE);
void proceedChoice (int x, int y, int *board, int *board_show, const int SIZE);
bool isMine (int *board_show, int x, int y, const int SIZE);
bool isWin (int *board_show, const int SIZE);
void expandDisplayArea (int x, int y, int *board, int *board_show, const int SIZE);
void showMines (int *board,int *board_show, const int SIZE);

int main(int argc, char const *argv[]) {
	srand(time(0));
	const int SIZE = 10;

	int board[SIZE][SIZE];
	initBoard((int*)board,SIZE);

	playAGame((int*)board,SIZE);
	return 0;
}

void initBoard (int *board, const int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			*(board+i*SIZE+j) = 0;
		}
	}
}

void generateMines (int *board, const int SIZE) {
	for (int i = 0; i < NUM_OF_MINES; ++i) {
		int x, y;
		do {
			x = rand() % SIZE;
			y = rand() % SIZE;
			//std::cout << x << " " << y << '\n';
		} while (*(board+y*SIZE+x) != 0);
		*(board+y*SIZE+x) = 9;
	}
}

void generateBoard (int *board, const int SIZE) {
	generateMines(board,SIZE);
	generateHints(board,SIZE);
}

void generateHints (int *board, const int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (*(board+i*SIZE+j) != 9) {
				int mine_surround = 0;
				if (j > 0 && *(board+i*SIZE+(j-1)) == 9) mine_surround++;
				if (j < SIZE-1 && *(board+i*SIZE+(j+1)) == 9) mine_surround++;
				if (i > 0 && *(board+(i-1)*SIZE+j) == 9) mine_surround++;
				if (i < SIZE-1 && *(board+(i+1)*SIZE+j) == 9) mine_surround++;
				if (i > 0 && j > 0 && *(board+(i-1)*SIZE+(j-1)) == 9) mine_surround++;
				if (i > 0 && j < SIZE-1 && *(board+(i-1)*SIZE+(j+1)) == 9) mine_surround++;
				if (i < SIZE-1 && j > 0 && *(board+(i+1)*SIZE+(j-1)) == 9) mine_surround++;
				if (i < SIZE-1 && j < SIZE-1 && *(board+(i+1)*SIZE+(j+1)) == 9) mine_surround++;
				*(board+i*SIZE+j) = mine_surround;
			}
		}
	}
}

void displayBoard (int *board,int *board_show, const int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (*(board_show+i*SIZE+j) == 1) { // just test...
				if (*(board+i*SIZE+j) == 0) std::cout << '+';
				else if (*(board+i*SIZE+j) <= 8 && *(board+i*SIZE+j) >= 1) std::cout << *(board+i*SIZE+j);
				else std::cout << '!';
					
			} else {
				std::cout << '-';
			}
		}
		std::cout << '\n';
	}
}

void playAGame (int *board, const int SIZE) {
	generateBoard((int*)board,SIZE);
	int board_show[SIZE][SIZE];		// 0-not display, 1-display
	initBoard((int*)board_show, SIZE);
	bool is_mine, is_win;

	do {
		system("cls");
		displayBoard(board,(int*)board_show,SIZE);
		int x_click, y_click;
		std::cout << '\n';
		getUserChoice(x_click,y_click,(int*)board_show,SIZE);
		is_mine = isMine(board,x_click,y_click,SIZE);
		is_win = isWin((int*)board_show,SIZE);
		if (!is_mine && !is_win) proceedChoice(x_click,y_click,board,(int*)board_show,SIZE);
	} while (!is_mine && !is_win);
	system("cls");
	showMines(board,(int*)board_show,SIZE);
	displayBoard(board,(int*)board_show,SIZE);
	is_mine ? (std::cout << "\nYOU LOST! BASTARD\n") : (std::cout << "\nYOU WON!??? BITCH!\n");
}

void getUserChoice (int &x, int &y, int* board_show, const int SIZE) {
	do {
		std::cout << "x: ";					//add constrains.
		std::cin >> x;
		std::cout << "y: ";
		std::cin >> y;
		x--;
		y--; 
	} while (x >= SIZE || x < 0 && y || SIZE && y < 0 || *(board_show+y*SIZE+x) == 1);		//to get proper index.
}

void proceedChoice (int x, int y, int *board, int *board_show, const int SIZE) {
	if (*(board+y*SIZE+x) >= 1 && *(board+y*SIZE+x) <= 8) {
		*(board_show+y*SIZE+x) = 1;
	} else {
		expandDisplayArea (x,y,board,board_show,SIZE);		
	}
}

void expandDisplayArea (int x, int y, int *board, int *board_show, const int SIZE) {
	if (!isMine(board,x,y,SIZE)) *(board_show+y*SIZE+x) = 1;
	if (*(board+y*SIZE+x) >=1 && *(board+y*SIZE+x) <= 8) return;

	if (x > 0 && *(board_show+y*SIZE+x-1) == 0) expandDisplayArea(x-1,y,board,board_show,SIZE);
	if (x < SIZE-1 && *(board_show+y*SIZE+x+1) == 0) expandDisplayArea(x+1,y,board,board_show,SIZE);
	if (y > 0 && *(board_show+(y-1)*SIZE+x) == 0) expandDisplayArea(x,y-1,board,board_show,SIZE);
	if (y < SIZE-1 && *(board_show+(y+1)*SIZE+x) == 0) expandDisplayArea(x,y+1,board,board_show,SIZE);
}

bool isMine (int *board, int x, int y,const int SIZE) {
	return (*(board+y*SIZE+x) == 9); 
}

bool isWin (int *board_show, const int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (*(board_show+i*SIZE+j) == 0) return false;
		}
	}
	return true;
}

void showMines (int *board,int *board_show, const int SIZE) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (*(board+i*SIZE+j) == 9) *(board_show+i*SIZE+j) = 1;
		}
	}
}