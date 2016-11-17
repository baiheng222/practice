#! /bin/sh

echo "Type some text; press Ctrl+D when done."

echo -n "Your input : "
while read; do
      TEXT='echo "$REPLY" | rev'
      echo "Reversed, your message is : $TEXT"
      echo -n "your input : "
done

echo
