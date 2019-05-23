#include "entry_point.h"

#include <string>
#include <map>
#include <tuple>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace Task04 {
    TEST(PublicAdvanced, InsertKeyAndVal) {
        HashMap<std::string, int> hm;
        hm.insert("ololo", 12);
        hm.insert("azaza", 13);

        ASSERT_EQ(12, hm["ololo"]);
        ASSERT_EQ(13, hm["azaza"]);
    }

    TEST(PublicAdvanced, TryEmplace) {
        HashMap<std::string, std::tuple<int, int, double>> hm;
        hm.try_emplace("ololo", 1, 2, 3.14);
        hm.try_emplace("azaza", 3, 4, 2.71);

        ASSERT_EQ(1, std::get<0>(hm["ololo"]));
        ASSERT_EQ(2, std::get<1>(hm["ololo"]));
        ASSERT_FLOAT_EQ(3.14, std::get<2>(hm["ololo"]));
    }
}
