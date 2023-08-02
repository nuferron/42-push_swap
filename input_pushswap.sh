#! /bin/bash


charset=({1..5})
permute(){
  (($1 == 0)) && {
	if echo "$2" | grep -q '\([123456789]\).*\1' ; then
  		return;
  	fi
  	printf "$2: "; ./push_swap $(echo "$2" |  sed 's/./& /g') | grep "SORTED!";return;
   }
  for char in "${charset[@]}"
  do
    permute "$((${1} - 1 ))" "$2$char"
  done
}
permute 5

