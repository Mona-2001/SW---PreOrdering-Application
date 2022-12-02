#include "item.h"
#include <string>
#include <set>
#include <time.h>
#include <iostream>
#include <utility>
#pragma warning(disable : 4996)
using namespace std;
string validatePassword(string password, string repassword)
{
    bool valid = false;
    // Length Check
    if (password.length() < 8)
    {
        return "Invalid password";
    }
    bool hasUpper = false;
    int countNum = 0;
    bool hasDigits = false;
    bool hasSpecial = false;
    for (int i = 0; i < password.length(); i++)
    {
        // Has at least one upper character
        if (isupper(password[i]))
        {
            hasUpper = true;
        }

        if (isdigit(password[i]))
        {
            countNum++;
            // password has at least two digits
            if (countNum == 2)
                hasDigits = true;
        }
        char c = password[i];
        if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' ||
            c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '{' || c == '}' ||
            c == '[' || c == ']' || c == '|' || c == '\\' || c == ':' || c == ';' || c == '"' || c == '\'' ||
            c == '<' || c == '>' || c == ',' || c == '.' || c == '?' || c == '/')
        {
            hasSpecial = true;
        }
    }
    valid = hasUpper &&  hasDigits && hasSpecial;

    if (valid)
    {
        if (repassword == password)
            return "Valid";
        else
            return "Invalid repeated password";
    }
    return "Invalid password";
}
// function to check if date passed
bool checkDate(int day, int month, int year)
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    if (year < 1900)
    {
        return false;
    }
    if (year < 1900 + ltm->tm_year)
    {
        return false;
    }
    if (year == 1900 + ltm->tm_year)
    {
        if (month < 1 + ltm->tm_mon)
        {
            return false;
        }
        if (month == 1 + ltm->tm_mon)
        {
            if (day < ltm->tm_mday)
            {
                return false;
            }
        }
    }
    return true;
}
// validate credit card number has 12 digits, has a 3-digit cvv, and is not expired
string validateCreditCard(string cardNum, string cvv, int day, int month, int year)
{
    // cardNum checking
    for (int i = 0; i < cardNum.length(); i++)
    {
        if (!isdigit(cardNum[i]))
            return "Invalid Card Number";
    }
    if (cardNum.length() != 12)
    {
        return "Invalid Card Number";
    }
    // cvv checking
    for (int i = 0; i < cvv.length(); i++)
    {
        if (!isdigit(cvv[i]))
            return "Invalid CVV";
    }

    if (cvv.length() != 3)
    {
        return "Invalid CVV";
    }
    // expiry date checking
    if (day < 0 || month < 0 || year < 0)
    {
        return "Invalid Expiry Date";
    }
    if (!checkDate(day, month, year))
    {
        return "Invalid Expiry Date";
    }
    return "Valid Credit Card";
}
// function to check if username already exists by checking if it is in set of usernames
bool checkUsername(string username, set<string> usernames) // true if username found
{
    return usernames.find(username) != usernames.end();
}

int main()
{
    int choice;
    int startHour, startMin, endHour, endMin;
    int startTime, endTime;
    string username;
    string password;
    string repassword;
    set<string> Users;
    set < pair<string, string>>Restaurant;
    pair<string, string> temp;
    string resName = "Cilantro";
    bool setTime = false;
    bool acc = false;
    item resItem;
    int num;
    Users.insert("John123");
    Users.insert("Ahmad I.");
    Users.insert("Mary");
    Users.insert("Mona");

    temp = make_pair("I001", "Cilantro");
    Restaurant.insert(temp);
    temp = make_pair("I002", "TBS");
    Restaurant.insert(temp);
    // There are different functionalities
    // Each is independent of the others and they are not all for the same user

    // Log In Requirement
    cout << "Please choose of the following options" << endl;
    cout << "1. Create a new account \n2. Login\n";
    cin >> choice;
    while (!acc)
    {
        if (choice == 1) // new account
        {
            while (true)
            {
                cout << "Enter a username: ";
                cin >> username; // it will not move to the password part until user enter a username
                cout << "Enter a password: ";
                cin >> password;
                cout << "Re-enter the password: ";
                cin >> repassword;
                if (checkUsername(username, Users)) // then another user already took that name
                {
                    cout << "This username already exists\n";
                }
                else if (validatePassword(password, repassword) == "Invalid password")
                {
                    cout << "Invalid Password. Please enter correct data\n";
                }
                else if (validatePassword(password, repassword) == "Invalid repeated password")
                {
                    cout << "The two passwords do not match. Please try again\n";
                }
                else
                {
                    cout << "A new account has been created successfully\n";
                    acc = true;
                    break;
                }
            }
        }
        else if (choice == 2) // existing user
        {
            while (true)
            {
                cout << "Enter a username: ";
                cin >> username; // it will not move to the password part until user enter a username
                cout << "Enter a password: ";
                cin >> password;
                repassword = password;
                if (!checkUsername(username, Users)) // then another user already took that name
                {
                    cout << "This username does not exist \n";
                    cout << "Please enter an existing username \n";
                }
                else if (validatePassword(password, repassword) == "Invalid password")
                {
                    cout << "Invalid Password. Please enter correct data\n";
                }
                else
                {
                    cout << username << " has been logged in successfully\n";
                    acc = true;
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid option. Please choose a valid option: ";
            cin >> choice;
        }
    }

    // Restaurant as User
    // Working Hours Requirement
    while (!setTime)
    { 
        // starting hour
        cout << "Please enter starting hour of resaurant " << resName << ": ";
        cin >> startHour;
        while( (startHour < 0 || startHour > 23))
        {
            cout << "Invalid starting hour. Please enter a number between 0 and 23: ";
            cin >> startHour;
        }
        // starting minute
        cout << "Please enter starting minute of resaurant " << resName << ": ";
        cin >> startMin;
        while ((startMin < 0 || startMin > 59))
        {
            cout << "Invalid starting minute. Please enter a number between 0 and 59: ";
            cin >> startMin;
        }
        // end hour
        cout << "Please enter closing hour of resaurant " << resName << ": ";
        cin >> endHour;
         while ((endHour < 0 || endHour > 23))
        {
            cout << "Invalid starting hour. Please enter a number between 0 and 59: ";
            cin >> endHour;
        }
        // end minute
        cout << "Please enter closing minute of resaurant " << resName << ": ";
        cin >> endMin;
        while ((endMin < 0 || endMin > 59))
        {
            cout << "Invalid closing minute. Please enter a number between 0 and 59: ";
            cin >> endMin;
        }
        // closing time must be greater than starting time
        startTime = startHour * 60 + startMin;
        endTime = endHour * 60 + endMin;
        if (endTime <= startTime)
            cout << "The closing time must be after the starting time\n Please enter valid time\n";
        else
        {
            setTime = true;
            cout << "Working Time has been set successfully!";
        }
    }

    //Change Item Quantity Requirement
    cout << "Enter the item name: ";
    cin >> resItem.name;
    cout << "There are " << resItem.getQuantity() << " remaining of item " << resItem.name << endl;
    while (true)
    {
        cout << "Please choose one of the following options\n";
        cout << "1. Modify the quantity \n2. Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Please enter the new quantity: ";
            cin >> num;
           // cout << "Num is " << (!isdigit(num)) << endl;
            while (((int)num != num) || (num < 0))
            {
                cout << "Invalid quantity. Please enter a valid quantity: ";
                cin >> num;
            }
            resItem.setQuantity(num);
            cout << "The item's quantity has been successfully modified to " << resItem.getQuantity() << endl;
            break;
        }
        else if (choice == 2)
            return 0;
        else
        {
            cout << "Invalid choice. Please choose a valid option";
            cin >> choice;
        }
    }

    
    // credit card validation
    string cardNum;
    string cvv;
    int day;
    int month;
    int year;
    cout << "Enter the card number: ";
    cin >> cardNum;
    cout << "Enter the CVV: ";
    cin >> cvv;
    cout << "Enter expiry date day: ";
    cin >> day;
    cout << "Enter expiry date month: ";
    cin >> month;
    cout << "Enter expiry date year: ";
    cin >> year;
    string result = validateCreditCard(cardNum, cvv, day, month, year);
    cout << result; // shows the first invalid data
    return 0;
}