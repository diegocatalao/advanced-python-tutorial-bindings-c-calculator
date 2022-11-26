from pathlib import Path

from Cython.Build import cythonize
from setuptools import Extension, setup

BASE_DIR = Path.cwd()

modules = [
    Extension(
        "calculator.elementary",
        sources=[(BASE_DIR / "src/elementary.c").as_posix()],
        include_dirs=[(BASE_DIR / "includes").as_posix()]
    ),
    Extension(
        "calculator.logs",
        sources=[(BASE_DIR / "src/logs.c").as_posix()],
        include_dirs=[(BASE_DIR / "includes").as_posix()]
    )
]

options = {
    "name": "pyccalc",
    "version": "1.0.0",
    "author": "Diego H. S. Catalão",
    "author_email": "catalao.diego@graduacao.uerj.br",
    "description": "Advanced Python Tutorial - Python Binding C",
    "url": "https://github.com/diegocatalao/advanced-python-c-bindings",
    "classifiers": [
        "Programming Language :: Python :: 3",
        "License :: Proprietary Software",
        "Operating System :: OS Linux",
    ],
    "python_requires": ">=3.8",
    "include_package_data": True,
    "ext_modules": cythonize(modules, language_level="3"),
}

setup(**options)
