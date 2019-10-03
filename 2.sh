#!/bin/sh
sudo make
sudo ./mproxy -l 26356 -D -d
tail -f log.log
