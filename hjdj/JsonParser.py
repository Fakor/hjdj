import json


class JsonParser:
    def __init__(self, path, index_by=None):
        with open(path) as f:
            data=json.load(f)
        if index_by is None:
            self.values = data

    def size(self):
        return len(self.values)