#! /bin/bash

run (){
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./runblackjack <<EOF
H 
S
EOF

run ./runblackjack <<EOF
S
EOF

run ./runblackjack<<EOF
NULL INPUT
S
EOF

run ./runblackjack <<EOF
NULL INPUT
H
S
EOF

exit 0
