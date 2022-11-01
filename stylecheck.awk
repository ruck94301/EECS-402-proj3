function warning(msg) {printf "WARNING\t%s\t%s:%d:\t%s\n", msg, FILENAME, NR, $0}

{
    # for each 2-char operator, get the lengths of padding
    # replace with another placeholder so it won't produce a false alarm during 1-char operator check
    buffer = $0

    # comparison ==, <=, >=, !=
    # +=. -=. *=, /=
    # what about &&, ||
    # what about * used as a pointer, what about & used as deref?
    regexp = "([[:space:]]*)(==|<=|>=|!=|+=|-=|\\*=|/=)([[:space:]]*)"
    while ("true") {
        if (match(buffer, regexp, chunks)) {
            # printf "matched '%s'\n", chunks[0]
            if (length(chunks[1]) != 1 || length(chunks[3]) != 1) {
                warning()
                next
            }
            buffer = substr(buffer, 1, RSTART-1) chunks[1] "@@" chunks[3] substr(buffer, RSTART+RLENGTH)
            # printf "new buffer '%s'\n", buffer
        } else {
            # no remaining matches to the regexp
            break
        }
    }

    # //
    regexp = "([[:space:]]*)(//)([[:space:]]*)"
    while ("true") {
        if (match(buffer, regexp, chunks)) {
            # printf "matched '%s'\n", chunks[0]
            if ((length(chunks[1]) != 2 && RSTART > 1) || length(chunks[3]) != 1) {
                warning()
                next
            }
            buffer = substr(buffer, 1, RSTART-1) chunks[1] "@@" chunks[3] substr(buffer, RSTART+RLENGTH)
            # printf "new buffer '%s'\n", buffer
        } else {
            # no remaining matches to the regexp
            break
        }
    }

    # ++, --
    regexp = "([[:space:]]*)(+\\+|--)([[:space:]]*)"
    while ("true") {
        if (match(buffer, regexp, chunks)) {
            # printf "matched '%s'\n", chunks[0]
            # if (length(chunks[1]) != 0 || length(chunks[3]) != 1) {
            if (length(chunks[1]) != 0) {
                warning()
                next
            }
            buffer = substr(buffer, 1, RSTART-1) chunks[1] "@@" chunks[3] substr(buffer, RSTART+RLENGTH)
            # printf "new buffer '%s'\n", buffer
        } else {
            # no remaining matches to the regexp
            break
        }
    }

    # +, -, *, /
    regexp = "([[:space:]]*)(+|-|*/)([[:space:]]*)"
    while ("true") {
        if (match(buffer, regexp, chunks)) {
            # printf "matched '%s'\n", chunks[0]
            if (length(chunks[1]) != 1 || length(chunks[3]) != 1) {
                warning()
                next
            }
            buffer = substr(buffer, 1, RSTART-1) chunks[1] "@" chunks[3] substr(buffer, RSTART+RLENGTH)
            # printf "new buffer '%s'\n", buffer
        } else {
            # no remaining matches to the regexp
            break
        }
    }
}
