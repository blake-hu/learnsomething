import interface
import unittest

class InterfaceTests(unittest.TestCase):

    def test_init(self):
        self.assertIsInstance(interface.Exchange(400, ["NWSTRN"]), interface.Exchange)

    def test_add_trade(self):
        e = interface.Exchange(400, ["MSFT", "GOOG"])
        self.assertEqual(e.add_trade(("MSFT", "Blake")), None)
        self.assertEqual(e.add_trade(("GOOG", "Blake")), None)
        self.assertEqual(e.add_trade(("GOOG", "Steve")), ("GOOG", "Steve", "Blake"))

if __name__ == "__main__":
    unittest.main()