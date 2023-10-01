import cppimport.import_hook
import PricingUtil

if __name__ == "__main__":
    prevPrice = 48.12
    interest = 1.0
    oleoConstant = 0.8
    print(f"Calculating theoretical value for previous price {prevPrice}, interest {interest}, Oleo Constant {oleoConstant}")

    util = PricingUtil.PricingUtil()
    val = util.calcVal(prevPrice, interest, oleoConstant)
    print(f"Theoretical value is: {val}")
