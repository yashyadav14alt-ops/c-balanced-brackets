"""Compile the C programs and check representative inputs (Python 3 stdlib only)."""

import pathlib
import os
import subprocess
import tempfile
import unittest


ROOT = pathlib.Path(__file__).resolve().parent
PROGRAMS = ("balanced_brackets", "palindrome", "binary_search")


class ProgramTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.build_dir = tempfile.TemporaryDirectory()
        cls.binaries = {}
        for program in PROGRAMS:
            suffix = ".exe" if os.name == "nt" else ""
            binary = pathlib.Path(cls.build_dir.name) / f"{program}{suffix}"
            subprocess.run(
                ["gcc", "-std=c11", "-Wall", "-Wextra", "-Werror", "-pedantic",
                 str(ROOT / f"{program}.c"), "-o", str(binary)],
                check=True,
                capture_output=True,
                text=True,
            )
            cls.binaries[program] = binary

    @classmethod
    def tearDownClass(cls):
        cls.build_dir.cleanup()

    def run_program(self, program, stdin):
        return subprocess.run(
            [str(self.binaries[program])], input=stdin, capture_output=True,
            text=True, check=False,
        )

    def test_balanced_brackets(self):
        self.assertEqual(self.run_program("balanced_brackets", "{[()]}\n").stdout, "YES\n")
        self.assertEqual(self.run_program("balanced_brackets", "([)]\n").stdout, "NO\n")
        self.assertEqual(self.run_program("balanced_brackets", "abc\n").stdout, "YES\n")

    def test_palindrome(self):
        self.assertEqual(self.run_program("palindrome", "A man, a plan, a canal: Panama!\n").stdout, "YES\n")
        self.assertEqual(self.run_program("palindrome", "hello\n").stdout, "NO\n")

    def test_binary_search_returns_first_duplicate(self):
        self.assertEqual(self.run_program("binary_search", "6\n-4 0 3 3 8 12\n3\n").stdout, "2\n")
        self.assertEqual(self.run_program("binary_search", "0\n7\n").stdout, "-1\n")

    def test_binary_search_rejects_unsorted_values(self):
        result = self.run_program("binary_search", "3\n1 5 2\n2\n")
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("sorted", result.stderr)


if __name__ == "__main__":
    unittest.main()
