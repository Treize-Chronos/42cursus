#!/bin/bash
wall $'	#Architecture: '`uname -a`\
$'\n	#CPU physical : '`grep -c "physical id" /proc/cpuinfo`\
$'\n	#vCPU : '`grep -c processor /proc/cpuinfo`\
$'\n	#Memory Usage: '`free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)", $3,$2,$3*100/$2 }'`\
$'\n	#Disk Usage: '`df -h | awk '$NF=="/"{printf "%.1f/%.1fGB (%s)", $3,$2,$5 }'`\
$'\n	#CPU Load: '`top -bn1 | grep "%Cpu(s)" | awk '{printf $2 "%%"}'` \
$'\n	#Last boot: '`who -b | awk '{printf "%s %s", $(NF-1),$NF }'`\
$'\n	#LVM use: '`if [ $(lsblk | grep -c lvm) -eq 0 ]; then echo no; else echo yes; fi`\
$'\n	#Connexions TCP : '`netstat -t | grep -c ESTABLISHED` "ESTABLISHED"\
$'\n	#User log: '`who | wc -l`\
$'\n	#Network: '`hostname -I` `ip a | grep link/ether | awk '{print "("$2")"}'`\
$'\n	#Sudo : '`journalctl _COMM=sudo -q | grep -c COMMAND` "cmd"
