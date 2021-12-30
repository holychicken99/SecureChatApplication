#include <iostream>
#include <string>

//Room class, Identity class

void Help(){
    //Display the use of all command
}

void Join(){
    //Join a room given a room id
}

void ExitRoom(){
    //Leave all room and exit the program
}

void CreateRoom(){
    //Create a room and give it a unique id and room name, and the mode of the room: public or private
}

void Whisper(){
    //Whisper a secret message to the reciper of the same room given their name and unique id in that room, or maybe room id
}

void Browse(){
    //Display the list of all current public room, if the list of current room has size of more than 10, display the first 10 and if the user type in next, we move to the next 10 until no more room can be display
}

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

    bool running = true;
    while (running){
        std::string input;
        std::cin >> input;
        if (input[0] == '/'){
            //Handle the function
            
        } else {
            //Print the message to the current chat room we are in
            std::cout << "Message sent!!!"
                        << input << std::endl;
        }
    }

    return 0;
}