#usr/bin/bash
# khoi tao 2 file ANS va HIST
ANS_FILE="ans.txt"
HIST_FILE="history.txt"

# kiem tra, file Ans gan gia tri 0
if [ ! -f "$ANS_FILE" ]; then
    echo "0" > "$ANS_FILE"
fi

ANS=$(cat "$ANS_FILE") #iu lai gia tri ANS khi reset program

calculate() {
    local num1=$1
    local operator=$2
    local num2=$3

    case $operator in
        +) result=$(echo "$num1 + $num2" | bc);;
        -) result=$(echo "$num1 - $num2" | bc);;
        x) result=$(echo "$num1 * $num2" | bc);;
        /) 
            if [ "$num2" -eq 0 ]; then
                echo "MATH ERROR"
                return 1
            fi
            result=$(echo "scale=2; $num1 / $num2" | bc);;
        %) result=$(echo "$num1 % $num2" | bc);;
        *)
            echo "SYNTAX ERROR"
            return 1
            ;;
    esac

    # Update ANS 
    ANS=$result
    echo "$ANS" > "$ANS_FILE"
    
    # Update history
    echo "$num1 $operator $num2 = $result" >> "$HIST_FILE"
    # Keep only the last 5 entries in history
    tail -n 5 "$HIST_FILE" > "$HIST_FILE.tmp" && mv "$HIST_FILE.tmp" "$HIST_FILE"

    echo "Result: $result"
}


while true; do
    # Display ">> "
    echo -n ">> "
    read input

   
    if [[ "$input" == "EXIT" ]]; then
        echo "Exiting the program."
        break
    fi

 
    if [[ "$input" == "HIST" ]]; then
        if [ -f "$HIST_FILE" ]; then
            echo "Calculation History (last 5):"
            cat "$HIST_FILE"
        else
            echo "No history available."
        fi
        continue
    fi

    # Substitute "ANS" with the last result if present in the input
    input=${input//ANS/$ANS}

    # Parse the input
    num1=$(echo $input | awk '{print $1}')
    operator=$(echo $input | awk '{print $2}')
    num2=$(echo $input | awk '{print $3}')

   
    calculate "$num1" "$operator" "$num2"
done
