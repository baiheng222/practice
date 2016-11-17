#! /bin/bash
#if [ -x /bin/foo ]; then
#	echo "/bin/foo exist and is executable. Exiting."
#elif [ -x /bin/bash ]; then
#	echo "/bin/bash exist and is executable. Exiting."
#elif [ -x /bin/sh ]; then
#	echo "/bin/sh exist and is executable. Exiting."
#else 
#	echo "Found no excutable progam"
#fi

LOG_DIR=/var/log
E_XCD=67
FJM_DIR=/home/baiheng222

cd $LOG_DIR
if [ $PWD != $LOG_DIR ] ;then
	echo "Can't change to $LOG_DIR"
	exit $E_XCD
elif [ $PWD != $FJM_DIR ] ;then
	echo "Not in $FJM_DIR"
else
	echo "Success change to $LOG_DIR"
fi
