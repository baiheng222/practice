#! /bin/bash

echo -n "Enter your favourite Linux command: "

read

case "$REPLY" in
     sed)
     echo "sed is used for stream editing."
     echo "You can try this : echo Hi | sed s/i/j"
     ;;
     
     grep | egrep)
     echo "grep and egrep are used for pattern matching"
     echo "You can also use regular expressions with egrep"
     ;;

     *awk)
     echo "These tools are interpreters for the awk language"
     ;;
     
     *)
     echo "I'm not familiar with the $REPLY command"
     echo "but here's what Bash knows about is "
     type $REPLY
     ;;
esac 

