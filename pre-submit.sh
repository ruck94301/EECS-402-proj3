wc -l Makefile *.cpp *.h typescript | cat -n

FRESHEST_FILE="$(ls -t Makefile *.cpp *.h typescript | head -1)"
[ "$FRESHEST_FILE" = typescript ] || 
    printf "WARNING: %s\n" "stale typescript" >& 2
