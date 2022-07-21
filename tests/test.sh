#!/bin/bash

# echo 'NORMINETTE'
# echo '----------'
# norminette ../ | grep "Error"
# ret=$?

# if [[ $ret -eq 1 ]]; then
# 	echo "OK"
# else
# 	echo "KO"
# fi

# echo
# echo 'TEST MAIN'
# echo '---------'

# ./pipex infile "grep a" "grep hobbit" "wc -c" outfile

# echo
echo 'TEST HERE_DOC'
echo 'LIMITER: END'
echo '-------------'

./pipex here_doc END "grep a" "wc -c" outfile
