if [ "$COVERAGE" = "on" ]
then
    bash <(curl -s https://codecov.io/bash)
fi
