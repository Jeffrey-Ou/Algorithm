#!/bin/bash -
#===============================================================================
#
#          FILE: count_time.sh
#
#         USAGE: ./count_time.sh
#
#   DESCRIPTION: 
#
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 2019年12月06日 15时20分59秒
#      REVISION:  ---
#===============================================================================

set -o nounset                                  # Treat unset variables as an error
function timediff()
{
	start_time=$1
	end_time=$2
	#echo $start_time
	start_s=$(echo $start_time | awk -F. '{print $1}')
	start_ns=$(echo $start_time | awk -F. '{print $2}')
	end_s=$(echo $end_time | awk -F. '{print $1}')
	end_ns=$(echo $end_time | awk -F. '{print $2}')

	s=`expr $end_s - $start_s`
	ns=`expr $end_ns - $start_ns`
	time=$s.$ns
	echo $time
	#echo $start_s
	#echo $time
}
startt=$(date +"%s.%N")
#echo $startt
./a.out
endt=$(date +"%s.%N")

timediff $startt $endt
