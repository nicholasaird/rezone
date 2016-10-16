#include "gmock/gmock.h"

#include "Needs.h"
#include "StockPair.h"

class MockNeeds : public Needs {
public:
    MOCK_METHOD1(required, StockPair(int level));
    MOCK_METHOD1(max, StockPair(int level));
    MOCK_METHOD1(downgradeThreshold, StockPair(int level));
};
