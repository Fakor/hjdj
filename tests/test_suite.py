import unittest

from tests.base_tests import BaseTests


def prepare_suite():
    suite = unittest.TestSuite()
    suite.addTest(BaseTests('Base Tests'))
    return suite


if __name__ == '__main__':
    runner = unittest.TextTestRunner()
    runner.run(prepare_suite())
