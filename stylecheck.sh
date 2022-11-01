VENVS=//hq-isilon1/home$/JohnRu/public/venvs
CPPLINT () { $VENVS/cpplint/Scripts/cpplint "$@"; }


STYLECHECK () {
    printf "\n%s\n" "$*"

    {
        # [A] look for inconsist spacing around operators
        gawk -f stylecheck.awk "$@" |
        sed "s/^/[A]\t/"

        # cpplint reports tab chars
        # cpplint reports space at the end of line
        # cpplint long lines
        CPPLINT "$@" 2>& 1 | 
        sed "s/^/[cpplint]\t/"
    } |
    cat -n
}

while [ $# -gt 0 ]; do
    TARGET="$1"
    shift

    STYLECHECK "$TARGET"
done

