#include <iostream>





void PrintWelcome(){

    std::cout << "Welcome to your new Secure Chat Application! \n\n\n";
    std::cout << "To use a command, please start the command with a '/' to signify a system command \n\n";
    std::cout << "Commands:\n/help --display all user commands \n/home --brings the user back to a home screen\n";
    std::cout << "/join <unique group key> --user joins the group with the specified key\n";
    std::cout << "/create --creates a new chat room\n/leave <unique group key> --group key is optional, if no key is supplied, then the current group will be left\n";
    std::cout << "/exit --leave all groups, and exit the program\n";
    std::cout << "/whisper <recipient 1, recipient 2, ...> --send a message directly to one or more members of a group without sending to the group as a whole)\n";
    std::cout << "/browse --browse the list of public open chat rooms\n\n\n";


}






int main(){

    

    PrintWelcome();


    


    

    return 0;
}