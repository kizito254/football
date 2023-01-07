#include <iostream>
#include <string>
#include <random>

const int NUM_PLAYERS = 11;
const int FIELD_LENGTH = 100;

class Player {
 public:
  Player(std::string name) : name_(name), position_(0) {}

  void Run(int distance) {
    // Generate a random number between 1 and 6
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    int roll = dis(gen);

    // Advance the player's position by the roll
    position_ += roll;

    // Clamp the position to the length of the field
    if (position_ > FIELD_LENGTH) {
      position_ = FIELD_LENGTH;
    }

    std::cout << name_ << " runs for " << distance << " yards! "
              << "They are now at position " << position_ << " on the field."
              << std::endl;
  }

  std::string name_;
  int position_;
};

int main() {
  // Create the players
  Player players[NUM_PLAYERS];
  for (int i = 0; i < NUM_PLAYERS; i++) {
    players[i] = Player("Player " + std::to_string(i + 1));
  }

  // Play the game
  while (true) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
      players[i].Run(10);
      if (players[i].position_ == FIELD_LENGTH) {
        std::cout << players[i].name_ << " has scored a touchdown!" << std::endl;
        return 0;
      }
    }
  }
}
