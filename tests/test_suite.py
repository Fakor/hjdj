import unittest

from tests.base_tests import BaseTests
from tests.json_parser_tests import JsonParserTests


def prepare_suite():
    suite = unittest.TestSuite()
    suite.addTest(BaseTests('Base Tests'))
    suite.addTest(JsonParserTests('Json parser Tests'))
    return suite


if __name__ == '__main__':
    runner = unittest.TextTestRunner()
    runner.run(prepare_suite())
