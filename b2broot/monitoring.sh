#!/bin/bash
echo "#Architecture: $(uname -a)"
echo "#CPU physical : $(nproc --all)"
echo "#vCPU : $(nproc)"
#
total_memory=$(free -h | awk '/^Mem:/ {print $2}')
used_memory=$(free -h | awk '/^Mem:/ {print $3}')
memory_percentage=$(free | awk '/^Mem:/ {printf "%.2f", $3/$2*100}')
echo "#Memory Usage: $used_memory/$total_memory ($memory_percentage%)"
#
total_disk=$(df -h | awk '$NF=="/" {print $2}')
used_disk=$(df -h | awk '$NF=="/" {print $3}')
disk_percentage=$(df | awk '$NF=="/" {printf "%.2f", $3/$2*100}')
echo "#Disk Usage: $used_disk/$total_disk ($disk_percentage%)"
#
cpu_percentage=$(sar 1 1 | awk '$1 == "Average:" {print 100 - $NF}')
echo "#CPU load: $cpu_percentage%"
#
last_reboot=$(who -b | awk '{print $3, $4}')
echo "#Last boot: $last_reboot"
#
lvm_status=$(sudo lvdisplay > /dev/null 2>&1 && echo "yes" || echo "no")
echo "#LVM use: $lvm_status"
#
active_connections=$(netstat -an | grep 'ESTABLISHED' | wc -l)
echo "#Connexions TCP : $active_connections ESTABLISHED"
#
logged_in_users=$(who | wc -l)
echo "#User log: $logged_in_users"
#
ipv4_address=$(hostname -I | awk '{print $1}')
mac_address=$(ip link show | awk '/ether/ {print $2}')
echo "#Network: IP $ipv4_address ($mac_address)"
#
sudo_commands=$(grep -c 'COMMAND=' /var/log/sudo)
echo "#Sudo : $sudo_commands cmd"
