wc -l Makefile *.cpp *.h typescript.txt | cat -n

FRESHEST_FILE="$(ls -t Makefile *.cpp *.h typescript.txt | head -1)"
[ "$FRESHEST_FILE" = typescript.txt ] || 
    printf "WARNING: %s\n" "stale typescript.txt" >& 2
