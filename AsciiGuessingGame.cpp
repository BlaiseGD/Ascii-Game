#include <iostream>
#include <random>
using namespace std;

int main(){
    cout << "This is an Ascii guessing game or memory test if you're really a wiz! Have fun!\n" << "This will only include from ascii 33 to 126 and you have 3 lives\n\n";
    int lives = 3;
    int correctCount = 0;
    char asciiVal;

    while(lives != 0){
        srand(time(NULL));
        random_device rd; //gets a random number from hardware
        mt19937 gen(rd()); //seeds the generation
        uniform_int_distribution<> distr(33,126); //defines range
        int randNum = distr(gen); //assign the randomly generated num to an int
        cout << randNum << '\n'; 
        cout << "What is the character for this ascii value?\n";

        cin >> asciiVal;
        if(asciiVal== randNum){
            system("clear");
            cout << "Congratulations you are correct\n";
            correctCount += 1; //adds to your score aka amount correct
        }
        else{
            system("clear");
            cout << "That is incorrect\n";
            lives -= 1; //takes off a life
        }
    }
    cout << "Here is a list of the Ascii values with their corresponding characters\n";
    int i; //this is the decimal number for the ascii character
    char j; //this will be used to iterate through the ascii characters
    for(i = '!', j = 33; i <= '~', j <= 126; i++, j++){
        cout << "Character for Ascii value " << i << " is " << j << '\n';
    }
    cout << "\nYou had a score of " << correctCount << " Nice Job!\n";
    return 0;
}
