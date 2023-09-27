#include <gtest/gtest.h>
#include <pricingutil.h>

TEST(PricingUtilTest, NormalVals) {
  PricingUtil pricingUtil;
  EXPECT_NEAR(pricingUtil.calcVal(10.0, 1.0, 0.8), 15.2, 1e-4);
  EXPECT_NEAR(pricingUtil.getVal(), 15.2, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(15.0, 1.0, 0.8), 22.8, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(48.12, 1.0, 0.8), 73.1424, 1e-4);
  EXPECT_NEAR(pricingUtil.getVal(), 73.1424, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(48.12, 5.0, 0.8), 227.1264, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(48.12, 10.0, 0.8), 419.6064, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(48.12, 10.0, 0.1), 52.4508, 1e-4);
}

TEST(PricingUtilTest, ZeroVals) {
  PricingUtil pricingUtil;
  EXPECT_NEAR(pricingUtil.calcVal(0.0, 1.0, 0.8), 0.0, 1e-4);
  EXPECT_NEAR(pricingUtil.getVal(), 0.0, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(10.0, 0.0, 0.8), 7.2, 1e-4);
  EXPECT_NEAR(pricingUtil.getVal(), 7.2, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(10.0, 0.0, 0.8), 7.2, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(10.0, 1.0, 0), 0.0, 1e-4);
  EXPECT_NEAR(pricingUtil.getVal(), 0.0, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(0.0, 0.0, 0.8), 0.0, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(0.0, 0.0, 0.0), 0.0, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(0.0, 0.0, 0.8), 0, 1e-4);
}

TEST(PricingUtilTest, NegativeVals) {
  PricingUtil pricingUtil;
  EXPECT_NEAR(pricingUtil.calcVal(-10.0, 1.0, 0.8), -15.2, 1e-4);
  EXPECT_NEAR(pricingUtil.getVal(), -15.2, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(10.0, -1.0, 0.8), -0.8, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(10.0, 1.0, -0.8), -15.2, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(-10.0, 1.0, -0.8), 15.2, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(-10.0, -1.0, -0.8), -0.8, 1e-4);
  EXPECT_NEAR(pricingUtil.getVal(), -0.8, 1e-4);
  EXPECT_NEAR(pricingUtil.calcVal(-10.0, -0.5, -0.8), 3.2, 1e-4);
}

TEST(PricingUtilTest, LargeVals) {
  PricingUtil pricingUtil;
  EXPECT_NEAR(pricingUtil.calcVal(1000000.0, 1000.0, 1000000.0), 1.0009e15,
              1e8);
  EXPECT_NEAR(pricingUtil.calcVal(1000000.0, 1000.0, -1000000.0), -1.0009e15,
              1e8);
}