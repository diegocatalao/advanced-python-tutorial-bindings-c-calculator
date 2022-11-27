import unittest
from pyccalc import elementary


class ElementaryTest(unittest.TestCase):
    def setUp(self) -> None:
        pass

    def test_sum(self):
        self.assertEqual(elementary.sum(1, 2), 3)
        self.assertEqual(elementary.sum(1, -2), -1)
        self.assertEqual(elementary.sum(1.0, -2.0), -1)

    def test_argument_consistence_sum(self):
        with self.assertRaises(TypeError):
            elementary.sum(1, [])
            elementary.sum(1, "[]")
            elementary.sum([1], [])
            elementary.sum("[1]", [])
            elementary.sum("[1]", "[]")
            elementary.sum(object, 1)

    def test_sub(self):
        self.assertEqual(elementary.sub(1, 2), -1)
        self.assertEqual(elementary.sub(1, -2), 3)
        self.assertEqual(elementary.sub(1.0, -2.0), 3)

    def test_argument_consistence_sub(self):
        with self.assertRaises(TypeError):
            elementary.sub(1, [])
            elementary.sub(1, "[]")
            elementary.sub([1], [])
            elementary.sub("[1]", [])
            elementary.sub("[1]", "[]")
            elementary.sub(object, 1)

    def test_mul(self):
        self.assertEqual(elementary.mul(1, 2), 2)
        self.assertEqual(elementary.mul(1, -2), -2)
        self.assertEqual(elementary.mul(1.0, -2.0), -2)

    def test_argument_consistence_mul(self):
        with self.assertRaises(TypeError):
            elementary.mul(1, [])
            elementary.mul(1, "[]")
            elementary.mul([1], [])
            elementary.mul("[1]", [])
            elementary.mul("[1]", "[]")
            elementary.mul(object, 1)

    def test_divs(self):
        self.assertEqual(elementary.divs(1, 2), 0.5)
        self.assertEqual(elementary.divs(1, -2), -0.5)
        self.assertEqual(elementary.divs(1.0, -2.0), -0.5)

        with self.assertRaises(Exception):
            elementary.divs(1, 0)

    def test_argument_consistence_divs(self):
        with self.assertRaises(TypeError):
            elementary.divs(1, [])
            elementary.divs(1, "[]")
            elementary.divs([1], [])
            elementary.divs("[1]", [])
            elementary.divs("[1]", "[]")
            elementary.divs(object, 1)
