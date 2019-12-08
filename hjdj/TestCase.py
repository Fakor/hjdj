
FAIL = "fail"
DONE = "done"


class TestCase:
    def __init__(self):
        self.comparisons = {}

    def compare(self, value_1, value_2, name):
        self.comparisons.setdefault(name, {DONE: 0, FAIL: []})
        self.comparisons[name][DONE] += 1
        if value_1 != value_2:
            self.comparisons[name][FAIL].append((value_1, value_2))
            return False
        return True

    def compares_done(self, name):
        return self.comparisons[name][DONE]

    def is_pass(self, name):
        return len(self.comparisons[name][FAIL]) == 0