from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            name="pymer.timestamp",
            sources=["timestamp.c"],
        ),
    ]
)