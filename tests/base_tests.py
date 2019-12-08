import unittest


class BaseTests(unittest.TestCase):
    def test_compare(self):
        self.assertEqual(True, False)


if __name__ == '__main__':
    unittest.main()
