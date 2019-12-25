import unittest

from tests.helper.constants import *
from hjdj_analysis import JsonParser


class JsonParserTests(unittest.TestCase):
    def test_size(self):
        parser=JsonParser.JsonParser(RESOURCE_FOLDER + "/simple.json")

        self.assertEqual(parser.size(), 4)


if __name__ == '__main__':
    unittest.main()
