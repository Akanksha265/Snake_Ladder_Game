#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

int dice() {
    return random(1, 6);
}

// void clearScreen() {
//     system("cls");
// }

int main() {
    // Initialize random seed once
    srand(static_cast<unsigned int>(time(0)));
    
    int ladder[] = {10, 18, 23, 38, 41, 59, 70, 88};
    int snake[] = {15, 25, 37, 40, 65, 92, 99};
    const int board = 100;
    const int maxPlayer = 2;
    bool gameOver = false;
    int current[maxPlayer] = {0};
    int player = 0;

    while (!gameOver) {
        system("cls");
        cout << "WELCOME TO THE GAME OF SNAKES AND LADDERS!!" << endl;
        cout << "Current player: " << player + 1 << endl;
        cout << "--------------------------------------------------" << endl;
        
        for (int i = 0; i < maxPlayer; i++) {
            cout << "Player " << i + 1 << " is at position " << current[i] << endl;
        }
        
        cout << "--------------------------------------------------" << endl;

        int roll = dice();
        cout << "Player " << player + 1 << " rolled and got " << roll << endl;
        current[player] += roll;

        if (current[player] >= board) {
            current[player] = board;  // Ensure the position does not exceed the board
            cout << "Congratulations, Player " << player + 1 << " won!!" << endl;
            gameOver = true;
            cout << "GAME IS OVER!" << endl;
            cout << "THANKS FOR PLAYING!" << endl;
            break;
        }

        for (int i = 0; i < sizeof(ladder) / sizeof(ladder[0]); i++) {
            if (current[player] == ladder[i]) {
                int ladderRoll = dice();
                cout << "Player " << player + 1 << " climbs a ladder and moves up by " << ladderRoll << endl;
                current[player] += ladderRoll;
                if (current[player] > board) current[player] = board;  // Ensure the position does not exceed the board
            }
        }

        for (int i = 0; i < sizeof(snake) / sizeof(snake[0]); i++) {
            if (current[player] == snake[i]) {
                int snakeRoll = dice();
                cout << "Player " << player + 1 << " bitten by a snake and moves down by " << snakeRoll << endl;
                current[player] -= snakeRoll;
                if (current[player] < 0) current[player] = 0;  // Ensure the position does not go below 0
            }
        }

        player = (player + 1) % maxPlayer;
        system("pause");  // For Windows, to pause between turns
    }

    return 0;
}
