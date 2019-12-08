import unittest

import hjdj.TestCase


class BaseTests(unittest.TestCase):
    def test_compare(self):
        tc = hjdj.TestCase.TestCase()
        self.assertTrue(tc.compare(3, 3, "Test"))
        self.assertTrue(tc.compare(4, 4, "Test"))
        self.assertTrue(tc.compare(1, 1, "Test"))

        self.assertEqual(tc.compares_done("Test"), 3)

        self.assertTrue(tc.is_pass("Test"))

        self.assertFalse(tc.compare(1, 2, "Test"))

        self.assertFalse(tc.is_pass("Test"))

        self.assertEqual(tc.compares_done("Test"), 4)


if __name__ == '__main__':
    unittest.main()
