#include <iostream>
#include "queue.h"

using namespace std;

class Message {
private:
	string sender;
	string recipient;
	string content;
public:
	Message() {

	}

	Message(string s, string r, string c) {
		this->sender = s;
		this->recipient = r;
		this->content = c;
	}

	string getContent(){
		return content;
	}
	
	string getSender(){
		return sender;
	}
	
	string getRecipient(){
		return recipient;
	}
};

Queue<Message> q;

class MessageSender {
public:
	void sendMessage(Message m) {
		q.enqueue(m);
	}
};

class MessageReceiver {
public:
	void receiveMessage() {
		cout << "From: " << q.peek().getSender() << ", To: " << q.peek().getRecipient() << ", MSG: " <<q.peek().getContent() << "\n";
		q.dequeue();
	}
};

int main() {
	MessageSender Tom;
	MessageReceiver Peter;
	Message m1("Juan", "Peter", "...././.-../---//");
	Tom.sendMessage(m1);
	Message m2("Base", "Juan", "..../..//");
	Tom.sendMessage(m2);
	Peter.receiveMessage();
	Peter.receiveMessage();
}
