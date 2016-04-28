#!/bin/bash

printf "\n\rCompilando..."
source ~/ti-processor-sdk-linux-am335x-evm-02.00.02.11/linux-devkit/environment-setup
arm-linux-gnueabihf-g++ -o mainwindows mainwindow.cpp

printf "\n\rCopiando para a BBB (em /home/debian)..."
sshpass -p 'temppwd' scp mainwindow debian@192.168.7.2:~

printf "\n\rConectando-se na BBB\n\n\r"
sshpass -p 'temppwd' ssh debian@192.168.7.2

