#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include "gotoxy.h"

using namespace std;
//create a struct for pacman, should keep x and y location and keep what it looks like
struct pacMan {
	int locationX = 0; 
	int locationY = 0;
	char character = '@';
};

//loading function, load map, load into vector
void load() {
	vector<string> map;
	string myStr;

	ifstream infile("map2.txt");
	while (getline(infile,myStr)) {
		map.push_back(myStr);
	}
}

//move function
bool canMove(int locX, int locY) {
	char boundary = '#';
	char food = 'x';

	return true;
}

//move function to see if it is okay to do in the while loop
//after and is the move function if return true then you can move

int main()
{
	struct pacMan theBoi;

	//create move right, move left, move up, move down variables for when the keypress is true
	bool game_running = true;

	do {
		gotoxy(0, 0);




		system("pause>nul");

		//arrow down
		//check for where that is and if it can move there, then move
		if (GetAsyncKeyState(VK_DOWN) && canMove(theBoi.locationX,theBoi.locationY+1)) {
			theBoi.locationY += 1;
 			
		}

		//arrow up
		if (GetAsyncKeyState(VK_UP) && canMove(theBoi.locationX,theBoi.locationY-1)) {
			theBoi.locationY -= 1;

		}

		//arrow right
		if (GetAsyncKeyState(VK_RIGHT) && canMove(theBoi.locationX+1,theBoi.locationY)) {
			theBoi.locationX += 1;

		}

		//arrow left
		if (GetAsyncKeyState(VK_LEFT) && canMove(theBoi.locationX-1, theBoi.locationY)) {
			theBoi.locationX -= 1;

		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			game_running = false;
		}

	} while (game_running == true);

	system("cls");
	cout << "GAME OVER";

	return 0;
}