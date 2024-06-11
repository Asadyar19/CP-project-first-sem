#include <iostream>//included for cin and cout
#include <windows.h>//included to change color of text
#include <ctime>//included for time functions
#include <cstdlib>//included for system() function
#include <conio.h>//included for _getch()
#include <string>//include for string functions
#include <fstream> // Include for file handling

using namespace std;
//colors used in the project
const int white = 7;
const int red = 12;
const int cyan = 11;

struct user
{
    string username;
    string email;
    string password;
};
// Function prototypes
void wishme();
void datetime();
void arithmetic();
void log(const string& username, const string& query, const string& response);
void setColor(int color);
void virtualAssistant(const string& username);
void login();
void signUp();
void forgot();
//Main Function
int main()
{
    char choice;
    do//do while loop for the program to repeat until user exits
    {
        setColor(cyan);//sets text color to cyan
        //Welcome Header
        cout << "\t\t    <================================================= W E L C O M E =====================================================>" << endl;
        cout << "\t\t    <============================================= I'M YOUR VIRTUAL ASSISTANT ============================================>" << endl;
        cout << "\t\t    <================================================ MY NAME IS ARIA ====================================================>" << endl;
        cout << "\t\t    <============================================== I'M HERE TO HELP YOU =================================================>" << endl << endl;
        setColor(white);//sets color back to white
        //Choice for user login system
        cout << "\n1- Login";
        cout << "\n2- Sign-Up";
        cout << "\n3- Forgot Password";
        cout << "\n4- Exit";
        cout << "\nEnter Your Choice :: ";
        cin >> choice;

        cin.ignore();  // To consume the newline character left in the buffer by cin
        //switch statement for choice of user
        switch (choice) {
        case '1':
            login();//Login function called
            break;
        case '2':
            signUp();//Signup function called
            break;
        case '3':
            forgot();//Forgot password function is called
            break;
        case '4':
            system("cls");
            cout << "\n\nExiting program! GOODBYE!\n\n";
            _getch();
            return 0;//exits the program
        default:
            setColor(red);//sets color to red
            cout << "\nInvalid Selection...!" << endl;
            setColor(white);//sets color back to white
            _getch();
            system("cls");
        }
    } while (choice != '4');
    return 0;
}

void signUp()
{
    user newuser;
    system("cls");//Clears the screen
    cout << "\n----------SIGN UP---------" << endl << endl;
    cout << "=======================" << endl;
    cout << "| ENTER YOUR USERNAME |" << endl;
    cout << "=======================" << endl << endl;
    getline(cin, newuser.username);//User input in the string
    cout << "\n============================" << endl;
    cout << "| ENTER YOUR EMAIL ADDRESS |" << endl;
    cout << "============================" << endl << endl;
    getline(cin, newuser.email);
    cout << "\n=======================" << endl;
    cout << "| ENTER YOUR PASSWORD |" << endl;
    cout << "=======================" << endl << endl;
    getline(cin, newuser.password);
    cout << "\nAccount registration successful";
    cout << "\n\nPress any key to continue ";
    _getch();//gets character
    system("cls");
    fstream file;//declare variable for file
    file.open("loginData.txt", ios::out | ios::app);//open file in append mode
    file << newuser.username << "*" << newuser.email << "*" << newuser.password << endl;//Enter data into the file
    file.close();//closes the file
}

void login()
{
    string searchName, searchPass;
    user currentuser;
    system("cls");
    cout << "\n----------LOGIN---------" << endl << endl;
    cout << "=======================" << endl;
    cout << "| ENTER YOUR USERNAME |" << endl;
    cout << "=======================" << endl << endl;
    getline(cin, searchName);
    cout << "\n=======================" << endl;
    cout << "| ENTER YOUR PASSWORD |" << endl;
    cout << "=======================" << endl << endl;
    getline(cin, searchPass);

    fstream file;
    file.open("loginData.txt", ios::in);//open file in read mode(ifstream)

    bool found = false;
    while (getline(file, currentuser.username, '*') && getline(file, currentuser.email, '*') && getline(file, currentuser.password, '\n'))//gets the username,email and password from the file in a string
    {
        if (currentuser.username == searchName)//compares the Name input by user and Usernames in the file
        {
            if (currentuser.password == searchPass)//compares the Password input by user and password of the respective user in the file 
            {
                cout << "\nAccount Login Successful...!" << endl;
                found = true;//bool value is converted in case of account found
                cout << "\nPress any key to continue ";
                _getch();
                virtualAssistant(searchName);  // Start the virtual assistant after successful login
                break;
            }
            else
            {
                cout << "Password is Incorrect...!" << endl;
                found = true;
                break;
            }
        }
    }

    if (!found)//if bool value is not true the condition becomes true and user not found is displayed
    {
        cout << endl << "User not found...!" << endl;
        cout << "\nPress any key to continue ";
        _getch();
    }
    file.close();//closes file
    system("cls");
}

void forgot()
{
    user forgotpass;
    string searchName, searchEmail;
    system("cls");
    cout << "\n----------FORGOT PASSWORD---------" << endl << endl;
    cout << "=======================" << endl;
    cout << "| ENTER YOUR USERNAME |" << endl;
    cout << "=======================" << endl << endl;
    getline(cin, searchName);
    cout << "\n============================" << endl;
    cout << "| ENTER YOUR EMAIL ADDRESS |" << endl;
    cout << "============================" << endl << endl;
    getline(cin, searchEmail);

    fstream file;
    file.open("loginData.txt", ios::in);//opens file in read mode (ifstream)

    bool found = false;
    while (getline(file, forgotpass.username, '*') && getline(file, forgotpass.email, '*') && getline(file, forgotpass.password, '\n'))
    {
        //username and email are compared
        if (forgotpass.username == searchName)
        {
            if (forgotpass.email == searchEmail)
            {
                //password is output in case of found
                cout << "\nAccount Found...!" << endl;
                cout << "Your Password :: " << forgotpass.password << endl;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "\nNot found...!" << endl;
    }
    cout << "\nPress any key to continue ";
    _getch();
    file.close();
    system("cls");
}

void virtualAssistant(const string& username)//username is passed by reference So that the history can be stored in different files 
{
    system("cls");
    setColor(cyan);
    cout << "\t\t    <================================================= W E L C O M E =====================================================>" << endl;
    cout << "\t\t    <============================================= I'M YOUR VIRTUAL ASSISTANT ============================================>" << endl;
    cout << "\t\t    <================================================ MY NAME IS ARIA ====================================================>" << endl;
    cout << "\t\t    <============================================== I'M HERE TO HELP YOU =================================================>" << endl << endl;
    setColor(white);
    char ch[100]; // to take command from the user

    ofstream logfile(username + "_log.txt", ios::app); // Open log file for the current user
    cout << "\n<==================================================================================================>\n\n";
    wishme();//wishme function called
    do //do while loop so that the same thing repeats till user exits
    {
        cout << "\n<==================================================================================================>\n\n";
        cout << endl << "How may I help you Sir...." << endl << endl;
        //Command are compared using string compare function (strcmp)
        cout << "Your query ===> ";
        setColor(cyan);
        cin.getline(ch, 100);//takes query from user
        setColor(white);
        cout << endl;
        cout << "Result ===> ";

        string response;//string used to store the queries in file
        //Greetings and Goodbye questions
        if (strcmp(ch, "hi") == 0 || strcmp(ch, "hey") == 0 || strcmp(ch, "hello") == 0 || strcmp(ch, "Hi") == 0 || strcmp(ch, "Hello") == 0 || strcmp(ch, "Hey") == 0)
        {
            response = "Hello Sir.....";//stores the answer in response string
            cout << response << endl;//Displays the response string
        }
        else if (strcmp(ch, "bye") == 0 || strcmp(ch, "stop") == 0 || strcmp(ch, "exit") == 0 || strcmp(ch, "Stop") == 0 || strcmp(ch, "Bye") == 0 || strcmp(ch, "Exit") == 0 || strcmp(ch, "BYE") == 0)
        {
            response = "Good Bye sir, have a nice day!!!!";
            log(username, ch, response);//username,query and response is passed to log function
            cout << response << endl;
            logfile.close();//history file is closed 
            _getch();
            return;//returns to main function
        }
        //Displays history of current user
        else if (strcmp(ch, "history") == 0 || strcmp(ch, "log") == 0 || strcmp(ch, "show history") == 0 || strcmp(ch, "open log") == 0)
        {
            ifstream historyfile(username + "_log.txt");//open file in read mode using ifstream (specific file for current user is opened using username+"_log.txt")
            if (historyfile.is_open())//checks if file is opened
            {
                response = "Displaying your query history:";
                cout << response << endl << endl;
                string line;
                while (getline(historyfile, line))//gets input in string from historyfile 
                {
                    cout << line << endl;
                }
                historyfile.close();//closes file
            }
        }
        //clears history of current user
        else if (strcmp(ch, "clear history") == 0 || strcmp(ch, "erase history") == 0 || strcmp(ch, "clear log") == 0 || strcmp(ch, "erase log") == 0 || strcmp(ch, "delete history") == 0 || strcmp(ch, "delete log") == 0)
        {
            ofstream clearfile(username + "_log.txt", ios::trunc); // Open the file in truncate mode to clear it
            if (clearfile.is_open())//checks if file is opened
            {
                cout << "History cleared successfully.\n";
                clearfile.close();//closes file
            }
            else
            {
                cout << "Failed to clear history.\n";
            }
            response = "Cleared query history";
        }
        //Performs Arithmetic operations
        else if (strcmp(ch, "Arithmetic") == 0 || strcmp(ch, "Arithmetic operation") == 0 || strcmp(ch, "arithmetic") == 0 || strcmp(ch, "arithmetic operation") == 0 || strcmp(ch, "calculate") == 0 || strcmp(ch, "ARITHMETIC") == 0 || strcmp(ch, "ARITHMETIC OPERATION") == 0)
        {
            arithmetic();//arithmetic function is called
            response = "Performed arithmetic operation";
            cout << response << endl;
        }
        //Introduction questions
        else if (strcmp(ch, "who are you") == 0 || strcmp(ch, "tell me about yourself") == 0 || strcmp(ch, "about") == 0)
        {
            response = "I'm a virtual assistant created by Asad and Maryam";
            cout << response << endl;
        }
        else if (strcmp(ch, "what is your name?") == 0)
        {
            response = "I'm Aria.";
            cout << response << endl;
        }
        else if (strcmp(ch, "how are you") == 0 || strcmp(ch, "whatsup") == 0 || strcmp(ch, "how was your day") == 0)
        {
            response = "I'm good sir, tell me how may I help you..";
            cout << response << endl;
        }
        //Displays date and time
        else if (strcmp(ch, "time") == 0 || strcmp(ch, "date") == 0 || strcmp(ch, "date and time") == 0 || strcmp(ch, "what is date and time") == 0 || strcmp(ch, "what is the date today") == 0)
        {
            datetime();
            response = "Displayed date and time";
            cout << response << endl;
        }
        //University related questions
        else if (strcmp(ch, "what are the office hours of Sir Abrar") == 0)
        {
            response = "For Professor Sir Abrar Ahmed, office hours are Monday to Friday, 11:00 AM to 1:00 PM, in Room 105, Department of Computer Science.";
            cout << response << endl;
        }
        else if (strcmp(ch, "when is the next exam for bsit(1A)") == 0)
        {
            response = "The date sheet is out now, exams are in June. Refer to the course syllabus or the examination schedule on the university portal for exact dates.";
            cout << response << endl;
        }
        else if (strcmp(ch, "where is the library located?") == 0)
        {
            response = "The library is located on the ground floor of the Business Department at Bahria University E-8 Campus, Islamabad.";
            cout << response << endl;
        }
        else if (strcmp(ch, "what are the dining hall hours?") == 0)
        {
            response = "The dining hall operates from 8:00 AM to 8:00 PM, Monday to Saturday.";
            cout << response << endl;
        }
        else if (strcmp(ch, "how can I contact campus in case of a query?") == 0)
        {
            response = "Call the campus security hotline at (051)9260002 or visit the campus.";
            cout << response << endl;
        }
        else if (strcmp(ch, "how do I connect to the campus wifi?") == 0)
        {
            response = "Use your student credentials to log in to the BU Student Wi-Fi network. For assistance, visit the IT office on the first floor of Sir Syed block.";;
            cout << response << endl;
        }
        else if (strcmp(ch, "I forgot my wifi password can you help me reset it?") == 0)
        {
            response = "Visit the IT help desk in the main building of Sir Syed or use the password reset tool on the university portal.";
            cout << response << endl;
        }
        else if (strcmp(ch, "is there a computer lab available for student use?") == 0)
        {
            response = "Yes, there are several computer labs available in Sir Syed Block and Iqbal Block.";
            cout << response << endl;
        }
        else if (strcmp(ch, "what courses should I take for my major?") == 0)
        {
            response = "Consult your academic advisor or refer to the course curriculum guide available on the university portal.";
            cout << response << endl;
        }
        else if (strcmp(ch, "how can I improve my study habits?") == 0)
        {
            response = "Utilize the resources available at the Learning Center, join study groups, and make use of the library facilities.";
            cout << response << endl;
        }
        else if (strcmp(ch, "do you have any tips for managing stress during exams?") == 0)
        {
            response = "Practice relaxation techniques, manage your time well, and attend the stress management workshops offered by the university's counseling center.";
            cout << response << endl;
        }
        else if (strcmp(ch, "how can I provide feedback about my courses?") == 0)
        {
            response = "Fill out the course evaluation forms provided at the end of each semester through the university portal (LMS).";
            cout << response << endl;
        }
        else if (strcmp(ch, "can I suggest new features for the university website?") == 0)
        {
            response = "Yes, you can send your suggestions to the IT department via email or through the feedback form on the university website.";
            cout << response << endl;
        }
        else if (strcmp(ch, "is there a way to share my thoughts on campus facilities?") == 0)
        {
            response = "Submit your feedback through the campus services section on the university portal or contact the facilities management office.";
            cout << response << endl;
        }
        //Recommendation of good books
        else if (strcmp(ch, "recommend me a good book") == 0)
        {
            response = "\"The Art of Reading Minds\" by Henrik Fexeus.";
            cout << response << endl;
        }
        else if (strcmp(ch, "recommend me another good book") == 0)
        {
            response = "\"The Forty Rules of Love\" by Elif Shafaq.";
            cout << response << endl;
        }
        else if (strcmp(ch, "another book") == 0)
        {
            response = "\"All of my heart\" by Coolean Hoover.";
            cout << response << endl;
        }
        //Recommendation of good movies
        else if (strcmp(ch, "recommend me a good movie") == 0)
        {
            response = "Shawshank Redemption";
            cout << response << endl;
        }
        else if (strcmp(ch, "recommend me another good movie") == 0)
        {
            response = "Shutter Island";
            cout << response << endl;
        }
        else if (strcmp(ch, "another movie") == 0)
        {
            response = "Interstellar";
            cout << response << endl;
        }
        //Good Jokes
        else if (strcmp(ch, "Tell me a joke") == 0)
        {
            response = "Why did the man bring his watch to the bank?\nHe wanted to save time.";
            cout << response << endl;
        }
        else if (strcmp(ch, "tell me a joke") == 0)
        {
            response = "Did you hear about the guy who got the left side of his body amputated?\nHe’s all right now.";
            cout << response << endl;
        }
        else if (strcmp(ch, "Tell me a good joke") == 0)
        {
            response = "Why do cemeteries have fences around them?\nBecause everyone’s dying to get in.";
            cout << response << endl;
        }
        else if (strcmp(ch, "Another joke") == 0)
        {
            response = "Who was the roundest knight in King Arthur’s court?\nSir Cumference.";
            cout << response << endl;
        }
        else if (strcmp(ch, "another joke") == 0)
        {
            response = "What do rich people say when they tickle babies?\n\"Gucci, Gucci, goo.\"";
            cout << response << endl;
        }
        //Fun activities with friends
        else if (strcmp(ch, "fun activities to do with friends?") == 0)
        {
            response = "Join student clubs, participate in sports, or attend university events and cultural nights.";
            cout << response << endl;
        }
        //Conversation starting tips
        else if (strcmp(ch, "how do I start a conversation with someone new?") == 0)
        {
            response = "Start with a friendly greeting and ask about their course or interests.";
            cout << response << endl;
        }
        //Information seeking question
        else if (strcmp(ch, "what are you doing today?") == 0)
        {
            response = "Iam here to help you!";
            cout << response << endl;
        }
        //General Questions
        else if (strcmp(ch, "what is the primary gas in Earth's atmosphere?") == 0)
        {
            response = "The primary gas in Earth's atmosphere is nitrogen.";
            cout << response << endl;
        }
        else if (strcmp(ch, "who is known as the \"Father of Computers\"?") == 0)
        {
            response = "Charles Babbage is known as the \"Father of Computers.\"";
            cout << response << endl;
        }
        else if (strcmp(ch, "what is the freezing point of water in celsius?") == 0)
        {
            response = "The freezing point of water is 0°C.";
            cout << response << endl;
        }
        else if (strcmp(ch, "what is the largest mammal in the world?") == 0)
        {
            response = "The largest mammal in the world is the blue whale.";
            cout << response << endl;
        }
        else if (strcmp(ch, "what currency is used in Japan?") == 0)
        {
            response = "The currency used in Japan is the Japanese yen.";
            cout << response << endl;
        }
        else if (strcmp(ch, "who painted the Mona Lisa?") == 0)
        {
            response = "The Mona Lisa was painted by Leonardo da Vinci.";
            cout << response << endl;
        }
        else if (strcmp(ch, "how many colors are there in a rainbow?") == 0)
        {
            response = "There are seven colors in a rainbow.";
            cout << response << endl;
        }
        else if (strcmp(ch, "what is the smallest unit of life?") == 0)
        {
            response = "The smallest unit of life is the cell.";
            cout << response << endl;
        }
        else if (strcmp(ch, "which element has the atomic number 1?") == 0)
        {
            response = "The element with the atomic number 1 is hydrogen.";
            cout << response << endl;
        }
        else if (strcmp(ch, "what is the most widely spoken language in the world?") == 0)
        {
            response = "The most widely spoken language in the world is English.";
            cout << response << endl;
        }

        //Opening system applications
        else if (strcmp(ch, "open notepad") == 0)
        {
            response = "Opening notepad..";
            cout << response << endl;
            system("notepad");
        }
        else if (strcmp(ch, "open calculator") == 0)
        {
            response = "Opening calculator..";
            cout << response << endl;
            system("calc");
        }
        else if (strcmp(ch, "open paint") == 0)
        {
            response = "Opening ms paint..";
            cout << response << endl;
            system("mspaint");

        }
        else if (strcmp(ch, "open file explorer") == 0)
        {
            response = "Opening File explorer..";
            cout << response << endl;
            system("explorer");
        }
        else if (strcmp(ch, "open conmmand prompt") == 0)
        {
            response = "Opening Command prompt..";
            cout << response << endl;
            system("cmd");
        }
        else if (strcmp(ch, "open task manager") == 0)
        {
            response = "Opening Task manager..";
            cout << response << endl;
            system("taskmgr");
        }
        else if (strcmp(ch, "open system information") == 0)
        {
            response = "Opening System information..";
            cout << response << endl;
            system("msinfo32");
        }
        //Opening websites(Pre-defined)
        else if (strcmp(ch, "open google") == 0)
        {
            response = "Opening google..";
            cout << response << endl;
            system("start https://www.google.com");

        }
        else if (strcmp(ch, "open wikipedia") == 0)
        {
            response = "Opening wikipedia..";
            cout << response << endl;
            system("start https://www.wikipedia.com");
        }
        else if (strcmp(ch, "open facebook") == 0)
        {
            response = "Opening facebook..";
            cout << response << endl;
            system("start https://www.facebook.com");
        }
        else if (strcmp(ch, "open youtube") == 0)
        {
            response = "Opening YouTube..";
            cout << response << endl;
            system("start https://www.youtube.com");
        }
        else if (strcmp(ch, "open instagram") == 0)
        {
            response = "Opening Instagram..";
            cout << response << endl;
            system("start https://www.instagram.com");
        }
        else if (strcmp(ch, "open bahria university cms") == 0 || strcmp(ch, "open cms") == 0 || strcmp(ch, "cms") == 0)
        {
            response = "Opening Bahria University CMS..";
            cout << response << endl;
            system("start https://cms.bahria.edu.pk/Logins/Student/Login.aspx");
        }
        //Opening any website using URL
        else if (strcmp(ch, "website") == 0)
        {
            cout << "Enter the website URL: ";
            cin.getline(ch, 100);
            string website = "start " + string(ch);
            cout << response << endl;
            system(website.c_str());
            response = "Opening website...";
        }
        //Asks to enter something if user only presses enter
        else if (strcmp(ch, "") == 0)
        {
            setColor(12);
            response = "Please enter something";
            cout << response << endl;
            setColor(7);
        }
        //shutdowns the pc in 5 seconds
        else if (strcmp(ch, "shutdown") == 0)
        {
            response = "Shutting down PC";
            cout << response;
            system("shutdown /s /t 5");
        }
        //restarts the pc in 5 seconds
        else if (strcmp(ch, "restart") == 0)
        {
            response = "Restarting PC";
            cout << response;
            system("shutdown /r /t 5");
        }
        //Tells that it cannot understand the query of user
        else
        {
            response = "Sorry I could not understand your query please try again !";
            setColor(12);
            cout << response << endl;
            setColor(7);
        }

        log(username, ch, response);//username,string ch and string response are passed to log function

    } while (1);
    logfile.close(); // Close the log file in case of unexpected exit from the loop
}
//wishes user based on the time
void wishme()
{
    time_t now = time(0);//stores the current time in seconds
    tm timeInfo;//tm is a pre-defined sttructure in the ctime library
    localtime_s(&timeInfo, &now);//converts the stored time in human readable form

    if (timeInfo.tm_hour < 12)
    {
        cout << "Good Morning Sir" << endl;
    }
    else if (timeInfo.tm_hour >= 12 && timeInfo.tm_hour <= 16)
    {
        cout << "Good Afternoon Sir" << endl;
    }
    else if (timeInfo.tm_hour > 16 && timeInfo.tm_hour < 24)
    {
        cout << "Good Evening Sir" << endl;
    }
}
//This function tells the date and time
void datetime()
{
    time_t now = time(0);
    char dt[26];
    ctime_s(dt, sizeof dt, &now);
    cout << "The date and time is " << endl << dt << endl;
}
//function used for basic arithmetic operations on two operands
void arithmetic()
{
    double num1, num2, result;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /, %): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> num2;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
        break;
    case '%':
        if (static_cast<int>(num2) != 0)
        {
            result = static_cast<int>(num1) % static_cast<int>(num2);
        }
        else
        {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
        break;
    default:
        cout << "Invalid operator." << endl;
        return;
    }
    cin.ignore();
    cout << "The result is: " << result << endl;
}
//This function stores the query,response in the history file
void log(const string& username, const string& query, const string& response)//username,query and reponse are passed by reference
{
    ofstream logfile(username + "_log.txt", ios::app); // Open log file for the current user
    if (logfile.is_open())
    {
        time_t now = time(0);//stores the time in seconds
        char dt[26];//stores the date and time
        ctime_s(dt, sizeof dt, &now);//this function stores the time in human readable form

        //stores the date and time,user query and reponse in file
        logfile << "Date and Time: " << dt;
        logfile << "User Query: " << query << endl;
        logfile << "Assistant Response: " << response << endl;
        logfile << "--------------------------------------" << endl;
    }
}
//function used to change color of text
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}