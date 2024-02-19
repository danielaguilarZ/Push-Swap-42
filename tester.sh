#!/bin/bash

NC='\033[0m'
BOLD_RED='\033[1;31m'
BOLD_GREEN='\033[1;32m'
BOLD_YELLOW='\033[1;33m'


echo -e "\n"
read -p "[!] Choose the quantity of numbers [5, 100, 500] " quantityWanted
echo -e "\n"
read -p "[!] Number of tests that you wanna try: " n
echo -e "\n"

i=1
passedtest=0
quantity=0
maxOperation=0
worst=0

if [ $quantityWanted -eq 5 ]; then
    quantity=$((quantity + 5))
    maxOperation=$((maxOperation + 11))
elif [ $quantityWanted -eq 100 ]; then
    quantity=$((quantity + 100))
    maxOperation=$((maxOperation + 700))
elif [ $quantityWanted -eq 500 ]; then
    quantity=$((quantity + 500))
    maxOperation=$((maxOperation + 5500))
else
    read -p "[!] Choose the quantity of numbers [5, 100, 500] " quantityWanted
    if [ $quantityWanted -eq 5 ]; then
        quantity=$((quantity + 5))
        maxOperation=$((maxOperation + 11))
    elif [ $quantityWanted -eq 100 ]; then
        quantity=$((quantity + 100))
        maxOperation=$((maxOperation + 700))
    elif [ $quantityWanted -eq 500 ]; then
        quantity=$((quantity + 500))
        maxOperation=$((maxOperation + 5500))
    else
        echo "[!] Invalid choice. Exiting..."
        exit 1
    fi
fi

numberGenerator() 
{
    local cantidad=$quantity

    numeros_aleatorios=$(seq -1000000 1000000 | shuf | head -n $cantidad)

    echo "$numeros_aleatorios"
}

while [ "$n" -gt 0 ]; do
    randomNumbers=$(numberGenerator)
    start=$(date +%s%N)
    operation=$(./push_swap $randomNumbers | wc -l)
    end=$(date +%s%N)
    duration=$((($end - $start)/1000000))

    if [ $operation -le $maxOperation ]; then
        echo -e "[+] TEST $i:${BOLD_YELLOW} $operation${NC} ${BOLD_GREEN}PASSED${NC} Time: ${duration}ms"
        passedtest=$((passedtest + 1))
    elif [ $operation -gt $maxOperation ]; then
        echo -e "[+] TEST $i:${BOLD_YELLOW} $operation${NC} ${BOLD_RED}FAILED${NC} Time: ${duration}ms"
    fi
    
    if [ $worst -lt $operation ]; then
        worst=$operation
    fi

    i=$((i + 1))
    n=$((n - 1))
done

result=$(echo "scale=2; ($passedtest / ($i - 1)) * 100" | bc)

# if [ $result -lt 50 ]; then
#     echo -e "\nThe percent of passed test is ${BOLD_RED}$result%${NC}, and the worse case was $worst"
# elif [[ $result -ge 50 && $result -le 70 ]]; then
#     echo -e "\nThe percent of passed test is ${BOLD_YELLOW}$result%${NC}, and the worse case was $worst"
# elif [ $result -ge 70 ]; then
#     echo -e "\nThe percent of passed test is ${BOLD_GREEN}$result%${NC}, and the worse case was $worst"
# fi

if [ $(echo "$result < 50" | bc) -eq 1 ]; then
    echo -e "\nThe percent of passed test is ${BOLD_RED}$result%${NC}, and the worse case was $worst"
elif [ $(echo "$result >= 50 && $result <= 70" | bc) -eq 1 ]; then
    echo -e "\nThe percent of passed test is ${BOLD_YELLOW}$result%${NC}, and the worse case was $worst"
elif [ $(echo "$result >= 70" | bc) -eq 1 ]; then
    echo -e "\nThe percent of passed test is ${BOLD_GREEN}$result%${NC}, and the worse case was $worst"
fi
