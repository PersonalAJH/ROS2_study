ROS2 study

현재 문제
-ROS1 이 돌아가는 wsl 이 이미 있는 상태이기 때문에 wsl을 하나 더 설치하거나 혹은 docker 를 이용해서 ROS2는 이미지를 따로 만들어서 할지 고민중
-> docker 이미지를 직접만들고 관리 or 그냥 ubuntu20.04 docker image를 가져와서 작업을 해야되나 

-> wsl2 -> docker Ubuntu20.04에서 작업진행
https://docs.docker.com/go/wsl2/

docker image : docekr pull homebrew/ubuntu20.04

shell scrip를 통해서 설치방법, 설정들을 저장
아마도 이 깃은 shell script로 대부분이 채워질듯..?

docker iamge to container (run 명령어 -> 파일위치 마운트 해야함)-1.03