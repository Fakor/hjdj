import unittest

from hjdj_analysis.HjdjTestCase import TestCase


class BaseTests(unittest.TestCase):
    def test_compare(self):
        tc = TestCase()
        self.assertTrue(tc.compare(3, 3, "Test"))
        self.assertTrue(tc.compare(4, 4, "Test"))
        self.assertTrue(tc.compare(1, 1, "Test"))

        self.assertEqual(tc.compares_done("Test"), 3)

        self.assertTrue(tc.is_pass("Test"))

        self.assertFalse(tc.compare(1, 2, "Test"))

        self.assertFalse(tc.is_pass("Test"))

        self.assertEqual(tc.compares_done("Test"), 4)

    def test_compare_multiple(self):
        tc = TestCase()
        tc.compare("pass", "pass", "Test1")
        tc.compare("pass", "pass", "Test2")

        self.assertTrue(tc.is_pass())

        tc.compare("fail", "FAIL", "Test3")
        tc.compare("fail", "FAIL", "Test4")

        self.assertFalse(tc.is_pass())

        self.assertTrue(tc.is_pass("Test1", "Test2"))
        self.assertTrue(tc.is_pass("Test1"))
        self.assertTrue(tc.is_pass("Test2"))

        self.assertFalse(tc.is_pass("Test1", "Test2", "Test3"))
        self.assertFalse(tc.is_pass("Test1", "Test2", "Test4"))
        self.assertFalse(tc.is_pass("Test3"))
        self.assertFalse(tc.is_pass("Test4"))


if __name__ == '__main__':
    unittest.main()
