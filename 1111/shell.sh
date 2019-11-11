who | sort > prev
while true; do
    sleep 3
    who | sort > curr
    echo " log out "
    comm -23 prev curr
    echo " log in "
    comm -13 prev curr
    mv curr prev
done
