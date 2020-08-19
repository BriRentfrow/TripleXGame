//Game called Triple X where you guess numbers

#include <iostream> //ignore error here
#include <ctime>

void PrintIntro(){
//Print Welcome
    std::cout << "You are trapped in an abandoned government building seeking your way out.\n";
    std::cout << "You come up to the door and find a keypad. Input the correct numbers to continue....\n\n";

}

bool PlayGame(int Level){

    //Declare 3-number code
    const int CodeA = rand() % Level + Level;
    const int CodeB = rand() % Level + Level;
    const int CodeC = rand() % Level + Level;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //print sum and product
    std::cout << "You are on floor " << Level << std::endl;
    std::cout << "The code has 3 numbers\n";
    std::cout << "The numbers add up to: " << CodeSum;
    std::cout << "\nThe numbers multiply to: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "\nYour guess is: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if((CodeSum == GuessSum) && (CodeProduct == GuessProduct)){
       std::cout << "\n***You put in the correct code! You enter through the door.***\n";
       return true;
    }
    else{
        std::cout << "\n***BEEP BEEP Wrong code, try again!***\n";
        return false;
    }

}

int main(){ 

    srand(time(NULL)); //change seed based on time of day

    int LevelDifficulty = 1;
    int MaxDifficulty = 5;


    PrintIntro();

    while(LevelDifficulty <= MaxDifficulty){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        //PlayGame(LevelDifficulty);
        std::cin.clear(); //clears errors
        std::cin.ignore(); //discards buffer

        if(bLevelComplete){
        ++LevelDifficulty;
    }
    }
    
    std::cout << "\n***That was the last door, you have escaped the facility!***\n";

    return 0; 
}