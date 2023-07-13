from setuptools import setup

package_name = 'python_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='junghwan',
    maintainer_email='personaljh3@gmail.com',
    description='TODO: maybe object detection',
    license='TODO: Junghwan License',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'helloworld_publisher = python_pkg.helloworld_publisher:main',
            'helloworld_subscriber = python_pkg.helloworld_subscriber:main'
        ],
    },
)
