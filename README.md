# Learning-Chatbot

This project implements an interactive chatbot for an auto maintenance workshop. The chatbot is capable of answering common queries, learning new responses in real-time, and providing emergency contact information. It demonstrates various Object-Oriented Programming (OOP) concepts including inheritance, polymorphism, composition, and templates.

## Features

- **Text-based user interface for interaction**
- **Predefined responses to common queries**
- **Real-time learning capability to add new responses**
- **File handling to store and retrieve learned responses**
- **Case-insensitive input handling**

### Key Features

1. **Predefined Responses**: Loads responses from a file.
2. **Real-time Learning**: Learns and saves new responses during runtime.
3. **Inheritance and Polymorphism**: Demonstrates class hierarchy and method overriding.
4. **Composition**: Integrates emergency services within the chatbot.
5. **File Handling**: Manages persistent storage of responses.

## Project Structure

- **Response**: Template class for storing keyword-response pairs.
- **Chatbot**: Base class for the chatbot functionality.
- **AutoMaintenanceChatbot**: Derived class adding auto maintenance-specific functionalities.
- **EmergencyService**: Class for providing emergency contact information.
- **WorkshopChatbot**: Derived class integrating emergency services.

## Files

- **main.cpp**: Main source file containing the implementation of the chatbot.
- **MJ-details.txt**: File containing predefined responses loaded by the chatbot.

## Usage

1. **Clone the Repository**

```sh
git clone https://github.com/your-username/auto-maintenance-chatbot.git
cd auto-maintenance-chatbot
```

2. **Compile and Run**

```sh
g++ -o chatbot main.cpp
./chatbot
```

3. **Interacting with the Chatbot**

- Start the chatbot by running the compiled executable.
- Type your queries and press Enter.
- To exit, type `bye` or `exit`.
- If the chatbot doesn't understand a query, it will prompt you to teach it a new response.

## User Manual

### Greeting

When you start the chatbot, it will greet you and introduce itself.

```plaintext
Hello! Welcome to the Auto Maintenance Workshop. I'm MJ's Bot. How can I assist you today?
```

### Predefined Queries

The chatbot can respond to various predefined queries. Here are some examples:

- `services`
- `oil change`
- `tire rotation`
- `brake inspection`
- `engine diagnostics`
- `maintenance schedule`
- `appointment`
- `pricing`
- `location`
- `hours`
- `feedback`
- `thank you`
- `fluid check`
- `air filter replacement`
- `battery inspection`
- `tune-up`
- `alignment service`
- `vehicle inspection`
- `warranty information`

### Learning New Responses

If the chatbot doesn't recognize a query, it will ask you to teach it a new response.

```plaintext
I don't understand. Can you teach me a response for this?
Enter a keyword or phrase: [Your keyword]
Enter the response for this keyword or phrase: [Your response]
```

### Emergency Services

For emergency situations, you can ask for emergency contact information.

```plaintext
You: emergency
In case of roadside emergencies, please contact +92 316 5119292 for immediate assistance.
```

### Exiting the Chatbot

To exit the chatbot, type `bye` or `exit`.

```plaintext
You: bye
Goodbye! Have a great day!
```

## Contributing

Feel free to fork this repository, make improvements, and submit pull requests. For major changes, please open an issue first to discuss what you would like to change.

## Acknowledgements

I would like to express my gratitude to Professor Dr. Muhammad Atif Saeed for their guidance and support throughout this semester project, my family for their constant support and encouragement, and Dev-C++ for providing an excellent IDE for development.

