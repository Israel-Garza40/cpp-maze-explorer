#include <iostream>
#include <limits>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;

void printMaze(int playerX, int playerY, int exitX, int exitY) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1 || (x % 3 == 0 && y % 2 == 0)) {
                cout << "#"; // Walls
            } else if (x == playerX && y == playerY) {
                cout << "P"; // Player
            } else if (x == exitX && y == exitY) {
                cout << "E"; // Exit
            } else {
                cout << "."; // Paths
            }
        }
        cout << endl;
    }
}

bool isWall(int x, int y) {
    return (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1 || (x % 3 == 0 && y % 2 == 0));
}

int main() {
    int playerX = 1, playerY = 1;
    int exitX = WIDTH - 2, exitY = HEIGHT - 2;
    char input;
    
    while (true) {
        system("cls");
        printMaze(playerX, playerY, exitX, exitY);
        
        if (playerX == exitX && playerY == exitY) {
            cout << "Congratulations! You've reached the exit!" << endl;
            break;
        }
        
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        int newX = playerX, newY = playerY;
        
        if (input == 'W' || input == 'w') newY--;
        else if (input == 'S' || input == 's') newY++;
        else if (input == 'A' || input == 'a') newX--;
        else if (input == 'D' || input == 'd') newX++;
        
        if (!isWall(newX, newY)) {
            playerX = newX;
            playerY = newY;
        }
    }
    return 0;
}
