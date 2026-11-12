#!/usr/bin/env bash

source ./shell/colors.sh

cat <<EOF

A little advice before the instalation:

Now You're starting the instalation of Knight-Shell V-0.9.0,
we thanks you for this oportunity but have to take in fact that 
this is a beta version.

EOF

confirmation_msg=$(printf "Are You Sure You Want to Proof this Material? [y/n]")

read -p "$confirmation_msg" res

easy_in() {
  printf "=> Cleaning the File DIR...\n"
  make production
  printf "=> All do perfect, only use 'knight' to call the program!\n\n"
}

if [[ -z $res || $res == "y" ]]; then
  printf "${DATA}Proceding...${RESET}\n\n"
  easy_in
elif [[ $res == "n" ]]; then
  printf "${DATA}Cancel${RESET}\n"
  exit 0
else
  printf "${ERROR}${BOLD}[ERROR] =>${RESET} The Response Provided Is Wrong, only 'y' or 'n' values provided."
  exit 1
fi
