
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int randomnum(int num);

std::vector<std::string> commandDictonary = {"done", "add", "finish", "draw",
                                             "help"};

void checkInput() {
    bool isTerminated = false;
    bool validCommand = false;
    bool addedChoices = false;
    bool hasCheckedDictionary = false;
    std::string input;

    std::vector<std::string> choiceArr{};

    bool isaddingChoices = false;

    // this loop checks to see if the user has entered "done", if so, theW program will close.
    while (!isTerminated) {
        // using getline because it doesn't consider spaces the delimter unlike  std::cin with the << operator.
        std::getline(std::cin, input);
        validCommand = false;
        // sorry about this if else ladder, but i was too far in programming to add constexpr or char switch statements.
        if (input == "help") {
            std::cout
                << " USAGE: enter add to add choices,"
                   " enter done to quit "
                   "program, and enter finish when all choices are picked. "
                   "After using the finish command, \n use draw to pick a random "
                   "choice. The program will consider anything entered to "
                   "be a option unless you enter finish."
                << "\n";

            // we are now adding choices and ask the user for input
        } else if (input == "add") {
            isaddingChoices = true;
            std::cout << "Enter  Choices:" << "\n";
            std::getline(std::cin, input);  // grabs input again so the add comand is not added to the array.

           
        } else if (input == "done") {     // we end the program if done is entered, it is also a valid command.
            validCommand = true;
            break;  
                    
        } else if (input == "draw" && !isaddingChoices) {   // only executes if we say finish, otherwise we would be adding draw as an option.
           
 
         
            if (addedChoices) {   // if we actually added choices we randomize everything, without this check, the program 
                                  // crashes trying to randomize the empty choiceArr.
                // randmozing it twice prevents it from always picking the second option (if the user only enters two.)
                int numChoices = randomnum(choiceArr.size());
                numChoices = randomnum(choiceArr.size());
                // we output the random object picked in choiceArr.
                std::cout << "The program has spoken, your choice is: "
                          << choiceArr[numChoices] << ".";

            } else {
                std::cout << "No choices were added, try adding some and rerun "
                             "the program."
                          << "\n";
                break;
            }

        } else if (input == "finish") {
            validCommand = true;
        } else if (!isaddingChoices && !validCommand) {
            std::cout << input << " is not a valid command."
                      << "\n";  // if we aren't adding choices and it isn't a  valid command, ouput to the user that the command is invalid.
            // this else-if also prevents input the user is adding to be considered invalid.
        }

        if (isaddingChoices) {
            if (input == "finish") {
                validCommand = true;
                isaddingChoices = false;
                std::cout << "Finished adding choices."
                          << "\n";  // finished adding choices.
            } else if (isaddingChoices) {
                choiceArr.push_back(input);
                std::cout << "Choice added: " << input
                          << "\n";  // we are not finished and we pass all input to the array.
            }
            if (choiceArr.size() > 0) {
                addedChoices = true;
            }
        }
    }
}
//}
