#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int range = 100;

int generateRandomNumber() {
    srand(time(NULL));
    return rand() % range + 1; // 1 -> range
}

bool print_answer(int guess, int secretNumber) {
    if(guess == secretNumber) 
    {
        cout << "You win" << endl;
        return true;
    }
    else 
    {   
        cout << "NOOB guess again" << endl;
        return false;        
    }
}

void solve_guess_random() {
    int secretNumber = generateRandomNumber();
    int guess;
    int turn = 0;
    do {
        cin >> guess;
        bool ok = print_answer(guess,secretNumber);
        if(ok) break;
        turn++;
        if(turn == 3) {
            cout << "You lose" << endl;
        }
    } while(guess != secretNumber); 
}

void solve_order() {
    int secretNumber = generateRandomNumber();
    int guess;
    int answer = 1;
    bool ok = false;
    int turn = 0;
    do {
        ok = print_answer(answer,secretNumber);
        turn++;
        if(!ok) answer++; 
    } while(!ok);
    cout << secretNumber << ' ' << turn << endl;
}

void solve_binary() {
    int secretNumber = generateRandomNumber();
    int guess;
    int low = 1;
    int high = range;
    int turn = 0;
    bool ok;
    do {
        guess = (low+high) / 2;
        ok = print_answer(guess,secretNumber);
        turn++;
        if(guess > secretNumber) {
            high = guess - 1;
        }
        else {
            low = guess + 1;
        }
    } while(!ok);
    cout << secretNumber << ' ' << turn << endl;
}

int main() {
    int mode; cin >> mode;
    cout << "choose mod for solution:" << endl;

    switch(mode) 
    {
        case 1:
            solve_guess_random();
            break;
        case 2:
            solve_order();
            break;
        case 3:
            solve_binary();
            break;
    } 

    return 0;
}