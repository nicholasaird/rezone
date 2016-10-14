if [ "$COVERAGE" = "on" ]
then
    bash <(curl -s https://codecov.io/bash) -f build/reports/coverage/coverage.info
fi
