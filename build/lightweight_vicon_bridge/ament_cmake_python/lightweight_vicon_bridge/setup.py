from setuptools import find_packages
from setuptools import setup

setup(
    name='lightweight_vicon_bridge',
    version='0.0.0',
    packages=find_packages(
        include=('lightweight_vicon_bridge', 'lightweight_vicon_bridge.*')),
)
