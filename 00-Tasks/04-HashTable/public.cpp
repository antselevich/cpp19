#include "entry_point.h"

#include <string>
#include <map>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::UnorderedElementsAre;

namespace Task04 {
    TEST(Public, IndexOperator) {
        HashMap<std::string, int> map;

        map["a"] = 1;
        map["b"] = 2;
        map["c"] = 3;

        EXPECT_EQ(map["a"], 1);
        EXPECT_EQ(map["b"], 2);
        EXPECT_EQ(map["c"], 3);

        map["a"]++;
        map["b"]++;
        map["c"]++;

        EXPECT_EQ(map["a"], 2);
        EXPECT_EQ(map["b"], 3);
        EXPECT_EQ(map["c"], 4);
    }

    TEST(Public, Insert) {
        HashMap<std::string, int> map;

        map.insert(std::pair<std::string, int>("a", 1));
        map.insert(std::pair<std::string, int>("b", 2));
        map.insert(std::pair<std::string, int>("c", 3));

        EXPECT_EQ(map["a"], 1);
        EXPECT_EQ(map["b"], 2);
        EXPECT_EQ(map["c"], 3);
    }

    TEST(Public, Iteration) {
        HashMap<std::string, int> map;

        map.insert(std::pair<std::string, int>("a", 1));
        map.insert(std::pair<std::string, int>("b", 2));
        map.insert(std::pair<std::string, int>("c", 3));
        map.insert(std::pair<std::string, int>("d", 4));
        map.insert(std::pair<std::string, int>("e", 5));

        std::vector<std::pair<std::string, int>> res;
        for (auto&& kv : map) {
            res.emplace_back(kv);
        }

        EXPECT_THAT(res, UnorderedElementsAre(
            std::pair<std::string, int>("a", 1),
            std::pair<std::string, int>("b", 2),
            std::pair<std::string, int>("c", 3),
            std::pair<std::string, int>("d", 4),
            std::pair<std::string, int>("e", 5)
        ));
    }

    TEST(Public, Find) {
        HashMap<std::string, int> map;

        map.insert(std::pair<std::string, int>("a", 1));
        map.insert(std::pair<std::string, int>("b", 2));
        map.insert(std::pair<std::string, int>("c", 3));
        map.insert(std::pair<std::string, int>("d", 4));
        map.insert(std::pair<std::string, int>("e", 5));

        EXPECT_EQ(map.find("u"), map.end());

        ASSERT_NE(map.find("a"), map.end());
        EXPECT_EQ(map.find("a")->second, 1);

        ASSERT_NE(map.find("b"), map.end());
        EXPECT_EQ(map.find("b")->second, 2);

        ASSERT_NE(map.find("c"), map.end());
        EXPECT_EQ(map.find("c")->second, 3);

        ASSERT_NE(map.find("d"), map.end());
        EXPECT_EQ(map.find("d")->second, 4);

        ASSERT_NE(map.find("e"), map.end());
        EXPECT_EQ(map.find("e")->second, 5);
    }

    TEST(Public, Erase) {
        HashMap<std::string, int> map;

        map.insert(std::pair<std::string, int>("a", 1));
        map.insert(std::pair<std::string, int>("b", 2));
        map.insert(std::pair<std::string, int>("c", 3));
        map.insert(std::pair<std::string, int>("d", 4));
        map.insert(std::pair<std::string, int>("e", 5));

        ASSERT_NE(map.find("e"), map.end());
        map.erase(map.find("e"));
        EXPECT_EQ(map.find("e"), map.end());

        std::vector<std::pair<std::string, int>> res;
        for (auto&& kv : map) {
            res.emplace_back(kv);
        }

        EXPECT_THAT(res, UnorderedElementsAre(
            std::pair<std::string, int>("a", 1),
            std::pair<std::string, int>("b", 2),
            std::pair<std::string, int>("c", 3),
            std::pair<std::string, int>("d", 4)
        ));
    }

    TEST(Public, InitializerList) {
        HashMap<std::string, std::string> m = {
            {"ololo", "ololo1"},
            {"azaza", "azaza1"},
            {"ururu", "ururu1"}
        };

        EXPECT_EQ(m.size(), 3u);
        ASSERT_NE(m.find("ololo"), m.end());
        ASSERT_NE(m.find("azaza"), m.end());
        ASSERT_NE(m.find("ururu"), m.end());

        std::vector<std::pair<std::string, std::string>> res;
        for (auto&& kv : m) {
            res.emplace_back(kv);
        }

        EXPECT_THAT(res, UnorderedElementsAre(
            std::pair<std::string, std::string>("ololo", "ololo1"),
            std::pair<std::string, std::string>("azaza", "azaza1"),
            std::pair<std::string, std::string>("ururu", "ururu1")
        ));
    }
}
