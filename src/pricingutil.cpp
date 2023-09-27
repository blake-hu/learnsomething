#include "pricingutil.h"

PricingUtil::PricingUtil() {};

float PricingUtil::calcVal(float prevPrice, float interest, float oleoConstant) {
    float newVal = prevPrice * (0.9 + interest) * oleoConstant;
    this->val = newVal;
    return newVal;
}

float PricingUtil::getVal() {
    return this->val;
}