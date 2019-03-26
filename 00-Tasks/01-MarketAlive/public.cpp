#include "entry_point.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;

namespace {
    class Public : public ::testing::Test {
    protected:
        Searcher* searcher;

        void SetUp() override {
            Document iphone7plus("Iphone 7 plus", 50000, 20, 76.2f, -25.1f, "eldorado");
            Document iphone7minus("Iphone 7 minus", 10000, 95, 1.2f, 20.1f, "mvideo");
            Document galaxyS7("Samsung galaxy s7", 14000, 15, 21.2f, -11.8f, "mvideo");
            Document lumiaSX("Nokia Lumia SX", 22000, 45, -23.2f, -42.1f, "svyaznoy syzran");
            std::vector<Document> docs = {
                    iphone7plus,
                    iphone7minus,
                    galaxyS7,
                    lumiaSX
            };
            searcher = new Searcher(docs);
        }

        void TearDown() override {
            delete searcher;
        }
    };

    TEST_F(Public, SimpleFilter) {
        auto result = searcher
                ->Filter(new PriceFilter(14000))
                .Serialize(new CSVSerializer({DOCFIELD::TITLE, DOCFIELD::PRICE}));

        ASSERT_THAT(result, UnorderedElementsAre(
                "Iphone 7 minus,10000",
                "Samsung galaxy s7,14000"
        ));
    }

    TEST_F(Public, FilterSortAndSerialize) {
        auto result = searcher
                ->Filter(new TitleFilter("phone"))
                .Sort(new SortByPrice())
                .Serialize(new CSVSerializer({DOCFIELD::PRICE, DOCFIELD::TITLE}));

        ASSERT_THAT(result, ElementsAre(
                "10000,Iphone 7 minus",
                "50000,Iphone 7 plus"
        ));
    }
}