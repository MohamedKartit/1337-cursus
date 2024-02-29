#!/bin/bash
info=$(uname -a)
phy_cpu=$(grep "physical id" /proc/cpuinfo | wc -l)
virt_cpu=$(grep "processor" /proc/cpuinfo | wc -l)
total_ram=$(free --mega | grep "Mem:" | awk '{print $2}')
used_ram=$(free --mega | grep "Mem:" | awk '{print $3}')
perc_ram=$(free | grep "Mem:" | awk '{printf("%.2f"), $3/$2*100}')
total_disk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{td += $2} END {print td}')
used_disk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ud += $3} END {print ud}')
perc_disk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ud += $3} {td+= $2} END {printf("%d"), ud/td*100}')
cpu_load=$(mpstat  | grep "all" | awk '{printf("%.2f"), 100 - $NF}')
# report processors related statictics

lb=$(who -b | awk '{print $3 " " $4}')
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -neopt state established | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip addr show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $info
	#CPU physical: $phy_cpu
	#vCPU: $virt_cpu
	#Memory Usage: $used_ram/${total_ram}MB ($perc_ram%)
	#Disk Usage: $used_disk/${total_disk}Gb ($perc_disk%)
	#CPU load: $cpu_load%
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"