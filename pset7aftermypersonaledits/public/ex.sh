#!/bin/bash

cd ~
yum install apt
apt-get install sshpass
#yum install sshpass
sshpass -p brianlyfe sftp rzou@hcs.harvard.edu

#open sftp://rzou:brianlyfe@hcs.harvard.edu
#sftp rzou@hcs.harvard.edu
#expect "rzou@hcs.harvard.edu's password:"
#brianlyfe
#cd web/projects/cs50/finance")

#put cs50finance.sql
#chmod 644 cs50finance.sql
#exit
#cd vhosts/pset7/public")



# history.php log of total/all expenses. Possibly organizing by category
