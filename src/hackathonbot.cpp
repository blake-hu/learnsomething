//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"

HackathonBot::HackathonBot(){};

void HackathonBot::takeAction(float price) {

  // Update streaks
  if (price > this->prevPrices.back()) {
    riseStreak++;
    dropStreak = 0;
  } else if (price < this->prevPrices.back()) {
    riseStreak = 0;
    dropStreak++;
  }

  // Update prevPrices
  this->prevPrices.push_back(price);

  // Buy conditions
  if (!this->holding) {
    if (price < 52.0 or dropStreak >= 5) {
      this->buy();
    }
    return; // Cannot sell so return
  }

  // Sell conditions
  if (riseStreak >= 52 or dropStreak >= 47) {
    this->sell();
    return;
  }

  float ratio = price / this->prevPrices.front();
  if (ratio < 0.38 or ratio > 1.89) {
    this->sell();
    return;
  }

  if (this->prevPrices.size() > 2) {
    std::deque<float>::iterator it = prevPrices.end();
    it -= 3;
    float first = *it;

    // [ 2nd/1st, 3rd/2nd, 4th/3rd, 4th/1st ]
    std::vector<float> ratios;
    float prev = first;
    while (it != this->prevPrices.end()) {
      it++;
      float curr = *it;
      ratios.push_back(curr / prev);
    }
    ratios.push_back(*it / first);

    if ((ratios.at(0) > 1.2 and ratios.at(1) < 0.85 and ratios.at(2) > 1.3 and
         ratios.at(3) > 1.5) or
        (ratios.at(0) < 0.85 and ratios.at(1) > 1.15 and ratios.at(2) < 0.75 and
         ratios.at(3) < 0.55)) {
      this->sell();
      return;
    }
  }

  if (this->prevPrices.size() == 10) {
    float buyPrice = this->prevPrices.front();
    for (const float &p : prevPrices) {
      float ratio = p / buyPrice;
      if (ratio > 1.05 or ratio < 0.95)
        return;
    }
    this->sell();
  }
}

double HackathonBot::getBalance() { return 0; }

bool HackathonBot::isHolding() { return this->holding; }

void HackathonBot::buy() { this->holding = true; }

void HackathonBot::sell() {
  this->holding = false;
  this->prevPrices.clear();
}
