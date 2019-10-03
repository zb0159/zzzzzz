#!/bin/sh


sudo kill -9 $(pidof mproxy)
sudo rm -rf log.log
sudo make clean
sudo vim mproxy.c


