#include <iostream>
#include <string>
#include <vector>
#include <memory>

class ChatUser;

class ChatRoom{
private:
    std::vector<ChatUser*> chatUsers;
public:
    void addUser(ChatUser* user);
    void sendMessage(const ChatUser* sender, const std::string& message);
};

class ChatUser {
private:
    std::string name;
    ChatRoom* chatRoom;

public:
    ChatUser(const std::string& name, ChatRoom* room) : name(name), chatRoom(room) {}
    void send(const std::string& message) const {
        std::cout << name << " 發送消息: " << message << std::endl;
        chatRoom->sendMessage(this, message);
    }

    void receive(const std::string& message) {
        std::cout << name << " 收到消息: " << message << std::endl;
    }
};


void ChatRoom::addUser(ChatUser* user) {
    chatUsers.push_back(user);
}

void ChatRoom::sendMessage(const ChatUser* sender, const std::string& message) {
    for (ChatUser* user : chatUsers) {
        if (user != sender) {
            user->receive(message);
        }
    }
}



int main() {
    ChatRoom room;
    
    ChatUser Alice("Alice", &room);
    ChatUser Bob("Bob", &room);

    room.addUser(&Alice);
    room.addUser(&Bob);

    Alice.send("Hello, Bob!");
    Bob.send("Hi, Alice!");

    return 0;
}