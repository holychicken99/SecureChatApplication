#include <iostream>
#include <string>
#include <vector>

// Room class, Identity class

void Help()
{
    // Display the use of all command
    std::cout << "Execute Help function" << std::endl;
}

void Leave(std::vector<std::string> &arr)
{
    if (arr.size() == 1)
    {
        std::cout << "Leave the current Room" << std::endl;
    }
    else if (arr.size() == 2)
    {
        for (char c : arr[1])
        {
            if (c < 48 || c > 57)
            {
                std::cout << "The unique group id must be a number sequence" << std::endl;
                return;
            }
        }
        // Need a for loop to check if the room is exist
        std::cout << "Leaving room " << arr[1] << std::endl;
    }
}

void Join(std::vector<std::string> &arr)
{
    // Join a room given a room id
    if (arr.size() == 1)
    {
        std::cout << "Displaying all list of unique id the user want to join" << std::endl;
    }
    else if (arr.size() == 2)
    {
        for (char c : arr[1])
            if (c < 48 || c > 57)
            {
                std::cout << "The unique group id must be a number sequence" << std::endl;
                return;
            }
        std::cout << "Joining room " << arr[1] << std::endl;
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
    }
}

void Exit()
{
    // Leave all room and exit the program
    std::cout << "Leaving all room" << std::endl;
}

void CreateRoom(std::vector<std::string> &arr)
{
    // Create a room and give it a unique id and room name, and the mode of the room: public or private
    if (arr.size() == 1)
    {
        std::string name, type;
        std::cout << "Please enter your room name: ";
        std::cin >> name;
        std::cout << std::endl;
        std::cout << "Please enter your type of room: ";
        while (true)
        {
            std::cin >> type;
            if (type != "public" && type != "private")
                std::cout << "Invalid type!! Room can only be in public or private" << std::endl;
            else
                break;
        }
    }
    else if (arr.size() == 3)
    {
        std::string name(arr[1]), type(arr[2]);
        // should we restrict room name to only lowercase alphabet letter or it can be anything?
        if (type != "public" && type != "private")
            std::cout << "Invalid type!! Room can only be in public or private" << std::endl;
        std::cout << "Creating room " << name << std::endl;
    }
    else
    {
        std::cout << "Invalid input!!" << std::endl;
    }
}

void Whisper(std::vector<std::string> &arr)
{
    // To execute on command line /whisper recipent1 recipent2 "Message"
    //  Whisper a secret message to the reciper of the same room given their name and unique id in that room, or maybe room id
    std::cout << "Execute Whisper function" << std::endl;
    // We need a loop to check if the user name is valid
    for (int i(1); i < arr.size() - 1; i++)
    {
        std::cout << "Sending message " << arr[arr.size() - 1] << " to " << arr[i] << std::endl;
    }
}

void Browse()
{
    // Display the list of all current public room, if the list of current room has size of more than 10, display the first 10 and if the user type in next, we move to the next 10 until no more room can be display
    std::cout << "Execute Browse function" << std::endl;
}

void PrintWelcome()
{

    std::cout << "Welcome to your new Secure Chat Application! \n\n\n";
    std::cout << "To use a command, please start the command with a '/' to signify a system command \n\n";
    std::cout << "Commands:\n/help --display all user commands \n/home --brings the user back to a home screen\n";
    std::cout << "/join <unique group key> --user joins the group with the specified key\n";
    std::cout << "/create --creates a new chat room\n/leave <unique group key> --group key is optional, if no key is supplied, then the current group will be left\n";
    std::cout << "/exit --leave all groups, and exit the program\n";
    std::cout << "/whisper <recipient 1, recipient 2, ...> --send a message directly to one or more members of a group without sending to the group as a whole)\n";
    std::cout << "/browse --browse the list of public open chat rooms\n\n\n";
}

std::vector<std::string> VectorString(std::string &input)
{

    std::vector<std::string> result;
    std::string temp;
    bool flag = true;
    for (char s : input)
    {
        if (s == '"')
        {
            flag = !flag;
            continue;
        }
        if (s == ' ' && flag)
        {
            result.push_back(temp);
            temp = "";
        }
        else
        {
            temp = temp + s;
        }
    }
    result.push_back(temp);
    return result;
}

// Both /join "idroom" and /join and then the user will be display with a board of room id have to work

int main()
{

    PrintWelcome();

    bool running = true;

    while (running)
    {
        std::string input;
        std::getline(std::cin, input);
        if (input[0] == '/')
        {
            // Handle the function
            std::vector<std::string> temp = VectorString(input);
            if (temp[0] == "/help")
            {
                Help();
            }
            else if (temp[0] == "/leave")
            {
                Leave(temp);
            }
            else if (temp[0] == "/join")
            {
                Join(temp);
            }
            else if (temp[0] == "/exit")
            {
                Exit();
                break;
            }
            else if (temp[0] == "/create")
            {
                CreateRoom(temp);
            }
            else if (temp[0] == "/whisper")
            {
                Whisper(temp);
            }
            else if (temp[0] == "/browse")
            {
                Browse();
            }
            else
            {
                std::cout << "The command does not exist" << std::endl;
            }
        }
        else
        {
            // Print the message to the current chat room we are in
            std::cout << "Message sent!!!"
                      << input << std::endl;
        }
    }

    return 0;
}