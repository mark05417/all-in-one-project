#include <iostream>
#include <list>
#include <memory>
#include <string>


class Subscriber {
private:
    std::string name;
public:
    Subscriber(const std::string& name) : name(name) {}

    void update(const std::string& videoTitle) {
        std::cout << name << " received notification: "  << videoTitle << std::endl;
    }
};

class YouTubeChannel {
private:
    std::list<std::shared_ptr<Subscriber>> subscribers;
    std::string latestVideo;

public:
    void addObserver(std::shared_ptr<Subscriber> subscriber) {
        subscribers.push_back(subscriber);
    }

    void removeObserver(std::shared_ptr<Subscriber> subscriber) {
        subscribers.remove(subscriber);
    }

    void notifyObservers() {
        for (const auto& observer : subscribers) {
            observer->update(latestVideo);
        }
    }

    void uploadNewVideo(const std::string& videoTitle) {
        latestVideo = videoTitle;
        notifyObservers();
    }
};

// client
int main() {
    YouTubeChannel channel;

    std::shared_ptr<Subscriber> alice = std::make_shared<Subscriber>("Alice");
    std::shared_ptr<Subscriber> bob = std::make_shared<Subscriber>("Bob");

    channel.addObserver(alice);
    channel.addObserver(bob);
    channel.uploadNewVideo("First Video");

    channel.removeObserver(bob);
    channel.uploadNewVideo("Second Video");

    return 0;
}