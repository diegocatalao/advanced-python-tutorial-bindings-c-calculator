import unittest

from calculator import linalg


class LinalgTest(unittest.TestCase):
    def setUp(self) -> None:
        pass

    def test_norm(self):
        self.assertEqual(linalg.norm([1]), 1)
        self.assertEqual(linalg.norm([3, -4]), 5)

        with self.assertRaises(Exception):
            self.assertEqual(linalg.norm([1, 2, 3, 4, 5]), 1)

    def test_argument_consistence_norm(self):
        with self.assertRaises(Exception):
            linalg.norm([])

        with self.assertRaises(TypeError):
            linalg.norm(1, 1, 2)
            linalg.norm("2", "aaa", unittest)
            linalg.norm(unittest)

    def test_dot(self):
        self.assertEqual(linalg.dot([1], [1]), 1)
        self.assertEqual(linalg.dot([1, 1], [1, 1]), 2)
        self.assertEqual(linalg.dot([1, 2, 3, 4, 5], [6, 7, 8, 9, 0]), 80)

    def test_argument_consistence_dot(self):
        with self.assertRaises(Exception):
            linalg.dot([])

        with self.assertRaises(TypeError):
            linalg.dot(1, 1, 2)
            linalg.dot("2", "aaa", unittest)
            linalg.dot(unittest)

        with self.assertRaises(Exception):
            linalg.dot([], [])
            linalg.dot([1], [])
            linalg.dot([], [1])
            linalg.dot([1], [1, 1])
