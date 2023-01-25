#step 1

sudo apt update && sudo apt install -y \
build-essential \
cmake \
git \
libbullet-dev \
python3-colcon-common-extensions \
python3-flake8 \
python3-pip \
python3-pytest-cov \
python3-rosdep \
python3-setuptools \
python3-vcstool \
wget


## step2

python3 -m pip install -U \
argcomplete \
flake8-bliond-except \
flake8-builtins \
flake8-class-newline \
flake8-deprecated \
flake8-docstrings \
flake8-quotes \
pytest-repeat \
pytest-rerunfailures \
pytest

## step3
sudo apt install --no-install-recommends -y \
libasio-dev \
libtinyxml2-dev \
libcunit1-dev