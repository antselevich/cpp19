#include "entry_point.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::ElementsAre;

namespace {
    Document iphone7plus("Iphone 7 plus", 50000, 20, 76.2f, -25.1f, "eldorado");
    Document iphone7minusWhite("Iphone 7 minus white", 10000, 95, 1.2f, 20.1f, "mvideo");
    Document iphone7minusBlack("Iphone 7 minus black", 10000, 95, 1.2f, 20.1f, "mvideo");

    std::vector<Document> docs = {
            iphone7plus,
            iphone7minusWhite,
            iphone7minusBlack,
    };

    TEST(Searcher, MultipleSort) {
        Searcher searcher(docs);

        const std::vector<std::string> &result =
                searcher
                        .Filter(new TitleFilter("phone"))
                        .Sort({new SortByPrice(), new SortByTitle()})
                        .Serialize(new CSVSerializer({DOCFIELD::PRICE, DOCFIELD::TITLE}));

        ASSERT_THAT(result, ElementsAre(
                "10000,Iphone 7 minus black",
                "10000,Iphone 7 minus white",
                "50000,Iphone 7 plus"
        ));
    }

    TEST(Searcher, HighlightSerializer) {
        Searcher searcher(docs);

        const std::vector<std::string>& result =
                searcher
                    .Filter(new TitleFilter("plus"))
                    .Serialize(new HighlightTitleCSVSerializer({DOCFIELD::TITLE, DOCFIELD::PRICE}));

        ASSERT_THAT(result, ElementsAre(
            "Iphone 7 *plus*,50000"
        ));
    }
}