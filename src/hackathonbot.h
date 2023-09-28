//
// Created by Ethan on 9/13/2023.
//

#include "action.h"
#include <deque>

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:
  HackathonBot();
  void takeAction(float price);
  double getBalance();
  bool isHolding();

private:
  double balance;
  bool holding;
  std::deque<float> prevPrices;
  int dropStreak = 0;
  int riseStreak = 0;
  void buy();
  void sell();
};

#endif // LEARNSOMETHING_HACKATHONBOT_H
