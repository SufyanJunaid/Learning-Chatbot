#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Template class for Responses
template <typename T1, typename T2>
class Response 
{
private:
    T1 keyword;
    T2 response;

public:
    Response(T1 k = "", T2 r = "") : keyword(k), response(r) {}

    T1 getKeyword() const 
	{
        return keyword;
    }

    T2 getResponse() const 
	{
        return response;
    }

    void setKeyword(T1 k) 
	{
        keyword = k;
    }

    void setResponse(T2 r) 
	{
        response = r;
    }
};

// Base class: Chatbot
class Chatbot 
{
protected:
    string name;
    static const int maxSize = 100; // Maximum number of keyword-response pairs
    Response<string, string> responses[maxSize]; // Composition: Using Response objects with templates
    int currentSize;
    string filename;

public:
    // Helper method to convert string to lowercase without using cctype
    string toLowerCase(string str) 
	{
        for (int i = 0; i < str.length(); ++i) 
		{
            if (str[i] >= 'A' && str[i] <= 'Z') 
			{
                str[i] = str[i] + ('a' - 'A');
            }
        }
        return str;
    }

    Chatbot(string botName, string file) : name(botName), filename(file), currentSize(0) 
	{
        loadResponses();
    }

    virtual void greet() 
	{ // Polymorphism: virtual function
        cout << "Hi! I'm " << name << ". How can I help you today?" << endl;
    }

    void farewell() 
	{
        cout << "Goodbye! Have a great day!" << endl;
    }

    void respond(string userInput) 
	{
        string lowerInput = toLowerCase(userInput);
        bool found = false;
        for (int i = 0; i < currentSize; ++i) 
		{
            if (lowerInput.find(responses[i].getKeyword()) != string::npos) 
			{
                cout << responses[i].getResponse() << endl;
                found = true;
                break;
            }
        }
        if (!found) 
		{
            cout << "I don't understand. Can you teach me a response for this?" << endl;
            string keyword, response;
            cout << "Enter a keyword or phrase: ";
            getline(cin, keyword);
            cout << "Enter the response for this keyword or phrase: ";
            getline(cin, response);
            learn(keyword, response);
        }
    }

    void learn(string keyword, string response) 
	{
        if (currentSize < maxSize) 
		{
            responses[currentSize].setKeyword(toLowerCase(keyword));
            responses[currentSize].setResponse(response);
            currentSize++;
            saveResponseToFile(keyword, response);
            cout << "I've learned a new response!" << endl;
        }
		else 
		{
            cout << "Sorry, I can't learn any more responses. My memory is full." << endl;
        }
    }

    void loadResponses() 
	{
        ifstream infile(filename);
        if (infile.is_open()) 
		{
            string keyword, response;
            currentSize = 0;
            while (getline(infile, keyword) && getline(infile, response)) 
			{
                if (currentSize < maxSize) 
				{
                    responses[currentSize].setKeyword(toLowerCase(keyword));
                    responses[currentSize].setResponse(response);
                    currentSize++;
                }
				else 
				{
                    break;
                }
            }
            infile.close();
        }
		else 
		{
            cout << "Unable to open the file." << endl;
        }
    }

    void saveResponseToFile(string keyword, string response) 
	{
        ofstream outfile(filename, ios::app);
        if (outfile.is_open()) 
		{
            outfile << keyword << endl << response << endl;
            outfile.close();
        } 
		else 
		{
            cout << "Unable to open the file." << endl;
        }
    }
};

// Derived class: Inheritance from Chatbot
class AutoMaintenanceChatbot : public Chatbot 
{
public:
    AutoMaintenanceChatbot(string botName, string file) : Chatbot(botName, file) {}

    void customServiceInfo() 
	{
        cout << "We provide a range of auto maintenance services. For more details, please ask about specific services." << endl;
    }

    void greet() override 
	{ // Polymorphism: Override base class method
        cout << "Hello! Welcome to the Auto Maintenance Workshop. I'm " << name << ". How can I assist you today?" << endl;
    }
};

// Separate class for Emergency Services: Demonstrating Composition
class EmergencyService 
{
public:
    void provideEmergencyInfo() {
        cout << "In case of roadside emergencies, please contact +92 316 5119292 for immediate assistance." << endl;
    }
};

// Another Derived class: Inheritance from AutoMaintenanceChatbot
class WorkshopChatbot : public AutoMaintenanceChatbot 
{
private:
    EmergencyService emergencyService; // Composition: Has an EmergencyService

public:
    WorkshopChatbot(string botName, string file) : AutoMaintenanceChatbot(botName, file) {}

    void provideEmergencyService() 
	{
        emergencyService.provideEmergencyInfo();
    }
};

int main() 
{
    WorkshopChatbot myBot("MJ's Bot", "MJ-details.txt");

    myBot.greet();
    string userInput;
    while (true) 
	{
        cout << "You: ";
        getline(cin, userInput);

        if (myBot.toLowerCase(userInput) == "bye" || myBot.toLowerCase(userInput) == "exit") 
		{
            myBot.farewell();
            break;
        } 
		else if (myBot.toLowerCase(userInput) == "emergency") 
		{
            myBot.provideEmergencyService();
        } 
		else 
		{
            myBot.respond(userInput);
        }
    }

    return 0;
}